#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
	int data;
	struct Node* next;
	int index;
}node;
typedef struct
{
	node* head;
	int len;
}list;
int seek(int n,int len,list* o)
{
	node* u = o->head;
	for (int i = 0; i < len; i++)
	{
		if (u->index == n)
			return u->data;
		else
			u = u->next;
	}
	return -1;
}
int main()
{
	int o = 0;
	int len;
	printf("请输入链表长度：\n");
	scanf_s("%d", &len);
	list* lst = (list*)malloc(sizeof(list));
	lst->head = NULL;
	node* temp = NULL, * prev = NULL;
	for (int i = 0; i < len; i++)
	{
		node* newNode = (node*)malloc(sizeof(node));
		newNode->index = i;
		printf("请输入一个整数（点的数值）：\n");
		scanf_s("%d", &newNode->data);
		newNode->next = NULL;
		if (lst->head == NULL)
		{
			lst->head = newNode;
		}
		else
		{
			prev->next = newNode;
		}
		prev = newNode;
	}
	for (int y = 0; y < (len / 2); y++)
	{
		int a = seek(y, len, lst);
		int b = seek(len - 1 - y, len, lst);
		if (a != b)
		{
			o = -1;
			printf("false\n");
			break;
		}
	}
		if (o != -1)
		{
			printf("true\n");
		}
		node* current = lst->head;
		while (current != NULL) 
		{
			node* next = current->next;
			free(current);
			current = next;
		}
		free(lst);
		return 0;
}