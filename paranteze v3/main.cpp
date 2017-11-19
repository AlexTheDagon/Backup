#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
ifstream in("paranteze.in");
ofstream out("paranteze.out");
int n,a[1000000],l,lmax;
char c;
stack <pair<char,int> > s;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>c;
        if(c=='(' || c=='[' || c=='{')s.push({c,i});
        else
        {
            if(!s.empty())
            {
                if((s.top().first=='(' && c==')') || (s.top().first=='[' && c==']') || (s.top().first=='{' && c=='}'))
                {
                    a[i]=1;
                    a[s.top().second]=1;
                    s.pop();
                }
                else while(!s.empty())s.pop();
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(a[i]==1)++l;
        else
        {
            lmax=max(l,lmax);
            l=0;
        }
    }
    out<<lmax;
    return 0;
}
