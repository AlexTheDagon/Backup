#include <iostream>
#include <fstream>
#include <map>
#define s second
#define f first
#define mp make_pair
using namespace std;
ifstream in("sea2.in");
ofstream out("sea2.out");
map<int,int> m;
map<int,int>::iterator i1,i2;
int x,y,n,sem;
int main()
{
    in>>n;
    for(int N=1;N<=n;++N)
    {
        in>>x>>y;
        i1=m.upper_bound(x);
        if(i1!=m.end() && (*i1).s>y)out<<"-1"<<'\n';
        else
        {
            i1=i2=m.insert(mp(x,y)).f;
            sem=1;
            while(i1!=m.begin() && sem)
            {
                --i1;
                if((*i1).s>y)
                {
                    ++i1;
                    sem=0;
                }
            }
            m.erase(i1,i2);
            out<<m.size()<<'\n';
        }
    }
    return 0;
}
