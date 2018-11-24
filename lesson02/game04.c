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
			else if(masu[i][j] == PLAYER2){
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

int judge_yoko(int masu[3][3], int turn){
	int i;
	for(i = 0; i < 3; i++){
		if(masu[i][0] == turn && masu[i][1] == turn && masu[i][2] == turn){
			return 1;
		}
	}
	return 0;
}

int judge_tate(int masu[3][3], int turn){
	int i;
	for(i = 0; i < 3; i++){
		if(masu[0][i] == turn && masu[1][i] == turn && masu[2][i] == turn){
			return 1;
		}
	}
	return 0;
}

int judge_naname(int masu[3][3], int turn){
	int i;
	int fr_cnt = 0;
	int fl_cnt = 0;
	for(i = 0; i < 3;i++){
		if(masu[i][i] == turn){
			fl_cnt += 1;
		}
		if(masu[i][2 - i] == turn){
			fr_cnt += 1;
		}
	}
	if(fr_cnt == 3 || fl_cnt == 3){
		return 1;
	}
	return 0;
}

int judge_winner(int masu[3][3], int turn){
	int winner_flag = 0;
	if ( judge_yoko(masu , turn) || judge_tate(masu, turn) || judge_naname(masu, turn)){
		winner_flag = 1;
	}
	return winner_flag;
}

int main(int argc, char *argv[]){
	int input_num; /* 入力 */
	int line, row;
	enum TURN turn = P1_TURN; /* どちらのターンか */
	int masu[3][3]; /* マス目 */
	int i, j;
	int player;
	for( i = 0; i < 3;i ++){
		for(j = 0; j < 3;j++){
			masu[i][j] = INIT;
		}
	}
	while(1){
		if(turn ==  P1_TURN){
			printf("先行の番です\n");
		}
		else{
			printf("後攻の番です\n");
		}
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
			if (judge_winner(masu, turn)){
				printf("先行の勝ち\n");
				printf("最終結果\n\n\n");
				show(masu);
				break;
			}
		}
		else if (turn == PLAYER2){
			masu[line][row] = PLAYER2;
			if (judge_winner(masu, turn)){
				printf("後攻の勝ち\n");
				printf("最終結果\n\n\n");
				show(masu);
				break;
			}
		}
		show(masu);
		turn = (turn != P1_TURN) ? P1_TURN : P2_TURN; // ターンチェンジ
	}
	return 0;
}
