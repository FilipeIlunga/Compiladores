#include "semantic.h"
#include "ast.h"
#include <stdlib.h>

int semanticErrors = 0;

void checkUndeclared(AST *node){
    semanticErrors += checkUndeclaredHash();
}

void handleSemanticErrors(int errorType, int lineNumber, const char* customMessage) {
    fprintf(stderr, "Erro Semântico na Linha %d: %s\n", lineNumber, customMessage);
    ++semanticErrors;
}

void checkAndSetDeclarations(AST *node, AST *root){
    if(node == NULL) {
        return;
    }

    switch(node->type){
        case AST_DECVAR:
            if(node->symbol->type != SYMBOL_IDENTIFIER){
                handleSemanticErrors(1, node->lineNumber, "Variable already declared");
            }
            else {
                setSymbolDataType(node, node->son[0]);
                node->symbol->type = SYMBOL_VAR;
            }
            break;
        case AST_DECVEC:
            if(node->symbol->type != SYMBOL_IDENTIFIER){
                handleSemanticErrors(1, node->lineNumber, "Vector already declared");
            }
            else {
                setSymbolDataType(node, node->son[0]);
                node->symbol->type = SYMBOL_VEC;
            }
            break;
        case AST_DECPROTO:
            if(node->symbol->type != SYMBOL_IDENTIFIER){
                handleSemanticErrors(1, node->lineNumber, "Function already declared");
            }
            else {
                setSymbolDataType(node, node->son[0]);
                node->symbol->type = SYMBOL_FUN;
            }

            setFunctionImplementation(node->symbol->text, root);
            if(node->symbol->wasImplemented > 1) {
                handleSemanticErrors(1, node->lineNumber, "Function already implemented");
            } else if(node->symbol->wasImplemented == 0) {
                handleSemanticErrors(1, node->lineNumber, "Function not implemented");
            }
            break;
        case AST_PARAM:
            if(node->symbol->type != SYMBOL_IDENTIFIER){
                handleSemanticErrors(1, node->lineNumber, "Parameter already declared");
            }
            else {
                setSymbolDataType(node, node->son[0]);
                node->symbol->type = SYMBOL_PARAM;
            }
            break;
        default:
            break;
    }

    for(int i = 0; i < MAX_SONS; i++){
        checkAndSetDeclarations(node->son[i], root);
    }
}

void setSymbolDataType(AST* node, AST* dataTypeNode) {
    if(dataTypeNode->type == AST_INT) {
        node->symbol->datatype = DATATYPE_INT;
    } else if(dataTypeNode->type == AST_FLOAT) {
        node->symbol->datatype = DATATYPE_FLOAT;
    } else {
        node->symbol->datatype = DATATYPE_CHAR;
    }
}

void checkAndSetNodes(AST *node) {
    if(node == NULL) {
        return;
    }

    for(int i = 0; i < MAX_SONS; i++) {
        checkAndSetNodes(node->son[i]);
    }

    if(node->type == AST_SYMBOL){
        handleSymbolNode(node);
    } else if(node->type == AST_FUNC || node->type == AST_VEC) {
        node->datatype = node->symbol->datatype;
    } else if(node->type == AST_PAREN) {
        node->datatype = node->son[0]->datatype;
    } else if(isArithmeticOperation(node->type)) {
        handleArithmeticOperation(node);
    } else if(isRelationalOperation(node->type)) {
        handleRelationalOperation(node);
    } else if(isLogicalOperation(node->type)) {
        handleLogicalOperation(node);
    }
}

void handleSymbolNode(AST* node) {
    if(node->symbol->type == SYMBOL_VEC || node->symbol->type == SYMBOL_FUN) {
        handleSemanticErrors(1, node->lineNumber, "Not a scalar");
    } 
    node->datatype = node->symbol->datatype;
}

void handleArithmeticOperation(AST* node) {
    AST* son0 = node->son[0];
    AST* son1 = node->son[1];

    if(isCompatible(son0->datatype, son1->datatype)) {
        node->datatype = son0->datatype;
    } else {
        handleSemanticErrors(1, node->lineNumber, "Incompatible operand types");
    }
}

void handleRelationalOperation(AST* node) {
    node->datatype = DATATYPE_BOOL;
}

void handleLogicalOperation(AST* node) {
    node->datatype = DATATYPE_BOOL;
}

int isArithmeticOperation(int type) {
    return (type == AST_ADD || type == AST_SUB || type == AST_MUL || type == AST_DIV);
}

int isRelationalOperation(int type) {
    return (type == AST_LESS || type == AST_GREATER || type == AST_LE || type == AST_GE || type == AST_EQ || type == AST_DIF);
}

int isLogicalOperation(int type) {
    return (type == AST_AND || type == AST_OR || type == AST_NOT);
}

void checkUsage(AST *node, AST *root) {
    if(node == NULL) {
        return;
    }

    switch(node->type) {
        case AST_ATTREXPR:
            handleAttributeExpression(node);
            break;
        case AST_ATTRVEC:
            handleAttributeVector(node);
            break;
        case AST_FUNC:
            checkFunction(node, root);
            break;
        default:
            break;
    }

    for(int i = 0; i < MAX_SONS; i++) {
        checkUsage(node->son[i], root);
    }
}

void handleAttributeExpression(AST* node) {
    if(node->symbol->type != SYMBOL_VAR) {
        handleSemanticErrors(1, node->lineNumber, "Not a variable");
    }
}

