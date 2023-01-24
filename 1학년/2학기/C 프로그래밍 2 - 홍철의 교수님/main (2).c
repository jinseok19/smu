#include <stdio.h>
#include <stdlib.h>

//1�� �Լ��� �ϼ��Ͻÿ�.
void prob_1(int* p1, int* p2, int* p3) {
	int tmp;

	//�Ʒ��� �ϼ��Ͻÿ�
	tmp = *p1;
	*p1 = *p2;
	*p2 = *p3;
	*p3 = tmp;
}

double prob_2(int* p, int size) {
	int i, sum = 0;
	//2�� �Լ��� �ϼ��Ͻÿ�.
	for (i = 0; i < size; i++) {
		sum += p[i * size];
	}


	return (double)sum / size;
}



double prob_3(int* p, int* q, int* sum) {
	int cnt;//�迭�� ũ��

	//3�� �Լ��� �ϼ��Ͻÿ�. ����� ������� ���ÿ�,���� ����� ���ϱ� ���Ͽ� �迭 ũ�� 16
	//�迭�� ũ�⸦ �Լ��ȿ� ����Ͻÿ�.
	cnt = q - p;
	while (p < q) {
		*sum += *p++;

	}
	return (double)*sum / cnt;
}
int main(void) {
	//1��
	int n1 = 3, n2 = 6, n3 = 9;
	printf("1�� ��: n1:%d, n2:%d, n3:%d\n", n1, n2, n3);
	prob_1(&n1, &n2, &n3);
	printf("1�� ��: n1:%d, n2:%d, n3:%d\n", n1, n2, n3);

	//2��
	int k = 1, a[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			a[i][j] = k++;
		}
	}
	for (int i = 0; i < 4; i++)
		printf("%d��° �� ���: %.2f\n", i, prob_2(a[0] + i, 4));

	//3��
	int sum = 0;
	double avg = prob_3((int*)a, (int*)a + 16, &sum);
	printf("�迭 a�� ��: %d, ���: %.2f\n", sum, avg);

	return 0;
}

/*���� ��°��
1�� ��: n1:3, n2:6, n3:9
1�� ��: n1:6, n2:9, n3:3
0��° �� ���: 7.00
1��° �� ���: 8.00
2��° �� ���: 9.00
3��° �� ���: 10.00
�迭 a�� ��: 136, ���: 8.50

C:\Users\rlawl\OneDrive\���� ȭ��\C code\Project1\x64\Debug\Project1.exe(���μ��� 25472��)��(��) ����Ǿ����ϴ�(�ڵ�: 0 ��).
�� â�� �������� �ƹ� Ű�� ��������...
*/
/*���� ��°��
1�� ��: n1:3, n2:6, n3:9
1�� ��: n1:6, n2:9, n3:3
0��° �� ���: 7.00
1��° �� ���: 8.00
2��° �� ���: 9.00
3��° �� ���: 10.00
�迭 a�� ��: 136, ���: 8.50
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/
