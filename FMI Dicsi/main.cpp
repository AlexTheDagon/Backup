#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;
ifstream in("dicsi.in");
ofstream out("dicsi.out");
int cul[100005],n,last;
vector <int> v;
int main()
{
    in>>n;
    for(int i=n/2+1;i<=n;++i)cul[i]=1;
    for(int i=n/2;i>0;--i)
    {
        for(int j=i+i;j<=n;j+=i)v.pb(cul[j]);
        sort(v.begin(),v.end());
        last=1;
        for(int j=0;j<v.size() && v[j]<=last;++j)if(v[j]==last)++last;
        cul[i]=last;
        v.clear();
    }
    out<<cul[1]<<'\n';
    for(int i=1;i<=n;++i)out<<cul[i]<<" ";
    return 0;
}
