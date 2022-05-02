#include<iostream>
using namespace std;
/*
working-
arr[] = {90, 43, 12, 76, 0};
take the first element from just element ahead start finding minimum element
90 is the first element, 43 is the just after the 90
0 is minimum after so swap them
repeat these steps

0 43 12 76 90
now 43 is the first and 12 just after it
12 is the minimum after
swap them

0 12 43 76 90
now 43 is the first and 76 just after it
43 is the minimum after
swap them

0 12 43 76 90
now 76 is the first and 90 just after it
76 is the minimum
swap them

0 12 43 76 90
now 90 is the last and no element after it
second loop will not start

Time Complexity:
Best: O(n^2)
Average: O(n^2)
Worst: O(n^2)

it has same complexity for trios case because loop is repeatedly moving and checking every element
*/
void swap_(int *x, int *y) //swaping elements
{
    int temp=*x;
    *x = *y;
    *y = temp;
}
void selectionSort(int arr[], int size_)
{
    for(int i=0; i<size_; i++)
    {
        for(int j=i+1; j<size_ - 1; j++) //loop starting one after element we take in previous loop.
        {
            if(arr[i] > arr[j]) //not only the first but every element is comparing with arr[i] and swaping with smaller values then its..
            {
                swap_(&arr[i], &arr[j]); 
            }
        }
    }
}
int main()
{
    int size_;
    cout<<"Enter array size: ";
    cin>>size_;
    
    int arr[size_];
    cout<<"Enter elements: "<<endl;
    for(int i=0; i<size_; i++) // take input as unsorted array
    {
        cin>>arr[i];
    }

    selectionSort(arr, size_);

    cout<<"Array after selection sort: ";
    for(int i=0; i<size_; i++) //display sorted array
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
