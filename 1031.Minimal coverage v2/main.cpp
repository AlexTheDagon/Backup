#include <iostream>
#include <vector>
#include <algorithm>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
vector <pair<int,int> > v,sol;
pair<int,int> fr;
int m,a,b,finn,fin;
int main()
{
    cin>>m;
    cin>>a>>b;
    while(a!=0 || b!=0)
    {
        v.pb(mp(a,b));
        cin>>a>>b;
    }
    sort(v.begin(),v.end());
    v.pb(mp(m+1,m+1));
    fr=mp(-1,-1);
    for(int i=0;i<v.size() && fin<m;++i)
    {
        if(v[i].y>fin && v[i].y>fr.y && v[i].x<=fin)fr=v[i];
        if(v[i].x>fin && fr.y!=-1)
        {
            fin=fr.y;
            sol.pb(fr);
            fr=mp(-1,-1);
            --i;
        }
    }


    if(fin<m)cout<<"No solution";
    else
    {
        cout<<sol.size()<<'\n';
        for(auto i:sol)
        {
            cout<<i.x<<" "<<i.y<<'\n';
        }
    }
    return 0;
}
