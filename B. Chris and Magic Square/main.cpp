#include <iostream>

using namespace std;
long long n,s,sem,a[501][501],ii,jj,sp;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cin>>a[i][j];
            if(a[i][j]==0)ii=i,jj=j;
        }
    }
    if(ii!=1)for(int i=1;i<=n;++i)s+=a[1][i];
    else for(int i=1;i<=n;++i)s+=a[2][i];
    sp=s;
    for(int i=1;i<=n;++i)sp-=a[ii][i];
    a[ii][jj]=sp;
    if(a[ii][jj]<1)sem=1;
    for(int i=1;i<=n;++i)
    {
        sp=0;
        for(int j=1;j<=n;++j)
        {
            sp+=a[i][j];
        }
        if(sp!=s)sem=1;
        sp=0;
        for(int j=1;j<=n;++j)
        {
            sp+=a[j][i];
        }
        if(sp!=s)sem=1;
    }
    sp=0;
    for(int i=1;i<=n;++i)
    {
        sp+=a[i][i];
    }
    if(sp!=s)sem=1;
    sp=0;
    for(int i=1;i<=n;++i)
    {
        sp+=a[i][n+1-i];
    }
    if(sp!=s)sem=1;
    if(n!=1){if(sem==1)cout<<"-1";
    else cout<<a[ii][jj];}
    else cout<<"1";
    return 0;
}
