#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
ifstream in("paranteze.in");
ofstream out("paranteze.out");
int lg,lgmax,n;
stack <char> st;
char c;
int main()
{
    in>>n;
    while(n)
    {
        --n;
        in>>c;
        if(!st.empty())
        {
            if((st.top()=='{' && c=='}')||(st.top()=='[' && c==']')||(st.top()=='(' && c==')'))
            {
                 lg=lg+2;
                 st.pop();
                 cout<<"1 ";
            }
            else
            {
                lgmax=max(lgmax,lg);
                lg=0;
                while(!st.empty())st.pop();
                cout<<"2 ";
            }
        }
        else
        {
            if(c!=')' && c!=']' && c!='}')
            {
                lgmax=max(lgmax,lg);
                lg=0;
                cout<<"3 ";
            }
            else
            {
                st.push(c);
                lgmax=max(lgmax,lg);
                cout<<"4 ";
            }
        }
        cout<<lg<<endl;
    }
    out<<lgmax;
    return 0;
}
