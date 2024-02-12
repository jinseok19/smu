#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 5
#define D1 5
#define D2 4
#define D3 2

//1.
int find_index(int arr[][COLS], int key) {
	//�Ʒ��� �ϼ��Ͻÿ�.
	
	for (int k = 0; k <= ROWS * COLS; k++) {
		if (key == arr[k / COLS][k % COLS])
			return k;
	}
		return -1;
}

//2.
void inverse_chars(char word[], int len)
{
	char tmp;
	int start = 0, end = len - 1;
	while (start < end) {
		//�Ʒ��� �ϼ��Ͻÿ�.
		tmp = word[start];
		word[start] = word[end];
		word[end] = tmp;
		start++;
		end--;

	}

}


//3.
void print(int a[][D2][D1]) {
	for (int i = 0; i < D3; i++) {
		for (int j = 0; j < D2; j++) {
			for (int k = 0; k < D1; k++)
				printf("%5d", a[i][j][k]);
			printf("\n");
		}
		printf("\n");
	}
}

void min_max_swap(int a[][D2][D1]) {
	int min_value, min_index, max_value, max_index;
	int min_i, min_j, min_k;
	int max_i, max_j, max_k;
	int tmp;
	int index;

	min_value = max_value = a[0][0][0];
	min_index = max_index = 0;

	index = 0;
	for (int i = 0; i < D3; i++)
		for (int j = 0; j < D2; j++)
			for (int k = 0; k < D1; k++) {
				if (a[i][j][k] < min_value) {
					min_value = a[i][j][k];
					min_index = index;
				}
				else if (a[i][j][k] > max_value) {
					max_value = a[i][j][k];
					max_index = index;
				}
				index++;
			}

	//�Ʒ��� �ϼ��Ͻÿ�.
	min_i = min_index / (D2 * D1);
	min_j = min_index % (D2 * D1) / D1;
	min_k = min_index % D1;

	max_i = max_index / (D2 * D1);
	max_j = max_index % (D2 * D1) / D1;
	max_k = max_index % D1;
	
	
	tmp = a[min_i][min_j][min_k];
	a[min_i][min_j][min_k] = a[max_i][max_j][max_k];
	a[max_i][max_j][max_k] = tmp;
}

int main(void) {
	int a[ROWS][COLS];
	int i, j;

	//srand((unsigned)time(NULL));
	srand(1);
	for (i = 0; i < ROWS; i++)
		for (j = 0; j < COLS; j++)
			a[i][j] = rand() % 10;
	int index = find_index(a, 5);
	if (index >= 0) {
		i = index / COLS;
		j = index % COLS;
		printf("Ű�� 5�� ����� ���� ���� %d, �ε����� (%d,%d)�̴�\n", a[i][j], i, j);
	}
	else
		printf("Ű�� 5�� ����� ��Ҵ� �����ϴ�.\n");


	char word[] = { 'T', 'i', 'm', 'e', 's' };
	int len = sizeof(word) / sizeof(char);

	printf("������ �ܾ�\n");
	for (int i = 0; i < len; i++)
		printf("%c", word[i]);
	printf("\n");

	inverse_chars(word, len);

	printf("������ �ܾ�\n");
	for (int i = 0; i < len; i++)
		printf("%c", word[i]);
	printf("\n");


	int arr[D3][D2][D1];
	int k;

	//srand(1);
	for (i = 0; i < D3; i++)
		for (j = 0; j < D2; j++)
			for (k = 0; k < D1; k++)
				arr[i][j][k] = rand() % 100 + 1;

	printf("������ �迭: \n");
	print(arr);

	min_max_swap(arr);

	printf("��ȯ���� �迭: \n");
	print(arr);

	return 0;
}


/*�������

Ű�� 5�� ����� ���� ���� 5, �ε����� (2,0)�̴�
������ �ܾ�
Times
������ �ܾ�
semiT
������ �迭:
   92   96   43   28   37
   92    5    3   54   93
   83   22   17   19   96
   48   27   72   39   70

   13   68  100   36   95
	4   12   23   34   74
   65   42   12   54   69
   48   45   63   58   38

��ȯ���� �迭:
   92   96   43   28   37
   92    5  100   54   93
   83   22   17   19   96
   48   27   72   39   70

   13   68    3   36   95
	4   12   23   34   74
   65   42   12   54   69
   48   45   63   58   38


C:\Users\rlawl\OneDrive\���� ȭ��\C code\Project1\x64\Debug\Project1.exe(���μ��� 43064��)��(��) ����Ǿ����ϴ�(�ڵ�: 0 ��).
�� â�� �������� �ƹ� Ű�� ��������...
/* �������
Ű�� 5�� ����� ���� ���� 5, �ε����� (2,0)�̴�
������ �ܾ�
Times
������ �ܾ�
semiT
������ �迭:
   92   96   43   28   37
   92    5    3   54   93
   83   22   17   19   96
   48   27   72   39   70

   13   68  100   36   95
	4   12   23   34   74
   65   42   12   54   69
   48   45   63   58   38

��ȯ���� �迭:
   92   96   43   28   37
   92    5  100   54   93
   83   22   17   19   96
   48   27   72   39   70

   13   68    3   36   95
	4   12   23   34   74
   65   42   12   54   69
   48   45   63   58   38

����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/
/*����
��������� srand(1)���� �õ尪�� �����ؼ� ���� ������ �߻��մϴ�
��, �ٸ� ȯ���� ������� �ʴ� �̻� ���ð���� ���ƾ� �մϴ�.

*/