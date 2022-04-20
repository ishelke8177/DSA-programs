#include <bits/stdc++.h>
using namespace std;

int binarySearch(int A[],int N,int key)
{
    int l = 0 , h = N-1;
    int mid;

    while(l <= h)
    {
        mid = (l+h)/2;
        if(A[mid] == key)
            return mid;
        else if(key < A[mid]){
            h = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return 0;
}

int main()
{
    int arr[] = {3,5,6,9,8,10,12,15};
    int N = sizeof(arr)/sizeof(int);

    return 0;
}
