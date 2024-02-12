#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

int list[MAX_SIZE];
//����Ž��-�ݺ� ����
int binary_iterative(int key, int low, int high, int* cnt) {
    int middle;

    while (low <= high) {
        (*cnt)++;
        middle = (low + high) / 2;
        if (key == list[middle])
            return middle; 	// Ž�� ����
        else if (key < list[middle])
            high = middle - 1; 	// ������ �κи���Ʈ Ž��
        else
            low = middle + 1; // ���� �κи���Ʈ Ž��
    }
    return -1; 					// Ž�� ����
}

//����Ž��-��ȯ ����
int binary_recursive(int key, int low, int high, int* cnt) {
    int middle;
    if (low <= high) {
        //�Ʒ��� �ϼ��Ͻÿ�.

        (*cnt)++;
        int middle = (low + high) / 2;

        if (key == list[middle]) {
            return middle; // Ž�� ����
        }
        else if (key < list[middle]) {
            return binary_recursive(key, low, middle - 1, cnt); // ���� �κ� ����Ʈ Ž��
        }
        else {
            return binary_recursive(key, middle + 1, high, cnt); // ������ �κ� ����Ʈ Ž��
        }
    }


    return -1; 					// Ž�� ����
}

//����Ž��-�ݺ� ����
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
    if (list[low] == key) return(low);  // Ž������
    else return -1;  // Ž������
}

