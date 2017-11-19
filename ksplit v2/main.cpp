#include <iostream>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("ksplit.in");
ofstream out("ksplit.out");
long long a[100005],sp[100005],smax=-2000000000,s=-1,imin,mini,imax,n,smininainte=1<<30,smindupa=1<<30,sminim,smaxim,ist,ifin,csmax,cmini,cimax,cimin;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>a[i];
        sp[i]=a[i]+sp[i-1];
    }
    for(int i=1;i<=n;++i)
    {
        if(s<0)
        {
            s=a[i];
            cimin=i;
        }
        else s=s+a[i];
        if(s>csmax)
        {
            cmini=cimin;
            csmax=s;
            cimax=i;
        }
    }
    s=-1;
    for(int i=2;i<n;++i)
    {
        if(s<0)
        {
            s=a[i];
            imin=i;
        }
        else s=s+a[i];
        if(s>smax)
        {
            mini=imin;
            smax=s;
            imax=i;
        }
    }
    ///smax suma maxima
    ///mini ind de inaput al smax
    ///imax ind final a  lui smax
    s=0;
    for(int i=mini-1;i>0;--i)
    {
        s+=a[i];
        if(s<=smininainte)
        {
            smininainte=s;
            ist=i;
        }
    }
    s=0;
    for(int i=imax+1;i<=n;++i)
    {
        s+=a[i];
        if(s<smindupa)
        {
            smindupa=s;
            ifin=i;
        }
    }
    if(smindupa>smininainte)
    {
        smax=smax-smininainte;
        mini=ist;
        if(smindupa>=0)
        {
            imax=ifin;
            smax+=smindupa;
        }
    }
    else
    {
        smax=smax-smindupa;
        imax=ifin;
        if(smininainte>=0)
        {
            mini=ist;
            smax+=smininainte;
        }
    }
    ///k
    for(int i=cmini;i<=cimax;++i)
    {
        cout<<abs(sp[cimax]-sp[i]-sp[i]+sp[cmini])<<endl;
        if(abs(sp[cimax]-sp[i]-sp[i]+sp[cmini])>smax)
        {
            smax=abs(sp[cimax]-sp[i]-sp[i]+sp[cmini]);
            imax=cimax;
            mini=cmini;
        }
    }
    if(n!=2)out<<smax<<'\n'<<(imax-mini+1);
    else out<<max(a[1],a[2])-min(a[1],a[2])<<'\n'<<"2";
    return 0;
}
