#include <iostream>
#include <fstream>
#define NM 2005
using namespace std;
ifstream in("gaz.in");
ofstream out("gaz.out");
long long gazr,cmin[NM],g[NM],d,l,p,c,costact,sp[NM],n;
int main()
{
    in>>l>>p>>d>>c>>n;
    for(int i=1;i<=n;++i)
    {
        in>>g[i];
        sp[i]=sp[i-1]+g[i];
        cmin[i]=(1<<30);
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=i;j>=1;--j)
        {
            costact=p+(sp[i]-sp[j-1])*d+cmin[j-1];
            gazr=sp[i]-sp[j-1];
            int ind=j;
            ///de verificat
            while(ind<=i)
            {
                gazr-=g[ind];
                if(gazr>l)costact+=(gazr-l)*c;
                ++ind;
            }
            if(costact<cmin[i])cmin[i]=costact;
        }
    }
    out<<cmin[n];
    return 0;
}
