#include <iostream>

using namespace std;
long long n,a[501][501];
int main()
{
    cin>>n;
    for(int i=0;i<n;++i)a[i][i]=1;
    for(int i=1;i<n;i++)
        for(int j=i-1;j>=0;j--)a[i][j]=a[i-j-1][j+1]+a[i][j+1];
    cout<<a[n-1][0]-1;
    return 0;
}
