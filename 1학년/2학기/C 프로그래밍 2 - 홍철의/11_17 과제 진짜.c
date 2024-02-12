
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void f1(int a[][2][2])
{
	printf("%d ", a[1][1][1]);
	//�Ʒ��� �߰��� a[1][1][1]�� ����ϴ� 6���� �ٸ� ������ �����ÿ�.

	printf("%d ", (*(a + 1))[1][1]);
	printf("%d ", (*(a[1] + 1))[1]);
	printf("%d ", *(a[1][1] + 1));
	printf("%d ", (*((*(a + 1)) + 1))[1]);
	printf("%d ", *((*(a + 1))[1] + 1));
	printf("%d ", *((*((*(a + 1)) + 1)) + 1));

	printf("\n");
}
void f2(int* arr, int size, int* min_idx, int* max_idx) {
	*max_idx = *min_idx = 0;
	for (int i = 1; i < size; i++) {
		//�Ʒ��� �ϼ��Ͻÿ�.
		if (*(arr + i - 1) < *(arr + i))		
			*max_idx = i;
		if (*(arr + i - 1) > *(arr + i))		
			*min_idx = i;

	}
}
int main(void)
{
	//1��
	int arr[2][2][2] = { 0,1,2,3,4,5,6,7 };
	f1(arr);

	//2��
	int min_idx, max_idx;
	f2(**arr, sizeof(arr) / sizeof(int), &min_idx, &max_idx);
	printf("�ּҰ�: %d, �ִ밪: %d\n", arr[min_idx / 2 / 2][min_idx / 2 % 2][min_idx % 2], arr[max_idx / 2 / 2][max_idx / 2 % 2][max_idx % 2]);

	int a[3][2] = { 1,2,3,4,5,6 };
	//3��;
	int i, j;
	int* p1[3];
	// p1�� ������ �����ڸ� �̿��Ͽ� �迭 a�� ��� ��ҿ� 1�� ���Ͻÿ�.

	for (i = 0; i < 3; i++)
		*(p1 + i) = *(a + i);

	for (i = 0; i < 3; i++)		
	{
		for (j = 0; j < 2; j++)
		{
			(*(*(p1 + i) + j))++;
		}
	}

	//4��
	int(*p2)[2];
	// p2�� ������ �����ڸ� �̿��Ͽ� �迭 a�� ��� ��ҿ� 1�� ���Ͻÿ�.
	p2 = a;
	for (i = 0; i < 3; i++) {
		
		for (j = 0; j < 2; j++)
			(*(*(p2 + i) + j))++;
	}



	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}

	return 0;
}
/*���� ��°��
7 7 7 7 7 7 7
�ּҰ�: 0, �ִ밪: 7
3 4
5 6
7 8

C:\Users\rlawl\OneDrive\���� ȭ��\C code\Project1\x64\Debug\Project1.exe(���μ��� 35428��)��(��) ����Ǿ����ϴ�(�ڵ�: 0 ��).
�� â�� �������� �ƹ� Ű�� ��������...
*/
/*���� ��°��
7 7 7 7 7 7 7
�ּҰ�: 0, �ִ밪: 7
3 4
5 6
7 8
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/
