/*����һ���������飬������������Ҳ�и�����
������������һ�������������һ�������飬ÿ�������鶼��һ���͡�
������������ĺ͵����ֵ��Ҫ��ʱ�临�Ӷ�ΪO(n)��

�������������Ϊ1, -2, 3, 10, -4, 7, 2, -5��
������������Ϊ3, 10, -4, 7, 2��
������Ϊ��������ĺ�18��*/

#include <stdio.h>

int find_greatest_sum_of_subarray(int *array, int length) {
    if(array == NULL || length <=0)
        return -1; //���ش���

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
