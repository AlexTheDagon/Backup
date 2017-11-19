#include <iostream>
#include <queue>
#include <fstream>
#include <functional>
#define x first.first
#define y first.second
#define z second
using namespace std;
ifstream in("torr3.in");
ofstream out("tort3.out");
int a[505][505],viz[505][505];
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
/***
dp[i][j]-lat maxima a unui patrat ce se termina in i,j;
