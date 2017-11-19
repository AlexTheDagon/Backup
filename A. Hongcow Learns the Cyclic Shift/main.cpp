#include <iostream>
#include <string>
using namespace std;
string s;
string m[100];
int nr,sem;
int main()
{
    cin>>s;
    m[1]=s;
    for(int i=2;i<=s.size();++i)
    {
        m[i].append(m[i-1],1,(s.size()-1));
        m[i].append(m[i-1],0,1);
    }
    for(int i=1;i<=s.size();++i)
    {
        sem=1;
        for(int j=i+1;j<=s.size();++j)if(m[i]==m[j])sem=0;
        if(sem==1)++nr;
    }
    cout<<nr;
    return 0;
}
