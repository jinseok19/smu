#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

int list[MAX_SIZE];
//이진탐색-반복 버젼
int binary_iterative(int key, int low, int high, int* cnt) {
    int middle;

    while (low <= high) {
        (*cnt)++;
        middle = (low + high) / 2;
        if (key == list[middle])
            return middle; 	// 탐색 성공
        else if (key < list[middle])
            high = middle - 1; 	// 오른쪽 부분리스트 탐색
        else
            low = middle + 1; // 왼쪽 부분리스트 탐색
    }
    return -1; 					// 탐색 실패
}

//이진탐색-순환 버젼
int binary_recursive(int key, int low, int high, int* cnt) {
    int middle;
    if (low <= high) {
        //아래를 완성하시오.

        (*cnt)++;
        int middle = (low + high) / 2;

        if (key == list[middle]) {
            return middle; // 탐색 성공
        }
        else if (key < list[middle]) {
            return binary_recursive(key, low, middle - 1, cnt); // 왼쪽 부분 리스트 탐색
        }
        else {
            return binary_recursive(key, middle + 1, high, cnt); // 오른쪽 부분 리스트 탐색
        }
    }


    return -1; 					// 탐색 실패
}

//보간탐색-반복 버젼
int interpolation_iterative(int key, int low, int high, int* cnt) {
    int middle;

    while ((list[high] >= key) && (key > list[low])) {
        (*cnt)++;
        middle = (int)((float)(key - list[low]) / (list[high] - list[low]) * (high - low) + low);
        if (key == list[middle])
            low = middle;
        else if (key < list[middle])
            high = middle - 1;
        else //if (key > list[middle]) 
            low = middle + 1;
    }
    if (list[low] == key) return(low);  // 탐색성공
    else return -1;  // 탐색실패
}

