#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
ifstream in("par.in");
ofstream out("par.out");
stack <char> c;
char a;
int n,pd,pi;
int main()
{
    in>>n;

    for(int i=1;i<=n;++i)
    {
        in>>a;
        if(!c.empty())
        {
            if(a==')' && c.top()=='(')c.pop();
            else c.push(a);
        }
        else c.push(a);
    }
    while(!c.empty())
    {
        if(c.top()=='(')++pd;
        else ++pi;
        c.pop();
    }
    if((pd+pi)%2==1)out<<"-1";
    else
    {
        if(pi==0 || pd==0)out<<(pd+pi)/2;
        else out<<pi/2+pi%2+pd%2+pd/2;
    }
    return 0;
}
