
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define N	6
int nodes[N + 1];

void print_node() {
	static int res = 0;
	printf("���%d: ", ++res);
	for (int i = 1; i <= N; i++)
		printf("(%d,%d) ", i, nodes[i]);
	printf("\n");
}
bool promising(int i, int j)
{
	int d = 1;
	for (int k = i - 1; k > 0; k--) {
		if (nodes[k] == j) //���� �� Ȯ��
			return false;
		if (j - d > 0 && nodes[k] == j - d)//�� �밢�� ���� Ȯ��(���� ���� ����)
			return false;
		//1. �Ʒ��� �ϼ��Ͻÿ�. ���� �밢�� ���� Ȯ��(���� ������ ����)
		if (j + d <= N && nodes[k] == j + d)//���� �밢�� ���� Ȯ��(���� ������ ����)
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
				//2. �Ʒ��� �ϼ��Ͻÿ�. (i+1,k) ��ǥ�� ���� ���� ��� ��ȯ ȣ��
				checknode(i + 1, k);
			}
		}
	}
}

#define N_ITEMS 8 //�������� ����
#define TRIES	20 //����ī���α������ �õ� Ƚ��
int n = N_ITEMS;
int w[] = { 0, 2, 5, 10, 13, 17, 20, 22, 42 };
int W = 52; //��� ���� ����
bool include[N_ITEMS + 1];

int m = 2; //������ ������ ��
int mprod; //�� �ܰ������ ������ �����Ǽ��� ��
int t = 2;//��� �ڽ� ������ ��
int numnodes;//�湮�� ������ ��

bool promising(int i, int weight, int total) {
	//3. �Ʒ��� �ϼ��Ͻÿ�. 
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
			//4. �Ʒ��� �ϼ��Ͻÿ�. include[i + 1] = false �� ���
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
				//5. �Ʒ��� �ϼ��Ͻÿ�. include[i + 1] = true �� ���
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
	//1��
	printf("%d-���ո� ����\n", N);
	checknode(0, 0);

	//2��
	int sum_weight = 0;
	for (int i = 1; i <= N_ITEMS; i++)
		sum_weight += w[i];
	printf("\n������ ���� %d, �� ���� %d �� �κ���\n", N_ITEMS, W);
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
	printf("\n�� %d �湮�� ����ī���α������ ��� �湮 ��� ��:%.1f\n", TRIES, (double)sum / TRIES);

	return 0;
}
/*�������
6-���ո� ����
���1: (1,2) (2,4) (3,6) (4,1) (5,3) (6,5)
���2: (1,3) (2,6) (3,2) (4,5) (5,1) (6,4)
���3: (1,4) (2,1) (3,5) (4,2) (5,6) (6,3)
���4: (1,5) (2,3) (3,1) (4,6) (5,4) (6,2)

������ ���� 8, �� ���� 52 �� �κ���
item 1,item 2,item 3,item 4,item 7,
item 1,item 4,item 5,item 6,
item 2,item 3,item 5,item 6,
item 3,item 6,item 7,
item 3,item 8,
item 4,item 5,item 7,

�� 20 �湮�� ����ī���α������ ��� �湮 ��� ��:293.4

C:\Users\rlawl\OneDrive\���� ȭ��\�����б�\2�г�\2�б�\�˰��� - ȫö��\Project1_111\x64\Debug\Project1_111.exe(���� ���� 23460��)��(��) ����Ǿ����ϴ�(�ڵ�: 0��).
�� â�� �������� �ƹ� Ű�� ��������...

*/
/*���� ���
6-���ո� ����
���1: (1,2) (2,4) (3,6) (4,1) (5,3) (6,5)
���2: (1,3) (2,6) (3,2) (4,5) (5,1) (6,4)
���3: (1,4) (2,1) (3,5) (4,2) (5,6) (6,3)
���4: (1,5) (2,3) (3,1) (4,6) (5,4) (6,2)

������ ���� 8, �� ���� 52 �� �κ���
item 1,item 2,item 3,item 4,item 7,
item 1,item 4,item 5,item 6,
item 2,item 3,item 5,item 6,
item 3,item 6,item 7,
item 3,item 8,
item 4,item 5,item 7,

�� 20 �湮�� ����ī���α������ ��� �湮 ��� ��:293.4
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/