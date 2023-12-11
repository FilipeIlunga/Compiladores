#include "ast.h"

AST* astCreate(int type, HASH_NODE* symbol,AST* son0, AST* son1, AST* son2, AST* son3) {
    AST* newnode;
    newnode = (AST*) calloc(1,sizeof(AST));
    newnode->type = type;
    newnode->symbol = symbol;
    newnode->son[0] = son0;
    newnode->son[1] = son1;
    newnode->son[2] = son2;
    newnode->son[3] = son3;
    return newnode;
}

void uncompileAST(AST* node, FILE* file) {

    if (node == NULL) return;
      printf(" %s )\n", node->symbol?node->symbol->text:"");
    switch (node->type) {
        case AST_SYMBOL: 
            fprintf(file, " %s ", node->symbol->text); 
            break;
        case AST_ADD: 
            uncompileAST(node->son[0], file);
            fprintf(file, " + ");
            uncompileAST(node->son[1], file);
            break;
        case AST_SUB: 
            uncompileAST(node->son[0], file);
            fprintf(file, " - ");
            uncompileAST(node->son[1], file);
            break;
        case AST_MUL: 
            uncompileAST(node->son[0], file);
            fprintf(file, " * ");
            uncompileAST(node->son[1], file);
            break;
        case AST_DIV: 
            uncompileAST(node->son[0], file);
            fprintf(file, " / ");
            uncompileAST(node->son[1], file);
            break;
        case AST_LESS: 
            uncompileAST(node->son[0], file);
            fprintf(file, " < ");
            uncompileAST(node->son[1], file);
            break;
        case AST_GREATER:
            uncompileAST(node->son[0], file);
            fprintf(file, " > ");
            uncompileAST(node->son[1], file);
            break;
        case AST_LE:
            uncompileAST(node->son[0], file);
            fprintf(file, " <= ");
            uncompileAST(node->son[1], file);
            break;
        case AST_GE:
            uncompileAST(node->son[0], file);
            fprintf(file, " >= ");
            uncompileAST(node->son[1], file);
            break;
        case AST_EQ:    
            uncompileAST(node->son[0], file);
            fprintf(file, " == ");
            uncompileAST(node->son[1], file);
            break;
        case AST_DIF:
            uncompileAST(node->son[0], file);
            fprintf(file, " != ");
            uncompileAST(node->son[1], file);
            break;
        case AST_NOT:
            fprintf(file, "!");
            uncompileAST(node->son[0], file);
            break;
        case AST_LSTDEC:
            uncompileAST(node->son[0], file);
            uncompileAST(node->son[1], file);
            break;
        case AST_DECVAR:
            uncompileAST(node->son[0], file);
            fprintf(file, " %s = ", node->symbol->text);
            uncompileAST(node->son[1], file);
            fprintf(file, ";\n");
            break;
        case AST_DECVEC:
            uncompileAST(node->son[0], file);
            fprintf(file, " %s[", node->symbol->text);
            uncompileAST(node->son[1], file);
            fprintf(file, "]");
            uncompileAST(node->son[2], file);
            fprintf(file, ";\n");
            break;

        case AST_DECPROTO:
            uncompileAST(node->son[0], file);
            fprintf(file, " %s(", node->symbol->text);
            uncompileAST(node->son[1], file);
            fprintf(file, ");\n");
            // uncompileAST(node->son[2], file);
            // fprintf(file, ";\n");
            break;
        case AST_PARAM:
            uncompileAST(node->son[0], file);
            fprintf(file, " ");
            fprintf(file, " %s", node->symbol->text);
            // uncompileAST(node->son[1], file);
            break;
        case AST_BLOCO:
            fprintf(file, "{\n");
            uncompileAST(node->son[0], file);
            fprintf(file, "}\n");
            break;
        case AST_LSTCOMANDO:
            uncompileAST(node->son[0], file);
            uncompileAST(node->son[1], file);
            break;
        case AST_PRINT:
            fprintf(file, "print ");
            uncompileAST(node->son[0], file);
            fprintf(file, ";\n");
            break;
        case AST_RETURN:
            fprintf(file, "return ");
            uncompileAST(node->son[0], file);
            fprintf(file, ";\n");
            break;
        case AST_IF:
            fprintf(file, "if (");
            uncompileAST(node->son[0], file);
            fprintf(file, ")\n");
            uncompileAST(node->son[1], file);
            break;
        case AST_ELSE:
            fprintf(file, " else\n");
            uncompileAST(node->son[2], file);
            break;
        case AST_WHILE:
            fprintf(file, "while (");
            uncompileAST(node->son[0], file);
            fprintf(file, ")\n");
            uncompileAST(node->son[1], file);
            break;
        case AST_INPUT:
            fprintf(file, "input (");
            uncompileAST(node->son[0], file);
            fprintf(file, ");\n");
            break;
        case AST_CODE:
            fprintf(file, "code ");
            fprintf(file, " %s ", node->symbol->text);
            uncompileAST(node->son[0], file);
        case AST_INT:
            fprintf(file, " int ");
            break;
        case AST_FLOAT:
            fprintf(file, "float");
            break;
        case AST_CHAR:
            fprintf(file, "char");
            break;
        case AST_OPT:
            uncompileAST(node->son[0], file);
            fprintf(file, " ");
            uncompileAST(node->son[1], file);
            break;
        case AST_PARAMINIT:
            uncompileAST(node->son[0], file);
            uncompileAST(node->son[1], file);
            break;
        case AST_LSTPARAM:
            fprintf(file, ", ");
            uncompileAST(node->son[0], file);
            uncompileAST(node->son[1], file);
            break;
        case AST_LSTCODIGO:
            fprintf(file, "code ");
            fprintf(file, "%s", node->symbol->text);
            uncompileAST(node->son[0], file);
            uncompileAST(node->son[1], file);
            break;
        // case AST_ATTR:
        //     uncompileAST(node->son[0], file);
        //     fprintf(file, " = ");
        //     uncompileAST(node->son[1], file);
        //     fprintf(file, ";\n");
        //     break;
        case AST_PAREN:
            fprintf(file, "(");
            uncompileAST(node->son[0], file);
            fprintf(file, ")");
            break;
        case AST_LSTARG:
            uncompileAST(node->son[0], file);
            fprintf(file, ",");
            uncompileAST(node->son[1], file);
            break;
        case AST_LSTARGFIM:
            uncompileAST(node->son[0], file);
            fprintf(file, ",");
            uncompileAST(node->son[1], file);
            break;
        case AST_VEC:
            fprintf(file, "%s[", node->symbol->text);
            uncompileAST(node->son[0], file);
            fprintf(file, "]");
            break;
        case AST_FUNC:
            fprintf(file, "%s(", node->symbol->text);
            uncompileAST(node->son[0], file);
            fprintf(file, ")");
            break;
        case AST_ATTREXPR:
            fprintf(file, "%s = ", node->symbol->text);
            uncompileAST(node->son[0], file);
            fprintf(file, ";\n");
            break;
        case AST_ATTRVEC:
            fprintf(file, "%s[", node->symbol->text);
            uncompileAST(node->son[0], file);
            fprintf(file, "] = ");
            uncompileAST(node->son[1], file);
            fprintf(file, ";\n");
            break;
        // case AST_VECFIM:
        //     uncompileAST(node->son[0], file);
        //     break;
        // case AST_PROG:
        //     uncompileAST(node->son[0], file);
        //     break;
        case AST_LDECGLOBAL:
            uncompileAST(node->son[0], file);
            uncompileAST(node->son[1], file);
            break;
        case AST_PRINTEXP:
        fprintf(file, "print ");
        uncompileAST(node->son[0], file);
        fprintf(file, ";\n");
        break;
        default: fprintf(file, "UNKNOWN"); break;
    }
}


