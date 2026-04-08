/*
Perform the calculation of single-digit suffix expressions.
The input format doesn't need spaces to be seperated.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#define MAXSIZE 100

//enumerate character type
typedef enum{
    LEFT,RIGHT,NUM,ADD,SUB,MUL,DIV,MOD,EOS
}contentType;

//create stack
typedef struct{
    int *data;
    int top;
}Stack;

//initialize the stack.
Stack *initstack(){     
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->data = (int*)malloc(sizeof(int) * MAXSIZE);
    s->top = -1;
    return s;
}

//push n into the stack
int push(Stack *s,int n){
    s->top++;
    if (s->top > MAXSIZE-1) {
        printf("full stack!");
        return 0;
    }
    s->data[s->top] = n;
    return 1;
}

//pop the top of stack 
int pop(Stack *s){
    if (s->top == -1){
        printf("empty stack!");
        return -1;
    }
    int m = s->data[s->top];
    s->top--;
    return m;
}

//calculate the suffix expressions
int calculate(char *str){
    Stack *stack = initstack();
    int op1,op2;                    //the numbers involved in the calculation
    char *s = strtok(str," ");
    while (s != NULL){
        //push the number when the token is a number
        if (isdigit(s[0]) || (s[0] == '-' && isdigit(s[1]))){
            push(stack,atoi(s));   
        }
        //pop stack when the token is a symbol
        else{
            op2 = pop(stack);
            op1 = pop(stack);
            //perform calculation and push the result into the stack
            switch(s[0]){
                case '+' : push(stack, op1 + op2);break;
                case '-' : push(stack, op1 - op2);break;
                case '*' : push(stack, op1 * op2);break;
                case '/' : push(stack, op1 / op2);break;
                case '%' : push(stack, op1 % op2);break;
                default : break;
            }
        }
        s = strtok(NULL," ");
    }
    //get the result
    int result = pop(stack);
    free(stack->data);
    free(stack);
    return result;
}

int main(){
    char str[MAXSIZE];
    fgets(str,MAXSIZE,stdin);
    str[strcspn(str, "\n")] = '\0';
    int result = calculate(str);
    printf("%d",result);
    return 0;
}
