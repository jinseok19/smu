
#include <stdio.h>

#include <stdlib.h>




void scalar_mult(int a[][3], int sclar, int b[][3]);
void transpose(int a[][3], int b[][3]);
void print(int a[][3]);


int main(void)

{

	//���� 1.

	int list[10];

	int i, j, max, min;



	srand(1);

	printf("list:");

	for (i = 0; i < 10; i++) {

		list[i] = rand() % 1000;

		printf("%5d", list[i]);

	}

	printf("\n");

	max = min = list[0];



	//�Ʒ��� �ϼ��Ͻÿ�.

	for (i = 1; i < 10; i++) {



		if (list[i] < min)



			min = list[i];



		if (list[i] > max)



			max = list[i];

	}

	printf("�ִ밪: %d, �ּҰ�: %d\n\n", max, min);



	//���� 2

	int sum;

	int data[3][5] =

	{

		{ 12, 56, 32, 16, 98 },

		{ 99, 56, 34, 41, 3 },

		{ 65, 3, 87, 78, 21 }

	};



	for (i = 0; i < 3; i++) {

		sum = 0;

		for (j = 0; j < 5; j++)

			sum += data[i][j];

		printf("%d���� �հ�: %d\n", i, sum);

	}

	//�Ʒ��� �ϼ��Ͻÿ�.

	for (j = 0; j < 5; j++) {

		sum = 0;

		for (i = 0; i < 3; i++)

			sum += data[i][j];

		printf("%d���� �հ�: %d\n", j, sum);

	}



	//���� 3.

	int a[3][3] = { { 1, 2, 3 },{ 4, 5, 6 },{ 7, 8, 9 } };

	int b[3][3];

	scalar_mult(a, 2, b);

	printf("scalr ��\n");

	print(b);



	printf("transpose(��ġ)\n");

	transpose(a, b);

	print(b);



	return 0;

}











void print(int a[][3]) {

	int r, c;

	for (r = 0; r < 3; r++) {

		for (c = 0; c < 3; c++)

			printf("%d ", a[r][c]);

		printf("\n");

	}

}



//�Ʒ��� scalar_mult, transpose�� �ϼ��Ͻÿ�.

void scalar_mult(int a[][3], int sclar, int b[][3]) {
	int r, c;
	for (r = 0; r < 3; r++) {
		for (c = 0; c < 3; c++) {
			b[r][c] = a[r][c] * 2;

		}
	}

}

void transpose(int a[][3], int b[][3]) {

	int r, c;
	for (r = 0; r < 3; r++) {
		for (c = 0; c < 3; c++) {
			b[r][c] = a[c][r];
		}
	}



}


/*���� ���
list:   41  467  334  500  169  724  478  358  962  464
�ִ밪: 962, �ּҰ�: 41

0���� �հ�: 214
1���� �հ�: 233
2���� �հ�: 254
0���� �հ�: 176
1���� �հ�: 115
2���� �հ�: 153
3���� �հ�: 135
4���� �հ�: 122
scalr ��
2 4 6
8 10 12
14 16 18
transpose(��ġ)
1 4 7
2 5 8
3 6 9
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .



*/
/*���� ���
list:   41  467  334  500  169  724  478  358  962  464
�ִ밪: 962, �ּҰ�: 41

0���� �հ�: 214
1���� �հ�: 233
2���� �հ�: 254
0���� �հ�: 176
1���� �հ�: 115
2���� �հ�: 153
3���� �հ�: 135
4���� �հ�: 122

scalar ��
2 4 6
8 10 12
14 16 18
transpose(��ġ)
1 4 7
2 5 8
3 6 9
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/