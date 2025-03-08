#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node* prior;
	struct Node* next;
}node;
typedef struct
{
	int len;
	node* head;
}list;
int exchange(list* l, node* p) 
{
	if (p == NULL || p->prior == NULL)
	{
		// 如果p是NULL或p是头节点（没有前一个节点），则无法进行交换
		return -1;
	}
	node* priorNode = p->prior;
	// 调整前一个节点的next指针
	priorNode->next = p->next;
	if (p->next != NULL)
	{
		p->next->prior = priorNode;
	}
	// 调整当前节点的prior和next指针
	p->prior = priorNode->prior;
	if (priorNode->prior != NULL)
	{
		priorNode->prior->next = p;
	}
	else 
	{
		// 如果priorNode是头节点，则更新头节点
		l->head = p;
	}
	p->next = priorNode;
	priorNode->prior = p;
	return 0;
}
int main()
{
	list* lst = (list*)malloc(sizeof(list));
	printf("请输入链表的长度：\n");
	int len;
	scanf_s("%d", &len);
	lst->len = len;
	lst->head = NULL;
	node* tail = NULL;
	for (int i = 0; i < len; i++) {
		node* newNode = (node*)malloc(sizeof(node));
		printf("请输入一个数据（整数）：\n");
		scanf_s("%d", &newNode->data);
		newNode->prior = tail;
		newNode->next = NULL;
		if (tail != NULL)
		{
			tail->next = newNode;
		}
		else
		{
			lst->head = newNode;
		}
		tail = newNode;
	}
	int t;
	printf("随机输入一个不大于链表长度的数值：\n");
	scanf_s("%d", &t);
	if (t < 1 || t > lst->len) 
	{ // 注意这里从1开始检查
		printf("输入的索引无效！\n");
		return 1;
	}
	node* temp = lst->head;
	for (int i = 0; i < t - 1; i++) 
	{ // 注意这里是 t - 1，因为用户可能从1开始计数
		temp = temp->next;
	}
	int result = exchange(lst, temp);
	node* y = lst->head;
	if (result == 0)
	{
		for (int u = 0; u < lst->len; u++)
		{
			printf("%d ", y->data);
			y = y->next;
		}
		printf("\n");
	}
	else 
	{
		printf("交换条件未满足，请重试！\n");
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