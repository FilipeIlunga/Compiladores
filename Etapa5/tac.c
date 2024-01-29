#include "tac.h"

TAC* newTac(int type, HASH_NODE* res, HASH_NODE* op1, HASH_NODE* op2) {
  TAC* node = (TAC*) calloc(1, sizeof(TAC));

  node->type = type;
  node->res = res;
  node->op1 = op1;
  node->op2 = op2;
  node->prev = NULL;
  node->next = NULL;

  return node;
}

TAC* tacUnion(TAC* list_1, TAC* list_2) {
  TAC* aux;

  if(!list_1)
    return list_2;
  
  if(!list_2)
    return list_1;

  aux = list_2;

  while(aux->prev)
    aux = aux->prev;

  aux->prev = list_1;

  return list_2;
}

TAC* rewindTac(TAC* list) {
  TAC* aux = list;

  for(aux; aux->prev; aux = aux->prev)
    aux->prev->next = aux;

  return aux;
}

TAC* buildTac(AST* node, HASH_NODE* label) {
  if(!node) return NULL;

	TAC* son[MAX_SONS];
	if(node->type == AST_WHILE){
		label = createLabel();
	}
  
	for(int i = 0; i < MAX_SONS; i++)
		son[i] = buildTac(node->son[i], label);

switch (node->type) {
    case AST_SYMBOL:
        return newTac(TAC_SYMBOL, node->symbol, 0, 0);
    case AST_ATTR:
        return tacUnion(son[0], newTac(TAC_MOVE, node->symbol, son[0] ? son[0]->res : 0, 0));
    case AST_ATTRVEC:
        return tacUnion(son[0], tacUnion(son[1], newTac(TAC_VECATTR, node->symbol, son[0] ? son[0]->res : 0, son[1] ? son[1]->res : 0)));
    case AST_INPUT:
        return newTac(TAC_INPUT, node->symbol, 0, 0);
    case AST_PRINT:
        return tacUnion(tacUnion(son[0], newTac(TAC_PRINT, son[0] ? son[0]->res : 0, 0, 0)), son[1]);
    case AST_RETURN:
        return tacUnion(son[0], newTac(TAC_RET, son[0] ? son[0]->res : 0, 0, 0));
    case AST_IF:
    case AST_ELSE:
        return makeIf(son);
    case AST_WHILE:
        return makeWhile(son, label);
    case AST_CODE:
    case AST_FUNC:
        return tacUnion(son[0], newTac(TAC_CALL, createTemp(), node->symbol, 0));
    case AST_LSTARG:
    case AST_LSTARGFIM:
        return tacUnion(son[1], tacUnion(son[0], newTac(TAC_ARGPUSH, son[0] ? son[0]->res : 0, 0, 0)));
    case AST_VEC:
        return tacUnion(son[0], newTac(TAC_VEC, createTemp(), node->symbol, son[0] ? son[0]->res : 0));
    case AST_DECPROTO:
        return createFunction(newTac(TAC_SYMBOL, node->symbol, 0, 0), son[1], son[2]);
    case AST_PARAM:
        return tacUnion(newTac(TAC_PARAMPOP, node->symbol, 0, 0), son[1]);
    case AST_ADD:
        return makeBinop(TAC_ADD, son);
    case AST_SUB:
        return makeBinop(TAC_SUB, son);
    case AST_MUL:
        return makeBinop(TAC_MUL, son);
    case AST_DIV:
        return makeBinop(TAC_DIV, son);
    case AST_GREATER:
        return makeBinop(TAC_GT, son);
    case AST_LESS:
        return makeBinop(TAC_LT, son);
    case AST_EQ:
        return makeBinop(TAC_EQ, son);
    case AST_GE:
        return makeBinop(TAC_GE, son);
    case AST_LE:
        return makeBinop(TAC_LE, son);
    case AST_DIF:
        return makeBinop(TAC_DIF, son);
    case AST_AND:
        return makeBinop(TAC_AND, son);
    case AST_OR:
        return makeBinop(TAC_OR, son);
    case AST_NOT:
        return makeBinop(TAC_NOT, son);
    default:
        return tacUnion(tacUnion(tacUnion(son[0], son[1]), son[2]), son[3]);
}

}

