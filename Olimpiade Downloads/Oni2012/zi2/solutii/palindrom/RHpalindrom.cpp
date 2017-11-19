#include <stdio.h>

#define NMAX 1000001
#define KMAX 21

int P[10], K, x[NMAX], N;
int cost[10][10];
int compar[KMAX][KMAX];
int costMin[2][KMAX];
int rez[NMAX][KMAX];
int back[NMAX][KMAX];
int putere[NMAX];
int partial[KMAX][2];
int rezFinal[NMAX];
int cnt, k;

void citire() {
	freopen("palindrom.in", "r", stdin);
	freopen("palindrom.out", "w", stdout);

	for (int i = 0; i < 10; scanf("%d ", P + i), ++i);
	while (true) {
		char c;
		scanf("%c", &c);
		if (c >= '0' && c<='9')
			x[N++] = c - '0';
		else {
			scanf("%d", &K);
			break;
		}
	}

}

void preprocesareCosturiTranzitie() {
	int uz[10];

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; uz[j] = 0, cost[i][j++] = -1)
			;
		int j = i;
		int cc = 0;

		cost[i][i] = 0;
		uz[i] = 1;

		while (uz[P[j]] == 0) {
			uz[P[j]] = 1;
			cost[i][P[j]] = ++cc;
			j = P[j];
		}
	}
}

void preprocesarePuteri10() {
	putere[0] = 1;
	for (int i = 1; i < N; ++i) {
		putere[i] = (putere[i - 1] * 10) % K;
	}
}

void cerintaA() {
	for (int i = 0; i < N; ++i) {
		int j = 9;
		while (cost[x[i]][j] == -1)
			--j;
		printf("%d", j);
	}
	printf("\n");
}

void cerintaB() {
	preprocesarePuteri10();

	costMin[1][0] = 0;
	for (int i = 1; i < K; ++i)
		costMin[1][i] = -1;

	for (int i = 0, L = N / 2; i < L; ++i) {
		int st = x[i];
		int dr = x[N - i - 1];
		k = i & 1;

		for (int ii = 0; ii < K; ++ii)
			partial[ii][0] = partial[ii][1] = costMin[k][ii] = rez[i][ii] = back[i][ii] = -1;

		for (int j = 9; i == 0 ? j >= 1 : j >= 0; --j) {
			if (cost[st][j] != -1 && cost[dr][j] != -1) {
				int costTranf = cost[st][j] + cost[dr][j];
				int restAdaugat = (j * putere[i] + j * putere[N - 1 - i]) % K;

				if (partial[restAdaugat][0] == -1
						|| costTranf < partial[restAdaugat][0]) {
					partial[restAdaugat][0] = costTranf;
					partial[restAdaugat][1] = j;
				}
			}
		}

		for (int j = 0; j < K; ++j) {
			printf("part %d: %d %d\n", j, partial[j][0], partial[j][1]);
		}

		for (int j = 0; j < K; ++j) {
			for (int l = 0; l < K; ++l) {
				if (partial[l][0] == -1 || costMin[1 - k][j] == -1)
					continue;

				int restTarget = (j + l) % K;

				if (costMin[k][restTarget] == -1
						|| costMin[k][restTarget]
								> costMin[1 - k][j] + partial[l][0]) {

					costMin[k][restTarget] = costMin[1 - k][j] + partial[l][0];
					rez[i][restTarget] = partial[l][1];
					back[i][restTarget] = j;
				}

				if (costMin[k][restTarget]
						== costMin[1 - k][j] + partial[l][0]) {

					if (compar[j][restTarget] == 0) {
						if (rez[i][restTarget] < partial[l][1]) {
							costMin[k][restTarget] = costMin[1 - k][j]
									+ partial[l][0];
							rez[i][restTarget] = partial[l][1];
							back[i][restTarget] = j;
						}
					} else if (compar[j][restTarget] == 1) {
						costMin[k][restTarget] = costMin[1 - k][j]
								+ partial[l][0];
						rez[i][restTarget] = partial[l][1];
						back[i][restTarget] = j;
					}
				}

			}
		}

		for (int j = 0; j < K; ++j) {
			printf("%d : %d %d %d\n", j, costMin[k][j], rez[i][j], back[i][j]);
		}

		//refac comparatiile
		for (int j = 0; j < K; ++j) {
			for (int l = 0; l < K; ++l) {
				if (compar[j][l] == 0) {
					if (rez[i][j] > rez[i][l])
						compar[j][l] = 1;
					else if (rez[i][j] < rez[i][l])
						compar[j][l] = -1;
				}
			}
		}

	}

	int poz = 0;
	int i = N / 2 - 1;
	while (i >= 0) {
		rezFinal[cnt++] = rez[i][poz];
		poz = back[i][poz];
		--i;
	}

	for (int i = N / 2 - 1; i >= 0; --i)
		printf("%d", rezFinal[i]);
	for (int i = 0; i < N / 2; ++i)
		printf("%d", rezFinal[i]);

	printf("\n");
	printf("%d\n", costMin[k][0]);
}

int main(int argc, char *argv) {
	citire();

	preprocesareCosturiTranzitie();

	cerintaA();
	//cerintaB();

	return 0;
}
