#include <stdio.h>

int main(int argc, char *argv[]){
	int array[] = {72, 101, 108, 108, 111, 32, 87, 111, 114, 108, 100};
	int length = sizeof(array) / sizeof(int);
	int i;
	for(i = 0;i < length; i++){
		printf("%c",array[i]);
	}
	printf("\n");
	return 0;
}
