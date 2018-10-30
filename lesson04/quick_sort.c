#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max_num 20

void show(int array[]){
	int i;
	
	for(i = 0; i < max_num; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}

void swap(int *x, int *y){
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

int main(int argc, char *argv[]){
	int i, j;
	int array[20];
	srand(time(NULL));

	for(i = 0; i < max_num;i++){
		array[i] = rand() % 1000 + 1;
	}
	printf("交換前\n");
	show(array);

	for(i = 0;i < max_num - 1; i++){
		for(j = i; j < max_num; j++){
			if(array[i] > array[j]){
				swap(&array[i], &array[j]);
			}
		}
	}

	printf("交換後\n");
	show(array);

	return 0;
}
