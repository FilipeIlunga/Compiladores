#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "ast.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void checkUndeclared(AST *node);
void handleSemanticErrors(int errorType, int lineNumber, const char *customMessage);
void checkAndSetDeclarations(AST *node, AST *root);
void setSymbolDataType(AST *node, AST *dataTypeNode);
void checkAndSetNodes(AST *node);
void handleSymbolNode(AST *node);
void handleArithmeticOperation(AST *node);
void handleRelationalOperation(AST *node);
void handleLogicalOperation(AST *node);
int isArithmeticOperation(int type);
int isRelationalOperation(int type);
int isLogicalOperation(int type);
void checkUsage(AST *node, AST *root);
void handleAttributeExpression(AST *node);
void handleAttributeVector(AST *node);
void checkFunction(AST *node, AST *root);
void compareFunctionArguments(AST *node1, AST *node2);
int countParams(AST *node);
AST *findFunctionDeclaration(char *text, AST *node);
void setFunctionImplementation(char *text, AST *node);
void checkExpressionCompatibility(AST *node);
int checkOperandCompatibility(AST *operand1, AST *operand2);
void handleSemanticSwitch(AST *node);
void checkOperands(AST *node);
void checkMisc(AST *node);
void checkReturnTypeCompatibility(AST *node, int datatype);
int totalSemanticErrors();
int isCompatible(int type1, int type2);


#endif
