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
	//아래를 완성하시오. 다른 변수를 선언하지 마시오.
	

}
void prob_2(int* ptr, int size) {
	//아래를 완성하시오. 다른 변수를 선언하지 마시오.
	

}
void prob_3(int* ptr, int size) {
	//아래를 완성하시오. 다른 변수를 선언하지 마시오.
	

}
void prob_4(int* p, int *q) {
	int tmp;
	//아래를 완성하시오. 다른 변수를 선언하지 마시오.
	

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

/*실제 출력결과

*/
/*예시 출력결과
arr[]:
9 8 7
6 5 4
계속하려면 아무 키나 누르십시오 . . .
*/
