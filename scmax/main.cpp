#include <iostream>

using namespace std;
#include <fstream>
ifstream in("scmax.in");
ofstream out("scmax.out");
int n,a[100001],scm[100001],maxx,b[100001],k;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        maxx=0;
        in>>a[i];
        for(int j=1;j<i;++j)
        {
            if(maxx<scm[j] && a[j]<a[i])maxx=scm[j];
        }
        scm[i]=maxx+1;
    }
    maxx=0;
    for(int i=1;i<=n;++i)maxx=max(maxx,scm[i]);
    out<<maxx<<'\n';
    for(int i=n;i>=1;--i)
    {
        if(scm[i]==maxx)
        {
            b[++k]=a[i];
            maxx--;
        }
    }
    for(int i=k;i>0;--i)out<<b[i]<<" ";
    return 0;
}
