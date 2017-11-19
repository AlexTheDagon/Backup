#include <iostream>
#include <algorithm>
using namespace std;
float med[100],maxx,s;
int n,p,k=1;
int main()
{
    cin>>n;
    ///a)
    for(int i=1;i<=n;++i)cin>>med[i];
    for(int i=1;i<=n;++i)if(med[i]>maxx)maxx=med[i];
    for(int i=1;i<=n;++i)if(med[i]==maxx)cout<<i<<" ";
    cout<<endl;
    ///b)
    cin>>p;
    for(int i=1;i<=n;++i)if(med[p]<med[i])++k;
    cout<<k<<endl;
    ///c)
    k=1;
    for(int i=1;i<=n;++i)if(7<med[i])++k;
    cout<<k<<endl;
    for(int i=1;i<=n;++i)if(7<med[i])cout<<med[i]<<" ";
    cout<<endl;
    ///d)
    k=1;
    for(int i=1;i<=n;++i)s+=med[i];
    s=s/n;
    for(int i=1;i<=n;++i)if(med[i]<s)k++;
    cout<<k;



    return 0;
}
