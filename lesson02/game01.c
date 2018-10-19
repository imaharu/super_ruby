#include <stdio.h>

#define INIT 0
#define PLAYER1 1
#define PLAYER2 2

void show(int masu[3][3]){
	int i,j;
	for( i = 0; i < 3;i ++){
		for(j = 0; j < 3;j++){
			printf("%d ", masu[i][j]);
		}
		printf("\n");
	}
} 

int main(int argc, char *argv[]){
	int masu[3][3]; /* マス目 */
	int i, j;

	for( i = 0; i < 3;i ++){
		for(j = 0; j < 3;j++){
			masu[i][j] = INIT;
		}
	}
	show(masu);

	return 0;
}
