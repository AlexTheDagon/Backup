#include <iostream>

using namespace std;
long long l,r,k,x,sem;
int main()
{
    cin>>l>>r>>k;
    x=1;
    while(x<=r/k)
    {
        if(l<=x)
        {
            cout<<x<<" ";
            sem=1;
        }
        x=x*k;
    }
    if(sem==0 && x==1)x=-1;
    cout<<x;
    return 0;
}
