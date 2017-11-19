#include <iostream>
#include <fstream>
using namespace std;
ifstream in("avarcolaci.in");
ofstream out("avarcolaci.out");
int t,v,apv,vcur,n,sol[15],nr[15];
int main()
{
    in>>t;
    for(int l=1;l<=t;++l)
    {
        in>>n;
        apv=0;
        v=-1;
        for(int i=1;i<=2*n;++i)
        {
            in>>vcur;
            if(apv==0)
            {
                v=vcur;
                apv=1;
            }
            else
            {
                if(vcur!=v)
                {
                    apv--;
                }
                else ++apv;
            }
        }
        if(apv>0)sol[l]=v;
        else sol[l]=-1;
    }
    in.close();
    ifstream in("avarcolaci.in");
    in>>t;
    for(int l=1;l<=t;++l)
    {
        in>>n;
        for(int i=1;i<=2*n;++i)
        {
            in>>vcur;
            if(sol[l]==vcur)++nr[l];
        }
        if(nr[l]>n)out<<sol[l]<<'\n';
        else out<<"Mozart"<<'\n';
    }
    return 0;
}
