#include <iostream>
#include <fstream>
using namespace std;
ifstream in("palind2.in");
ofstream out("palind2.out");
int n,cr[2][7005],de[2][7005],s[2][7005],minn1,minn2,fr1,fr2,t,x;
int main()
{
    in>>t;
    while(t)
    {
        --t;
        in>>n;
        minn1=10000000;
        minn2=10000000;
        for(int i=1;i<=n;++i)
        {
            in>>x;
            cr[i%2][x+1]++;
            de[i%2][x-1]++;
        }
        for(int i=1;i<=7000;++i)
            for(int j=0;j<2;++j)cr[j][i]+=cr[j][i-1];
        for(int i=7000;i>=0;--i)
            for(int j=0;j<2;++j)de[j][i]+=de[j][i+1];
        for(int i=1;i<=7000;++i)
            for(int j=0;j<2;++j)cr[j][i]+=cr[j][i-1];
        for(int i=7000;i>=0;--i)
            for(int j=0;j<2;++j)de[j][i]+=de[j][i+1];
        for(int i=1;i<=7000;++i)
            for(int j=0;j<2;++j)s[j][i]=de[j][i]+cr[j][i];
        for(int i=1;i<=7000;++i)
        {
            if(s[0][i]<minn1)
            {
                fr1=0;
                minn1=s[0][i];
            }
            if(s[0][i]==minn1)++fr1;
        }
        for(int i=1;i<=7000;++i)
        {
            if(s[1][i]<minn2)
            {
                fr2=0;
                minn2=s[1][i];
            }
            if(s[1][i]==minn2)++fr2;
        }
        if(n>1)out<<minn1+minn2<<" "<<fr1*fr2<<'\n';
        else out<<"0 1"<<'\n';
        for(int i=0;i<=7002;++i)
            for(int j=0;j<2;++j)de[j][i]=cr[j][i]=s[j][i]=0;
    }
    return 0;
}
