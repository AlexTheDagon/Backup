#include <iostream>

using namespace std;
int n,k,a,b,mex=1000000,x;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=k;++i)
    {
        cin>>a>>b;
        mex=min(mex,b-a+1);
    }
    cout<<mex<<'\n';
    for(int i=1;i<=n;++i)
    {
        cout<<x<<" ";
        ++x;
        if(x==mex)x=0;
    }
    return 0;
}
