import numpy as np
import matplotlib.pyplot as plt

def swap(arr, pivot, q):
    temp = arr[pivot]
    arr[pivot] = arr[q]
    arr[q] = temp

def quickSort(arr, start, arrLen):
    pivot = np.random.randint(arrLen)
    for i in range(arrLen):
        p = i; q = arrLen - i
        if arr[p] > arr[pivot]:
            saveP = 
        elif p > q:
            swap(arr, pivot, q) #swap pivot element with q
            quickSort(arr, )
        elif p > pivot and q < pivot:
            qucikSort(arr)#array element is on position
        
    
def main():
    arr = []
    for i in range(int(input("Array size: "))):
        arr.append(int(input("enter element: ")))
     
    arrLen =  
    qucikSort(arr, 0, len(arr) - 1)