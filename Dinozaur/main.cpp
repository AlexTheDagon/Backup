#include <iostream>
#include <fstream>
using namespace std;
ifstream in("dinozaur.in");
ofstream out("dinozaur.out");
string s;
int fr[30],sem;
int main()
{
    in>>s;
    for(int i=0;i<s.size();++i)
    {
        fr[s[i]-'a']++;
    }
    for(int i=0;i<29;++i)
    {
        if(fr[i]>1)sem=1;
    }
    out<<sem;
    return 0;
}
