
#include <stdio.h>

#include <stdlib.h>




void scalar_mult(int a[][3], int sclar, int b[][3]);
void transpose(int a[][3], int b[][3]);
void print(int a[][3]);


int main(void)

{

	//문제 1.

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



	//아래를 완성하시오.

	for (i = 1; i < 10; i++) {



		if (list[i] < min)



			min = list[i];



		if (list[i] > max)



			max = list[i];

	}

	printf("최대값: %d, 최소값: %d\n\n", max, min);



	//문제 2

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

		printf("%d행의 합계: %d\n", i, sum);

	}

	//아래를 완성하시오.

	for (j = 0; j < 5; j++) {

		sum = 0;

		for (i = 0; i < 3; i++)

			sum += data[i][j];

		printf("%d열의 합계: %d\n", j, sum);

	}



	//문제 3.

	int a[3][3] = { { 1, 2, 3 },{ 4, 5, 6 },{ 7, 8, 9 } };

	int b[3][3];

	scalar_mult(a, 2, b);

	printf("scalr 곱\n");

	print(b);



	printf("transpose(전치)\n");

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



//아래에 scalar_mult, transpose를 완성하시오.

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


/*실제 출력
list:   41  467  334  500  169  724  478  358  962  464
최대값: 962, 최소값: 41

0행의 합계: 214
1행의 합계: 233
2행의 합계: 254
0열의 합계: 176
1열의 합계: 115
2열의 합계: 153
3열의 합계: 135
4열의 합계: 122
scalr 곱
2 4 6
8 10 12
14 16 18
transpose(전치)
1 4 7
2 5 8
3 6 9
계속하려면 아무 키나 누르십시오 . . .



*/
/*예시 출력
list:   41  467  334  500  169  724  478  358  962  464
최대값: 962, 최소값: 41

0행의 합계: 214
1행의 합계: 233
2행의 합계: 254
0열의 합계: 176
1열의 합계: 115
2열의 합계: 153
3열의 합계: 135
4열의 합계: 122

scalar 곱
2 4 6
8 10 12
14 16 18
transpose(전치)
1 4 7
2 5 8
3 6 9
계속하려면 아무 키나 누르십시오 . . .
*/