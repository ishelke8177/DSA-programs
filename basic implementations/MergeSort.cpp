#include <iostream>
using namespace std;

void merge(int A[], int l, int m, int u)
{
    int L[m-l+1] , R[u-m];
    int i , j , k;

    for(i=0;i<m-l+1;i++)
        L[i] = A[l+i];

    for(j=0;j<u-m;j++)
        R[j] = A[m+1+j];

    for(k=l,i=0,j=0;i<m-l+1 && j<u-m;k++)
    {
        if(L[i]<R[j]){
            A[k]=L[i];
            i++;
        }
        else{
            A[k]=R[j];
            j++;
        }
    }

    while(i < m-l+1){
        A[k]=L[i];
        i++;
        k++;
    }

    while(j < u-m){
        A[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(int A[],int l,int u)
{
    if(l<u){
        int m = (l+u)/2;
        mergeSort(A,l,m);
        mergeSort(A,m+1,u);
        merge(A,l,m,u);
    }
}

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}

int main()
{
    int arr[] = { 0,1,2,4,6,5,3 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}
