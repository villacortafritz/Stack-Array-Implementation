#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

Stack newStack(){
	Stack n;
	n=(Stack)malloc(sizeof(struct stack));
	n->data=(stackItem*)malloc(sizeof(stackItem)*MAX);
	n->top = 0;
	n->size = MAX;
	return n;
}
void push(Stack s, stackItem string){
	s->data[s->top++]=string;
}
void pop(Stack s){
	if(!isEmpty(s)){
		s->top--;
	}
}
char peek(Stack s){
	char ch;
	if(!isEmpty(s)){
		ch=s->data[s->top-1];
	}
	return ch;
}
void destroyStack(Stack *s){
	free((*s)->data);
	free(*s);
	*s=NULL;
}
void display(Stack s){
	int i;
	printf("[");
	for(i=0; i<s->top; i++){
		printf("%c ", s->data[i]);
	}
	printf("]");
}
void clear (Stack s){
	s->top=0;
}
boolean isEmpty(Stack s){
	return s->top == 0 ? true : false;
}
int check(char data[]){
	Stack s = newStack();
	int i, errorcode=1;
	char temp='\0';
	for(i=0; data[i]!='\0'; i++){
		temp=data[i];
		if(temp=='('){
			push(s, ')');
		}
		else if(temp=='['){
			push(s,']');
		}
		else if(temp=='{'){
			push(s, '}');
		}
		else if(temp==')'){
			if(!isEmpty(s)){
				if(peek(s)==temp){
					pop(s);		
				}
				else if(peek(s)!=temp){
				errorcode=2;
				break;
				}
			}
			else{
				errorcode=2;
				break;
			}	
		}
		else if(temp==']'){
			if(!isEmpty(s)){
				if(peek(s)==temp){
					pop(s);		
				}
				else if(peek(s)!=temp){
				errorcode=2;
				break;
				}
			}
			else{
				errorcode=2;
				break;
			}
		}
		else if(temp=='}'){
			if(!isEmpty(s)){
				if(peek(s)==temp){
					pop(s);		
				}
				else if(peek(s)!=temp){
				errorcode=2;
				break;
				}
			}
			else{
				errorcode=2;
				break;
			}	
		}
	}
	
	if(!isEmpty(s)){
		errorcode=3;
	}
	destroyStack(&s);
	return errorcode;
}