//����Ž��-��ȯ ����
int interpolation_recursive(int key, int low, int high, int* cnt) {
    int middle;
    if ((list[high] >= key) && (key > list[low])) {
        //�Ʒ��� �ϼ��Ͻÿ�.
        (*cnt)++;
        int middle = (int)((float)(key - list[low]) / (list[high] - list[low]) * (high - low) + low);

        if (key == list[middle]) {
            return middle; // Ž�� ����
        }
        else if (key < list[middle]) {
            return interpolation_recursive(key, low, middle - 1, cnt); // ���� �κ� ����Ʈ Ž��
        }
        else {
            return interpolation_recursive(key, middle + 1, high, cnt); // ������ �κ� ����Ʈ Ž��
        }
    }

    
    if (list[low] == key) return(low);  // Ž������
    else return -1;  // Ž������
}
int compare(const void* v1, const void* v2)	// ���Լ� ����
{
    int cmpvalue1, cmpvalue2;

    cmpvalue1 = *(int*)v1;
    cmpvalue2 = *(int*)v2;

    return cmpvalue1 - cmpvalue2;	// �������� ����
    //return cmpvalue2 - cmpvalue1;	// �������� ����
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
    printf("\nŽ�� Ű: %d\n", key);
    cnt = 0;
    index = binary_iterative(key, 0, MAX_SIZE - 1, &cnt);
    printf("�ݺ� ���� Ž�� �ε���: %d, ��Ƚ��: %d\n", index, cnt);
    cnt = 0;
    index = binary_recursive(key, 0, MAX_SIZE - 1, &cnt);
    printf("��ȯ ���� Ž�� �ε���: %d, ��Ƚ��: %d\n", index, cnt);
    cnt = 0;
    index = interpolation_iterative(key, 0, MAX_SIZE - 1, &cnt);
    printf("�ݺ� ���� Ž�� �ε���: %d, ��Ƚ��: %d\n", index, cnt);
    cnt = 0;
    index = interpolation_recursive(key, 0, MAX_SIZE - 1, &cnt);
    printf("��ȯ ���� Ž�� �ε���: %d, ��Ƚ��: %d\n", index, cnt);

    key = 0;
    printf("\nŽ�� Ű: %d\n", key);
    cnt = 0;
    index = binary_iterative(key, 0, MAX_SIZE - 1, &cnt);
    printf("�ݺ� ���� Ž�� �ε���: %d, ��Ƚ��: %d\n", index, cnt);
    cnt = 0;
    index = binary_recursive(key, 0, MAX_SIZE - 1, &cnt);
    printf("��ȯ ���� Ž�� �ε���: %d, ��Ƚ��: %d\n", index, cnt);
    cnt = 0;
    index = interpolation_iterative(key, 0, MAX_SIZE - 1, &cnt);
    printf("�ݺ� ���� Ž�� �ε���: %d, ��Ƚ��: %d\n", index, cnt);
    cnt = 0;
    index = interpolation_recursive(key, 0, MAX_SIZE - 1, &cnt);
    printf("��ȯ ���� Ž�� �ε���: %d, ��Ƚ��: %d\n", index, cnt);

    key = 9997;
    printf("\nŽ�� Ű: %d\n", key);
    cnt = 0;
    index = binary_iterative(key, 0, MAX_SIZE - 1, &cnt);
    printf("�ݺ� ���� Ž�� �ε���: %d, ��Ƚ��: %d\n", index, cnt);
    cnt = 0;
    index = binary_recursive(key, 0, MAX_SIZE - 1, &cnt);
    printf("��ȯ ���� Ž�� �ε���: %d, ��Ƚ��: %d\n", index, cnt);
    cnt = 0;
    index = interpolation_iterative(key, 0, MAX_SIZE - 1, &cnt);
    printf("�ݺ� ���� Ž�� �ε���: %d, ��Ƚ��: %d\n", index, cnt);
    cnt = 0;
    index = interpolation_recursive(key, 0, MAX_SIZE - 1, &cnt);
    printf("��ȯ ���� Ž�� �ε���: %d, ��Ƚ��: %d\n", index, cnt);

    key = 10000;
    printf("\nŽ�� Ű: %d\n", key);
    cnt = 0;
    index = binary_iterative(key, 0, MAX_SIZE - 1, &cnt);
    printf("�ݺ� ���� Ž�� �ε���: %d, ��Ƚ��: %d\n", index, cnt);
    cnt = 0;
    index = binary_recursive(key, 0, MAX_SIZE - 1, &cnt);
    printf("��ȯ ���� Ž�� �ε���: %d, ��Ƚ��: %d\n", index, cnt);
    cnt = 0;
    index = interpolation_iterative(key, 0, MAX_SIZE - 1, &cnt);
    printf("�ݺ� ���� Ž�� �ε���: %d, ��Ƚ��: %d\n", index, cnt);
    cnt = 0;
    index = interpolation_recursive(key, 0, MAX_SIZE - 1, &cnt);
    printf("��ȯ ���� Ž�� �ε���: %d, ��Ƚ��: %d\n", index, cnt);

    return 0;
}
/*���� ���

Ž�� Ű: 1000
�ݺ� ���� Ž�� �ε���: 1278, ��Ƚ��: 10
��ȯ ���� Ž�� �ε���: 1278, ��Ƚ��: 10
�ݺ� ���� Ž�� �ε���: 1278, ��Ƚ��: 6
��ȯ ���� Ž�� �ε���: 1278, ��Ƚ��: 6

Ž�� Ű: 0
�ݺ� ���� Ž�� �ε���: 1, ��Ƚ��: 12
��ȯ ���� Ž�� �ε���: 1, ��Ƚ��: 12
�ݺ� ���� Ž�� �ε���: 0, ��Ƚ��: 0
��ȯ ���� Ž�� �ε���: 0, ��Ƚ��: 0

Ž�� Ű: 9997
�ݺ� ���� Ž�� �ε���: 9999, ��Ƚ��: 14
��ȯ ���� Ž�� �ε���: 9999, ��Ƚ��: 14
�ݺ� ���� Ž�� �ε���: 9999, ��Ƚ��: 1
��ȯ ���� Ž�� �ε���: 9999, ��Ƚ��: 1

Ž�� Ű: 10000
�ݺ� ���� Ž�� �ε���: -1, ��Ƚ��: 14
��ȯ ���� Ž�� �ε���: -1, ��Ƚ��: 14
�ݺ� ���� Ž�� �ε���: -1, ��Ƚ��: 0
��ȯ ���� Ž�� �ε���: -1, ��Ƚ��: 0

C:\Users\rlawl\OneDrive\���� ȭ��\�����б�\2�г�\�ڷᱸ��\05-31\Project1\x64\Debug\Project1.exe(���μ��� 20800��)��(��) ����Ǿ����ϴ�(�ڵ�: 0��).
�� â�� �������� �ƹ� Ű�� ��������...

*/
/*���� ���

Ž�� Ű: 1000
�ݺ� ���� Ž�� �ε���: 1278, ��Ƚ��: 10
��ȯ ���� Ž�� �ε���: 1278, ��Ƚ��: 10
�ݺ� ���� Ž�� �ε���: 1278, ��Ƚ��: 6
��ȯ ���� Ž�� �ε���: 1278, ��Ƚ��: 6

Ž�� Ű: 0
�ݺ� ���� Ž�� �ε���: 1, ��Ƚ��: 12
��ȯ ���� Ž�� �ε���: 1, ��Ƚ��: 12
�ݺ� ���� Ž�� �ε���: 0, ��Ƚ��: 0
��ȯ ���� Ž�� �ε���: 0, ��Ƚ��: 0

Ž�� Ű: 9997
�ݺ� ���� Ž�� �ε���: 9999, ��Ƚ��: 14
��ȯ ���� Ž�� �ε���: 9999, ��Ƚ��: 14
�ݺ� ���� Ž�� �ε���: 9999, ��Ƚ��: 1
��ȯ ���� Ž�� �ε���: 9999, ��Ƚ��: 1

Ž�� Ű: 10000
�ݺ� ���� Ž�� �ε���: -1, ��Ƚ��: 14
��ȯ ���� Ž�� �ε���: -1, ��Ƚ��: 14
�ݺ� ���� Ž�� �ε���: -1, ��Ƚ��: 0
��ȯ ���� Ž�� �ε���: -1, ��Ƚ��: 0
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/