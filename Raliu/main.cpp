#include <iostream>
#include <fstream>
using namespace std;
ifstream in("raliu.in");
ofstream out("raliu.out");
int a[2000005],l[1000005],d[1000005],n,lng,st,ind,t,sem;
long long s,sum;
int main()
{
    in>>t;
    while(t)
    {
        --t;
        in>>n;
        sum=0;
        for(int i=1;i<=n;++i)in>>l[i];
        for(int i=1;i<=n;++i)in>>d[i];
        for(int i=1;i<=n;++i)sum+=l[i]-d[i];
        for(int i=1;i<=n;++i)a[i]=a[i+n]=l[i]-d[i];
        lng=0;
        s=0;
        sem=0;
        for(int i=1;i<=2*n;++i)
        {
            s+=a[i];
            ++lng;
            if(s<0)
            {
                lng=0;
                s=0;
            }
            if(lng==n)
            {
                sem=1;
                st=i-n+1;
            }
        }
        if(sem && sum>=0)out<<"DA"<<'\n'<<st<<'\n';
        else out<<"NU"<<'\n';
    }
    return 0;
}
