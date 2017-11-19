#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
ifstream in("editor.in");
ofstream out("editor.out");
stack <char> s,st;
char c;
int a[100001],sem;
int m,x,t;
int main()
{
    in>>t;
    for(int l=1;l<=t;++l)
    {
        c=(char)0;
        sem=0;
        while(in>>c && c!='E')
        {
            if(c!='*')s.push(c);
            else if(!s.empty())s.pop();
        }///Citirea e bine
        while(!s.empty())
        {
            c=s.top();
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
            s.pop();
            if(st.empty())st.push(c);
            else
            {
                if(c==']' && st.top()=='[')st.pop();
                else
                {
                    if(c==')' && st.top()=='(')st.pop();
                    else st.push(c);
                }
            }
        }
        if(!st.empty())
        {
            out<<":(";
            while(!st.empty())st.pop();
        }
        else out<<":)";
        out<<'\n';
    }
    return 0;
}