void handleAttributeVector(AST* node) {
    if(node->symbol->type != SYMBOL_VEC) {
        handleSemanticErrors(1, node->lineNumber, "Not a vector");
    }
}

void checkFunction(AST* node, AST* root) {
    AST* decFunc = findFunctionDeclaration(node->symbol->text, root);

    fprintf(stderr, "Function %s, %d\n", node->symbol->text, node->symbol->wasImplemented);

    if (node->symbol->wasImplemented < 1) {
        handleSemanticErrors(1, node->lineNumber, "Function not implemented");
    }

    if (decFunc == NULL) {
        handleSemanticErrors(1, node->lineNumber, "Function not declared");
    } else {
        int expectedParams = countParams(decFunc->son[1]);
        int actualParams = countParams(node->son[0]);

        if (actualParams != expectedParams) {
            handleSemanticErrors(1, node->lineNumber, "Incorrect number of parameters");
        } else {
            compareFunctionArguments(node->son[0], decFunc->son[1]);
        }
    }
}

void compareFunctionArguments(AST* node1, AST* node2) {
    if (node1 == NULL && node2 == NULL) return;

    if (node1 == NULL || node2 == NULL) {
        handleSemanticErrors(1, node1 ? node1->lineNumber : node2->lineNumber, "Incorrect parameter types");
        return;
    }

    if (node1->son[0]->symbol->datatype != node2->son[0]->symbol->datatype) {
        handleSemanticErrors(1, node1->lineNumber, "Incorrect parameter types");
        return;
    }

    compareFunctionArguments(node1->son[1], node2->son[1]);
}

int countParams(AST* node) {
    return (node == NULL) ? 0 : 1 + countParams(node->son[1]);
}

AST* findFunctionDeclaration(char* text, AST* node) {
    if (node == NULL) return NULL;

    if (node->type == AST_DECPROTO && strcmp(node->symbol->text, text) == 0) return node;

    for (int i = 0; i < MAX_SONS; i++) {
        AST* result = findFunctionDeclaration(text, node->son[i]);

        if (result != NULL) return result; 
    }

    return NULL;
}

void setFunctionImplementation(char* text, AST* node) {
    if (node == NULL) return;

    if (node->type == AST_CODE && strcmp(node->symbol->text, text) == 0) {
        node->symbol->wasImplemented++;
    }

    for (int i = 0; i < MAX_SONS; i++) {
        setFunctionImplementation(text, node->son[i]);
    }
}

void checkExpressionCompatibility(AST* node) {
   if(isArithmeticOperation(node->type) || isRelationalOperation(node->type) || isLogicalOperation(node->type)) {
        if(!checkOperandCompatibility(node->son[0], node->son[1])) {
            handleSemanticErrors(1, node->lineNumber, "Incompatible operand types");
        }
    } 
}

int checkOperandCompatibility(AST* operand1, AST* operand2) {
    return isCompatible(operand1->datatype, operand2->datatype);
}

void handleSemanticSwitch(AST* node) {
    switch (node->type) {
        case AST_INPUT:
            if (node->son[0]->type != AST_FLOAT && node->son[0]->type != AST_CHAR && node->son[0]->type != AST_INT) {
                handleSemanticErrors(1, node->lineNumber, "Input parameter must be a type (char, int or float");
            }
            break;
        case AST_IF:
            if (isCompatible(node->son[0]->datatype, DATATYPE_BOOL) == 0) {
                handleSemanticErrors(2, node->lineNumber, "If condition must be a boolean");
            }
            break;
        case AST_ATTREXPR:
            if (node->symbol->type != SYMBOL_VAR) {
                handleSemanticErrors(3, node->lineNumber, "Assignment to non-variable");
            }
            break;
        case AST_ATTRVEC:
            if (node->son[0]->symbol->type != SYMBOL_LIT_INT) {
                handleSemanticErrors(4, node->lineNumber, "Vector index must be an integer");
            }
            if (node->son[1]->type != SYMBOL_VEC) {
                handleSemanticErrors(5, node->lineNumber, "Vector value must be a vector");
            }
            break;
        default:
            break;
    }
}

void checkOperands(AST* node){
    if(node == 0) {
        return;
    }

 checkExpressionCompatibility(node);
  handleSemanticSwitch(node);

    
    for(int i = 0; i < MAX_SONS; i++) checkOperands(node->son[i]);
}   

void checkMisc(AST* node) {
    if(node == 0) {
        return;
    }
    if(node->type == AST_CODE){
        checkReturnTypeCompatibility(node, node->symbol->datatype);
    }
    for(int i = 0; i < MAX_SONS; i++){
        checkMisc(node->son[i]);
    }
}

void checkReturnTypeCompatibility(AST *node, int datatype) {
    if(node == 0) {
        return;
    }
    if(node->type == AST_RETURN) {
        if(node->son[0]->datatype != datatype) {
            fprintf(stderr, "Erro Semântico na Linha %d: Tipo de retorno incompatível\n", node->lineNumber);
            ++semanticErrors;

        }
    }
    for(int i = 0; i < MAX_SONS; i++){
        checkReturnTypeCompatibility(node->son[i], datatype);
    }
}

int totalSemanticErrors(){
    return semanticErrors;
}

int isCompatible(int type1, int type2){
    if((type1 == type2)  || (type1 == DATATYPE_INT && type2 == DATATYPE_FLOAT) || (type1 == DATATYPE_CHAR && type2 == DATATYPE_CHAR)) {
        return 1;
    }
    return 0;
}
