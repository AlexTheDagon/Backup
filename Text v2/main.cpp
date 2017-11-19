#include <iostream>
#include <string>
#include <fstream>
using namespace std;
ifstream in("text.in");
ofstream out("text.out");
string cuv;

int main()
{
    string line="";
    int cnt=0,car=0,lit=0;
    while(getline(in,line))
    {
        for(int i=0;i<line.size();++i)
        {
            if(isalpha(line[i]))
            {
                ++car;
                ++lit;
            }
            else
            {
                if(lit!=0)++cnt;
                lit=0;
            }
        }
        if(lit!=0)
        {
            ++cnt;
            lit=0;
        }
    }
    if(cnt!=0)out<<car/cnt;
    else out<<"0";
    return 0;
}
