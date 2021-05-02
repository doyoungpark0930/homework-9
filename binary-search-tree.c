/*
 * Binary Search Tree #1
 * 작성자: 박도영
 * 작성일자 :2021/05/02
 * Data Structures
 *
 * Department of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
typedef struct node {
	int key;
	struct node* left;
	struct node* right;
} Node;

int initializeBST(Node** h);

/* functions that you have to implement */
void inorderTraversal(Node* ptr);	  /* recursive inorder traversal */
void preorderTraversal(Node* ptr);    /* recursive preorder traversal */
void postorderTraversal(Node* ptr);	  /* recursive postorder traversal */
int insert(Node* head, int key);  /* insert a node to the tree */
int deleteLeafNode(Node* head, int key);  /* delete the leaf node for the key */
Node* searchRecursive(Node* ptr, int key);  /* search the node for the key */
Node* searchIterative(Node* head, int key);  /* search the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */


int main()
{
	char command;
	int key;
	Node* head = NULL;
	Node* ptr = NULL;	/* temp */

	do {
        printf("Do young park 2018038077");
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Leaf Node             = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f \n");
		printf(" Postorder Traversal  = t      Quit                         = q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch (command) {
		case 'z': case 'Z':
			initializeBST(&head);
			break;
		case 'q': case 'Q':
			freeBST(head);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteLeafNode(head, key);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchIterative(head, key);
			if (ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;
		case 's': case 'S':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchRecursive(head->left, key);
			if (ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;

		case 'i': case 'I':
			inorderTraversal(head->left);
			break;
		case 'p': case 'P':
			preorderTraversal(head->left);
			break;
		case 't': case 'T':
			postorderTraversal(head->left);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q');

	return 1;
}

int initializeBST(Node** h) {

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if (*h != NULL)
		freeBST(*h);

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node));
	(*h)->left = NULL;	/* root */
	(*h)->right = *h; //첫 시작은 어차피 leftChild부터 시작이다, rightChild가 자기 자신을 가리키는 이유는 혹시 rightChild쪽으로 가더라도 다시 잘 실행되기 위함
	(*h)->key = -9999;
	return 1;
}



void inorderTraversal(Node* ptr)//중위 순회 함수
{
	if (ptr != NULL) { //ptr이 NULL이 아니라면 ptr이 가리키는 구조체가 적어도 하나는 있다는 뜻
		inorderTraversal(ptr->left);
		printf("%d", ptr->key);
		inorderTraversal(ptr->right);
	}

}

void preorderTraversal(Node* ptr) //전위 순회 함수
{
	if (ptr != NULL) {//ptr이 NULL이 아니라면 ptr이 가리키는 구조체가 적어도 하나는 있다는 뜻
		printf("%d", ptr->key);
		preorderTraversal(ptr->left);
		preorderTraversal(ptr->right);
	}

}

void postorderTraversal(Node* ptr) //후위 순회 함수
{
	if (ptr != NULL) {//ptr이 NULL이 아니라면 ptr이 가리키는 구조체가 적어도 하나는 있다는 뜻
		postorderTraversal(ptr->left);
		postorderTraversal(ptr->right);
		printf("%d", ptr->key);
	}

}


int insert(Node* head, int key)
{

}

int deleteLeafNode(Node* head, int key)
{

}

Node* searchRecursive(Node* ptr, int key) //이원탐색 트리의 반복적 탐색 (재귀적)
{
	/*키값이 key인 노드에 대한 포인터를 반환함
	그런 노드가 없는 경우는 NULL값 반환*/
	if (ptr == NULL) return NULL;
	if (key == ptr->key)
		return ptr;
	if (key < ptr->key)
		return searchRecursive(ptr->left, key);
	return
		searchRecursive(ptr->right, key);

}

Node* searchIterative(Node* head, int key) //이원탐색 트리의 반복적 탐색 (비 재귀적)
{
	/*키값이 key인 노드에 대한 포인터를 반환함
	그런 노드가 없는 경우는 NULL값 반환*/
	while (head!=NULL) {
		if (key == head->key)
			return head;
		if (key < head->key)
			head = head->left;
		else
			head = head->right;
	}
	return NULL;
}


int freeBST(Node* head)
{

}



