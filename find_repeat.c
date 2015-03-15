/*数组a[N]，存放了1至N-1个数，其中某个数重复一次。
写一个函数，找出被重复的数字时间复杂度必须为o（N）*/

/*申请一个长度为n-1且均为'0'组成的字符串。
然后从头遍历a[n]数组，取每个数组元素a[i]的值，
将其对应的字符串中的相应位置置1，如果已经置过1的话，
那么该数就是重复的数。就是用位图来实现的。*/

#include <stdio.h>
#include <stdlib.h>

int find_repeat(int *A, int n)
{
    //int tmp[n-1] = {0}; 可变长数组不能被初始化
    int *tmp = calloc(n, sizeof(int));
    int i;
    for(i = 0; i < n; i++) {
        if(tmp[A[i]] != 0)
            return A[i];
        else
            tmp[A[i]] = 1;
    }
}


int main(int argc, char **argv) {
    int a[10] = {1,2,3,4,5,6,7,8,9,6};

    int result = find_repeat(a, 10);
    printf("%d\n", result);
}
