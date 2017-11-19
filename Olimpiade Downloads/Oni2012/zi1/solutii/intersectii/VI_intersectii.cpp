#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 2048

int W, H, T, N;
int res[maxn], viz[maxn], d[maxn], a[maxn];

int main() {
     FILE *f1=fopen("intersectii.in", "r"), *f2=fopen("intersectii.out", "w");
     int i, j, p, q, k;

     fscanf(f1, "%d %d %d\n", &W, &H, &T);

     N = max(W, H) + 1;

     for(i=1; i<=N; i++) d[i] = 1;

     for(i=2; i<=N; i++) {
          if(!viz[i]) {
               for(j=i; j<=N; j+=i) {
                    viz[j] = 1;
                    d[j] = i;
               }
          }
     }

     for(i=1; i<H; i++) {
          memset(a, 0, sizeof(a));

          for(j=1; j<W; j++) {
               if(d[j] == 1 || d[i] == 1) {
                    a[j] = 1;
               }

               p = j / d[j];
               q = i / a[p];

               if(q % d[j] == 0) {
                    a[j] = d[j] * a[p];
               }
               else {
                    a[j] = a[p];
               }

               if(i == 1) {
                    p = j;

                    res[p] += 4;
               }
               else if(j == 1) {
                    p = i;

                    res[p] += 4;
               }
               else if(i == j) {
                    p = i;
                    res[p] += 4;
               }
               else {
                    p = i + j - a[j];
                    res[p] += 4;
               }
          }
     }

     while(T--) {
          fscanf(f1, "%d\n", &p);

          fprintf(f2, "%d\n", res[p]);
     }

     fclose(f1); fclose(f2);
     return 0;
}
