#include <iostream>

using namespace std;
int n,a[100001],minn=1000000000,maxx=-1,x,ex,sem,c=-1,d=-1,sem2;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        maxx=max(maxx,a[i]);
        minn=min(minn,a[i]);
    }
    for(int i=1;i<=n;++i)
    {
        if(c==-1)c=a[i];
        else
        {
            if(c!=a[i] && d==-1)d=a[i];
            else if(a[i]!=d && a[i]!=c)sem2=1;
        }
    }
    if(sem2==1)
    {
        x=(maxx-minn)/2;
        ex=minn+x;
        for(int i=1;i<=n && sem==0;++i)
        {
            if((a[i]+x)!=ex && (a[i]-x)!=ex && (a[i]!=ex))sem=1;
        }
    }
    if(sem==1)cout<<"NO";
    else cout<<"YES";
    return 0;
}
