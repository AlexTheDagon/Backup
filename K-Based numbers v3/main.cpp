#include <iostream>

using namespace std;
unsigned long long l=10000000000000000000;
int a[100][100],n,k;
int main()
{
    cout<<l;
    cin>>n>>k;
    for(int i=1;i<k;++i)
    {
        a[1][i]=1;
    }
    for(int i=2;i<=n;++i)
    {
        int s=0;
        for(int j=0;j<k;++j)
        {
            s+=a[i-1][j];
        }
        a[i][0]=s-a[i-1][0];
        for(int j=1;j<k;++j)
        {
            a[i][j]=s;
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<k;++j)cout<<a[i][j]<<" ";
        cout<<'\n';
    }
    return 0;
}
