#include <stdio.h>
#include <stdlib.h>

#define ROW 2
#define COL 3
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

void print_arr(int arr[][COL]) 
{
	printf("arr[]:\n");
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}

void prob_1(int *ptr, int size) {
	//�Ʒ��� �ϼ��Ͻÿ�. �ٸ� ������ �������� ���ÿ�.
	

}
void prob_2(int* ptr, int size) {
	//�Ʒ��� �ϼ��Ͻÿ�. �ٸ� ������ �������� ���ÿ�.
	

}
void prob_3(int* ptr, int size) {
	//�Ʒ��� �ϼ��Ͻÿ�. �ٸ� ������ �������� ���ÿ�.
	

}
void prob_4(int* p, int *q) {
	int tmp;
	//�Ʒ��� �ϼ��Ͻÿ�. �ٸ� ������ �������� ���ÿ�.
	

}
int main(void)
{
	int arr[][COL] = { {1, 2, 3,}, {4, 5, 6} };
	int size = ROW * COL;

	prob_1((int*)arr, size);
	prob_2((int*)arr+1, size);
	prob_3((int*)arr-1, size);
	prob_4((int*)arr, (int*)arr+size);

	print_arr(arr);

	return 0;
}

/*���� ��°��

*/
/*���� ��°��
arr[]:
9 8 7
6 5 4
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/
