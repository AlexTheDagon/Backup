#include <iostream>

using namespace std;
int sem1,sem2,n,l[30],g;
char sir[50001];
int main()
{
    cin>>sir;
    for(int i=0;i<=50000;++i)if((sir[i]-'?')>=0 && (sir[i]-'Z')<=0)n++;
    if(n>=26)
    {
        for(int i=0;i<n-25;++i)
        {
            sem1=0;
            for(int j=i;j<=i+25 && sem1==0;++j)
            {
                if(sir[j]-'A'>=0)l[sir[j]-'A']++;
                if(l[sir[j]-'A']>1)
                {
                    for(int k=0;k<=29;k++)l[k]=0;
                    sem1=1;
                }
            }
            if(sem1==0)
            {
                sem2=1;
                for(int j=i;j<=i+25;++j)
                {
                    if(sir[j]=='?')
                    {
                        while(l[g]!=0 && g<=25)++g;
                        if(g<26){sir[j]=(char)(g+'A');
                        l[g]=1;}
                    }
                }

            }
        }
        if(sem2==1)
        {
            for(int i=0;i<n;++i)
            {
                if(sir[i]=='?')sir[i]='A';
                cout<<sir[i];
            }
        }
        else cout<<"-1";
    }
    else cout<<"-1";
    return 0;
}
