#include <iostream>

using namespace std;
int n,k,nr[20][12],s;
int main()
{
    cin>>n>>k;
    for(int i=0;i<=k-1;++i)nr[i][1]=1;
    for(int i=0;i<=k-1;++i)nr[i][2]=k-1;
    for(int j=3;j<=n;++j)
    {
        for(int i=1;i<=k-1;++i)nr[0][j]+=nr[i][j-1];
        for(int l=1;l<=k-1;++l)
        {
            for(int i=0;i<=k-1;++i)nr[l][j]+=nr[i][j-1];
        }
    }
    for(int i=0;i<=k-1;++i)s+=nr[i][n];
    cout<<s;
    return 0;
}
