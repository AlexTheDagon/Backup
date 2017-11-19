#include <iostream>
#include <fstream>
using namespace std;
ifstream in("vase.in");
ofstream out("vase.out");
float n,d[100000],s[100000],x,vas;
long long svas;
float dif;
char v;
long long ss,sd;
int main()
{in>>n;
for(int i=0;i<n;i++)
{
    in>>x>>v;
    if(v=='D')
    {
        d[i]=x;
        sd=sd+x;
    }
    else
    {
        ss=ss+x;
        s[i]=x;
    }
}
in>>vas;
dif=(ss-sd)/2;
out<<ss-dif<<'\n';
if(d[vas-1]!=0)
{
    for(int i=0;i<vas-1;i++)svas=svas+d[i];
    if(svas-dif<0)
    {
        if(svas+d[vas-1]-dif<0)
        {
            out<<(float)(dif-svas)<<" S"<<'\n';
            out<<(float)(dif-svas-d[vas-1])<<" S"<<'\n';
        }
        else
        {
            out<<(float)(dif-svas)<<" S"<<'\n';
            out<<(float)(svas+d[vas-1]-dif)<<" D"<<'\n';
        }
    }
    else
    {
        out<<(float)(svas+d[vas-1]-dif)<<" D"<<'\n';
        out<<(float)(svas-dif)<<" D"<<'\n';
    }
}
else
{
    for(int i=0;i<vas-1;i++)svas=svas+s[i];
    if(svas-dif<0)
    {
        if(svas+s[vas-1]-dif<0)
        {
            out<<(float)(dif-svas)<<" D"<<'\n';
            out<<(float)(dif-svas-s[vas-1])<<" D"<<'\n';
        }
        else
        {
            out<<(float)(svas+s[vas-1]-dif)<<" S"<<'\n';
            out<<(float)(dif-svas)<<" D"<<'\n';
        }
    }
    else
    {
        out<<(float)(svas+s[vas-1]-dif)<<" S"<<'\n';
        out<<(float)(svas-dif)<<" S"<<'\n';
    }
}



    return 0;
}
