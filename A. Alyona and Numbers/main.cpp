#include <iostream>

using namespace std;
long long a[5],b[5],n,m,s;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)a[i%5]++;
    for(int i=1;i<=m;++i)b[i%5]++;
    cout<<a[0]*b[0]+a[1]*b[4]+a[2]*b[3]+a[3]*b[2]+a[4]*b[1];

    return 0;
}
