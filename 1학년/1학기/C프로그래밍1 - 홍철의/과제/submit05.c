#include <stdio.h>



int main(void) {
	
	//1번
	int a, b, c, max, min;
	max = 0;
	min = 100;
	printf("3개의 정수를 입력하시오: ");
	scanf("%d %d %d", &a, &b, &c);

	if (a > b && a>c) {
	max = a;
	}
	else if (b > a && b > c) {
	max = b;
	}
	else {
	max = c;
	}

	if (a < b && a < c) {
	min = a;
	}
	else if (b < a && b < c) {
	min = b;
	}
	else {
	min = c;
	}
	printf("최대값: %d, 최소값: %d\n", max, min);

	printf("\n");
	
	//2
	unsigned char num1 = 3;

	num1 = num1 << 3;
	num1 = num1 >> 2;
	printf("3*8/4= %u\n", num1);

	printf("\n");
	
	
	//3
	int k;
	printf("정수 입력: ");
	scanf("%d", &k);

	k = ~k;
	k++;
	printf("부호를 바꾼 결과: %d\n", k);

	return 0;

}
/*실제 출력 결과
3개의 정수를 입력하시오: 12 33 54
최대값: 54, 최소값: 12

3*8/4= 6

정수 입력: 5
부호를 바꾼 결과: -5
계속하려면 아무 키나 누르십시오 . . .
*/

/*예시 출력 결과
3개의 정수를 입력하시오: 12 33 54
최대값: 54, 최소값: 12

3*8/4= 6

정수 입력: 5
부호를 바꾼 결과: -5
계속하려면 아무 키나 누르십시오 . . .
*/