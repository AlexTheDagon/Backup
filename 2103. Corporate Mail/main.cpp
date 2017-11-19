#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;
long long s,t,d,dmin=100,a[100000],x;
queue <long long> q;
int main()
{
    cin>>s>>t;
    for(int i=1;i<=sqrt(t);++i)
    {
        if(t%i==0)
        {
            a[++d]=i;
            if(t!=i*i)a[++d]=t/i;
        }
    }///divizori primi
    dmin=abs(s-t);
    q.push(s),q.push(t);
    for(int j=1;j<=14;++j)
    {
        for(int i=1;i<=d;++i)
        {
            if(dmin>(abs(s-j)+min(a[i]%j,j-a[i]%j)) && j<=a[i])
            {
                dmin=(abs(s-j)+min(a[i]%j,j-a[i]%j));
                while(!q.empty())q.pop();
                q.push(s);
                if(j!=s)q.push(j);
                if(a[i]%j<j-a[i]%j)x=a[i]-a[i]%j;
                else x=a[i]+j-a[i]%j;
                if(x!=j)q.push(x);
                if(a[i]!=x)q.push(a[i]);
                if(a[i]!=t)q.push(t);
            }
        }
    }
    if(s==t)q.pop();
    if(s==t)dmin=0;
    cout<<dmin<<'\n';
    cout<<q.size()<<'\n';
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}
///Avem 4 cazuri:
/// direct fie prin celule fie prin divizibilitate
/// prin intermediar din divizorii apropiati la care se merge direct
/// din intermediar in alt apropierea unui div prim;
