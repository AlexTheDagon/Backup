#include <iostream>
#include <fstream>
using namespace std;
ifstream in("ceas2.in");
ofstream out("ceas2.out");
int x[30],sem,nr;
string a,b;
int main()
{
    in>>a>>b;
    for(int i=0;i<a.size() && sem==0;++i)
    {
        if(b[i]!=a[i])
        {
            if(x[a[i]-'a']==0)
            {
                x[a[i]-'a']=b[i]-'a'+1;
                ++nr;
            }
            else
            {
                if(x[a[i]-'a']!=b[i]-'a'+1)sem=1;
            }
        }
    }
    if(sem==0)
    {
        out<<"DA"<<'\n';
        for(int i=0;i<27;++i)
        {
            if(x[i]!=0)out<<(char)(i+'a')<<" "<<(char)(x[i]+'a'-1)<<'\n';
        }
    }
    else out<<"NU";
    return 0;
}
