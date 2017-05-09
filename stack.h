#ifndef _STACK_H_
#define _STACK_H_ 

#define Status int
#define OK       0
#define ERROR    1

#define STACK_INIT_SIZE 32
#define STACK_INCREMENT 32

#ifdef  STACK_FLAG_INT
#define STACK_FLAG  1
#endif

#ifdef  STACK_FLAG_CHAR
#define STACK_FLAG  2
#endif

#ifdef  STACK_FLAG_DOUBLE
#define STACK_FLAG  3
#endif

#if   STACK_FLAG == 1
typedef int elemType;
#elif STACK_FLAG == 2
typedef char elemType;
#elif STACK_FLAG == 3
typedef double elemType;
#endif

typedef struct _sq_stack_{
    elemType *base;
    elemType *top;
    int      stackSize;
}sqStack;

Status initStack   (sqStack *s);
Status emptyStack  (sqStack *s);
Status destroyStack(sqStack *s);
Status pushStack   (sqStack *s, elemType *e);
Status popStack    (sqStack *s, elemType *e);
int    lenStack    (const sqStack *s);

#endif

