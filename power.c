/*题目:实现函数 double Power(double base, int exponent)，求base的exponent 
 *次方。不得使用库函数，同时不需要考虑大数问题
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

/*在计算机内表示小数时(包括float和double型小数)都有误差。判断
 *两个小数是否相等，只能判断它们之间的绝对值是不是在一个很小的
 *范围内。如果两个数相差很小，比如小于0.0000001，
 *就可以认为它们相等。
 */
bool equal(double num1, double num2)
{
    if((num1 - num2 > -0.0000001)
        && (num1 - num2 < 0.0000001))
        return true;
    else
        return false;
}

// ====================测试代码====================
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
    // 底数、指数都为正数
    printf("Test1 begins.\n");
    Test(2, 3, 8, false);  

    // 底数为负数、指数为正数
    printf("Test2 begins.\n");
    Test(-2, 3, -8, false);

    // 指数为负数
    printf("Test3 begins.\n");
    Test(2, -3, 0.125, false);

    // 指数为0
    printf("Test4 begins.\n");
    Test(2, 0, 1, false);

    // 底数、指数都为0
    printf("Test5 begins.\n");
    Test(0, 0, 1, false);

    // 底数为0、指数为正数
    printf("Test6 begins.\n");
    Test(0, 4, 0, false);

    // 底数为0、指数为负数
    printf("Test7 begins.\n");
    Test(0, -4, 0, true);

    return 0;
}


