#include <bits/stdc++.h>
using namespace std;

int partition(int A[],int l,int h)
{
    int pivot = A[l];
    int i = l , j = h;

    while(i < j)
    {
        do{
            i++;
        }while(A[i] <= pivot);

        do{
            j--;
        }while(A[j] > pivot);

        if(i<j)
            swap(A[i],A[j]);
    }

    swap(A[l],A[j]);
    return j;
}

void quickSort(int A[],int l,int h)
{
    if(l < h)
    {
        int j = partition(A,l,h);
        quickSort(A,l,j);
        quickSort(A,j+1,h);
    }
}

int main()
{
    int arr[] = {10,16,8,12,15,6,3,9,5};
    int N = sizeof(arr)/sizeof(int);
    quickSort(arr,0,N);
    for(int i=0;i<N;i++)
        cout << arr[i] << " ";
    return 0;
}
