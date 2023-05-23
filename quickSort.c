#include<stdio.h>
#include<time.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if( arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);

    return (i + 1);
}

void quickSort(int arr[], int low, int high){
    if(low < high){

        int pi = partition(arr, low, high); //partition

        quickSort(arr, low, pi-1); // left
        quickSort(arr, pi+1, high); //right
    }
}

void printArray(int arr[], int size){
    for(int k=0; k < size; k++){
        printf("%d ", arr[k]);
    }
}

int main(){
    //clock_t t;

    int arr[] = {34, 3, 11, 67, 9, 0, 12, 55, 45, 56, 57, 8, 34, 67, 78, 787, 67, 67, 76};

    int size = sizeof(arr) / sizeof(arr[1]);

    printf("Array before sorting: "); printArray(arr, size);

    //t = clock();

    quickSort(arr, 0, size - 1);

    //t = clock() - t;

    //double time_taken = ((double)t) / CLOCKS_PER_SEC;

    //printf("%f", t);

    printf("\n\nArray after sorting: "); printArray(arr, size);

    return 0;
}
