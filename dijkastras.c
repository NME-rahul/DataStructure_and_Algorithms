#include<stdio.h>

void dijkastrs(int col, int arr[][col], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            for(int k = 0; k < size; k++){
                if(arr[i][j] > (arr[i][k] + arr[k][j])){
                    printf("arr[%d][%d]->arr[%d][%d],   arr[%d][%d]->arr[%d][%d]\n", i, j, i, k, i, k, i, j);
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }
}

void printArray(int col, int arr[][col], int size){
    printf("\n\nDijkastra's Algorithm: \n");
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int arr[][4] = {{0, 1, 999, 2},
                    {1, 0, 999, 999},
                    {999, 999, 0, 3},
                    {2, 999, 3, 0}};

    int size = sizeof(arr) / (sizeof(arr[0][0])*sizeof(arr[0][0]));

    dijkastrs(size, arr, size);

    printArray(size, arr, size);

    return 0;
}
