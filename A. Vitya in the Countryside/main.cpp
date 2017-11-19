#include <iostream>

using namespace std;
int n,a[100];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    if(n>1)
    {
        if(a[n-1]<a[n] && a[n]<15)cout<<"UP";
        else
        {
            if(a[n-1]<a[n] && a[n]==15)cout<<"DOWN";
            else
            {
                if(a[n-1]>a[n] && a[n]>0)cout<<"DOWN";
                else cout<<"UP";
            }
        }
    }
    else
    {
        if(a[n]==15)cout<<"DOWN";
        else
        {
            if(a[n]==0)cout<<"UP";
            else cout<<"-1";
        }
    }
    return 0;
}
