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
	//아래를 완성하시오.
	
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
		//아래를 완성하시오.
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

	//아래를 완성하시오.
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
		printf("키값 5가 저장된 최초 값은 %d, 인덱스는 (%d,%d)이다\n", a[i][j], i, j);
	}
	else
		printf("키값 5가 저장된 요소는 없습니다.\n");


	char word[] = { 'T', 'i', 'm', 'e', 's' };
	int len = sizeof(word) / sizeof(char);

	printf("본래의 단어\n");
	for (int i = 0; i < len; i++)
		printf("%c", word[i]);
	printf("\n");

	inverse_chars(word, len);

	printf("역순의 단어\n");
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

	printf("최초의 배열: \n");
	print(arr);

	min_max_swap(arr);

	printf("교환후의 배열: \n");
	print(arr);

	return 0;
}


/*실제출력

키값 5가 저장된 최초 값은 5, 인덱스는 (2,0)이다
본래의 단어
Times
역순의 단어
semiT
최초의 배열:
   92   96   43   28   37
   92    5    3   54   93
   83   22   17   19   96
   48   27   72   39   70

   13   68  100   36   95
	4   12   23   34   74
   65   42   12   54   69
   48   45   63   58   38

교환후의 배열:
   92   96   43   28   37
   92    5  100   54   93
   83   22   17   19   96
   48   27   72   39   70

   13   68    3   36   95
	4   12   23   34   74
   65   42   12   54   69
   48   45   63   58   38


C:\Users\rlawl\OneDrive\바탕 화면\C code\Project1\x64\Debug\Project1.exe(프로세스 43064개)이(가) 종료되었습니다(코드: 0 개).
이 창을 닫으려면 아무 키나 누르세요...
/* 예시출력
키값 5가 저장된 최초 값은 5, 인덱스는 (2,0)이다
본래의 단어
Times
역순의 단어
semiT
최초의 배열:
   92   96   43   28   37
   92    5    3   54   93
   83   22   17   19   96
   48   27   72   39   70

   13   68  100   36   95
	4   12   23   34   74
   65   42   12   54   69
   48   45   63   58   38

교환후의 배열:
   92   96   43   28   37
   92    5  100   54   93
   83   22   17   19   96
   48   27   72   39   70

   13   68    3   36   95
	4   12   23   34   74
   65   42   12   54   69
   48   45   63   58   38

계속하려면 아무 키나 누르십시오 . . .
*/
/*참고
실제출력은 srand(1)으로 시드값을 고정해서 같은 난수가 발생합니다
즉, 다른 환경을 사용하지 않는 이상 예시결과와 같아야 합니다.

*/