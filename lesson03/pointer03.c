#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y){
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

int main(int argc, char *argv[]){
	int x, y;

	if(argc != 3){
		printf("標準入力の引数は2つです。\n");
		return 0;
	}

	x = atoi(argv[1]);
	y = atoi(argv[2]);

	printf("before_x = %d\n", x);
	printf("before_y = %d\n", y);

	swap(&x, &y);
	
	printf("after_x = %d\n", x);
	printf("after_y = %d\n", y);

	return 0;
}
