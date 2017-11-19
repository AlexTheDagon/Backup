#include <iostream>
#include <map>
#include <cctype>
using namespace std;
int t,n,m,sem,imposibil,g,h,p[105][105],d[105][105],a[105][105];
string s,user_mesaj,sender,user[105],msg[105],sol[105];
int main()
{
    cin>>t;
    while(t)
    {
        for(int i=0;i<=102;++i)
        {
            msg[i]="";
            user[i]="";
            sol[i]="";
            for(int j=0;j<=102;++j)
            {
                d[i][j]=0;
                p[i][j]=1;
                a[i][j]=0;
            }
        }
        --t;
        imposibil=0;
        map<string,int> mapp;
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>user[i];
            mapp[user[i]]=i;
        }
        cin>>m;
        getline(cin,s);///bine
        for(int i=1;i<=m;++i)
        {
            sem=0;
            user_mesaj="";
            sender="";
            getline(cin,s);///bine
            for(int j=0;j<s.size();++j)
            {
                if(s[j]==':')sem=1;
                if((isdigit(s[j]) || isalpha(s[j])) && sem==1)user_mesaj+=s[j];
                else
                {
                    if(user_mesaj!="" && mapp.find(user_mesaj)!=mapp.end())p[i][mapp[user_mesaj]]=0;
                    user_mesaj="";
                }
                if(sem==1)msg[i]+=s[j];
                else sender+=s[j];
            }
            if(user_mesaj!="" && mapp.find(user_mesaj)!=mapp.end())p[i][mapp[user_mesaj]]=0;
            user_mesaj="";
            if(s[0]!='?')
            {
                for(int j=1;j<=n;++j)
                {
                    if(user[j]==sender)
                    {
                        if(p[i][j]==0)imposibil=1;
                    }
                    else p[i][j]=0;
                }
            }
        }///bine
        a[0][0]=-1;
        for(int j=1;j<=n;++j)
        {
            if(p[1][j])
            {
                d[1][j]=1;
            }
        }///bine
        for(int i=2;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(p[i][j]==1)
                {
                    a[i][j]=-1;
                    for(int q=1;q<=n;++q)
                    {
                        if(p[i-1][q] && d[i-1][q]==1 && j!=q)
                        {
                            a[i][j]=q;
                            d[i][j]=1;
                        }
                    }
                }
            }
        }
        for(g=1;g<=n && d[m][g]!=1;++g);
        if(g>n || imposibil)cout<<"Impossible"<<'\n';
        else
        {
            for(int i=m;a[i][g]!=-1;--i)
            {
                sol[i]=user[g];
                g=a[i][g];
                h=i-1;
            }
            if(h!=0)cout<<"Impossible"<<'\n';
            else
            {
                for(int i=1;i<=m;++i)cout<<sol[i]<<msg[i]<<'\n';
            }
        }
    }
    return 0;
}
///de reintializat msg,d,p,a
