#include<iostream>
using namespace std;

/*
step by step procedure -

arr[] = {90, 80, 70, 60, 50, 40, 30, 20, 10, 00};
start from second element 80 and compare with every left element of it's

90 80 70 60 50 40 30 20 10 00

compare 70 with it's every left element 90
80 is smaller then 90, so swap them
after swapping
80 90 70 60 50 40 30 20 10 00

(loop increase by 1)
compare 70 with it's every left elements 80 90
after finding minimum in left swap them
70 80 90 60 50 40 30 20 10 00
(70 is smaller it will swap with 80 , now 80 is at place of 70 the loop will start again and compare with it's left elements and again swap occur with 90 now 90 is at the place of 80)

(loop increase by 1)
compare 60 with it's every left element 70 80 90
after finding minimum in left swap them
60 70 80 90 50 40 30 20 10 00

(loop increase by 1)
compare 50 with it's every left elements 60 70 80 90
after finding minimum in left swap them
50 60 70 80 90 40 30 20 10 00

(loop increase by 1)
compare 40 with it's every left elements 50 60 70 80 90
40 50 60 70 80 90 30 20 10 00

(loop increase by 1)
compare 30 with it's every left elements 40 50 60 70 80 90
after finding minimum in left swap them
30 40 50 60 70 80 90 20 10 00

(loop increase by 1)
compare 20 with it's every left elements 30 40 50 60 70 80 90
after finding minimum in left swap them
20 30 40 50 60 70 80 90 10 00

(loop increase by 1)
compare 20 with it's every left elements 30 40 50 60 70 80 90
after finding minimum in left swap them
20 30 40 50 60 70 80 90 10 00

(loop increase by 1)
compare 10 with it's every left elements 20 30 40 50 60 70 80 90
after finding minimum in left swap them
10 20 30 40 50 60 70 80 90 00

(loop increase by 1)
compare 10 with it's every left elements 10 20 30 40 50 60 70 80 90
after finding minimum in left swap them
00 10 20 30 40 50 60 70 80 90
*/

void swap_(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void insertionSort(int arr[], int size_)
{
    for(int i=1; i<size_; i++) //loop starting from second element.
    {
        for(int j=0; j<i; j++) //this loop will go from 0 to value i(from where previous loop started).
        {
            if(arr[i] < arr[j]) //compare elements with it's(arr[i]) every left element.
            {
                swap_(&arr[i], &arr[j]); //swap values
            }
        }
    }
}
int main()
{
    int size_;
    cout<<"Enter size: ";
    cin>>size_;

    int arr[size_];
    cout<<"Enter elements: "<<endl;
    for(int i=0; i<size_; i++) //take input as unsorted array.
    {
        cin>>arr[i];
    }

    insertionSort(arr, size_);

    cout<<"Array after sorting: "<<endl;
    for(int i=0; i<size_; i++) //display output as sorted array.
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
