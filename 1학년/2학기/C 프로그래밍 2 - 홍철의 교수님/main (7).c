
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 80

void prob_1(char* s, int f[])
{
	//새로운 변수를 선언하지 마시오.
	//문자처리 라이브러리를 이용하시오.
	//아래를 완성하시오.
	while (*s != '\0') {
		if (isdigit(*s)) {
			f[*s - '0']++;
			s++;
		}
		else
			s++;
		
	};

}
void prob_2(char* s1, char* s2)
{
	//새로운 변수를 선언하지 마시오.
	//strcat()과 같은 문자열 처리 라이브러리를 이용하지 마시오.
	//아래를 완성하시오.
	while (*s1 !='\0')
	{
		s1++;
	}
	while (*s2 !='\0')
	{
		*s1 = *s2;
		s2++;
		s1++;
	}
	
}
void prob_3(int d[], int size)
{
	int i;
	//새로운 변수를 선언하지 마시오.
	//아래를 완성하시오.
	for (i = 0; i < size; i++) {
		switch (d[i]) {
		case 1:
			printf("일");
			break;
		case 2:
			printf("이");
			break;
		case 3:
			printf("삼");
			break;
		case 4:
			printf("사");
			break;
		case 5:
			printf("오");
			break;
		case 6:
			printf("육");
			break;
		case 7:
			printf("칠");
			break;
		case 8:
			printf("팔");
			break;
		case 9:
			printf("구");
		default:
			continue;

		}
		switch (i) {
		case 0:
			printf("천");
			break;
		case 1:
			printf("백");
			break;
		case 2:
			printf("십");
			break;
		}
	}
		printf("\n");

}
int main(void)
{
	//1번
	char str[SIZE];
	int freq[10] = { 0 };
	printf("문자열을 입력하시오: ");
	gets_s(str, sizeof(str));

	prob_1(str, freq);
	for (int i = 0; i < 10; i++) {
		if (freq[i])
			printf("(%d,%d)", i, freq[i]);
	}
	printf("\n");

	//2번
	char str1[SIZE] = "C 언어 ", * str2 = "사랑합니다.";
	prob_2(str1, str2);
	printf("두 문자열을 붙인 결과: %s\n", str1);

	//3번
	int i, j;
	int num;
	int digits[4];
	printf("10000보다 작은 양의 정수 입력: ");
	scanf_s("%d", &num);
	//정수를 4자리수 배열로 바꿈, 예로 504 ->{0, 5, 0, 4}
	for (i = 1000, j = 0; i > 0; i /= 10, j++) {
		digits[j] = num / i;
		num %= i;
	}
	prob_3(digits, 4);

	return 0;
}

/*실제 출력결과
문자열을 입력하시오: 125-589
(1,1)(2,1)(5,2)(8,1)(9,1)
두 문자열을 붙인 결과: C 언어 사랑합니다.
10000보다 작은 양의 정수 입력: 504
오백사

C:\Users\rlawl\OneDrive\바탕 화면\C code\Project1\x64\Debug\Project1.exe(프로세스 16496개)이(가) 종료되었습니다(코드: 0 개).
이 창을 닫으려면 아무 키나 누르세요...
*/
/*예시 출력결과
문자열을 입력하시오: 125-589
(1,1)(2,1)(5,2)(8,1)(9,1)
두 문자열을 붙인 결과: C 언어 사랑합니다.
10000보다 작은 양의 정수 입력: 504
오백사
계속하려면 아무 키나 누르십시오 . . .
*/
