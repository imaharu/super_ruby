#include <stdio.h>
#include <stdio.h>

#define INIT 0
#define PLAYER1 1
#define PLAYER2 2

enum TURN { P1_TURN = 1, P2_TURN = 2};

void show(int masu[3][3]){
	int i,j;
	for( i = 0; i < 3;i ++){
		for(j = 0; j < 3;j++){
			if(masu[i][j] == INIT){
				printf(" - ");
			}
			else if(masu[i][j] == PLAYER1){
				printf(" ○ ");
			}
			else{
				printf(" × ");
			}	
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
	int line, row;
	enum TURN turn = P1_TURN; /* どちらのターンか */
	int masu[3][3]; /* マス目 */
	int i, j;
	for( i = 0; i < 3;i ++){
		for(j = 0; j < 3;j++){
			masu[i][j] = INIT;
		}
	}

	while(1){

		printf("1 ~ 9を入力して下さい\n");
		
		scanf("%d",&input_num);
		
		// 入力判定 
		if(!check_input(input_num)){
			printf("入力が間違っています\n");
			break;
		}
	
		
		line = (input_num - 1) / 3; // 行
		row  = (input_num - 1) % 3; // 列
		if(turn == PLAYER1){
			masu[line][row] = PLAYER1;
		}
		else if(turn == PLAYER2){
			masu[line][row] = PLAYER2;
		}
		show(masu);
		turn = (turn != P1_TURN) ? P1_TURN : P2_TURN; // ターンチェンジ
	}
	return 0;
}
