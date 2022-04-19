#include <bits/stdc++.h>
using namespace std;

// to generate a particular fibonacci number iteratively
int genNthFiboNum(int n){
    // base case
    if(n==0) return 0;
    if(n==1) return 1;

    int a=0, b=1;

    int i=0;
    while(i < n-2){
        int next = a+b;
        a=b;
        b=next;
        i++;
    }

    return b;
}

// to generate a particular fibonacci number using DP
int fibDp(int n)
{
    // Declare an array to store
    // Fibonacci numbers.
    // 1 extra to handle
    // case, n = 0
    int f[n];
    int i;

    // 0th and 1st number of the
    // series are 0 and 1
    f[0] = 0;
    f[1] = 1;

    for(i = 2; i <= n-2; i++)
    {
       //Add the previous 2 numbers
       // in the series and store it
       f[i] = f[i - 1] + f[i - 2];
    }

    return f[n];
}

// to generate fib series iteratively
void genFiboSeriesIteratively(int n){
    int a=0, b=1;

    if(n==1)
        cout<<a<<" ";
    else{
        cout<<a<<" "<<b<<" ";
        int i=0;
        while(i < n-2){
            int next = a+b;
            a=b;
            b=next;
            i++;
            cout<<b<<" ";
        }
    }
}

// to generate fib series recursively
void fibo(int n){
    if(n==1)
        return 0;
    return fibo(n-1)+fibo(n);
}

// to check weather a number is fibonacci
bool checkFibo(int n){

    int flag=0;
    int a=0, b=1;
    if(n==1 || n==0)
        return true;
    else{

        while(1){
            int next = a+b;
            if(next==n){
                flag=1;
                break;
            }
            if(next>n)
                break;

            a=b;
            b=next;
        }
    }

    if(flag==1)
        return true;

    return false;
}

int main()
{
    int n;
    cin>>n;
    cout<<checkFibo(n)<<endl;
    // genFiboSeries(n);
    return 0;
}
