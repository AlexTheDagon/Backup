#include <iostream>
#include <fstream>
using namespace std;
ifstream in("raliu.in");
ofstream out("raliu.out");
int a[2000005],l[1000005],d[1000005],n,lng,st,ind,t,sem,val[2000005];
long long s,sum;
int main()
{
    in>>t;
    while(t)
    {
        --t;
        in>>n;
        for(int i=1;i<=n;++i)in>>l[i];
        for(int i=1;i<=n;++i)in>>d[i];
        for(int i=1;i<=n;++i)a[i]=a[i+n]=l[i]-d[i];
        for(int i=1;i<=2*n;++i)out<<a[i]<<" ";
        out<<endl;
        for(int i=1;i<=2*n;++i)
        {
            a[i]+=a[i-1];
            if(a[i]>=0)val[i]=1;
            else val[i]=0;
            val[i]+=val[i-1];
        }
        for(int i=1;i<=2*n;++i)out<<a[i]<<" ";
        out<<endl;
        for(int i=1;i<=2*n;++i)out<<val[i]<<" ";
        out<<endl;
        sem=0;
        for(int i=0;i<n && sem==0;++i)
        {
            cout<<i<<" "<<a[i+n]-a[i]<<" "<<(val[i+n]-val[i])<<endl;
            if(a[i+n]-a[i]>=0 && (val[i+n]-val[i])==n)
            {
                st=i+1;
                sem=1;
            }
        }
        cout<<endl;
        if(sem)out<<"DA"<<'\n'<<st<<'\n';
        else out<<"NU"<<'\n';
    }
    return 0;
}

