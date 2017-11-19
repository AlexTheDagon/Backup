#include <iostream>
#include <stdlib.h>

using namespace std;
char t[3][20];
int dist[130][130],cmin[2][105],minn=10000000,sp[2][105];
string s;
void dec();
int main()
{
    dec();
    cin>>s;
    for(int i=0;i<=1;++i)
        for(int j=1;j<=102;++j)cmin[i][j]=100000;
    cmin[0][0]=dist['F'][s[0]];
    cmin[1][0]=dist['J'][s[0]];
    for(int i=1;i<s.size();++i)
    {
        for(int j=0;j<i;++j)
        {

        }
    }
    cout<<min(cmin[0][s.size()-1],cmin[1][s.size()-1]);
    return 0;
}
///0 degestul de porneste de la F
///1 cel ce proneste de la J



void dec()
{
    t[1][1]='Q';
    t[1][2]='W';
    t[1][3]='E';
    t[1][4]='R';
    t[1][5]='T';
    t[1][6]='Y';
    t[1][7]='U';
    t[1][8]='I';
    t[1][9]='O';
    t[1][10]='P';
    t[2][1]='A';
    t[2][2]='S';
    t[2][3]='D';
    t[2][4]='F';
    t[2][5]='G';
    t[2][6]='H';
    t[2][7]='J';
    t[2][8]='K';
    t[2][9]='L';
    t[3][1]='Z';
    t[3][2]='X';
    t[3][3]='C';
    t[3][4]='V';
    t[3][5]='B';
    t[3][6]='N';
    t[3][7]='M';
    for(int i=1;i<=3;++i)
        for(int j=1;j<=10;++j)
            if(t[i][j]>='A')
                for(int ii=1;ii<=3;++ii)
                    for(int jj=1;jj<=10;++jj)
                        if(i!=ii || j!=jj)
                            if(t[ii][jj]>='A')
                                dist[t[i][j]][t[ii][jj]]=abs(i-ii)+abs(j-jj);
}

