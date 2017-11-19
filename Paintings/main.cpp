#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,k,pn;
char sol[10][300][300];
int main()
{
    cin>>n>>k;
    pn=n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)cin>>sol[1][i][j];
    for(int kk=2;kk<=k;++kk)
    {
        for(int i=1;i<=pn;++i)
        {
            for(int j=1;j<=pn;++j)
            {
                for(int ii=n*(i-1)+1;ii<=i*n;++ii)
                {
                    for(int jj=n*(j-1)+1;jj<=j*n;++jj)
                    {
                        if(sol[kk-1][i][j]=='*')sol[kk][ii][jj]='*';
                        else sol[kk][ii][jj]=sol[1][ii-n*(i-1)][jj-n*(j-1)];
                    }
                }
            }
        }
        pn*=n;
    }
    for(int i=1;i<=pn;++i)
    {
        for(int j=1;j<=pn;++j)
        {
            cout<<sol[k][i][j];
        }
        cout<<'\n';
    }
    return 0;
}
