#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
ifstream in("int.in");
ofstream out("int.out");
int n,ts,tf,maxx;
pair <int,int> t[500001];
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>t[i].second>>t[i].first;
    }
    sort(t+1,t+n+1);
    tf=t[1].first;
    ts=t[1].second;
    maxx=1;
    for(int i=2;i<=n;++i)
    {
        if(t[i].second>=tf)
        {
            ts=t[i].second;
            tf=t[i].first;
            maxx++;
        }
    }
    out<<maxx;
    return 0;
}
