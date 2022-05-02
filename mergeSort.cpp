#include<iostream>
using namespace std;
/*
step by step procedure-
arr[] = {92, 32, 11, 55, 2}

break the array every by middle in subarrays until one element left
size of array is 5 after break
two subarrays form {92, 32, 11} and {55, 2}
now break both the subarrays from middle
{93, 32}, {11} , {55}, {2}
again break
{93}, {32}, {11}, {55}, {2}
after breaking arrays
merge every subarray by their comparing them
we can say that 93 and 32 are two arrays respectively rightSubArray[] and leftSubArray[], merge them as smaller first and successively greater elements.
{32, 93}
{11, 55}
{2} alone element

every time we create a new left and right subArrays.

now merge subarrays {32, 93} an {11, 55}
{11, 32, 55, 93}
{2}

now merge subarrays {11, 32, 55, 93} and {2}
{2, 11, 32, 55, 93}

NOTE: for better viualization how array breaks in subarrays see the image ![Merge-Sort-Tutorial](https://user-images.githubusercontent.com/100432854/166328277-4ca0c711-11d5-4020-912b-88de3a711d2c.png)

major drawback - Slower comparative to the other sort algorithms for smaller tasks.

Time Complexity:-
Best: O(n*log(n))
Average: O(n*log(n))
Worst: O(n*log(n))
*/
void merge_(int arr, int beg, int mid, int end_)
{
    int i=0, j=0, k=0;
    int rightSubArray[mid + 1 - beg], leftSubArray[end_ - mid];

    //merge subarrays
    for(i=0; i<mid+1 - beg; i++)
        rightSubArray[i] = arr[beg+i];
    for(i=0; i<end_ - mid; i++)
        leftSubArray[i] = arr[mid+1+i];

    i=0;
    k=beg;

    //merge subarrays in main array
    while(i < (mid+1 - beg) && j < (end_ - mid))
    {
        if(rightSubArray[i] <= leftSubArray[j] )
        {
            arr[k] = rightSubArray[i];
            i++;
        }
        else
        {
            arr[k] = leftSubArray[j];
            j++;
        }
        k++;
    }

    //merge remaining elements of subrrays that are left by uneven size of the subarrays
    while(i < (mid+1 - beg))
    {
        arr[k] = rightSubArray[i];
        i++; k++;
    }
    while(j < (end_ - mid))
    {
        arr[k] = leftSubArray[j];
        j++; k++;
    }
}
void mergeSort(int arr[], int size_, int beg, int end_)
{
    int mid;
    if(end_ > beg)
    {
        mid = (beg + end_)/2;
        mergeSort(arr, beg, mid); //recursive call of function to break the array in in right subarrays and get the size of their
        mergeSort(arr, mid+1, end_); //recursive call of function to break the array in left subarrays and  get the size of their
        merge_(arr, beg, mid, end_); //recursive call of function to merge subarrays and subarrays in main array
    }
}
int main()
{
    int size_;
    cout<<"Enter array size: ";
    cin>>size_;

    int arr[size_];
    cout<<"Enter elements in array: ";
    for(int i=0; i<size_; i++)
    {
        cin>>arr[i];
    }

    mergeSort(arr, size_, 0, size_-1);

    cout<<"\narray after sorting: ";
    for(int i=0; i<size_; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
