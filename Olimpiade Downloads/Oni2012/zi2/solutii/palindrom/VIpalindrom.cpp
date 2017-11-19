#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define maxn 100010
#define maxk 22
#define maxcifre 10
#define inf 99999999
#define pii pair<int, int>
#define pb push_back
#define mkp make_pair

int N, K;
char A[maxn], sol[maxn];
int perm[maxcifre], put[maxn];
int ajunge[maxcifre][maxcifre];
int D[maxn][maxk];

void preproc_puteri() {
     int i;

     put[0] = 1;
     for(i=1; i<=N; i++) {
          put[i] = (put[i-1] * 10) % K;
     }
}

void preproc_ajunge() {
     int i, j, p;

     for(i=0; i<maxcifre; i++) {
          for(j=0; j<maxcifre; j++) {
               ajunge[i][j] = -1;
          }
     }

     for(i=0; i<maxcifre; i++) {
          ajunge[i][i] = 0;

          p = i;

          for(j=1; j<=100; j++) {
               p = perm[p];

               if(p == i) break;

               ajunge[i][p] = j;
          }
     }
}

int main() {
     FILE *f1=fopen("palindrom.in", "r"), *f2=fopen("palindrom.out", "w");
     int i, j, p, q;

     for(i=0; i<=9; i++) {
          fscanf(f1, "%d ", &perm[i]);
     }

     fscanf(f1, "%s\n", A+1);
     N = strlen(A+1);

     fscanf(f1, "%d\n", &K);

     preproc_puteri();
     preproc_ajunge();

     int jumatate = N / 2;
     
     //prima cerinta
     for(i=jumatate; i>=1; i--) {
     	  int cif1 = A[i] - '0';
          int cif2 = A[N-i+1] - '0';
          
          int finish = 0;
          if(i == 1) finish = 1;
          
          for(q=9; q>=1; q--) {
          		if(ajunge[cif1][q] >= 0 && ajunge[cif2][q] >= 0) {
          			sol[i] = (q + '0');
          			break;
				}
			}
	  }
	  for(i=1; i<=jumatate; i++) {
          fprintf(f2, "%c", sol[i]);
      }
      for(i=jumatate; i>=1; i--) {
          fprintf(f2, "%c", sol[i]);
      }
      fprintf(f2, "\n");
     
	 //a doua cerinta	
     for(i=jumatate+1; i>=1; i--) {
          for(j=0; j<K; j++) {
               D[i][j] = inf;
          }
     }

     D[jumatate+1][0] = 0;

     for(i=jumatate; i>=1; i--) {
          int cif1 = A[i] - '0';
          int cif2 = A[N-i+1] - '0';

          for(j=0; j<K; j++) {
               int start = 0;
               if(i == 1) start = 1; //prima cifra a palindromului nu poate fi 0

               for(p=start; p<=9; p++) {
                    if(ajunge[cif1][p] >= 0 && ajunge[cif2][p] >= 0) {
                         int nou_rest = (j + p * (put[N-i] + put[i-1])) % K;

                         D[i][nou_rest] = min(D[i][nou_rest], D[i+1][j] + ajunge[cif1][p] + ajunge[cif2][p]);
                    }
               }
          }
     }


     int cost = D[1][0];
     int rest = 0;

     if(cost >= N * 10) {
          fprintf(f2, "-1\n");

          fclose(f1); fclose(f2);
          return 0;
     }

     for(i=1; i<=jumatate; i++) {
          //calculez sol[i]
          int cif1 = A[i] - '0';
          int cif2 = A[N-i+1] - '0';

          int finish = 0;
          if(i == 1) finish = 1;

          for(q=9; q>=finish; q--) {
               if(ajunge[cif1][q] >= 0 && ajunge[cif2][q] >= 0) {
                    p = (q * (put[N-i] + put[i-1])) % K;
                    int nou_rest = rest - p;
                    if(nou_rest < 0) nou_rest += K;

                    if(D[i+1][nou_rest] + ajunge[cif1][q] + ajunge[cif2][q] == cost) {
                         //este ok ok ok
                         sol[i] = (q + '0');

                         cost -= (ajunge[cif1][q] + ajunge[cif2][q]);
                         rest = nou_rest;

                         break;
                    }
               }
          }
     }

     for(i=1; i<=jumatate; i++) {
          fprintf(f2, "%c", sol[i]);
     }
     for(i=jumatate; i>=1; i--) {
          fprintf(f2, "%c", sol[i]);
     }
     fprintf(f2, "\n");

     fclose(f1); fclose(f2);
     return 0;
}
