
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

struct point
{
	int x, y;
};

void get_max_min(int* p, int* last_p, int* max, int* min)
{
	//���ο� ������ �������� ���ÿ�.
	//�迭�� ����(3x5)�� ����� ������� ���ÿ�.
	*max = *min = *p++;

	//�Ʒ��� �ϼ��Ͻÿ�.
	while (p <= last_p) {
		if (*max < *p) {
			*max = *p;
		}
		else if (*min > *p) {
			*min = *p;
		}
		p++;
	}
}

double get_distance(point* p, int size)
{
	//���ο� ������ �������� ���ÿ�.
	int i, j;
	double tmp, distance = 0.0;

	//�Ʒ��� �ϼ��Ͻÿ�.�����Լ��� �̿��Ͻÿ�.
	for (i = 0; i <= size; i++) {
		for (j = i+1; j < size; j++) {
			tmp = sqrt(pow(abs(p[j].x - p[i].x), 2) + pow(abs(p[j].y - p[i].y), 2));
			if (distance < tmp) {
				distance = tmp;
			}
			
				
			
		}
		
	}
	

	return distance;
}
int main(void)
{
	int list[3][5];
	int i, j, max, min;

	//���� 1.
	srand(1);
	printf("list:\n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 5; j++) {
			list[i][j] = rand() % 100 + 101;
			printf("%5d", list[i][j]);
		}
		printf("\n");
	}
	get_max_min(*list, *(list + 2) + 4, &max, &min);
	printf("�ִ밪: %d, �ּҰ�: %d\n", max, min);

	//���� 2.
	point point_arr[5] =
	{
		3, 5,
		4, 9,
		1, 9,
		6, 2,
		8, 3,
	};

	printf("\n�ִ� �Ÿ�: %.2f\n", get_distance(point_arr, 5));

	return 0;
}

/*������°��
list:
  142  168  135  101  170
  125  179  159  163  165
  106  146  182  128  162
�ִ밪: 182, �ּҰ�: 101

�ִ� �Ÿ�: 9.22

C:\Users\rlawl\OneDrive\���� ȭ��\�����б�\2�г�\�ڷᱸ��\03_22\Project1\x64\Debug\Project1.exe(���μ��� 55068��)��(��) ����Ǿ����ϴ�(�ڵ�: 0��).
�� â�� �������� �ƹ� Ű�� ��������...
*/
/*
���� ���
list:
  142  168  135  101  170
  125  179  159  163  165
  106  146  182  128  162
�ִ밪: 182, �ּҰ�: 101

�ִ� �Ÿ�: 9.22
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/