#include <stdio.h>
#include <stdlib.h>
//认为以顺式存储结构进行存储
int main()
{
    int k,len;
    printf("请输入一个正整数：\n");//获取数组长度
    scanf_s("%d",&len);
    if (len < 0)
    {
        printf("The length of the array is not available！");
        return 1;
    }
    printf("请输入一个正整数：\n");
    scanf_s("%d", &k);//获取向右轮转步数
    if (k < 0)
    {
        printf("The number of step is not available!");
        return 1;
    }
    int* array = (int*)malloc(sizeof(int) * len);//建立数组
    if (array == NULL) 
    {
        printf( "内存分配失败\n");
        return 1;
    }
    printf("请输入%d个0-9的整数:\n",len);// 数组赋值
    for (int i = 0; i < len; i++) 
    {
        scanf_s("%d", & array[i]);
    }
    int n;
    k = k % len;
    while (k>0)//数组向右轮转k次
    {
        int m = array[len - 1];
        for (int i = len-1; i  > 0; i--)
        {
            array[i] = array[i - 1];
        }
        array[0] = m;
        k -= 1;
    }
    printf("轮转后的数组：\n"); // 输出轮转后的数组
    for (int i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    free(array); // 释放内存
    return 0;
}