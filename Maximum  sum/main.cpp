#include <iostream>

using namespace std;
int a[101][101],n,smax=-1000000,sum;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)a[i][j]+=a[i][j-1];
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
        {
            sum=0;
            for(int k=1;k<=n;k++)
            {
                sum+=a[k][j]-a[k][i-1];
                smax=max(smax,sum);
                if(sum<0)sum=0;
            }
        }
    cout<<smax;
    return 0;
}
