#include <stdio.h>

int main(void)
{
  #1
  int kor, eng, math, sum;  
  float avg;

  sum=avg=0;

  printf("1. ���� ���� :");
  scanf("%d", &kor);
  printf("2. ���� ���� :");
  scanf("%d", &eng);
  printf("3. ���� ���� :");
  scanf("%d", &math);

  sum = kor + eng + math;
  avg = sum/3.0;
  printf("�� �� : %d\n",sum);
  printf("��� ���� : %.2f\n",avg);

  #2
  int num1, num2, triple;
  double division;

  triple = division = 0;
  
  printf("2�� ������ �Է� :");
  scanf("%d %d",&num1,&num2);
  triple = num1*num1*num1;
  division = (double) num1/ (double) num2;


  printf("������ ���� ��� : [ %d * %d * %d = %d %]\n", num1, num1, num1, triple);
  printf("������ ���� ��� : [ %d / %d = %.3f %]", num1, num2, division);

  
  

  return 0;

  
}