/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
P163
 */

#include <stdio.h>
#include <stdlib.h>

/*-------------------------解法一---------------------------*/
/*如果将数组排序，因为这个数字出现的次数超过数组长度的一半，所以
  下标为n/2的数字就是我们要找的数。利用partition，可以轻易找到
  数组中第k大的数字

  使用这种方法需要允许修改数组的值
  */

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int *array, int length, int start, int end)
{
    if(array == NULL || length <= 0 || start < 0 || 
       end >= length || start >= length)
        exit(-1);
        
    if(start < end) {
        int k = (start + end)/2;
        swap(&array[end], &array[k]);

        int i = start;
        int j = end - 1;

        while(1) {
            while(i < end && array[i] < array[start])
                i++;
            while(j > start && array[j] > array[start])
                j--;
            if(i < j) {
                swap(&array[i], &array[j]);
                
                if(array[i] == array[j] && array[i] == array[start]) {
                        //i++;
                        j--;
                }
            }
            else
                break;
        }

        swap(&array[start], &array[j]);

        return j;
    }
}


int more_than_half_num(int *array, int length)
{
    int middle = length >> 1;
    int start = 0;
    int end = length - 1;
    int index = partition(array, length, start, end);

    while(index != middle) {
        if(index > middle) {
            end = index - 1;
            index = partition(array, length, start, end);
        }
        if(index < middle) {
            start = index + 1;
            index = partition(array, length, start, end);
        }
    }

    return array[index];  
        
}

/*------------------------解法二-----------------------------*/

int more_than_half_num2(int *array, int n)
{
    if(array == NULL || n < 0)
        exit(0);
    int result = array[0];
    int time = 1;
    int i;
    for(i = 0; i < n; i++) {
        if(time == 0) {
            result = array[i];
            time = 1;
        }
        else if(array[i] == result)
            time++;
        else
            time--;
    }

    printf("%d\n", time);
    return result;
}


int main(int argc, char **argv)
{
    int a[20] = {3,1,2,3,4,5,3,3,3,3,4,4,4,4,4,4,4,4,4,4};
    int half = more_than_half_num2(a, 20);
    printf("%d \n", half);

    return 0;
}
