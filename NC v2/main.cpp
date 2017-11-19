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
        sem=1;
        if(s.size()==1)
        {
            if(s[0]!='!' && s[0]!='?' && s[0]!='.' && s[0]!=',')++cuv;
            else
            {
                if(!(s[0]!='!' && s[0]!='?' && s[0]!='.'))
                {
                    x[++fr]=cuv;
                    cuv=0;
                }
            }
        }
        else
        {
            if(s.size()==3 && s[0]=='.' && s[1]=='.' && s[2]=='.')
            {
                x[++fr]=cuv;
                cuv=0;
            }
            else
            {
                for(int i=0;i<s.size();++i)
                {
                    if(i>0 && i<(s.size()-1))
                    {
                        if(s[i]==',' && s[i+1]!='\0')
                        {
                            ++cuv;
                            sem=1;
                        }
                    }
                    if((s[i]=='!' || s[i]=='.' || s[i]=='?') && cuv>0)
                    {
                        if(s.size()>1 && (s[0]!='!' || s[0]!='.' || s[0]!='?'))
                        x[++fr]=cuv;
                        cuv=0;
                    }
                }
                if(sem==1)++cuv;
            }
        }

    }
    out<<fr<<'\n';
    for(int i=1;i<=fr;++i)out<<x[i]<<'\n';
    return 0;
}
