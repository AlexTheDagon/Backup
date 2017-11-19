#include <iostream>
#include <fstream>
#include<algorithm>
using namespace std;
ifstream in("rucsac.in");
ofstream out("rucsac.out");
int n,g,o[10001],sol;
pair <int,int> a[5001];
int main()
{
    in>>n>>g;
    for(int i=1;i<=n;++i)
    {
        in>>a[i].first>>a[i].second;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=g-a[i].first;j>=0;--j)
        {
            if(o[j+a[i].first]<o[j]+a[i].second)o[j+a[i].first]=o[j]+a[i].second;
            sol=max(sol,o[j+a[i].first]);
        }
    }
    out<<sol;
    return 0;
}
