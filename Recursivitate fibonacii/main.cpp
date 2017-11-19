#include <iostream>
#include <fstream>
using namespace std;

int k;
int fib(int n)
{
    if(n==0)return 0;
    if(n==1)return 1;
    return fib(n-1)+fib(n-2);
}
int main()
{
    cin>>k;
    cout<<fib(k)<<" ";
    return 0;
}
