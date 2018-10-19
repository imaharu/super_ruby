#include <stdio.h>
#include <stdio.h>

#define INIT 0
#define PLAYER1 1
#define PLAYER2 2

enum TURN { P1_TURN , P2_TURN };

void show(int masu[3][3]){
	int i,j;
	for( i = 0; i < 3;i ++){
		for(j = 0; j < 3;j++){
			printf("%d ", masu[i][j]);
		}
		printf("\n");
	}
} 

int check_input(int input_num){	
	int flag = 0; /* input_numが1 ~ 9の整数値か判断*/
	int i;
	for(i = 1; i <= 9;i++){
		if(i == input_num){
			flag = 1;
		}
	}
	return flag;
}

int main(int argc, char *argv[]){
	int input_num; /* 入力 */
	enum TURN turn = P1_TURN; /* どちらのターンか */
	int masu[3][3]; /* マス目 */
	int i, j;
	for( i = 0; i < 3;i ++){
		for(j = 0; j < 3;j++){
			masu[i][j] = INIT;
		}
	}

	while(1){
		scanf("%d",&input_num);
		if(check_input(input_num)){
			printf("flag = true : input_num = %d\n",input_num);	
		}
		else{
			printf("1 ~ 9を入力して下さい");
			break;
		}
		printf("turn = %d\n", turn);
		turn = (turn != P1_TURN) ? P1_TURN : P2_TURN; // ターンチェンジ
	}
	return 0;
}