void astPrint(AST* node, int level) {
    if (node == 0) return;
    int i;
    for (i = 0; i < level; ++i) fprintf(stderr,"  ");
    switch (node->type) {
        case AST_SYMBOL: fprintf(stderr, "AST_SYMBOL"); break;
        case AST_ADD: fprintf(stderr, "AST_ADD"); break;
        case AST_SUB: fprintf(stderr, "AST_SUB"); break;
        case AST_MUL: fprintf(stderr, "AST_MUL"); break;
        case AST_DIV: fprintf(stderr, "AST_DIV"); break;
        case AST_LESS: fprintf(stderr, "AST_LESS"); break;
        case AST_GREATER: fprintf(stderr, "AST_GREATER"); break;
        case AST_INT: fprintf(stderr, "AST_INT"); break;
        case AST_FLOAT: fprintf(stderr, "AST_FLOAT"); break;
        case AST_CHAR: fprintf(stderr, "AST_CHAR"); break;
        case AST_LE: fprintf(stderr, "AST_LE"); break;
        case AST_GE: fprintf(stderr, "AST_GE"); break;
        case AST_EQ: fprintf(stderr, "AST_EQ"); break;
        case AST_DIF: fprintf(stderr, "AST_DIF"); break;
        case AST_NOT: fprintf(stderr, "AST_NOT"); break;
        case AST_IF: fprintf(stderr, "AST_IF"); break;
        case AST_ELSE: fprintf(stderr, "AST_ELSE"); break;
        case AST_WHILE: fprintf(stderr, "AST_WHILE"); break;
        case AST_INPUT: fprintf(stderr, "AST_INPUT"); break;
        case AST_CODE: fprintf(stderr, "AST_CODE"); break;
        case AST_PRINT: fprintf(stderr, "AST_PRINT"); break;
        case AST_RETURN: fprintf(stderr, "AST_RETURN"); break;
        case AST_LSTDEC: fprintf(stderr, "AST_LSTDEC"); break;
        case AST_DECVAR: fprintf(stderr, "AST_DECVAR"); break;
        case AST_DECVEC: fprintf(stderr, "AST_DECVEC"); break;
        case AST_DECPROTO: fprintf(stderr, "AST_DECPROTO"); break;
        case AST_PARAM: fprintf(stderr, "AST_PARAM"); break;
        case AST_BLOCO: fprintf(stderr, "AST_BLOCO"); break;
        case AST_LSTCOMANDO: fprintf(stderr, "AST_LSTCOMANDO"); break;
        case AST_VEC: fprintf(stderr, "AST_VEC"); break;
        case AST_FUNC: fprintf(stderr, "AST_FUNC"); break;
        case AST_OPT: fprintf(stderr, "AST_OPT"); break;
        case AST_PARAMINIT: fprintf(stderr, "AST_PARAMINIT"); break;
        case AST_LSTPARAM: fprintf(stderr, "AST_LSTPARAM"); break;
        case AST_LSTCODIGO: fprintf(stderr, "AST_LSTCODIGO"); break;
        case AST_ATTR: fprintf(stderr, "AST_ATTR"); break;
        case AST_ATTREXPR: fprintf(stderr, "AST_ATTREXPR"); break;
        case AST_PAREN: fprintf(stderr, "AST_PAREN"); break;
        case AST_LSTARG: fprintf(stderr, "AST_LSTARG"); break;
        case AST_LSTARGFIM: fprintf(stderr, "AST_LSTARGFIM"); break;
        case AST_ATTRVEC: fprintf(stderr, "AST_ATTRVEC"); break;
        case AST_VECFIM: fprintf(stderr, "AST_VECFIM"); break;
        case AST_PROG: fprintf(stderr, "AST_PROG"); break;
        case AST_LDECGLOBAL: fprintf(stderr, "AST_LDECGLOBAL"); break;
        case AST_PRINTEXP: fprintf(stderr, "AST_PRINTEXP"); break;

        default: fprintf(stderr, "UNKNOWN"); break;
    }

  printf(" %s )\n", node->symbol?node->symbol->text:"");
  for(i=0; i<MAX_SONS; i++) {
    astPrint(node->son[i], level+1);
  }
  
}
