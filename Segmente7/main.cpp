#include <iostream>
#include <fstream>
using namespace std;
ifstream in("7segmente.in");
ofstream out("7segmente.out");
long long a[20],cif,p,nou[20],put,b[10],ncif,sem,limit;
string s;
int main()
{
    b[1]=2;
    b[2]=5;
    b[3]=5;
    b[4]=4;
    b[5]=5;
    b[6]=6;
    b[7]=3;
    b[8]=7;
    b[9]=6;
    in>>s>>p;
    for(auto i:s)
    {
        a[s.size()-cif]=i-'0';
        put+=b[i-'0'];
        ++cif;
    }
    out<<put<<" ";
    for(int i=1;i<=s.size() && p>1;++i,p-=2,++ncif)nou[i]=1;
    if(ncif<s.size())sem=1;
    for(int i=ncif;i>0;--i)
    {
        if(sem)limit=9;
        else limit=a[i];
        for(int j=limit;j>0;--j)
        {
            if(b[j]<=p+b[nou[i]] && j>nou[i])
            {
                p+=b[nou[i]];
                nou[i]=j;
                p-=b[nou[i]];
            }
        }
        if(a[i]>nou[i])sem=1;
    }
    for(int i=ncif;i>0;--i)out<<nou[i];
    return 0;
}
