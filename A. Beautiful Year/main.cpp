#include <iostream>

using namespace std;
int n,a,b,c,d;
int main()
{
    cin>>n;
    ++n;
    do
    {
        a=n%10;
        b=n/10%10;
        c=n/100%10;
        d=n/1000;
        ++n;
    }
    while(a==b || a==c || a==d || b==c || b==d || c==d);
    cout<<n-1;
    return 0;
}