void printTac(TAC* list) {
  if(list->type == TAC_SYMBOL) return;
	
	fprintf(stderr, "TAC(");
	switch(list->type){
		case TAC_MOVE: fprintf(stderr, "MOVE(");break;
		case TAC_ADD: fprintf(stderr, "ADD(");break;
		case TAC_SUB: fprintf(stderr, "SUB(");break;
		case TAC_MUL: fprintf(stderr, "MUL(");break;
		case TAC_DIV: fprintf(stderr, "DIV(");break;
		case TAC_GT: fprintf(stderr, "GREAT(");break;
		case TAC_LT: fprintf(stderr, "LESS(");break;
		case TAC_GE: fprintf(stderr, "GE(");break;
		case TAC_LE: fprintf(stderr, "LE(");break;
		case TAC_EQ: fprintf(stderr, "EQ(");break;
		case TAC_DIF: fprintf(stderr, "DIF(");break;
		case TAC_AND: fprintf(stderr, "AND(");break;
		case TAC_OR: fprintf(stderr, "OR(");break;
		case TAC_NOT: fprintf(stderr, "NOT(");break;
		case TAC_LABEL: fprintf(stderr, "LABEL(");break;
		case TAC_BEGINFUN: fprintf(stderr, "BEGINFUN(");break;
		case TAC_ARGPUSH: fprintf(stderr, "ARGPUSH(");break;
		case TAC_ENDFUN: fprintf(stderr, "ENDFUN(");break;
		case TAC_IF: fprintf(stderr, "IF(");break;
		case TAC_JUMP: fprintf(stderr, "JUMP(");break;
		case TAC_CALL: fprintf(stderr, "CALL(");break;
		case TAC_ARG: fprintf(stderr, "ARG(");break;
		case TAC_RET: fprintf(stderr, "RET(");break;
		case TAC_PRINT: fprintf(stderr, "PRINT(");break;
		case TAC_INPUT: fprintf(stderr, "INPUT(");break;
		case TAC_VECATTR: fprintf(stderr, "VECATTR(");break;
		case TAC_VEC: fprintf(stderr, "VEC(");break;
		case TAC_PARAMPOP: fprintf(stderr, "PARAMPOP(");break;

		default: fprintf(stderr, "UNKNOWN TAC TYPE!(");break;
	}

	if(list->res) {
		fprintf(stderr, "%s, ", list->res->text);
  } else {
		fprintf(stderr, "0, ");
  }

	if(list->op1) {
		fprintf(stderr, "%s, ", list->op1->text);
  } else {
		fprintf(stderr, "0, ");
  }

	if(list->op2) {
		fprintf(stderr, "%s", list->op2->text);
  } else {
		fprintf(stderr, "0");
  	fprintf(stderr, "))\n");
  }
}

void generatedTac(TAC* list) {
  TAC* aux = list;

  for(aux; aux; aux = aux->next)
    printTac(aux);
}

TAC* makeBinop(int type, TAC* children[]) {

  HASH_NODE* code1;
  HASH_NODE* code2;
  TAC* temp;

  if(children[0]) {
    code1 = children[0]->res;
  } else {
    code1 = 0;
  }

  if(children[1]) {
    code2 = children[1]->res;
  } else {
    code2 = 0;
  }

  temp = tacUnion(children[0], tacUnion(children[1], newTac(type, createTemp(), code1, code2)));
  return temp;
}

TAC* makeWhile(TAC* children[], HASH_NODE* label) {
  HASH_NODE* jumpLabel = createLabel();

  TAC* whileTac = newTac(TAC_IF, jumpLabel, children[0]?children[0]->res:0, 0);
  TAC* whileLabelTac = newTac(TAC_LABEL, label, 0, 0);
  TAC* jumpTac = newTac(TAC_JUMP, label, 0, 0);
	TAC* jumpLabelTac= newTac(TAC_LABEL, jumpLabel, 0, 0);

  return tacUnion(tacUnion(tacUnion(tacUnion(tacUnion(whileLabelTac, children[0]), whileTac), children[1]), jumpTac), jumpLabelTac);
}

TAC* createFunction(TAC* symbol, TAC* params, TAC* code) {
  return tacUnion(tacUnion(tacUnion(newTac(TAC_BEGINFUN, symbol->res, 0, 0), params), code), newTac(TAC_ENDFUN, symbol->res, 0, 0));
}

TAC* makeIf(TAC* children[]) {
    HASH_NODE* ifLabel = createLabel();
    TAC* ifTac = tacUnion(children[0], newTac(TAC_IF, ifLabel, children[0] ? children[0]->res : 0, 0));
    TAC* ifLabelTac = newTac(TAC_LABEL, ifLabel, 0, 0);

    if (children[2]) {
        HASH_NODE* elseLabel = createLabel();
        TAC* elseLabelTac = newTac(TAC_LABEL, elseLabel, 0, 0);
        TAC* elseJumpTac = newTac(TAC_JUMP, elseLabel, 0, 0);
        TAC* ifElseTac = tacUnion(tacUnion(tacUnion(tacUnion(tacUnion(ifTac, children[1]), elseJumpTac), ifLabelTac), children[2]), elseLabelTac);

        return ifElseTac;
    } else {
        return tacUnion(tacUnion(ifTac, children[1]), ifLabelTac);
    }
}
