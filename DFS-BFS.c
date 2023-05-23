#include<stdio.h>

void printArray(int col, int arr[][col], int row){
    printf("Adjacency matrix: \n");
    for(int p = 0; p < row; p++){
        for(int q = 0; q < col; q++){
            printf("%5d ", arr[p][q]);
        }
        printf("\n\n");
    }
}

void removeTraversedVertice(int col, int arr[][col], int vertice){
    for(int k = 0; k < col; k++){
        arr[k][vertice] = -999;
    }
}

void push(int stack[], int vertice, int *ptr){
    *ptr = *ptr + 1;
    stack[*ptr] = vertice;
}
int pop(int stack[], int *ptr){
    int v = stack[*ptr];
    *ptr = *ptr - 1;
    return v;
}

void dfs(int col, int arr[][col], int row){

    int stack[row], ptr = -1;
    int vertice = 0;

    //initialization with first vertice
    push(stack, vertice, &ptr);
    removeTraversedVertice(col, arr, vertice);
    vertice = pop(stack, &ptr);

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(arr[vertice][j] != -999){
                if(arr[vertice][j] == 1){
                    push(stack, j, &ptr);
                    removeTraversedVertice(col, arr, j);
                }
            }
            printArray(col, arr, row);
        }
        vertice = pop(stack, &ptr);
        printf("\n");
    }
}

void insertV(int queue[], int *rear, int vertice){
    *rear = *rear + 1;
    queue[*rear] = vertice;
}

int removeV(int queue[], int *front, int *rear){
    if(*front > *rear){ //this condition will never occur because no queue will not empty while bfs
        printf("Queue is empty.");
        return -999;
    }
    else{
        *front = *front + 1;
        int v = queue[*front];
        return v;
    }
}

void bfs(int col, int arr[][col], int row){
    int vertice = 0;
    int queue[row], front = -1, rear = -1;

    //initialize queue by inserting first vertice
    insertV(queue, &rear, vertice);
    removeTraversedVertice(col, arr, vertice);
    vertice = removeV(queue, &front, &rear);

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(arr[vertice][j] != -999){
                if(arr[vertice][j] == 1){
                    insertV(queue, &rear, vertice);
                    removeTraversedVertice(col, arr, j);
                }
            }
            printArray(col, arr, row);
        }
        vertice = removeV(queue, &front, &rear);
        printf("\n");
    }
}

int main(){

    int arr[][6] ={{0, 1, 0, 0, 1, 0},
                   {0, 0, 1, 0, 0, 1},
                   {0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 1},
                   {0, 0, 0, 0, 0, 0},
                   {1, 0, 1, 0, 1, 0}};

    //dfs(6, arr, 6);
    //bfs(6, arr, 6);
    return 0;
}
