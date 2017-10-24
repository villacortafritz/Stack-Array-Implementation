#ifndef STACK_H
#define STACK_H
#define MAX 10

typedef enum{true, false} boolean;
typedef char stackItem;
struct stack{
	stackItem *data;
	int top;
	int size;
};
typedef struct stack *Stack;

Stack newStack();
void push(Stack s, stackItem string);
void pop(Stack s);
char peek(Stack s);
void destroyStack(Stack *s);
void display(Stack s);
void clear (Stack s);
boolean isEmpty(Stack s);
int check(char data[]);

#endif
