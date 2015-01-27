/*找出一个整数数组中第二大的数*/
#include <stdio.h>

int find_second_biggest_num(int *a, int size)
{
    if(size < 2)
        return -1;

    int first, second, i;
    if(a[0] > a[1]) {
        first = a[0];
        second = a[1];
    }
    else {
        first = a[1];
        second = a[0];
    }
    for(i = 2; i < size-1; i++) {
        if(a[i] >= first) {
            first = a[i];
            second = first;
        }
        else if(a[i] > second) {
            second = a[i];
        }
    }
    return second;
}

void main()
{
    int a[10] = {1,2,3,4,5,6,34,8,5,34};
    int second_biggest = find_second_biggest_num(a, 10);
    printf("the second biggest num is %d\n", second_biggest);
}
