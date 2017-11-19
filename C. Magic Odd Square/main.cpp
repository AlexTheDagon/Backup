#include <iostream>

using namespace std;
int n,a[50][50],x,nr,sem;
int main()
{
    cin>>n;
    nr=1;
    x=n/2+1;
    for(int i=1;i<=n;++i)
    {
        for(int j=x;j<=n+1-x;++j)
        {
            a[i][j]=nr;
            nr=nr+2;
        }
        if(x==1)sem=1;
        if(sem==0)x=x-1;
        else x=x+1;
    }
    nr=2;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(a[i][j]==0)
            {
                a[i][j]=nr;
                nr=nr+2;
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}
