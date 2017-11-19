#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
ifstream in("editor.in");
ofstream out("editor.out");
stack <char> s1,s2;
char c;
int a[100001],sem;
int t;
int main()
{
    in>>t;
    for(int l=1;l<=t;++l)
    {
        c='\0';
        sem=0;
        while(in>>c && c!='E')
        {
            if(c!='*')s1.push(c);
            else if(!s1.empty())s1.pop();
        }
        while(!s1.empty())
        {
            c=s1.top();
            if(c=='(')c=')';
            else
            {
                if(c==')')c='(';
                else
                {
                    if(c==']')c='[';
                    else c=']';
                }
            }
            s1.pop();
            if(s2.empty())s2.push(c);
            else
            {
                if(c==']' && s2.top()=='[')s2.pop();
                else
                {
                    if(c==')' && s2.top()=='(')s2.pop();
                    else s2.push(c);
                }
            }
        }
        if(!s2.empty())
        {
            out<<":(";
            while(!s2.empty())s2.pop();
        }
        else out<<":)";
        out<<'\n';
    }
    return 0;
}
