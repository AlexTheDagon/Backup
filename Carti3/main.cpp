#include <iostream>
#include <fstream>
#include <deque>
#define pb push_back
#define pf push_front
using namespace std;
ifstream in("carti3.in");
ofstream out("carti3.out");
int n,c,x,sem;
deque <int> d;
int main()
{
    in>>n>>c;
    for(int i=1;i<=c;++i)
    {
        in>>x;
        d.pb(x);
    }
    for(int i=1;i<=n;++i)
    {
        in>>x;
        if(x==-1)sem=1-sem;
        else
        {
            if(sem==0)d.pf(x);
            else d.pb(x);
        }
    }
    if(sem==1)
    {
        while(!d.empty())
        {
            out<<d.back()<<'\n';
            d.pop_back();
        }
    }
    else
    {
        while(!d.empty())
        {
            out<<d.front()<<'\n';
            d.pop_front();
        }
    }
    return 0;
}
