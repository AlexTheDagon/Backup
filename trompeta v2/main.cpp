#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
ifstream in("trompeta.in");
ofstream out("trompeta.out");
string x;
stack <char> c;
char a[1000001];
int n,m,cm,y;
int main()
{
    in>>n>>m;
    in>>x;
    for(int i = 0; i < n; i++)
    {
        while(!c.empty() && (c.size()+n-i-1)>=m && c.top()<(x[i]))c.pop();
        c.push(x[i]);
    }
    for(int i=c.size();i>0;--i)
    {
        a[i]=c.top();
        c.pop();
    }
    out<<a+1;
    return 0;
}
