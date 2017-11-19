#include <iostream>
#include <fstream>
using namespace std;
ifstream in("beep.in");
ofstream out("beep.out");
string interzis,s;
int sem=1;
int main()
{
    in>>interzis;
    while(in>>s)
    {
        if(sem==0)out<<" ";
        else sem=0;
        if(s==interzis)out<<"beep";
        else out<<s;

    }
    return 0;
}
