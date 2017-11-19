#include <iostream>

using namespace std;
long long f1,f2,f3,n,k;
int main()
{
    cin>>n>>k;
    f1=1;
    f2=1;
    for(int i=1;i<=n;++i)
    {
        f3=f1+f2;
        f1=f2;
        f2=f3;
    }
    if(k>f3)cout<<"-1";
    else
    {
        f2=f1;
        f1=f3-f2;
        for(int i=1;i<=n;++i)
        {
            if(k<=f2)
            {
                cout<<"0";
            }
            else
            {
                cout<<"1";
                k-=f2;
            }
            f3=f2;
            f2=f1;
            f1=f3-f2;
        }
    }
    return 0;
}
