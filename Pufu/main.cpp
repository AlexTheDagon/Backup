#include <iostream>
#include <fstream>
using namespace std;
ifstream in("pufu.in");
ofstream out("pufu.out");
int sare,cas,cioc,t,n;
string a,s,cs,ci;
int main()
{
    s="sare";
    ci="ciocolata";
    cs="cascaval";
    in>>t;
    for(int l=1;l<=t;++l)
    {
        cas=0;
        sare=0;
        cioc=0;
        in>>n;
        for(int i=1;i<=n;++i)
        {
            in>>a;
            if(a==s)++sare;
            if(a==cs)++cas;
            if(a==ci)++cioc;
        }
        out<<cioc<<" "<<cas<<" "<<sare<<'\n';
    }
    return 0;
}
