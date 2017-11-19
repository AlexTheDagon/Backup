#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
ifstream fin("editor.in");
ofstream fout("editor.out");
stack <char > Q;
stack <char > S;
char p;
int main()
{
    int t;
    fin>>t;
    for(int i=1;i<=t;i++)
    {
        while(fin>>p && p!='E')
        {
            if(p=='*')
            {
                if(!Q.empty())Q.pop();
            }
            else Q.push(p);
        }///bine
        while(!Q.empty())
        {
            if(!S.empty() && !Q.empty())
            {
                if((S.top()==')' && Q.top()=='(') or(S.top()==']' && Q.top()=='['))
                {
                    S.pop();
                    Q.pop();
                }
                else
                {
                    S.push(Q.top());
                    Q.pop();
                }
            }
            else
            {
                S.push(Q.top());
                Q.pop();
            }
            if(!Q.empty())
            {
                if((S.top()==')' && Q.top()=='(') or(S.top()==']' && Q.top()=='['))
                {
                    S.pop();
                    Q.pop();
                }
            }
        }
        if(S.empty())fout<<":)"<<'\n';
        else fout<<":("<<'\n';
        while(!Q.empty())Q.pop();
        while(!S.empty())S.pop();
    }
    return 0;
}
