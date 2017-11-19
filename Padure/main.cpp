#include <iostream>
#include <fstream>
#include <deque>
#define Nmax 1002
using namespace std;
ifstream in("padure.in");
ofstream out("padure.out");
int Di[]={-1,0,1,0};
int Dj[]={0,1,0,-1};
int N, M, A[Nmax][Nmax], DP[Nmax][Nmax],B[Nmax][Nmax],ii,jj;
int SourceI, SourceJ;
int DestI, DestJ;
deque < pair <int, int> > DQ;
pair <int, int> fr;
int inside(int i,int j)
{
    if(1<=i && i<=N && 1<=j && j<= M)return 1;
    return 0;
}
int main()
{
    in>>N>>M;
    in>>SourceI>>SourceJ;
    in>>DestI>>DestJ;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            in>>A[i][j];
            DP[i][j]=200000000;
        }
    }
    DP[SourceI][SourceJ] = 0;
    DQ.push_front({SourceI, SourceJ});
    while(!DQ.empty())
    {
        fr=DQ.front();
        B[fr.first][fr.second]
        =1;
        DQ.pop_front();
        for (int dir = 0, iv, jv; dir < 4; ++dir)
        {
            ii=fr.first+Di[dir];
            jj=fr.second+Dj[dir];
            if (inside(ii, jj) && B[ii][jj] == 0)
                if (A[ii][jj]!=A[fr.first][fr.second] && DP[ii][jj]>DP[fr.first][fr.second]+1)
                {
                    DP[ii][jj]=DP[fr.first][fr.second]+1;
                    DQ.push_back({ii, jj});
                }
                if (A[ii][jj]==A[fr.first][fr.second] && DP[ii][jj]>DP[fr.first][fr.second])
                {
                    DP[ii][jj]=DP[fr.first][fr.second];
                    DQ.push_front({ii, jj});
                }

        }
    }
    out<<DP[DestI][DestJ]<<'\n';
    return 0;
}
