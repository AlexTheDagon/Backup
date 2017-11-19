#include <iostream>

using namespace std;
long long n,p;
int main()
{
    cin>>n;
    p=3;
    --n;
    if(n%2)p+=3;
    p+=n/2*9;
    cout<<p;
    return 0;
}
