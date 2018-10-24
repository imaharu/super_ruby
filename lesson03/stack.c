#include <stdio.h>
#include <stdlib.h>

#define max_snum 10

int push(int *stack, int input, int *sp){
	stack[(*sp)] = input;
	*sp = *sp + 1;
	return *sp;
}

int pop(int *stack, int *sp){
	*sp = *sp - 1;
	return stack[*sp];
}

int main(int argc, char *argv[]){
	int stack[max_snum];
	int sp = 0;
	int data;

	/* push */ 
	push(stack, 10, &sp);
	printf("%d\n", stack[0]);

	push(stack, 20, &sp);
	printf("%d\n", stack[1]);
	
	/* pop */
	data = pop(stack , &sp);
	printf("data = %d\n", data);
	
	data = pop(stack , &sp);
	printf("data = %d\n", data);

	return 0;
}
