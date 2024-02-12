#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 100
typedef struct TreeNode {
	char ch;
	int weight;
	struct TreeNode* left_child;
	struct TreeNode* right_child;
} TreeNode;
typedef struct {
	TreeNode* ptree;
	int key;
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

// �ʱ�ȭ �Լ�
void init(HeapType* h)
{
	h->heap_size = 0;
}
// ���� �Լ�
void insert_min_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	//  Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;     // ���ο� ��带 ����
}
// ���� �Լ�
element delete_min_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// ���� ����� �ڽĳ���� �� ���� �ڽĳ�带 ã�´�.
		if ((child < h->heap_size) &&
			(h->heap[child].key) > h->heap[child + 1].key)
			child++;
		if (temp.key <= h->heap[child].key) break;
		// �Ѵܰ� �Ʒ��� �̵�
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

// ���� Ʈ�� ���� �Լ�
TreeNode* make_tree(TreeNode* left, TreeNode* right)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	if (node == NULL) {
		fprintf(stderr, "�޸� ����\n");
		exit(1);
	}
	node->left_child = left;
	node->right_child = right;
	return node;
}
// ���� Ʈ�� ���� �Լ�
void destroy_tree(TreeNode* root)
{
	if (root == NULL) return;
	destroy_tree(root->left_child);
	destroy_tree(root->right_child);
	free(root);
}

// ������ �ڵ� ���� �Լ�
TreeNode* huffman_tree(char ch_arr[], int freq[], int n)
{
	int i;
	TreeNode* node, * x;
	HeapType heap;
	element e, e1, e2;

	init(&heap);
	for (i = 0; i < n; i++) {
		node = make_tree(NULL, NULL);
		node->ch = ch_arr[i];
		e.key = node->weight = freq[i];
		e.ptree = node;
		insert_min_heap(&heap, e);
	}
	while (heap.heap_size > 1) {//for(i=1;i<n;i++){
		e1 = delete_min_heap(&heap);		// �ּҰ��� ������ �ΰ��� ��带 ����
		e2 = delete_min_heap(&heap);
		x = make_tree(e1.ptree, e2.ptree); // �ΰ��� ��带 ��ģ��.
		x->ch = 0;
		e.key = x->weight = e1.key + e2.key;
		e.ptree = x;
		insert_min_heap(&heap, e);
	}
	e = delete_min_heap(&heap); // ���� Ʈ��
	return e.ptree;
}
void traverse(TreeNode* p, char code[], int level) {
	int i;
	if (p != NULL) {
		//�Ʒ��� �ϼ��Ͻÿ�

		if (p->ch > 0) {
			printf("%c : ", p->ch);
			for (i = 0; i < level; i++) {
				printf("%c", code[i]);
				
			}
			printf("\n");
		}
		else {

			code[level] = '0';
			traverse(p->left_child, code, level + 1);
			code[level] = '1';
			traverse(p->right_child, code, level + 1);

		}

	}

}
// ���Լ� 
int main(void)
{
	char ch_arr[] = { 'A', 'B', 'C', 'D', 'E' };
	int freq[] = { 15, 12, 8, 6, 4 };
	TreeNode* node = huffman_tree(ch_arr, freq, 5);
	char h_code[100];

	traverse(node, h_code, 0);
	destroy_tree(node);

	return 0;
}
/* ���� ���
C: 00
E: 010
D: 011
B: 10
A: 11

C:\Users\rlawl\OneDrive\���� ȭ��\�����б�\2�г�\�ڷᱸ��\05_10\Project1\x64\Debug\Project1.exe(���μ��� 43464��)��(��) ����Ǿ����ϴ�(�ڵ�: 0��).
�� â�� �������� �ƹ� Ű�� ��������...

*/
/* ���� ���
C : 00
E : 010
D : 011
B : 10
A : 11
*/