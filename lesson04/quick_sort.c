#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max_num 10

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

void quicksort(int array[], int left, int right){
    int origin_l = left;
    int origin_r = right;
    int pivot = array[(left + right) / 2];
    do{
        while(1){
            if( array[left] >= pivot){
                break;
            }
            left++;
        }
        while(1){
            if( array[right] <= pivot){
                break;
            }
            right--;
        }
        if ( left <= right){
            swap(&array[left], &array[right]);
            left++;
            right--;
        }
    }while( left <= right);

    if (origin_l < right){
        quicksort(array, origin_l, right);
    }
    if (left < origin_r){
        quicksort(array, left , origin_r);
    }
}

int main(int argc, char *argv[]){
    int i, j;
    int array[max_num];
    int left = 0;
    int right = max_num - 1;
    clock_t start,end;
    srand(time(NULL));

    for(i = 0; i < max_num; i++){
        array[i] = rand() % 1000 + 1;
    }

    printf("交換前\n");
    show(array);
    start = clock();
    quicksort(array, left, right);
    end = clock();
    printf("交換後\n");
    show(array);
    printf("%.4f秒かかりました\n",(double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}
