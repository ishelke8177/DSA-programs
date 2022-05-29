// C++ code to print all possible
// subsequences for given array using
// recursion
#include <bits/stdc++.h>
using namespace std;

// Recursive function to print all
// possible subsequences for given array
void printSubs(int arr[], int index,
					vector<int> subarr,int n)
{
	// Print the subsequence when reach
	// the leaf of recursion tree
	if (index == n){
		for (auto it:subarr){
            cout << it << " ";
		}
        if(subarr.size()==0)
            cout<<"{}"<<endl;
        return;
	}

    //pick the current index into the subsequence.
    subarr.push_back(arr[index]);

    printSubs(arr, index + 1, subarr,n);

    subarr.pop_back();

    //not picking the element into the subsequence.
    printSubs(arr, index + 1, subarr,n);
}

int main()
{
	int arr[]={1, 2, 3};
	int n=3;
	vector<int> vec;

	printSubs(arr, 0, vec,n);

	return 0;
}
