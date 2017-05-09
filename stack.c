#define STACK_FLAG_CHAR

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Status initStack (sqStack *s){
    s->base = (elemType*)malloc(sizeof(elemType) * STACK_INIT_SIZE);
    if(s->base == NULL){
        return ERROR;
    }
    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
    return OK;
}
Status emptyStack(sqStack *s){
    s->top = s->base;
    return OK;
}

Status destroyStack(sqStack *s){
    free(s->base);
    return OK;
}

Status pushStack (sqStack *s, elemType *e){
    if (s->top - s->base >= s->stackSize){
        s->base = (elemType*)realloc(s->base,
                  (s->stackSize + STACK_INCREMENT) * sizeof(elemType));
        s->stackSize += STACK_INCREMENT;
        if(s->base == NULL){
            return ERROR;
        }
    }
    *((s->top)++) = *e;
    return OK;
}

Status popStack (sqStack *s, elemType *e){
    if(s->top == s->base){
        return ERROR;
    }    
    *e = *(--(s->top));
    return OK;
}

int lenStack (const sqStack *s){
    return (int)(s->top - s->base);
}

