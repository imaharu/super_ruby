#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int i;
	int max = 100;
	if (argc >= 2){
		max = atoi(argv[1]);
	}
	while(i != max){
		i++;
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
	return 0;
}
