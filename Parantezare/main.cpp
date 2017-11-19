#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
ifstream in("parantezare.in");
ofstream out("parantezare.out");
stack <int> c;
string s;
int a[100001];
int m,x;
int main()
{
    in>>s;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='(')c.push(i);
        else
        {
            if(s[i]==')')
            {
                a[c.top()]=i;
                c.pop();
            }
        }
    }
    in>>m;
    for(int i=1;i<=m;++i)
    {
        in>>x;
        out<<a[x]<<" ";
    }
    return 0;
}
