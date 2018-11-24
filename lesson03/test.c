#include<stdio.h>
int main(void){
    int x = 1111;
    int *p;
    p = &x; 
    printf("x_address: %p\n",&x);
    printf("p_address: %p\n",p);
    printf("what happens?: %p\n",&p);
    printf("x: %d\n",x);
    printf("p: %d\n",*p);
    return 0;
}
