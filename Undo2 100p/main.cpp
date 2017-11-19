#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define pb push_back
#define pp pop_back
using namespace std;
ifstream in("undo2.in");
ofstream out("undo2.out");
int n,l,op,x;
vector<int> s,v[200005];
vector<int>::iterator up;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>op>>x;
        if(op==1)
        {
            while(l<s.size())
            {
                v[s.back()].erase(v[s.back()].end()-1);
                s.pop_back();
            }
            ++l;
            s.pb(x);
            v[x].pb(l);
        }
        if(op==2)l-=x;
        if(op==3)l+=x;
        if(op==4)
        {
            up=upper_bound(v[x].begin(),v[x].end(),l);
            out<<up-v[x].begin()<<'\n';
        }
    }
    return 0;
}
///Se voloseste vector de vector pentru pozitiile
