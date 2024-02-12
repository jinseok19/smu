#include <stdio.h>
# include <stdlib.h>
#define MAX_ELEMENT 200
#define SEL_NUM 10
#define MAX_HEAP_SIZE 11
typedef struct {
	int list[MAX_HEAP_SIZE + 1];
	int heap_size;

}HeapType;

void init(HeapType* h) {
	h->heap_size = 0;

}
//�ִ��� ���� �Լ�
void insert_max_heap(HeapType* h, int item) {
	int i;
	i = ++(h->heap_size);
	
	// Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && (item > h->list[i / 2])) {
		h->list[i] = h->list[i / 2];
		i /= 2;
	}
	h->list[i] = item; //���ο� ��带 ����
 }

//��Ʈ�� Ű�� item���� ��ü�� �� �ִ��� �籸��
void delete_max_heap(HeapType* h, int item) {
	int parent, child;
	
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {// ���� ����� �ڽĳ���� �� ū �ڽĳ�带
		if ((child < h->heap_size) && (h->list[child]) < h->list[child + 1]) {
			child++;
		}
		if (item >= h->list[child]) {
			break;
		}
		// �Ѵܰ� �Ʒ��� �̵�
		h->list[parent] = h->list[child];
		parent = child;
		child *= 2;
	}
	h->list[parent] = item;
}

int main() {
	int i;
	int list[MAX_ELEMENT];
	HeapType heap;

	init(&heap);
	srand(1);
	printf("��� ����Ʈ");
	for (int i = 0; i < MAX_ELEMENT; i++) {
		list[i] = rand() % 100;
		if (i % 10 == 0) {
			printf("\n");
		}
		printf("%d ", list[i]);
	}
	printf("\n");
	for (i = 0; i < MAX_HEAP_SIZE; i++) {
		insert_max_heap(&heap, list[i]);
	}
	for (; i < MAX_ELEMENT; i++) {
		delete_max_heap(&heap, list[i]);
	}
	printf("\n���� Ű %d ���� ����Ʈ \n", SEL_NUM);
	for (int i = 2; i <= MAX_HEAP_SIZE; i++) {
		printf("%d ", heap.list[i]);
	}
	printf("\n");
	
	return 0;
}
/*

���ο� �˰��� ����

ũ�Ⱑ 11�� �ִ����� ����Ͽ� �Է¼����� ����� ��Ʈ���� �ִ밪�� ��ġ�ϰ�
�ε��� 2���� 11���� ������� �Էµ� ���߿��� ���� ���� ���� ��ġ�Ѵ�.
���� �ܰ迡�� ���ο� �Է°��� ��Ʈ�� ��ġ��Ų�� �ִ����� �籸���ϸ�
��Ʈ���� ������ ū ���� �̿��� ��Ʈ���� 10���� ���� ���� ���� �ݺ������� 
��ġ�ϰ� �ȴ�.

*/

/*
���

��� ����Ʈ
41 67 34 0 69 24 78 58 62 64
5 45 81 27 61 91 95 42 27 36
91 4 2 53 92 82 21 16 18 95
47 26 71 38 69 12 67 99 35 94
3 11 22 33 73 64 41 11 53 68
47 44 62 57 37 59 23 41 29 78
16 35 90 42 88 6 40 42 64 48
46 5 90 29 70 50 6 1 93 48
29 23 84 54 56 40 66 76 31 8
44 39 26 23 37 38 18 82 29 41
33 15 39 58 4 30 77 6 73 86
21 45 24 72 70 29 77 73 97 12
86 90 61 36 55 67 55 74 31 52
50 50 41 24 66 30 7 91 7 37
57 87 53 83 45 9 9 58 21 88
22 46 6 30 13 68 0 91 62 55
10 59 24 37 48 83 95 41 2 50
91 36 74 20 96 21 48 99 68 84
81 34 53 99 18 38 0 88 27 67
28 93 48 83 7 21 10 17 13 14

���� Ű 10 ���� ����Ʈ
3 5 1 2 4 4 0 0 2 0

C:\Users\rlawl\OneDrive\���� ȭ��\�����б�\2�г�\�ڷᱸ��\05_03\Project1\x64\Debug\Project1.exe(���μ��� 7200��)��(��) ����Ǿ����ϴ�(�ڵ�: 0��).
�� â�� �������� �ƹ� Ű�� ��������...

*/