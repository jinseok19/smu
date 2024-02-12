#include <stdio.h>
#include <stdlib.h>

void get_2int(int* a, int* b)
{
	//아래를 완성하시오.
	printf("2개의 정수를 입력하시오.: ");
	scanf_s("%d %d", a, b);

}
int add1(int a, int b)
{
	//아래를 완성하시오.
	return a + b;
}
void add2(int* sum, int a, int b)
{
	//아래를 완성하시오.
	*sum = a + b;
	
}
double func(int* a, int* b)
{
	double avg = (*a + *b) / 2.0; //1번
	int tmp;
	//아래를 완성하시오.
	
	tmp = *a;
	*a += *b;
	*b -= tmp;



	return avg;

}
int main(void)
{
	//1번
	int a, b, sum;

	get_2int(&a, &b);
	add2(&sum, a, b);
	printf("합: %d-%d\n", add1(a, b), sum);

	//2번
	double avg = func(&a, &b);
	printf("합:%d, 차: %d, 평균:%.2f\n", a, b, avg);

	return 0;
}


/*실제 출력결과
2개의 정수를 입력하시오.: 15 20
합: 35-35
합:35, 차: 5, 평균:17.50

C:\Users\rlawl\OneDrive\바탕 화면\C code\Project1\x64\Debug\Project1.exe(프로세스 25736개)이(가) 종료되었습니다(코드: 0 개).
이 창을 닫으려면 아무 키나 누르세요...
*/
/*예시 출력결과
2개의 정수를 입력하시오.: 15 20
합: 35-35
합:35, 차: 5, 평균:17.50
계속하려면 아무 키나 누르십시오 . . .
*/
