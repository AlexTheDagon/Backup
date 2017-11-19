#include <iostream>

using namespace std;
int a[100001][3],n,m,k,minn=1000000010,o1,b[100001];
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i)
    {
        cin>>a[i][1];
        cin>>a[i][2];
        cin>>a[i][3];
    }
    for(int i=1;i<=k;++i)
    {
        cin>>o1;
        b[o1]=1;
    }
    for(int i=1;i<=m;++i)if(b[a[i][1]]+b[a[i][2]]==1)minn=min(minn,a[i][3]);
    if(k==0 || minn==1000000010)cout<<"-1";
    else cout<<minn;
    return 0;
}
