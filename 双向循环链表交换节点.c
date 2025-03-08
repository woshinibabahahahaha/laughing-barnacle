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
		// ���p��NULL��p��ͷ�ڵ㣨û��ǰһ���ڵ㣩�����޷����н���
		return -1;
	}
	node* priorNode = p->prior;
	// ����ǰһ���ڵ��nextָ��
	priorNode->next = p->next;
	if (p->next != NULL)
	{
		p->next->prior = priorNode;
	}
	// ������ǰ�ڵ��prior��nextָ��
	p->prior = priorNode->prior;
	if (priorNode->prior != NULL)
	{
		priorNode->prior->next = p;
	}
	else 
	{
		// ���priorNode��ͷ�ڵ㣬�����ͷ�ڵ�
		l->head = p;
	}
	p->next = priorNode;
	priorNode->prior = p;
	return 0;
}
int main()
{
	list* lst = (list*)malloc(sizeof(list));
	printf("����������ĳ��ȣ�\n");
	int len;
	scanf_s("%d", &len);
	lst->len = len;
	lst->head = NULL;
	node* tail = NULL;
	for (int i = 0; i < len; i++) {
		node* newNode = (node*)malloc(sizeof(node));
		printf("������һ�����ݣ���������\n");
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
	printf("�������һ�������������ȵ���ֵ��\n");
	scanf_s("%d", &t);
	if (t < 1 || t > lst->len) 
	{ // ע�������1��ʼ���
		printf("�����������Ч��\n");
		return 1;
	}
	node* temp = lst->head;
	for (int i = 0; i < t - 1; i++) 
	{ // ע�������� t - 1����Ϊ�û����ܴ�1��ʼ����
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
		printf("��������δ���㣬�����ԣ�\n");
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