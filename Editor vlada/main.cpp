#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
ifstream fin("editor.in");
ofstream fout("editor.out");
int ok;
stack <int> stk,stk2;
int main()
{
    int t,i;
    char act;
    fin>>t;
    for(i=1;i<=t;i++)
    {
        ok=1;
        while(act!='E')
        {
            fin>>act;
            if(act!='*')stk.push(act);
            else stk.pop();///Adaugat
        }
        if(!stk.empty())
        {
            if(stk.top()==')'or stk.top()==']')ok=0;
            else
            while(!stk.empty())
            {
                if(stk.top()=='(' or stk.top()=='[')
                 stk2.push(stk.top());
                 else
                 {
                      if(stk2.top()=='(' && stk.top()==')')
                        stk2.pop();
                      if(stk2.top()=='[' && stk.top()==']')
                        stk2.pop();
                 }
                 stk.pop();
            }
            if(stk2.empty())
        }
    return 0;
}
