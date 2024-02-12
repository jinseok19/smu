
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int fib_recur(int n) //��ȯ �˰������� �Ǻ���ġ �� ���
{
	//�Ʒ��� �ϼ��Ͻÿ�.
	if (n <= 1)
		return n;
	return fib_recur(n - 1) + fib_recur(n - 2);
	

}
int fib_iter(int n)//�Ǻ���ġ �� ������ ���� �迭 ���
{
	int* arr = new int[n + 1];
	arr[0] = 0, arr[1] = 1;
	//�Ʒ��� �ϼ��Ͻÿ�.
	for (int i = 2; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}


	int result = arr[n];
	delete[] arr;
	return result;
}
int main()
{
	clock_t start, stop;
	double duration;
	int n;

	start = clock(); //��������
	n = fib_iter(40);
	stop = clock(); //��������
	duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
	printf("�ݺ�: fib(40)= %d, ����ð��� %f���Դϴ�.\n", n, duration);

	start = clock(); //��������
	n = fib_recur(40);
	stop = clock(); //��������
	duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
	printf("��ȯ: fib(40)= %d, ����ð��� %f���Դϴ�.\n", n, duration);

	return 0;
}
/*������°��
�ݺ�: fib(40)= 102334155, ����ð��� 0.000000���Դϴ�.
��ȯ: fib(40)= 102334155, ����ð��� 0.943000���Դϴ�.

C:\Users\rlawl\OneDrive\���� ȭ��\�����б�\2�г�\�ڷᱸ��\03_15\x64\Debug\03_15.exe(���μ��� 22268��)��(��) ����Ǿ����ϴ�(�ڵ�: 0��).
�� â�� �������� �ƹ� Ű�� ��������...

*/
/*������°��
�ݺ�: fib(40)= 102334155, ����ð��� 0.000000���Դϴ�.
��ȯ: fib(40)= 102334155, ����ð��� 7.426000���Դϴ�.
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/