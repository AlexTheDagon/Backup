#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#define pb push_back
using namespace std;
ifstream in("minerale.in");
ofstream out("minerale.out");
string s1,s2;
int n,r,fr[150],maxx;
map<string,vector<string> >m;
vector <string> v,formula;
void gen(string f)
{

}
int rec(string f)
{
    int sol=0;
    if(f.size()==1)
    {
        if(f[0]=='S')return 2;
        if(fr[f[0]])return 1;
        return 0;
    }
    string aux;
    aux+=f[0];
    aux+=f[1];
    f.erase(f.begin(),f.begin()+1);
    if(m.find(aux)!=m.end())
    {
        vector<string> vs=m[aux];
        for(auto i:vs)
        {
            sol=max(sol,rec(aux+f));
        }
    }
    else return 0;
}
int main()
{
    in>>r>>n;
    for(int i=1;i<=r;++i)
    {
        in>>s1>>s2;
        if(isupper(s1))fr[s1[0]]=1;
        if(m.find(s2)!=m.end())m[s2].pb(s1);
        else
        {
            v.clear();
            v.pb(s1);
            m[s2]=v;
        }
    }
    for(int i=1;i<=n;++i)
    {
        in>>formula;

        out<<rec(formula)<<'\n';
    }
    return 0;
}
