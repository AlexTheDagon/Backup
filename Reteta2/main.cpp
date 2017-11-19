#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream in("reteta2.in");
ofstream out("reteta2.out");
string s;
string v[100];
int sem,ing,a,x[100],timp;
int main()
{
    s='a';
    while(in>>s>>a)
    {
        cout<<a<<endl;
        if(s[0]!=')')
        {
            sem=0;
            if(s[0]=='(')
            {
                while(s[0]=='(')s.erase(s.begin());
            }
            for(int i=0;i<ing;++i)
            {
                if(v[i]==s)
                {
                    x[i]+=a;
                    sem=1;
                }
            }
            if(sem==0)
            {
                v[++ing]=s;
                x[ing]=a;
            }
        }
        else
        {
            timp+=a;
        }
    }
    out<<timp;
    return 0;
}
