#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream in("palindrom2.in");
ofstream out("palindrom2.out");
string s;
int sim,sem,l;
int main()
{
    in>>s;
    sim=s.size()-1;
    for(int i=s.size()-1;i>=s.size()/2;--i)
    {
        sem=0;
        for(int j=0;i-j>=0 && s[i+j]!='\0' && sem==0;++j)
        {
            if(s[i-j]!=s[i+j])sem=1;
        }
        if(sem==0)sim=i;
    }
    for(int i=sim-s.size()+sim+1;i>0;--i)
    {
        s.append(s,i-1,1);
    }
    out<<s;
    return 0;
}
