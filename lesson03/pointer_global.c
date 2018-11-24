#include <stdio.h>
#include <stdlib.h>

int x, y;

void swap(){
	int temp;

    printf("swap x_address: %p\n", &x);
	temp = x;
	x = y;
	y = temp;
}

int main(int argc, char *argv[]){

	if(argc != 3){
		printf("標準入力の引数は2つです。\n");
		return 0;
	}

	x = atoi(argv[1]);
	y = atoi(argv[2]);

	printf("before_x = %d\n", x);
	printf("before_y = %d\n", y);

    printf("main x_address: %p\n", &x);
	swap();
	
	printf("after_x = %d\n", x);
	printf("after_y = %d\n", y);

	return 0;
}
