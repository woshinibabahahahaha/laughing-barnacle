#include <stdio.h>
#include <stdlib.h>
//��Ϊ��˳ʽ�洢�ṹ���д洢
int main()
{
    int k,len;
    printf("������һ����������\n");//��ȡ���鳤��
    scanf_s("%d",&len);
    if (len < 0)
    {
        printf("The length of the array is not available��");
        return 1;
    }
    printf("������һ����������\n");
    scanf_s("%d", &k);//��ȡ������ת����
    if (k < 0)
    {
        printf("The number of step is not available!");
        return 1;
    }
    int* array = (int*)malloc(sizeof(int) * len);//��������
    if (array == NULL) 
    {
        printf( "�ڴ����ʧ��\n");
        return 1;
    }
    printf("������%d��0-9������:\n",len);// ���鸳ֵ
    for (int i = 0; i < len; i++) 
    {
        scanf_s("%d", & array[i]);
    }
    int n;
    k = k % len;
    while (k>0)//����������תk��
    {
        int m = array[len - 1];
        for (int i = len-1; i  > 0; i--)
        {
            array[i] = array[i - 1];
        }
        array[0] = m;
        k -= 1;
    }
    printf("��ת������飺\n"); // �����ת�������
    for (int i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    free(array); // �ͷ��ڴ�
    return 0;
}