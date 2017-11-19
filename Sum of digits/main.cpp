#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;
int cif[905][8105],l[905][8105],t,s1,s2,x;
vector <int> v;
int main()
{
    for(int i=0;i<=903;++i)
        for(int j=0;j<=8105;++j)
        {
            cif[i][j]=-1;
            l[i][j]=1000;
        }
    cif[0][0]=0;
    l[0][0]=0;
    for(int i=1;i<=901;++i)
    {
        for(int j=1;j<=8101;++j)
        {
            for(int c=1;c<=9;++c)
            {
                if(i-c>=0 && j-c*c>=0)
                {
                    if(cif[i-c][j-c*c]!=-1 && l[i-c][j-c*c]+1<l[i][j])
                    {
                        cif[i][j]=c;
                        l[i][j]=l[i-c][j-c*c]+1;
                    }
                }
            }
        }
    }
    cin>>t;
    for(int i=1;i<=t;++i)
    {
        cin>>s1>>s2;
        if(s1>900 || s2>8100)cout<<"No solution"<<'\n';
        else
        {
            if(cif[s1][s2]==-1 || l[s1][s2]>100 || s1>s2)cout<<"No solution"<<'\n';
            else
            {
                while(cif[s1][s2]!=0)
                {
                    v.pb(cif[s1][s2]);
                    x=cif[s1][s2];
                    s1=s1-x;
                    s2=s2-x*x;
                }
                sort(v.begin(),v.end());
                for(int j=0;j<v.size();++j)cout<<v[j];
                cout<<'\n';
            }
            v.clear();
        }
    }
    return 0;
}


/**
Tin minte in matricea a[i][j]ultima cifra adaugata si lungimea solutiei
Daca in matricea a[i][j] am adaugat cifra x atunci eu in i de j am venit din a[i-x][j-x^2];
la reconstructie merg pana in a[0][0]==0;
Sa nu uit sa afisez cifrele sortate
Pentru ce nu am solutie marchez cu -1;
De acutalizat daca pot obtine o solutie mai buna din punct de vedere al lungimii
**/
