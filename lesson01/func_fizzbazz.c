#include <stdio.h>
#include <stdlib.h>


void fizz_bazz(int i){
	if(i % 3 == 0 && i % 5 == 0){
    	printf("%d:FizzBazz\n",i);
	}
  	else if(i % 5 == 0){
    	printf("%d:Buzz\n",i);
    }
    else if(i % 3 == 0){
    	printf("%d:Fizz\n",i);
	}		
}


int main(int argc, char *argv[]){
	int i;
	int max = 100;
	if (argc >= 2){
		max = atoi(argv[1]);
	}
	while(i != max){
		i++;
		fizz_bazz(i);
	}
	return 0;
}
