#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("avarcolaci.in");
ofstream out("avarcolaci.out");
int t,v,apv,vcur,n,a[100005],sem;
int main()
{
    in>>t;
    for(int l=1;l<=t;++l)
    {
        in>>n;
        sem=0;
        for(int i=1;i<=2*n;++i)in>>a[i];
        sort(a+1,a+2*n+1);
        for(int i=1;i<=n && sem==0;++i)
        {
            if(a[i]==a[i+n])sem=1;
            v=a[i];
        }
        if(sem==1)out<<v<<'\n';
        else out<<"Mozart"<<'\n';
    }
    return 0;
}
