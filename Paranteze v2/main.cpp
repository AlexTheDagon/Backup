#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
ifstream in("paranteze.in");
ofstream out("paranteze.out");
stack <char> s;
int n,l,lmax,a[1000005];
char c;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>c;
        if((s.empty() && c!=')' && c!=']' && c!='}') || c=='(' || c=='[' || c=='{')
        {
            s.push(c);
            l=0;
        }
        else
        {
            if(!s.empty())
            {
                if((s.top()=='(' && c==')') || (s.top()=='[' && c==']') || (s.top()=='{' && c=='}'))
                {
                    l=l+2;
                    s.pop();
                }
                else
                {
                    l=0;
                    while(!s.empty())s.pop();

                }
            }
            else l=0;
        }
        a[i]=l;
        cout<<a[i]<<" ";
    }
    for(int i=1;i<=n;++i)
    {
        if(a[i]!=0 && a[i+1]==0)a[i]=a[i]+a[i-a[i]];
        lmax=max(lmax,a[i]);
    }
    out<<lmax;
    return 0;
}
///pt pozitia x o sa in care a[x]!=0 si a[x+1]==06
