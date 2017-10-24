#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char *argv[]) {
	
	Stack s1, s2, s3;
	s1 = newStack();
	s2 = newStack();
	s3 = newStack();
	int i;
	
	printf("Check (s1):\t\t");
	push(s1,'C');
	push(s1,'h');
	push(s1,'e');
	push(s1,'c');
	push(s1,'k');
	display(s1);
	
	printf("\nTop of the array:\t%c");
	
	printf("\nInput (s2):\t\t");
	push(s2,'(');
	push(s2,'(');
	push(s2,'(');
	push(s2,')');
	push(s2,')');
	push(s2,')');
	push(s2,')');
	display(s2);
	
	printf("\nIs s1 empty?\t\t%d", isEmpty(s1));
	printf("\nIs s2 empty?\t\t%d", isEmpty(s2));
	printf("\nIs s3 empty?\t\t%d", isEmpty(s3));
	
	
	printf("\n\nAPPLICATION:");
	//s2
	printf("\nCheck s2:\t\t"); 
	i=check("({}][)}[]()");
	if(i==1){
		printf("All Paired Up!");
	}
	else if(i==2){
		printf("Missing open");
	}
	else{
		printf("Missing close");
	}
	//s4
	/*printf("\nCheck s4:\t\t"); 
	j=check("((()))");
	if(j==1){
		printf("All Paired Up!");
	}
	else if(j==2){
		printf("Missing open parenthesis");
	}
	else{
		printf("Missing close parenthesis");
	}*/

	printf("\nClear s2:\t\t");
	clear(s2);
	display(s2);
	
	
	return 0;
}
