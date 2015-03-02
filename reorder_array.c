/*输入一个整数数组，实现一个函数来调整该整数中数字的顺序，使得所有奇数
 *位于数组的前半部分，所有偶数位于数组的后半部分
 */
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define false 0
#define true 1

void Reorder(int *pData, unsigned int length, bool (*func)(int));
bool isEven(int n);

// ====================方法一====================
/*参考了快排的partition，但是因为不涉及到具体数字大小，所以没有无限
循环的顾虑*/
void ReorderOddEven_1(int *pData, unsigned int length)
{
    if(pData == NULL || length == 0)
        return;

    int *pBegin = pData;
    int *pEnd = pData + length - 1;

    while(pBegin < pEnd)
    {
        // 向后移动pBegin，直到它指向偶数
        while(pBegin < pEnd && (*pBegin & 0x1) != 0)
            pBegin ++;

        // 向前移动pEnd，直到它指向奇数
        while(pBegin < pEnd && (*pEnd & 0x1) == 0)
            pEnd --;

        if(pBegin < pEnd)
        {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}

// ====================方法二====================
/*思想和方法二是一样的，只是写成了一个通用的算法，比如要将能被3整除的
数放在前面，不能的放在后面，只需要改变func函数就可以了*/
void ReorderOddEven_2(int *pData, unsigned int length)
{
    Reorder(pData, length, isEven); //将isEven函数作为参数传递
}

void Reorder(int *pData, unsigned int length, bool (*func)(int))
{
    if(pData == NULL || length == 0)
        return;

    int *pBegin = pData;
    int *pEnd = pData + length - 1;

    while(pBegin < pEnd) 
    {
        // 向后移动pBegin
        while(pBegin < pEnd && !func(*pBegin))
            pBegin ++;

        // 向前移动pEnd
        while(pBegin < pEnd && func(*pEnd))
            pEnd --;

        if(pBegin < pEnd)
        {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}

bool isEven(int n)
{
    return (n & 1) == 0;
}

// ====================测试代码====================
void PrintArray(int numbers[], int length)
{
    if(length < 0)
        return;
    int i;
    for(i = 0; i < length; ++i)
        printf("%d\t", numbers[i]);

    printf("\n");
}

void Test(char* testName, int numbers[], int length)
{
    if(testName != NULL)
        printf("%s begins:\n", testName);

    int* copy = calloc(length, sizeof(int));
    int i;
    for(i = 0; i < length; ++i)
    {
        copy[i] = numbers[i];
    }

    printf("Test for solution 1:\n");
    PrintArray(numbers, length);
    ReorderOddEven_1(numbers, length);
    PrintArray(numbers, length);

    printf("Test for solution 2:\n");
    PrintArray(copy, length);
    ReorderOddEven_2(copy, length);
    PrintArray(copy, length);

    free(copy);
}

void Test1()
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7};
    Test("Test1", numbers, sizeof(numbers)/sizeof(int));
}

void Test2()
{
    int numbers[] = {2, 4, 6, 1, 3, 5, 7};
    Test("Test2", numbers, sizeof(numbers)/sizeof(int));
}

void Test3()
{
    int numbers[] = {1, 3, 5, 7, 2, 4, 6};
    Test("Test3", numbers, sizeof(numbers)/sizeof(int));
}

void Test4()
{
    int numbers[] = {1};
    Test("Test4", numbers, sizeof(numbers)/sizeof(int));
}

void Test5()
{
    int numbers[] = {2};
    Test("Test5", numbers, sizeof(numbers)/sizeof(int));
}

void Test6()
{
    Test("Test6", NULL, 0);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}


