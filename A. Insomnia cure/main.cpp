#include <iostream>

using namespace std;
int a[100001],k,l,m,n,d,drag;
int main()
{
    cin>>k>>l>>m>>n>>d;
    for(int i=1;i<=d;++i)
    {
        if(i%k==0 || i%l==0 || i%m==0 || i%n==0)a[i]=1;
    }
    for(int i=1;i<=d;++i)if(a[i]==1)drag++;
    cout<<drag;
    return 0;
}
