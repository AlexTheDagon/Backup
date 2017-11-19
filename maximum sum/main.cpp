#include <iostream>

using namespace std;
int a[101][101],smax,smin,n,maxx;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cin>>a[i][j];
            a[i][j]+=a[i][j-1];
        }
    }
    return 0;
}
