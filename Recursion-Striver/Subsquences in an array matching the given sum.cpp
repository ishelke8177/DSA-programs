// C++ code to print all possible
// subsequences for given array with given sum using
// recursion
#include <bits/stdc++.h>
using namespace std;
/**
// to print all subs
void printSubs(int ind,vector<int> &subarr,int s, int sum,int arr[],int n)
{
	if (ind == n){
        if(s == sum){
            for (auto it:subarr)
                cout << it << " ";
            cout<<endl;
        }
        return;
	}

    //pick the current index into the subsequence.
    subarr.push_back(arr[ind]);
    s += arr[ind];

    printSubs(ind+1,subarr,s,sum,arr,n);

    s -= arr[ind];
    subarr.pop_back();

    //not picking the element into the subsequence.
    printSubs(ind+1,subarr,s,sum,arr,n);
}

// to print one subq
bool printSubs(int ind,vector<int> &subarr,int s, int sum,int arr[],int n)
{
	if (ind == n){
        if(s == sum){
            for (auto it:subarr)
                cout << it << " ";
            cout<<endl;
            return true;
        }
        return false;
	}

    //pick the current index into the subsequence.
    subarr.push_back(arr[ind]);
    s += arr[ind];

    if(printSubs(ind+1,subarr,s,sum,arr,n) == true)
        return true;

    s -= arr[ind];
    subarr.pop_back();

    //not picking the element into the subsequence.
    if(printSubs(ind+1,subarr,s,sum,arr,n) == true)
        return true;

    return false;
}
*/
// to count no of subs
int printSubs(int ind,vector<int> &subarr,int s, int sum,int arr[],int n)
{
	if (ind == n){
        if(s == sum){
            return 1;
        }
        return 0;
	}

    //pick the current index into the subsequence.
    subarr.push_back(arr[ind]);
    s += arr[ind];

    int left = printSubs(ind+1,subarr,s,sum,arr,n);

    s -= arr[ind];
    subarr.pop_back();

    //not picking the element into the subsequence.
    int right = printSubs(ind+1,subarr,s,sum,arr,n);

    return left+right;
}

int main()
{
	int arr[]={1, 2, 1};
	int n=3;
	vector<int> res;

	printSubs(0,res,0,2,arr,n);

	return 0;
}
