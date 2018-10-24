#include <stdio.h>

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
	
	return 0;
}
