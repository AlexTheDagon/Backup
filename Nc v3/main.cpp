#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream in("nc.in");
ofstream out("nc.out");
string s;
int x[2000000],fr,cuv,sem;
int main()
{
    while(in>>s)
    {
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='!' || s[i]=='?' || s[i]=='.')
            {
                if(s[i]=='.')
                {
                    if(cuv>0 || sem==1)
                    {
                        if(sem==1)
                        {
                            ++cuv;
                            sem=0;
                        }
                        x[++fr]=cuv;
                        cuv=0;
                    }
                }
                else
                {
                    if(sem==1)
                    {
                        ++cuv;
                        sem=0;
                    }
                    x[++fr]=cuv;
                    cuv=0;
                }
            }
            else
            {
                if(s[i]==',')
                {
                    if(sem==1)
                    {
                        ++cuv;
                        sem=0;
                    }
                }
            }
            if(isalpha(s[i]))sem=1;
        }
        if(sem==1)
        {
            ++cuv;
            sem=0;
        }
    }
    out<<fr<<'\n';
    for(int i=1;i<=fr;++i)out<<x[i]<<'\n';
    return 0;
}
