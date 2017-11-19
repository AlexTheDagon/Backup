#include <iostream>
#include <fstream>
using namespace std;
ifstream in("blaturi.in");
ofstream out("blaturi.out");
long long n,s1,p1,p2,s2,t[100005],sp1[100005],sp2[100005],cmin[100005],minn=1000000000000;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)in>>t[i];
    in>>p1>>s1>>p2>>s2;
    for(int i=1;i<=n;++i)sp1[i]=sp1[i-1]+t[i];
    for(int i=n;i>0;--i)sp2[i]=sp2[i+1]+t[i];
    for(int i=1;i<=n;++i)
    {
        cmin[i]=sp1[i]*p1+sp2[i+1]*p2;
        if(i<n-i)cmin[i]+=(n-i-i-1)*s2;
        else if(i>n-i)cmin[i]+=(2*i-n-1)*s1;
    }
    for(int i=1;i<=n;++i)minn=min(minn,cmin[i]);
    out<<minn;
    return 0;
}
