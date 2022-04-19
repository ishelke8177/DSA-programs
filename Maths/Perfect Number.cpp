/*
perfect number, a positive integer that is
equal to the sum of its proper divisors.
*/
#include <bits/stdc++.h>
using namespace std;

void isPerfect(int n){
    int original=n;
    int sum=0;

    int i=1;
    while(i <= n/2){
        if(n%i==0){
            sum += i;
        }
        i++;
    }

    if(sum == original)
        cout << "Yes";
    else
        cout << "No";
}

int main() {
    f(6);
    return 0;
}
