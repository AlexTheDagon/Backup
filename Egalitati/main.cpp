#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
ifstream in("egalitati.in");
ofstream out("egalitati.out");
int sem=1;
char c;
stack <char> st;
int main()
{
    while(in>>c)
    {
        if(c==';' || c=='.')
        {
            if(!st.empty())sem=0;
            out<<sem<<'\n';
            sem=1;
            while(!st.empty())st.pop();
        }
        else
        {
            if(c=='=')
            {
                if(st.size()>0)sem=0;
                while(!st.empty())st.pop();
            }
            else
            {
                if(st.size()>0)
                {
                    if(c==')')st.pop();
                    else st.push(c);
                }
                else
                {
                    if(c==')')sem=0;
                    else st.push(c);
                }
            }
        }
    }
    return 0;
}
