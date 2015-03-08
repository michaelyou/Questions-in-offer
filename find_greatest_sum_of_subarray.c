/*输入一个整形数组，数组里有正数也有负数。
数组中连续的一个或多个整数组成一个子数组，每个子数组都有一个和。
求所有子数组的和的最大值。要求时间复杂度为O(n)。

例如输入的数组为1, -2, 3, 10, -4, 7, 2, -5，
和最大的子数组为3, 10, -4, 7, 2，
因此输出为该子数组的和18。*/

#include <stdio.h>

int find_greatest_sum_of_subarray(int *array, int length) {
    if(array == NULL || length <=0)
        return -1; //返回错误

    int sum = 0;
    int greatest_sum = 0x80000000;

    int i;
    for(i = 0; i < length; i++) {
        if(sum <= 0)
            sum = array[i];
        else
            sum += array[i];

        if(sum > greatest_sum)
            greatest_sum = sum;
    }

    return greatest_sum;
}

int main(int argc, char **argv)
{
    int a[10] = {-9,-2,-3,-10,-4,-7,-2,-5};
    int result = find_greatest_sum_of_subarray(a, 8);
    printf("%d\n", result);
    printf("%d\n", 0x80000001);
}
