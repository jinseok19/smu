#include <stdio.h>

int main(void)
{
  #1
  int kor, eng, math, sum;  
  float avg;

  sum=avg=0;

  printf("1. 국어 점수 :");
  scanf("%d", &kor);
  printf("2. 영어 점수 :");
  scanf("%d", &eng);
  printf("3. 수학 점수 :");
  scanf("%d", &math);

  sum = kor + eng + math;
  avg = sum/3.0;
  printf("총 점 : %d\n",sum);
  printf("평균 점수 : %.2f\n",avg);

  #2
  int num1, num2, triple;
  double division;

  triple = division = 0;
  
  printf("2개 정수값 입력 :");
  scanf("%d %d",&num1,&num2);
  triple = num1*num1*num1;
  division = (double) num1/ (double) num2;


  printf("세제곱 연산 결과 : [ %d * %d * %d = %d %]\n", num1, num1, num1, triple);
  printf("나눗셈 연산 결과 : [ %d / %d = %.3f %]", num1, num2, division);

  
  

  return 0;

  
}