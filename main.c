#define STACK_FLAG_INT

#include "stack.h"
#include <stdio.h>

#define N 512
#define ISDIGIT(c)  \
    ((c) >= '0' && (c) <= '9')
#define ISWHITE(c)  \
    ((c) == ' ' || (c) == '\t' || (c) == '\n' )
#define CTOI(c)     \
    ((c) - '0')


size_t parseNum(char* str, int* e);
int rpnCalc(void);

int rpnCalc(void){
    sqStack s;
    initStack(&s);

    printf("Enter a RPN Expression (end with '#'): ");
    char rpn_str[N];
    fgets(rpn_str, N, stdin);

    char c;
    int i = 0;
    int num1, num2, tmp;
    int n = 0;

    while((c = rpn_str[i++]) != '#'){
        if(ISWHITE(c)){

        }
        else if(ISDIGIT(c)){
            n = parseNum(rpn_str + i - 1, &tmp);
            i = i - 1 + n;
//            tmp = CTOI(c);
            pushStack(&s, &tmp);
        }
        else{
            switch(c){
                case '+':
                    popStack(&s, &num1);
                    popStack(&s, &num2);
                    tmp = num1 + num2;
                    pushStack(&s, &tmp);
                    break;
                case '*':
                    popStack(&s, &num1);
                    popStack(&s, &num2);
                    tmp = num1 * num2;
                    pushStack(&s, &tmp);
                    break;
                case '-':
                    popStack(&s, &num1);
                    popStack(&s, &num2);
                    tmp = num2 - num1;
                    pushStack(&s, &tmp);
                    break;
                case '/':
                    popStack(&s, &num1);
                    popStack(&s, &num2);
                    if(num1 != 0){
                        tmp = num2 / num1;
                        pushStack(&s, &tmp);
                    }
                    else{
                        fprintf(stderr, "Error: divided by 0\n");
                        return 1;
                    }
                    break;
                default :
                    fprintf(stderr, "Error: invaild expression\n");
                    return 1;
                    break;
            }
        }
    }

    int ret = 0;
    if(lenStack(&s) == 1){
        popStack(&s, &ret);
        printf("%d\n", ret);
    }
    else{
        fprintf(stderr, "Error: invaild expression\n");
        return 1;
    }
    return 0;
}

size_t parseNum(char* str, int* e){
    int base = 10;
    int ret  =  0;
    char *sp = str;
    while(ISDIGIT(*sp)){
        ret = ret * base + CTOI(*sp);
        sp++;
    }
    *e = ret;
    return (sp - str);
}

#if 0
int infixCalc(char* s){

    sqStack s;
    initStack(&s);

    char c;
    char e;
    char str[N];
    fgets(str, N, stdin);
    size_t i = 0;
    size_t n = 0;
    while((c = str[i++]) != '#'){
        if(ISDIGIT(c)){
            n = getNum(str + i - 1);
            i += n - 1;
        }
        else if(ISWHITE(c)){

        }
        else if(c == '+' || c == '-'){
            if(lenStack(&s) == 0){
                pushStack(&s, &c);
            }else{
                do{
                    popStack(&s, &e);
                    printf("%c ", e);
                }while(lenStack(&s) != 0);
                pushStack(&s, &c);
            }
        }
        else if(c == '*' || c == '/'){
            pushStack(&s, &c);
        }
        else{
            fprintf(stderr, "Error: invaild expression\n");
        }
    }
    while(lenStack(&s) != 0){
        popStack(&s, &e);
        printf("%c ", e);
    }

    printf("#\n");
    return 0;
}
#endif

size_t getNum(char *s){
    
    size_t i = 0;
    while(ISDIGIT(*(s + i))){
        printf("%c", *(s + i));
        i++;
    }
    printf(" ");
    return i;
}



int main(int argc, char* argv[]){
    rpnCalc();
    return 0;
}

