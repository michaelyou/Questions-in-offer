/*��Ŀ:ʵ�ֺ��� double Power(double base, int exponent)����base��exponent 
 *�η�������ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ�������
 */
 
#include <stdio.h>
#include <stdlib.h>
#define bool int
#define false 0
#define true 1

bool g_InvalidInput = false;
bool equal(double num1, double num2);
double PowerWithUnsignedExponent(double base, unsigned int exponent);
 
double Power(double base, int exponent)
{
    g_InvalidInput = false;
 
    if(equal(base, 0.0) && exponent < 0)
    {
        g_InvalidInput = true;
        return 0.0;
    }
 
    unsigned int absExponent = (unsigned int)(exponent);
    if(exponent < 0)
        absExponent = (unsigned int)(-exponent);
 
    double result = PowerWithUnsignedExponent(base, absExponent);
    if(exponent < 0)
        result = 1.0 / result;
    //printf("locate result = %d\n", result);
    return result;
}
 

double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
    if(exponent == 0)
        return 1;
    if(exponent == 1)
        return base;

    double result = PowerWithUnsignedExponent(base, exponent >> 1);
    result *= result;
    if((exponent & 0x1) == 1)
        result *= base;

    return result;
}

/*�ڼ�����ڱ�ʾС��ʱ(����float��double��С��)�������ж�
 *����С���Ƿ���ȣ�ֻ���ж�����֮��ľ���ֵ�ǲ�����һ����С��
 *��Χ�ڡ��������������С������С��0.0000001��
 *�Ϳ�����Ϊ������ȡ�
 */
bool equal(double num1, double num2)
{
    if((num1 - num2 > -0.0000001)
        && (num1 - num2 < 0.0000001))
        return true;
    else
        return false;
}

// ====================���Դ���====================
void Test(double base, int exponent, double expectedResult, bool expectedFlag)
{
    double result = Power(base, exponent);
    //printf("%d\n", result);
    if(abs(result - expectedResult) < 0.00000001 
        && g_InvalidInput == expectedFlag)
        printf("Test passed.\n");
    else {
        printf("result is %f\n", result);
        printf("Test failed.\n");
    }
}

int main(int argc, char* argv[])
{
    // ������ָ����Ϊ����
    printf("Test1 begins.\n");
    Test(2, 3, 8, false);  

    // ����Ϊ������ָ��Ϊ����
    printf("Test2 begins.\n");
    Test(-2, 3, -8, false);

    // ָ��Ϊ����
    printf("Test3 begins.\n");
    Test(2, -3, 0.125, false);

    // ָ��Ϊ0
    printf("Test4 begins.\n");
    Test(2, 0, 1, false);

    // ������ָ����Ϊ0
    printf("Test5 begins.\n");
    Test(0, 0, 1, false);

    // ����Ϊ0��ָ��Ϊ����
    printf("Test6 begins.\n");
    Test(0, 4, 0, false);

    // ����Ϊ0��ָ��Ϊ����
    printf("Test7 begins.\n");
    Test(0, -4, 0, true);

    return 0;
}


