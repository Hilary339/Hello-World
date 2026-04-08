#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100

typedef enum{
    LEFT,RIGHT,NUM,ADD,SUB,MUL,DIV,MOD,EOS
}contentType;

typedef struct{
    int *data;
    int top;
}Stack;

//initize the stack.
Stack *initstack(){     
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->data = (int*)malloc(sizeof(int) * MAXSIZE);
    s->top = -1;
    return s;
}

//push n to the stack
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

//gain the kind of the char.
contentType gettoken(char *str,int index){
    int current = str[index];
    if (current >= '0' && current <= '9') return NUM;
    switch(current){
        case '(' : return LEFT;
        case ')' : return RIGHT;
        case '+' : return ADD;
        case '-' : return SUB;
        case '*' : return MUL;
        case '/' : return DIV;
        case '%' : return MOD;
        case '\0' : return EOS;
        default : return EOS;
    }
}

//calculate
int calculate(char *str){
    int n = strlen(str);
    Stack *stack = initstack();
    int op1,op2;                    //the numbers get involved in the calculation
    for (int index = 0; index < n; index++){
        contentType token = gettoken(str,index);    //token is the kind of char
        if (token == NUM){
            push(stack,str[index] - '0');   //push the number into the stack
        }
        else{
            op2 = pop(stack);
            op1 = pop(stack);
            //check the calculate method
            switch(token){
                case ADD : push(stack, op1 + op2);break;
                case SUB : push(stack, op1 - op2);break;
                case MUL : push(stack, op1 * op2);break;
                case DIV : push(stack, op1 / op2);break;
                case MOD : push(stack, op1 % op2);break;
                default : break;
            }
        }
    }
    //get the result
    int result = pop(stack);
    return result;
}

int main(){
    char str[MAXSIZE];
    scanf("%s",str);
    int result = calculate(str);
    printf("%d",result);
    return 0;
}