#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int binary_search(int key, int list[], int low, int high) {
	int middle;
	while (low <= high) { 				// 아직 키들이 남아 있으면
		middle = (low + high) / 2;
		if (key == list[middle])
			return middle; 	// 탐색 성공
		else if (key < list[middle])
			high = middle - 1; 	// 오른쪽 부분리스트 탐색
		else
			low = middle + 1; 	// 왼쪽 부분리스트 탐색
	}
	//아래를 완성하시오.
	//location is the index of the first element greater than or equal to key	
	return low;

}

void prob_2() {
	int i, j, n = 20, m = 10;
	int arr[] = { 1, 5, 7, 9, 8, 2, 4, 6, 0, 1, 5, 13, 7, 9, 8, 12, 4, 6, 10, 3 };
	int small[11], size;

	small[0] = arr[0];

	size = 1;
	for (i = 1; i < n; i++) {
		if (size <= m)
			j = size - 1;
		else
			j = m - 1;
		//아래를 완성하시오.
		while (j >= 0 && arr[i] < small[j]) {
			small[j + 1] = small[j];
			j--;
		}
		small[j + 1] = arr[i];
		if (size < m)
			size++;
	}

	printf("2-1번\n");
	for (i = 0; i < m; i++)
		printf("%d ", small[i]);
	printf("\n");

	int key, high, location;
	for (i = 1; i < n; i++) {
		key = arr[i];
		if (i > m)
			high = m - 1;
		else
			high = i - 1;
		location = binary_search(key, arr, 0, high);
		if (location < m) {
			//아래를 완성하시오.
			for (j = i - 1; j >= location; j--) {
				arr[j + 1] = arr[j];
			}
			arr[location] = key;

		}
	}
	printf("2-2번\n");
	for (i = 0; i < m; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
void prob_3() {
	int n = 5;
	int i, j, k;

	char str[] = "01234";
	printf("\n3번\n");
	//아래를 완성하시오.
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			for (k = j + 1; k < n; k++) {
				printf("%c%c%c, ",str[i],str[j],str[k]);

			}
				
		}
			
	}
		

	printf("\n");
}
void prob_6() {
	int i, n = 10;
	int max, min;
	int arr[] = { 1, 5, 3, 7, 9, 8, 2, 4, 6, 0 };

	if (arr[0] < arr[1]) {
		min = arr[0]; max = arr[1];
	}
	else {
		min = arr[1]; max = arr[0];
	}
	for (i = 2; i <= n - 1; i += 2) {// 입력 2개당 3번 비교
		//아래를 완성하시오.
		if (arr[i] < arr[i + 1]) {
			if (arr[i] < min) {
				min = arr[i];
			}
			if (arr[i + 1] > max) {
				max = arr[i + 1];
			}

		}
		else {
			if (arr[i + 1] < min) {
				min = arr[i + 1];
			}
			if (arr[i] > max) {
				max = arr[i];
			}
		}


	}
printf("\n6번\n");
printf("min:%d, max:%d\n", min, max);
	
}
int main(void)
{
	//2번
	prob_2();

	//3번
	prob_3();

	//6번
	prob_6();

	return 0;
}
/*예시 출력
2-1번
0 1 1 2 3 4 4 5 5 6
2-2번
0 1 1 2 3 4 4 5 5 6

3번
012, 013, 014, 023, 024, 034, 123, 124, 134, 234,

6번
min:0, max:9
계속하려면 아무 키나 누르십시오 . . .
*/
/*실제출력
2-1번
0 1 1 2 3 4 4 5 5 6
2-2번
0 1 1 2 3 4 4 5 5 6

3번
012, 013, 014, 023, 024, 034, 123, 124, 134, 234,

6번
min:0, max:9

C:\Users\rlawl\OneDrive\바탕 화면\상명대학교\2학년\2학기\알고리즘 - 홍철의\Project1\x64\Debug\Project1.exe(프로세스 18340개)이(가) 종료되었습니다(코드: 0개).
이 창을 닫으려면 아무 키나 누르세요...




*/