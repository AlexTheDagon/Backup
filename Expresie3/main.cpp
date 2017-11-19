#include <iostream>
#include <fstream>
using namespace std;
ifstream in("expresie3.in");
ofstream out("expresie3.out");
int a[40],nrp,val=1,fol[40],semafor,j,f,sem;
string s;
int main()
{
    in>>s;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]==')')
        {
            j=f=i;
            while(s[j]!='(')--j;
            i=i-2;
            if(s[j-1]=='/')
            {
                for(int l=j+1;l<f;++l)
                {
                    if(s[l]=='/')s[l]='*';
                    else if(s[l]=='*')s[l]='/';
                }
            }
            s.erase(f,1);
            s.erase(j,1);
        }
    }
    fol[s[0]-'a']=1;
    ++a[s[0]-'a'];
    for(int i=2;i<s.size();++i)
    {
        if(isalpha(s[i]))
        {
            fol[s[i]-'a']=1;
            if(s[i-1]=='*')++a[s[i]-'a'];
            else --a[s[i]-'a'];
        }
    }
    for(int i=0;i<30;++i)
    {
        if(fol[i]==1)out<<(char)(i+'a')<<" "<<a[i]<<'\n';
    }
    return 0;
}
