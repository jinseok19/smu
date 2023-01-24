
#include <stdio.h>
#include <stdlib.h>

//1번 함수 구현
int get_gcd(int n1, int n2)
{
	int i;
	for (i = n1 >= n2 ? n2 : n1; i > 1; i--)
	{//아래를 완성하시오
		if (n1 % i == 0 && n2 % i == 0) {
			return i;
		}

	}
	return 1;
}
//2번 함수 구현
int get_n(int n)
{
	int k = 0, result = 1;
	//아래를 완성하시오
	while (result <= n) {
		result = 2 << k;
		k++;
	}
	return k-1;
}
//3번 함수 구현
const int BREAD = 500;
const int SNACK = 700;
const int DRINK = 400;

void get_cases(int money)
{
	int i, j, k;

	for (i = 1; i < money / BREAD; i++)
	{//아래를 완성하시오
		for (j = 1; j < money / SNACK; j++) {

			for (k = 1; k < money / DRINK; k++) {
				if (BREAD * i + SNACK * j + DRINK * k == money) {
					printf("크림빵 %d개, 새우깡 %d개, 콜  라 %d개\n", i, j, k);

				}

			}

		}


	}
	
}

int main(void)
{
	//1
	int n1, n2;

	printf("두 개의 정수 입력 : ");
	scanf_s("%d %d", &n1, &n2);
	printf("두 수의 최대공약수 : %d\n\n", get_gcd(n1, n2));

	//2번
	int n;

	printf("상수 n 입력: ");
	scanf_s("%d", &n);
	printf("공식을 만족하는 k의 최댓값은 %d\n\n", get_n(n));

	//3번
	int money = 3500;

	printf("현재 소유하고 있는 금액: %d\n", money);
	get_cases(money);

	return 0;
}

/*실제 출력 결과
두 개의 정수 입력 : 6 9
두 수의 최대공약수 : 3

상수 n 입력: 256
공식을 만족하는 k의 최댓값은 8

현재 소유하고 있는 금액: 3500
크림빵 1개, 새우깡 2개, 콜  라 4개
크림빵 2개, 새우깡 3개, 콜  라 1개
크림빵 4개, 새우깡 1개, 콜  라 2개

C:\Users\rlawl\OneDrive\바탕 화면\C code\Project1\x64\Debug\Project1.exe(프로세스 25960개)이(가) 종료되었습니다(코드: 0 개).
이 창을 닫으려면 아무 키나 누르세요...
*/
/*예시 출력 결과
두 개의 정수 입력 : 6 9
두 수의 최대공약수 : 3

상수 n 입력: 256
공식을 만족하는 k의 최댓값은 8

현재 소유하고 있는 금액: 3500
크림빵 1개, 새우깡 2개, 콜  라 4개
크림빵 2개, 새우깡 3개, 콜  라 1개
크림빵 4개, 새우깡 1개, 콜  라 2개
계속하려면 아무 키나 누르십시오 . . .
*/
