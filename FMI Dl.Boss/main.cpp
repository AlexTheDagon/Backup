#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#define mp make_pair
#define x first
#define y second

using namespace std;
ifstream in("dlboss.in");
ofstream out("dlboss.out");
long long n,t;
pair<int,int> a[100005],aux[100005];
vector<pair<pair<int,int>,int> > v,nou;
int main()
{
    in>>n>>t;
    for(int i=1;i<=n;++i)
    {
        in>>a[i].x>>a[i].y;
        aux[i]=a[i];
        swap(aux[i].x,aux[i].y);
    }
    sort(aux+1,aux+n+1);
    for(int i=1;i<=n;++i)v.pb(mp(mp(a[i].y,a[i].x),i));
    sort(v.begin(),v.end());
    return 0;
}
