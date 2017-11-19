#include <iostream>
#include <fstream>
using namespace std;
ifstream in("secvente2.in");
ofstream out("secvente2.out");
int viz[1000003],p[1000005],a[200005],n,maxx,st,fn;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>a[i];
        viz[a[i]]=1;
    }
    for(int i=1;i<=n;++i)
    {
        st=a[i];
        fn=a[i];
        if(p[a[i]-1])st=p[a[i]-1];
        if(p[a[i]+1])fn=p[a[i]+1];
        p[st]=fn;
        p[fn]=st;
        maxx=max(maxx,fn-st+1);
        out<<maxx<<'\n';
    }
    return 0;
}
