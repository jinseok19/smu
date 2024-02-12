
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define N	6
int nodes[N + 1];

void print_node() {
	static int res = 0;
	printf("결과%d: ", ++res);
	for (int i = 1; i <= N; i++)
		printf("(%d,%d) ", i, nodes[i]);
	printf("\n");
}
bool promising(int i, int j)
{
	int d = 1;
	for (int k = i - 1; k > 0; k--) {
		if (nodes[k] == j) //같은 열 확인
			return false;
		if (j - d > 0 && nodes[k] == j - d)//주 대각선 방향 확인(위로 왼쪽 방향)
			return false;
		//1. 아래를 완성하시오. 보조 대각선 방향 확인(위로 오른쪽 방향)
		if (j + d <= N && nodes[k] == j + d)//보조 대각선 방향 확인(위로 오른쪽 방향)
			return false;
		d++;
	}
	return true;
}
void checknode(int i, int j)
{
	int k;

	if (promising(i, j)) {
		if (i == N)
			print_node();
		else {
			for (k = 1; k <= N; k++) {
				nodes[i + 1] = k;
				//2. 아래를 완성하시오. (i+1,k) 좌표에 말이 있을 경우 순환 호출
				checknode(i + 1, k);
			}
		}
	}
}

#define N_ITEMS 8 //아이템의 개수
#define TRIES	20 //몬테카를로기법에서 시도 횟수
int n = N_ITEMS;
int w[] = { 0, 2, 5, 10, 13, 17, 20, 22, 42 };
int W = 52; //허용 가능 무게
bool include[N_ITEMS + 1];

int m = 2; //유망한 마디의 수
int mprod; //현 단계까지의 유망한 마디의수의 곱
int t = 2;//모든 자식 마디의 수
int numnodes;//방문한 마디의 수

bool promising(int i, int weight, int total) {
	//3. 아래를 완성하시오. 
	return (weight + total >= W) && (weight == W || weight + w[i + 1] <= W);


}
void sum_of_subset(int i, int weight, int total) {
	int j;
	if (promising(i, weight, total)) {
		if (weight == W) {
			for (j = 1; j <= i; j++)
				if (include[j])
					printf("item %d,", j);
			printf("\n");
		}
		else {
			include[i + 1] = true;
			sum_of_subset(i + 1, weight + w[i + 1], total - w[i + 1]);
			//4. 아래를 완성하시오. include[i + 1] = false 인 경우
			include[i + 1] = false;
			sum_of_subset(i + 1, weight, total - w[i + 1]);
		}
	}
}
void monteCarlo(int i, int weight, int total) {
	if (promising(i, weight, total)) {
		if (weight != W) {
			mprod *= m;
			numnodes += mprod * t;
			if (((double)rand() / RAND_MAX) < 0.5) {
				//printf("%d:in,", i + 1);
				//5. 아래를 완성하시오. include[i + 1] = true 인 경우
				monteCarlo(i + 1, weight + w[i + 1], total - w[i + 1]);
			}
			else {
				//printf("%d:out,", i + 1);
				monteCarlo(i + 1, weight, total - w[i + 1]);
			}
		}
	}
}
int main(void)
{
	//1번
	printf("%d-여왕말 문제\n", N);
	checknode(0, 0);

	//2번
	int sum_weight = 0;
	for (int i = 1; i <= N_ITEMS; i++)
		sum_weight += w[i];
	printf("\n아이템 개수 %d, 총 무게 %d 의 부분합\n", N_ITEMS, W);
	sum_of_subset(0, 0, sum_weight);

	int sum = 0;
	//srand((unsigned)time(NULL));
	for (int i = 0; i < TRIES; i++) {
		numnodes = 1 + t;
		mprod = 1;
		monteCarlo(0, 0, sum_weight);
		//printf("\n%d:%d\n", i, numnodes);
		sum += numnodes;
	}
	printf("\n총 %d 방문의 몬테카를로기법에서 평균 방문 노드 수:%.1f\n", TRIES, (double)sum / TRIES);

	return 0;
}
/*실제출력
6-여왕말 문제
결과1: (1,2) (2,4) (3,6) (4,1) (5,3) (6,5)
결과2: (1,3) (2,6) (3,2) (4,5) (5,1) (6,4)
결과3: (1,4) (2,1) (3,5) (4,2) (5,6) (6,3)
결과4: (1,5) (2,3) (3,1) (4,6) (5,4) (6,2)

아이템 개수 8, 총 무게 52 의 부분합
item 1,item 2,item 3,item 4,item 7,
item 1,item 4,item 5,item 6,
item 2,item 3,item 5,item 6,
item 3,item 6,item 7,
item 3,item 8,
item 4,item 5,item 7,

총 20 방문의 몬테카를로기법에서 평균 방문 노드 수:293.4

C:\Users\rlawl\OneDrive\바탕 화면\상명대학교\2학년\2학기\알고리즘 - 홍철의\Project1_111\x64\Debug\Project1_111.exe(프로 세스 23460개)이(가) 종료되었습니다(코드: 0개).
이 창을 닫으려면 아무 키나 누르세요...

*/
/*예시 출력
6-여왕말 문제
결과1: (1,2) (2,4) (3,6) (4,1) (5,3) (6,5)
결과2: (1,3) (2,6) (3,2) (4,5) (5,1) (6,4)
결과3: (1,4) (2,1) (3,5) (4,2) (5,6) (6,3)
결과4: (1,5) (2,3) (3,1) (4,6) (5,4) (6,2)

아이템 개수 8, 총 무게 52 의 부분합
item 1,item 2,item 3,item 4,item 7,
item 1,item 4,item 5,item 6,
item 2,item 3,item 5,item 6,
item 3,item 6,item 7,
item 3,item 8,
item 4,item 5,item 7,

총 20 방문의 몬테카를로기법에서 평균 방문 노드 수:293.4
계속하려면 아무 키나 누르십시오 . . .
*/