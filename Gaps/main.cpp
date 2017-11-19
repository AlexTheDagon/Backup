#include <iostream>

using namespace std;
int n,a[101],sem,c,b,x;
int main()
{
    cin>>n;
    a[0]=1;
    for(int i=1;i<=n;++i)
    {
        cin>>x;
        a[x]=1;
    }
    if(n!=100)
    {
        for(int i=0;i<=100;++i)
        {
            if(a[i]==1 && a[i+1]==0)c=i+1;
            if(a[i]==0 && a[i+1]==1)
            {
                b=i;
                cout<<c<<"-"<<b<<'\n';
            }
        }
        if(a[100]==0)cout<<c<<"-100"<<'\n';
    }
    else cout<<"All clear!";
    return 0;
}
