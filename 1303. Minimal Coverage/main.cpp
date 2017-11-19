#include <iostream>
#include <algorithm>
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;
pair<int,int> fr;
int fin,finn,m,ind;
vector <pair<int,int> > a;
vector <pair<pair<int,int>,int> > v;
vector <int> sol;
int main()
{
    cin>>m;
    cin>>fr.x>>fr.y;
    while(fr.x!=0 || fr.y!=0)
    {
        a.pb(mp(fr.x,fr.y));
        v.pb(mp(mp(fr.y,fr.x),ind));
        ++ind;
        cin>>fr.x>>fr.y;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();++i)swap(v[i].x.x,v[i].x.y);
    fin=0;
    ind=0;
    for(auto i:v)
    {
        if(fin<m)
        {
            if(i.x.x<=fin)
            {
                if(i.x.y>finn)
                {
                    finn=i.x.y;
                    ind=i.y;
                }
            }
            else
            {
                sol.pb(ind);
                fin=finn;
                if(i.x.y>finn && i.x.x<=fin && fin<m)
                {
                    finn=i.x.y;
                    ind=i.y;
                }
            }
        }
    }
    if(finn>fin && fin<m)
    {
        sol.pb(ind);
        fin=finn;
    }
    if(fin<m)cout<<"No solution";
    else
    {
        sort(sol.begin(),sol.end());
        cout<<sol.size()<<'\n';
        for(auto i:sol)cout<<a[i].x<<" "<<a[i].y<<'\n';
    }
    return 0;
}
