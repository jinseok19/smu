
#include <stdio.h>

//main.c�� �������� op�� extern �� ����Ͽ� �ܺ� ����
extern int op;


int add() {
	//static Ű���带 ����Ͽ� ���� ���� sum �������� �ܺο��� ���� op�� sum�� ���� �� sum ��ȯ
	static int sum;
	sum += op;
	return sum;


}