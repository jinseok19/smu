
#define _CRT_SECURE_NO_WARNINGS
#define MAXWORD 80

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

typedef struct element {
	char word[MAXWORD];
	int count;
} element;
typedef struct TreeNode {
	element data;
	struct TreeNode* left, * right;
} TreeNode;

// ��ȯ���� Ž�� �Լ�
TreeNode* search(TreeNode* node, char* word)
{
	if (node == NULL) return NULL;
	int cmp = strcmp(node->data.word, word);
	if (cmp == 0)
		return node;
	else if (cmp > 0)
		return search(node->left, word);
	else
		return search(node->right, word);
}
TreeNode* new_node(char* word)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	strcpy(temp->data.word, word);
	temp->data.count = 1;
	temp->left = temp->right = NULL;
	return temp;
}
TreeNode* insert_node(TreeNode* node, char* word)
{
	// Ʈ���� �����̸� ���ο� ��带 ��ȯ�Ѵ�. 
	if (node == NULL) return new_node(word);

	// �׷��� ������ ��ȯ������ Ʈ���� ��������. 
	int cmp = strcmp(node->data.word, word);

	//�Ʒ��� �ϼ��Ͻÿ�.
	if (cmp == 0) {
		node->data.count++;

	}
	else if (cmp > 0) {
		node->left = insert_node(node->left, word);
	}
	else {
		node->right = insert_node(node->right, word);
	}


	// ����� ��Ʈ �����͸� ��ȯ�Ѵ�. 
	return node;
}

int get_height(TreeNode* node) {
	int height = 0;
	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));
	return height;
}
TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;

	// �� ���� �ܸ� ��带 ã���� ������
	while (current->left != NULL)
		current = current->left;

	return current;
}
TreeNode* max_value_node(TreeNode* node)
{
	TreeNode* current = node;

	// �� ������ �ܸ� ��带 ã���� ������
	while (current->right != NULL)
		current = current->right;

	return current;
}
// ���� Ž�� Ʈ���� Ű�� �־����� Ű�� ����� ��带 �����ϰ� 
// ���ο� ��Ʈ ��带 ��ȯ�Ѵ�. 
TreeNode* delete_node(TreeNode* root, char* word)
{
	if (root == NULL) return root;

	int cmp = strcmp(root->data.word, word);
	// ���� Ű�� ��Ʈ���� ������ ���� ���� Ʈ���� �ִ� ����
	if (cmp < 0)
		root->right = delete_node(root->right, word);
	// ���� Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ���� �ִ� ����
	else if (cmp > 0)
		root->left = delete_node(root->left, word);
	// Ű�� ��Ʈ�� ������ �� ��带 �����ϸ� ��
	else {
		//�Ʒ��� �ϼ��Ͻÿ�.
		root->data.count--;
		if (root->data.count > 0) {
			return root;
		}
		

		//count==0
		// ù ��°�� �� ��° ���
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		// �� ��° ���
		if (get_height(root->left) >= get_height(root->right)) {
			TreeNode* temp = max_value_node(root->left);

			// �߿� ��ȸ�� ���� ��带 �����Ѵ�. 
			root->data = temp->data;
			// �߿� ��ȸ�� ���� ��带 �����Ѵ�. 
			root->left = delete_node(root->left, temp->data.word);
		}
		else {
			TreeNode* temp = min_value_node(root->right);

			// �߿� ��ȸ�� �İ� ��带 �����Ѵ�. 
			root->data = temp->data;
			// �߿� ��ȸ�� �İ� ��带 �����Ѵ�. 
			root->right = delete_node(root->right, temp->data.word);
		}
	}
	return root;
}

// ���� ��ȸ
void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);// ���ʼ���Ʈ�� ��ȸ
		printf("%s \t%d\n", root->data.word, root->data.count);
		inorder(root->right);// �����ʼ���Ʈ�� ��ȸ
	}
}

int main(void)
{
	TreeNode* root = NULL;

	FILE* fp;
	char word[MAXWORD];

	fp = fopen("data.txt", "r");
	while (fscanf(fp, "%s", word) != EOF) {
		printf("%s ", word);
		root = insert_node(root, word);
	}
	printf("\n");
	fclose(fp);

	printf("�ܾ� \tȸ��\n");
	inorder(root);

	printf("������ �ܾ�(����:0): ");
	scanf_s("%s", word, sizeof(word));
	while (word[0] != '0') {
		delete_node(root, word);
		inorder(root);
		printf("������ �ܾ�(����:0): ");
		scanf("%s", word);
	}

	return 0;
}
/*�������
The output from Huffmans algorithm can be viewed as a variable length code table for encoding a source symbol such as a character in a file
�ܾ�    ȸ��
Huffmans        1
The     1
a       4
algorithm       1
as      2
be      1
can     1
character       1
code    1
encoding        1
file    1
for     1
from    1
in      1
length  1
output  1
source  1
such    1
symbol  1
table   1
variable        1
viewed  1
������ �ܾ�(����:0): a
Huffmans        1
The     1
a       3
algorithm       1
as      2
be      1
can     1
character       1
code    1
encoding        1
file    1
for     1
from    1
in      1
length  1
output  1
source  1
such    1
symbol  1
table   1
variable        1
viewed  1
������ �ܾ�(����:0): be
Huffmans        1
The     1
a       3
algorithm       1
as      2
can     1
character       1
code    1
encoding        1
file    1
for     1
from    1
in      1
length  1
output  1
source  1
such    1
symbol  1
table   1
variable        1
viewed  1
������ �ܾ�(����:0): 0

C:\Users\rlawl\OneDrive\���� ȭ��\�����б�\2�г�\�ڷᱸ��\04_12\Project1\x64\Debug\Project1.exe(���μ��� 19796��)��(��) ����Ǿ����ϴ�(�ڵ�: 0��).
�� â�� �������� �ƹ� Ű�� ��������...
*/
/*��°�� ����
The output from Huffmans algorithm can be viewed as a variable length code table
 for encoding a source symbol such as a character in a file
�ܾ�    ȸ��
Huffmans        1
The     1
a       4
algorithm       1
as      2
be      1
can     1
character       1
code    1
encoding        1
file    1
for     1
from    1
in      1
length  1
output  1
source  1
such    1
symbol  1
table   1
variable        1
viewed  1
������ �ܾ�(����:0): a
Huffmans        1
The     1
a       3
algorithm       1
as      2
be      1
can     1
character       1
code    1
encoding        1
file    1
for     1
from    1
in      1
length  1
output  1
source  1
such    1
symbol  1
table   1
variable        1
viewed  1
������ �ܾ�(����:0): be
Huffmans        1
The     1
a       3
algorithm       1
as      2
can     1
character       1
code    1
encoding        1
file    1
for     1
from    1
in      1
length  1
output  1
source  1
such    1
symbol  1
table   1
variable        1
viewed  1
������ �ܾ�(����:0): 0
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/

