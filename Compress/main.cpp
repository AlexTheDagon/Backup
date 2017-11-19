#include <iostream>
#include <fstream>
using namespace std;
ifstream in("compress.in");
ofstream out("compress.out");
char c,x;
string s;
int nr;
int main()
{
    in>>s;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]==c)
        {
            ++nr;
        }
        else
        {
            if(c!=(char)0)out<<c<<nr;
            nr=1;
            c=s[i];
        }
    }
    out<<c<<nr;
    return 0;
}
