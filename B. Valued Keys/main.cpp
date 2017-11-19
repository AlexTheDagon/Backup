#include <iostream>
using namespace std;
string s1,s2;
int sem;
int main()
{
    cin>>s1>>s2;
    for(int i=0;i<s1.size();++i)if(s2[i]>s1[i])sem=1;
    if(sem)cout<<"-1";
    else cout<<s2;
    return 0;
}
