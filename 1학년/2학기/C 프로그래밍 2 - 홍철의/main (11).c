
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void f1(int a[][2][2])
{
	printf("%d ", a[1][1][1] );
	//아래에 추가로 a[1][1][1]을 출력하는 6개의 다른 문장을 적으시오.



	printf("\n");
}
void f2(int* arr, int size, int* min_idx, int* max_idx) {
	*max_idx = *min_idx = 0;
	for (int i = 1; i < size; i++) {
		//아래를 완성하시오.


	}
}
int main(void)
{
	//1번
	int arr[2][2][2] = { 0,1,2,3,4,5,6,7 };
	f1(arr);

	//2번
	int min_idx, max_idx;
	f2(**arr, sizeof(arr) / sizeof(int), &min_idx, &max_idx);
	printf("최소값: %d, 최대값: %d\n", arr[min_idx/2/2][min_idx/2%2][min_idx%2], arr[max_idx/2/2][max_idx/2%2][max_idx%2]);

	int a[3][2] = { 1,2,3,4,5,6 };
	//3번;
	int i, j;
	int *p1[3];
	// p1의 포인터 연산자를 이용하여 배열 a의 모든 요소에 1을 더하시오.



	//4번
	int(*p2)[2];
	// p2의 포인터 연산자를 이용하여 배열 a의 모든 요소에 1을 더하시오.


	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}

	return 0;
}
/*실제 출력결과

*/
/*예시 출력결과
7 7 7 7 7 7 7
최소값: 0, 최대값: 7
3 4
5 6
7 8
계속하려면 아무 키나 누르십시오 . . .
*/
