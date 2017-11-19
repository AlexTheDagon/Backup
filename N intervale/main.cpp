#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int n,v[1000000],a,b,s[1000000],maxx;
int main()
{
    in>>n;
    for(int i=0;i<n;++i)
    {
        in>>a>>b;
        ++v[a];
        --v[b+1];
    }
    for(int i=1;i<1000000;++i)s[i]=s[i-1]+v[i];
    for(int i=0;i<1000000;++i)if(s[i]>maxx)maxx=s[i];
    for(int i=0;i<1000000;++i)if(maxx==s[i])out<<i<<" ";


    return 0;
}
