#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
ifstream in("cifre4.in");
ofstream out("cifre4.out");
long long n[6],r[6],p[6],t,nr;
bool viz[5000555];
int main()
{
    in>>t;
    for(int i=1;i<=t;++i)
    {
        in>>r[i]>>p[i];
        n[i]=-1;
        queue <long long> q;
        q.push(0);
        while(!q.empty() && n[i]==-1)
        {
            if(q.front()!=0)
            {
                if(q.front()%p[i]==r[i] && n[i]==-1)n[i]=q.front();
            }
            nr=q.front()*10;
            if(nr<=100000000000)
            {
                q.push(nr+2);
                q.push(nr+3);
                q.push(nr+5);
                q.push(nr+7);
            }
            q.pop();
        }
    }
    for(int i=1;i<=t;++i)
    {
        out<<n[i]<<'\n';
    }
    return 0;
}
