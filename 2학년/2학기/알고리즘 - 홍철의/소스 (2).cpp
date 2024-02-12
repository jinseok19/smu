
/*Program that times Binomial function calls*/
#include <time.h>
#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_VERTICES 5
#define INF 1000L

int B[101][101], B1[101];

//Recursive binomial
int bino_rec(int n, int k) {
	//아래를 완성하시오
	if (k == 0 || k == n)
		return 1;
	else
		return bino_rec(n - 1, k - 1) + bino_rec(n - 1, k);

}

//Dynamic programming binomial
void bino_dyn(int n, int k) {
	int min;

	for (int i = 0; i <= n; i++) {
		if (i < k) min = i;
		else min = k;
		//아래를 완성하시오

		for (int j = 0; j <= min; j++)
			if (j == 0 || j == i)
				B[i][j] = 1;
			else
				B[i][j] = B[i - 1][j - 1] + B[i - 1][j];

	}
}

//Dynamic programming binomial using one dimensional array
void bino_dyn_1d(int n, int k) {
	int min;
	int prev, cur;

	for (int i = 0; i <= n; i++) {
		prev = cur = B1[0];
		if (i < k) min = i;
		else min = k;
		//아래를 완성하시오
		for (int j = 0; j <= min; j++) {
			if (j == 0 || j == i)
				B1[j] = 1;
			else {
				cur = B1[j];
				B1[j] = prev + B1[j];
				prev = cur;
			}
		}

	}
}

void path(int P[][MAX_VERTICES], int q, int r)
{
	//아래를 완성하시오
	if (P[q][r] != -1)
	{
		path(P, q, P[q][r]);
		cout << "v" << P[q][r] << ", ";
		path(P, P[q][r], r);
	}

}
int main() {
	printf("binomail coefficient\n");
	time_t begin, end;

	int N, k;
	cout << ("Enter positive integer N(<=100): ");
	cin >> N;
	cout << ("Enter positive integer k(<=100): ");
	cin >> k;
	begin = time(NULL);
	cout << "Binomial recursive     : " << bino_rec(N, k) << endl;
	end = time(NULL);
	cout << "\ttime = " << difftime(end, begin) << " s" << endl;

	begin = time(NULL);
	bino_dyn(N, k);
	cout << "Fibonacci dynamic prog.: " << B[N][k] << endl;
	end = time(NULL);
	cout << "\ttime = " << difftime(end, begin) << " s" << endl << endl;

	begin = time(NULL);
	bino_dyn_1d(N, k);
	cout << "Fibonacci dynamic prog. using one dimensional array: " << B1[k] << endl;
	end = time(NULL);
	cout << "\ttime = " << difftime(end, begin) << " s" << endl << endl;

	printf("floyd shortest path\n");
	typedef struct GraphType {
		int n;	// 정점의 개수
		int W[MAX_VERTICES][MAX_VERTICES];
	} GraphType;

	GraphType g = { 5,
		{{ 0, 1, INF, 1, 5 },
		{ 9,  0, 3, 2, INF },
		{ INF, INF, 0, 4, INF },
		{ INF, INF, 2, 0, 3  },
		{ 3, INF, INF, INF, 0  }}
	};
	int P[MAX_VERTICES][MAX_VERTICES];
	int D[MAX_VERTICES][MAX_VERTICES];

	memset(P, -1, sizeof(int) * MAX_VERTICES * MAX_VERTICES);
	memcpy(D, g.W, sizeof(int) * MAX_VERTICES * MAX_VERTICES);
	printf("W:\n");
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			if (g.W[i][j] < INF)
				printf("%3d", g.W[i][j]);
			else
				printf("  -");
		}
		printf("\n");
	}
	//아래를 완성하시오	
	for (int k = 0; k < g.n; k++) {
		for (int i = 0; i < g.n; i++) {
			for (int j = 0; j < g.n; j++) {
				if (D[i][k] + D[k][j] < D[i][j]) {
					P[i][j] = k;
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}
	printf("v4에서 v2로 가는 최단경로는 v4, ");
	path(P, 4, 2);
	printf("v2\n\n");

	printf("D:\n");
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			if (D[i][j] < INF)
				printf("%3d", D[i][j]);
			else
				printf("  -");
		}
		printf("\n");
	}
	printf("P:\n");
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			if (P[i][j] < 0)
				printf("%3d", -1);
			else
				printf("%3d", P[i][j]);
		}
		printf("\n");
	}

	return 0;
}
/*실제출력
* 
binomail coefficient
Enter positive integer N(<=100): 50
Enter positive integer k(<=100): 8
Binomial recursive     : 536878650
		time = 5 s
Fibonacci dynamic prog.: 536878650
		time = 0 s

Fibonacci dynamic prog. using one dimensional array: 536878650
		time = 0 s

floyd shortest path
W:
  0  1  -  1  5
  9  0  3  2  -
  -  -  0  4  -
  -  -  2  0  3
  3  -  -  -  0
v4에서 v2로 가는 최단경로는 v4, v0, v3, v2

D:
  0  1  3  1  4
  8  0  3  2  5
 10 11  0  4  7
  6  7  2  0  3
  3  4  6  4  0
P:
 -1 -1  3 -1  3
  4 -1 -1 -1  3
  4  4 -1 -1  3
  4  4 -1 -1 -1
 -1  0  3  0 -1

C:\Users\rlawl\OneDrive\바탕 화면\상명대학교\2학년\2학기\알고리즘 - 홍철의\Project3\x64\Debug\Project3.exe(프로세스 37712개)이(가) 종료되었습니다(코드: 0개).
이 창을 닫으려면 아무 키나 누르세요...


*/
/*예시 출력
binomail coefficient
Enter positive integer N(<=100): 50
Enter positive integer k(<=100): 8
Binomial recursive     : 536878650
		time = 2 s
Fibonacci dynamic prog.: 536878650
		time = 0 s

Fibonacci dynamic prog. using one dimensional array: 536878650
		time = 0 s

floyd shortest path
W:
  0  1  -  1  5
  9  0  3  2  -
  -  -  0  4  -
  -  -  2  0  3
  3  -  -  -  0
v4에서 v2로 가는 최단경로는 v4, v0, v3, v2

D:
  0  1  3  1  4
  8  0  3  2  5
 10 11  0  4  7
  6  7  2  0  3
  3  4  6  4  0
P:
 -1 -1  3 -1  3
  4 -1 -1 -1  3
  4  4 -1 -1  3
  4  4 -1 -1 -1
 -1  0  3  0 -1
계속하려면 아무 키나 누르십시오 . . ..
*/