#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream in("palin3.in");
ofstream out("palin3.out");
int t,j;
string s;
int main()
{
    in>>t;
    for(int i=1;i<=t;++i)
    {
        in>>s;
        if(s.size()%3==0)
        {
            j=0;
            while(j<(s.size()-3))
            {
                if(s[j]==s[j+2])
                {
                    s.erase(j,3);
                    j=0;
                }
                else ++j;
            }
            if(s[0]==s[2] && s.size()==3)
            {
                out<<"DA"<<'\n';
                s="";
            }
            else out<<"NU"<<'\n';
        }
        else
        {
            out<<"NU"<<'\n';
            s="";
        }
    }
    return 0;
}
