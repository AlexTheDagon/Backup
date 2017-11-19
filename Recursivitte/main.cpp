#include <iostream>

using namespace std;
long long f(long long n)
{
    if(n<2)return 1;
    return f(n-1)*n;
}
int main()
{
    cout<<f(21);
    return 0;
}
