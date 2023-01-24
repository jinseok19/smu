#include <stdio.h>
#include <stdlib.h>

void prob_1() {
	int num1 = 20, num2 = 30;
	int* ptr1 = &num1, * ptr2 = &num2;

	//아래를 완성하시오
	* ptr1 += 10;
	* ptr2 -= 10;



	printf("num1:%d, *ptr1:%d, num2:%d, *ptr2:%d\n", num1, *ptr1, num2, *ptr2);

	//아래를 완성하시오
	int *temp;
	temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;


	printf("num1:%d, *ptr1:%d, num2:%d, *ptr2:%d\n", num1, *ptr1, num2, *ptr2);
}
void prob_3() {
	int arr[] = { 1, 2, 3, 4, 5 };
	int* ptr = arr; //*ptr= &(arr[0]);, *ptr= arr+0;

	//아래를 완성하시오
	for (int i = 0; i < 5; i++)
	{
		(*ptr)++;
		ptr++;

	}



	printf("ptr++, arr[]: ");
	for (int i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	printf("\n");

}
int main(void)
{
	////그림 예제
	//int num = 10;
	//int* ptr1 = &num;
	//int* ptr2 = ptr1;

	//(*ptr1)++;
	//(*ptr2)++;

	//1번
	prob_1();

	//3번
	prob_3();

	return 0;
}

/*실제 출력결과
num1:30, *ptr1:30, num2:20, *ptr2:20
num1:30, *ptr1:20, num2:20, *ptr2:30
ptr++, arr[]: 2 3 4 5 6

C:\Users\rlawl\OneDrive\바탕 화면\C code\Project1\x64\Debug\Project1.exe(프로세스 20088개)이(가) 종료되었습니다(코드: 0 개).
이 창을 닫으려면 아무 키나 누르세요...
*/
/*예시 출력결과
num1:30, *ptr1:30, num2:20, *ptr2:20
num1:30, *ptr1:20, num2:20, *ptr2:30
ptr++, arr[]: 2 3 4 5 6
계속하려면 아무 키나 누르십시오 . . .
*/
