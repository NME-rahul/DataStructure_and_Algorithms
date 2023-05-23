#include<stdio.h>

void printArray(int col, int adjTble[][col-1], int row){
    printf("\nAdjacent Table: \n");
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col - 1; j++){
            printf("%5d ", adjTble[i][j]);
        }
        printf("\n\n");
    }
}

void removeTraversedVertice(int col, int adjTble[][col-1], int row, int saveI, int saveJ){
    int remove = adjTble[saveI][saveJ];
    for(int p = 0; p < row; p++){
        for(int q = 0; q < col - 1; q++){
            if(remove == adjTble[p][q]){
                adjTble[p][q] = -999;
            }
        }
    }
}

void minSpanningTree(int col, int arr[][col], int row, int adjTble[][col-1]){
    printArray(col, adjTble, row);
    removeTraversedVertice(col, adjTble, row, 1, 0);
    int saveI = 0, saveJ = 0;
    int min = 999; //initially
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col - 1; j++){
            if(adjTble[i][j] != -999){
                if(min > arr[i][adjTble[i][j]]){
                    min = arr[i][adjTble[i][j]];
                    saveI = i; saveJ = j;
                }
            }
        }
        removeTraversedVertice(col, adjTble, row, saveI, saveJ);
        printArray(col, adjTble, row);
    }
}

int main(){

    int arr[][4] = {{0, 5, 4, 3},
                    {5, 0, 9, 2},
                    {4, 9, 0, 1},
                    {3, 2, 1, 0}};

    int adjTble[][4-1] = {{1, 2, 3},
                          {0, 2, 3},
                          {0, 1, 3},
                          {0, 1, 2}}; //adjacent table in which row value is used as a vertice number.

    minSpanningTree(4, arr, 4, adjTble);

    return 0;
}