//보간탐색-순환 버젼
int interpolation_recursive(int key, int low, int high, int* cnt) {
    int middle;
    if ((list[high] >= key) && (key > list[low])) {
        //아래를 완성하시오.
        (*cnt)++;
        int middle = (int)((float)(key - list[low]) / (list[high] - list[low]) * (high - low) + low);

        if (key == list[middle]) {
            return middle; // 탐색 성공
        }
        else if (key < list[middle]) {
            return interpolation_recursive(key, low, middle - 1, cnt); // 왼쪽 부분 리스트 탐색
        }
        else {
            return interpolation_recursive(key, middle + 1, high, cnt); // 오른쪽 부분 리스트 탐색
        }
    }

    
    if (list[low] == key) return(low);  // 탐색성공
    else return -1;  // 탐색실패
}
int compare(const void* v1, const void* v2)	// 비교함수 정의
{
    int cmpvalue1, cmpvalue2;

    cmpvalue1 = *(int*)v1;
    cmpvalue2 = *(int*)v2;

    return cmpvalue1 - cmpvalue2;	// 오름차순 정렬
    //return cmpvalue2 - cmpvalue1;	// 내림차순 정렬
}
int main(void)
{
    int key;
    //srand((unsigned)time(NULL));
    for (int i = 0; i < MAX_SIZE; i++)
        list[i] = rand() % 10000;
    qsort(list, MAX_SIZE, sizeof(int), compare);
    int index, cnt;

    key = 1000;
    printf("\n탐색 키: %d\n", key);
    cnt = 0;
    index = binary_iterative(key, 0, MAX_SIZE - 1, &cnt);
    printf("반복 이진 탐색 인덱스: %d, 비교횟수: %d\n", index, cnt);
    cnt = 0;
    index = binary_recursive(key, 0, MAX_SIZE - 1, &cnt);
    printf("순환 이진 탐색 인덱스: %d, 비교횟수: %d\n", index, cnt);
    cnt = 0;
    index = interpolation_iterative(key, 0, MAX_SIZE - 1, &cnt);
    printf("반복 보간 탐색 인덱스: %d, 비교횟수: %d\n", index, cnt);
    cnt = 0;
    index = interpolation_recursive(key, 0, MAX_SIZE - 1, &cnt);
    printf("순환 보간 탐색 인덱스: %d, 비교횟수: %d\n", index, cnt);

    key = 0;
    printf("\n탐색 키: %d\n", key);
    cnt = 0;
    index = binary_iterative(key, 0, MAX_SIZE - 1, &cnt);
    printf("반복 이진 탐색 인덱스: %d, 비교횟수: %d\n", index, cnt);
    cnt = 0;
    index = binary_recursive(key, 0, MAX_SIZE - 1, &cnt);
    printf("순환 이진 탐색 인덱스: %d, 비교횟수: %d\n", index, cnt);
    cnt = 0;
    index = interpolation_iterative(key, 0, MAX_SIZE - 1, &cnt);
    printf("반복 보간 탐색 인덱스: %d, 비교횟수: %d\n", index, cnt);
    cnt = 0;
    index = interpolation_recursive(key, 0, MAX_SIZE - 1, &cnt);
    printf("순환 보간 탐색 인덱스: %d, 비교횟수: %d\n", index, cnt);

    key = 9997;
    printf("\n탐색 키: %d\n", key);
    cnt = 0;
    index = binary_iterative(key, 0, MAX_SIZE - 1, &cnt);
    printf("반복 이진 탐색 인덱스: %d, 비교횟수: %d\n", index, cnt);
    cnt = 0;
    index = binary_recursive(key, 0, MAX_SIZE - 1, &cnt);
    printf("순환 이진 탐색 인덱스: %d, 비교횟수: %d\n", index, cnt);
    cnt = 0;
    index = interpolation_iterative(key, 0, MAX_SIZE - 1, &cnt);
    printf("반복 보간 탐색 인덱스: %d, 비교횟수: %d\n", index, cnt);
    cnt = 0;
    index = interpolation_recursive(key, 0, MAX_SIZE - 1, &cnt);
    printf("순환 보간 탐색 인덱스: %d, 비교횟수: %d\n", index, cnt);

    key = 10000;
    printf("\n탐색 키: %d\n", key);
    cnt = 0;
    index = binary_iterative(key, 0, MAX_SIZE - 1, &cnt);
    printf("반복 이진 탐색 인덱스: %d, 비교횟수: %d\n", index, cnt);
    cnt = 0;
    index = binary_recursive(key, 0, MAX_SIZE - 1, &cnt);
    printf("순환 이진 탐색 인덱스: %d, 비교횟수: %d\n", index, cnt);
    cnt = 0;
    index = interpolation_iterative(key, 0, MAX_SIZE - 1, &cnt);
    printf("반복 보간 탐색 인덱스: %d, 비교횟수: %d\n", index, cnt);
    cnt = 0;
    index = interpolation_recursive(key, 0, MAX_SIZE - 1, &cnt);
    printf("순환 보간 탐색 인덱스: %d, 비교횟수: %d\n", index, cnt);

    return 0;
}
/*실제 출력

탐색 키: 1000
반복 이진 탐색 인덱스: 1278, 비교횟수: 10
순환 이진 탐색 인덱스: 1278, 비교횟수: 10
반복 보간 탐색 인덱스: 1278, 비교횟수: 6
순환 보간 탐색 인덱스: 1278, 비교횟수: 6

탐색 키: 0
반복 이진 탐색 인덱스: 1, 비교횟수: 12
순환 이진 탐색 인덱스: 1, 비교횟수: 12
반복 보간 탐색 인덱스: 0, 비교횟수: 0
순환 보간 탐색 인덱스: 0, 비교횟수: 0

탐색 키: 9997
반복 이진 탐색 인덱스: 9999, 비교횟수: 14
순환 이진 탐색 인덱스: 9999, 비교횟수: 14
반복 보간 탐색 인덱스: 9999, 비교횟수: 1
순환 보간 탐색 인덱스: 9999, 비교횟수: 1

탐색 키: 10000
반복 이진 탐색 인덱스: -1, 비교횟수: 14
순환 이진 탐색 인덱스: -1, 비교횟수: 14
반복 보간 탐색 인덱스: -1, 비교횟수: 0
순환 보간 탐색 인덱스: -1, 비교횟수: 0

C:\Users\rlawl\OneDrive\바탕 화면\상명대학교\2학년\자료구조\05-31\Project1\x64\Debug\Project1.exe(프로세스 20800개)이(가) 종료되었습니다(코드: 0개).
이 창을 닫으려면 아무 키나 누르세요...

*/
/*예시 출력

탐색 키: 1000
반복 이진 탐색 인덱스: 1278, 비교횟수: 10
순환 이진 탐색 인덱스: 1278, 비교횟수: 10
반복 보간 탐색 인덱스: 1278, 비교횟수: 6
순환 보간 탐색 인덱스: 1278, 비교횟수: 6

탐색 키: 0
반복 이진 탐색 인덱스: 1, 비교횟수: 12
순환 이진 탐색 인덱스: 1, 비교횟수: 12
반복 보간 탐색 인덱스: 0, 비교횟수: 0
순환 보간 탐색 인덱스: 0, 비교횟수: 0

탐색 키: 9997
반복 이진 탐색 인덱스: 9999, 비교횟수: 14
순환 이진 탐색 인덱스: 9999, 비교횟수: 14
반복 보간 탐색 인덱스: 9999, 비교횟수: 1
순환 보간 탐색 인덱스: 9999, 비교횟수: 1

탐색 키: 10000
반복 이진 탐색 인덱스: -1, 비교횟수: 14
순환 이진 탐색 인덱스: -1, 비교횟수: 14
반복 보간 탐색 인덱스: -1, 비교횟수: 0
순환 보간 탐색 인덱스: -1, 비교횟수: 0
계속하려면 아무 키나 누르십시오 . . .
*/