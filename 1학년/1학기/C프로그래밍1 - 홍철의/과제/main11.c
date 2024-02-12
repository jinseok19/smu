#include <stdio.h>
#include <stdlib.h>

void prob_1() {
	int num1 = 20, num2 = 30;
	int* ptr1 = &num1, * ptr2 = &num2;

	//�Ʒ��� �ϼ��Ͻÿ�
	* ptr1 += 10;
	* ptr2 -= 10;



	printf("num1:%d, *ptr1:%d, num2:%d, *ptr2:%d\n", num1, *ptr1, num2, *ptr2);

	//�Ʒ��� �ϼ��Ͻÿ�
	int *temp;
	temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;


	printf("num1:%d, *ptr1:%d, num2:%d, *ptr2:%d\n", num1, *ptr1, num2, *ptr2);
}
void prob_3() {
	int arr[] = { 1, 2, 3, 4, 5 };
	int* ptr = arr; //*ptr= &(arr[0]);, *ptr= arr+0;

	//�Ʒ��� �ϼ��Ͻÿ�
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
	////�׸� ����
	//int num = 10;
	//int* ptr1 = &num;
	//int* ptr2 = ptr1;

	//(*ptr1)++;
	//(*ptr2)++;

	//1��
	prob_1();

	//3��
	prob_3();

	return 0;
}

/*���� ��°��
num1:30, *ptr1:30, num2:20, *ptr2:20
num1:30, *ptr1:20, num2:20, *ptr2:30
ptr++, arr[]: 2 3 4 5 6

C:\Users\rlawl\OneDrive\���� ȭ��\C code\Project1\x64\Debug\Project1.exe(���μ��� 20088��)��(��) ����Ǿ����ϴ�(�ڵ�: 0 ��).
�� â�� �������� �ƹ� Ű�� ��������...
*/
/*���� ��°��
num1:30, *ptr1:30, num2:20, *ptr2:20
num1:30, *ptr1:20, num2:20, *ptr2:30
ptr++, arr[]: 2 3 4 5 6
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/
