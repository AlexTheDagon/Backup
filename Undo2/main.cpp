#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#define pb push_back

using namespace std;
ifstream in("undo2.in");
ofstream out("undo2.out");
int op,x,act,n,poz[200005],sters,xaux,fr[200005];
stack <int> s;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>op>>x;
        if(op==1)
        {
            if(sters)
            {
                for(int j=1;j<=xaux;++j)
                {
                    s.pop();
                    --fr[poz[act+j]];
                    poz[act+j]=0;
                }
                sters=0;
            }
            ++act;
            poz[act]=x;
            ++fr[x];
            s.push(x);
        }
        if(op==2)
        {
            act-=x;
            sters=1;
            xaux=x;
        }
        if(op==3)
        {
            sters=0;
            xaux-=x;
            act+=x;
            for(int j=1;j<=xaux;++j)
            {
                s.pop();
                --fr[act+j];
                poz[act+j]=0;
            }
        }
        if(op==4)
        {
            int nr=0;
            for(int j=0;j<fr[x].size();++j)if(poz[fr[x][j]]==x && fr[x][j]<=act)++nr;
            out<<nr<<'\n';
        }
    }
    return 0;
}
