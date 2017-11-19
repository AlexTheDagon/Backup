#define TuTTy "Cosmin-Mihai Tutunaru"
#include<cstdio>
#include<cstring>
#include<algorithm>
#define infile "palindrom.in"
#define outfile "palindrom.out"
#define nMax 1000013
#define kMax 23
#define sigma 10
#define inf (nMax * kMax)

using namespace std;

int p[sigma];
char s[nMax];


int co[sigma][sigma];
int dp[nMax][kMax];

char chr[nMax][kMax];
char prv[nMax][kMax];

char sol[nMax];

int t[nMax];
int n, k;

void read() {

  for(int i = 0; i < sigma; ++i) {
    scanf("%d", &p[i]);
  }

  scanf("\n");
  scanf("%s\n", s + 1);
  scanf("%d", &k);

}

void init() {

  n = strlen(s + 1);

  t[0] = 1;
  for(int i = 1; i <= n; ++i) {
    t[i] = (t[i-1] * 10) % k;
    s[i] -= '0';
  }

  for(int i = 0; i < sigma; ++i) {

    for(int j = 0; j < sigma; ++j) {
      co[i][j] = inf;
    }

    int crt = i, cost = 0;
    while(cost < co[i][crt]) {
      co[i][crt] = cost++;
      crt = p[crt];
    }

  }

  for(int i = 1; i < k; ++i) {
    dp[(n>>1) + 1][i] = inf;
  }

}

void solve() {

  for(int i = (n>>1); i >= 1; --i) {

    int first = i;
    int last = n - i + 1;

    for(int j = 0; j < k; ++j) {

      dp[i][j] = inf;

      for(int d = sigma - 1; d >= 0 + (i == 1); --d) {
        int cost = co[s[first]][d] + co[s[last]][d];
        int div = (d * t[n - first] + d * t[n - last]) % k;
        int prvDiv = (j - div + k) % k;

        if(cost >= inf || dp[i-1][prvDiv] >= inf) continue;

        cost += dp[i+1][prvDiv];
        if(cost < dp[i][j]) {
          dp[i][j] = cost;
          chr[i][j] = d;
          prv[i][j] = prvDiv;
        }

      }

      //if(dp[i][j] != inf) printf("%d %d = %d\n", i, j, dp[i][j]);
    }
  }

}

void write() {

  printf("%d\n", dp[1][0]);

  int last = 0;
  for(int i = 1; i <= (n>>1); ++i) {
    sol[i] = sol[n - i + 1] = chr[i][last] + '0';
    last = prv[i][last];
  }

  printf("%s\n", sol + 1);
}

int main() {
  freopen(infile, "r", stdin);
  freopen(outfile, "w", stdout);

  read();
  init();
  solve();
  write();

  fclose(stdin);
  fclose(stdout);
  return 0;
}
