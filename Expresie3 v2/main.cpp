#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
ifstream in("expresie3.in");
ofstream out("expresie3.out");
stack <int> s;
int a[40],nrp,val=1,sem[40],sem,p,valori[40];
string s;
int main()
{
    while(in>>c)
    {

    }
    valori[c-'a']++;
    for(int i=0;i<30;++i)
    {
        if(sem[i]==1)out<<(char)(i+'a')<<" "<<valori[i]<<'\n';
    }
    return 0;
}

