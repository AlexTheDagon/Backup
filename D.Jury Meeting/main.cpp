#include<iostream>
#include<algorithm>
#include<queue>
#define pp pair<pair<int,int>,pair<int,int> >
#define d first.first
#define f first.second
#define t second.first
#define c second.second
using namespace std;
long long sol[1000005];
long long inf=9999999999999999;
int cmp(pp x,pp y)
{
	return x.d<y.d;
}
pp a[100005];
int n,m,k,ind=1;
int viz[100005];
long long sum,num,minn=inf;
int main()
{
	cin>>n>>m>>k;
    for(int i=1;i<=m;i++)cin>>a[i].d>>a[i].f>>a[i].t>>a[i].c;
    sort(a+1,a+m+1,cmp);
    for(int i=0;i<=100000;++i)viz[i]=0;
    for(int i=1;i<=1000000;++i)
    {
        for(ind;ind<=m && a[ind].d<=i;++ind)
        {
            if(a[ind].f==0)continue;
            if(viz[a[ind].f]!=0 && viz[a[ind].f]<a[ind].c)continue;
            if(viz[a[ind].f]==0)++num;
            sum=sum-viz[a[ind].f]+a[ind].c;
            viz[a[ind].f]=a[ind].c;
        }
        if (num!=n)sol[i]=inf;
        else sol[i]=sum;
    }
    num=0;
    sum=0;
    ind=m;
    for(int i=0;i<=100000;++i)viz[i]=0;
    for (int i=1000000;i-k-1>=1;--i)
    {
        for (ind;ind>=1 && a[ind].d>=i;--ind)
        {
            if(a[ind].t==0)continue;
            if(viz[a[ind].t]!=0 && viz[a[ind].t]<a[ind].c)continue;
            if(viz[a[ind].t]==0)++num;
            sum=sum-viz[a[ind].t]+a[ind].c;
            viz[a[ind].t]=a[ind].c;
        }
        if(num==n)minn=min(minn,sum+sol[i-k-1]);
    }
    if(minn==inf)minn=-1;
    cout<<minn<<endl;
	return 0;
}
///editorial+sursa
