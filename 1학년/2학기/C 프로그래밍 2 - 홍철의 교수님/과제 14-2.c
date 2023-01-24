
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char* get_aop(char* a[], int t_num, int c_num, char *p)
{
	*p = *(*(a + t_num - 1) + c_num);
	return a[t_num - 1];
}
char* get_poa(char(*a)[80], int t_num, int c_num, char* p)
{
	*p = *(*(a + t_num - 1) + c_num);
	return a[t_num - 1];
}

int add(int op1, int op2)
{
	return op1 + op2;
}
int subtract(int op1, int op2)
{
	return op1 - op2;
}
int main(void)
{
	char *traffics_aop[] = { "car", "train", "ship", "airplane" };
	char traffics_poa[][80] = { "car", "train", "ship", "airplane" };
	int traffic_num, char_num, size= 4;
	char ch;

	for (int i = 0; i < size; i++)
		printf("%d. %s\n", i + 1, traffics_aop[i]);
	printf("교통수단번호 : ");
	scanf("%d", &traffic_num);
	printf("문자 인덱스: ");
	scanf("%d", &char_num);

	//아래를 완성하시오. get_aop()를 호출하시오.


	//아래를 완성하시오. get_poa()를 호출하시오.



	int op1, op2;
	char str[80];
	printf("정수 계산식: ");
	scanf("%s", str);
	sscanf(str, "%d%c%d", &op1, &ch, &op2);

	//아래를 완성하시오. 함수 포인터 pf()를 정의하고 호출하시오.



	return 0;
}

/*실제 출력결과

*/
/*예시 출력결과
1. car
2. train
3. ship
4. airplane
교통수단번호 : 4
문자 인덱스: 3
교통수단: airplane, 문자: p
교통수단: airplane, 문자: p
정수 계산식: 5-2
5-2= 3
계속하려면 아무 키나 누르십시오 . . .
*/
