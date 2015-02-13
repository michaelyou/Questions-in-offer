/*删除整形数组内的重复元素,数组是已排序的数组*/
#include <stdio.h>
#include <stdlib.h>
int delete_repeat_element(int *a, int n) {
    if(n < 2)
        exit(0);        //0 is normal, 1 is abnormal
    int i = 0;
    int j = 1;
    while(j < n) {
        if(a[i] == a[j])
            j++;
        else {
            i++;
            a[i] = a[j];
            j++;
        }
    }

    return i;
}

int main()
{
    int a[16] = {1,1,2,2,3,3,3,3,4,5,5,5,5,523,545,545};
    int num = delete_repeat_element(a, 16);
    int i;
    for(i = 0; i <= num; i++)
        printf("%d ", a[i]);
    printf("\n");
}
