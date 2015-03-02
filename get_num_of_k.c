/*ͳ��һ�����������������г��ֵĴ�����
���磬������������{1,2,3,3,3,3,4,5}������3
����3����������г�����4�Σ�������4.
 */

/*����ʹ�ö��ֲ��ҵķ������ҳ���һ��k�����һ��k. P204*/
#include <stdio.h>

int get_first_k(int *array, int n, int k)
{
    int start = 0;
    int end = n-1;
    
    while(start <= end) {        //�����жϵ�=�ǲ����ٵ�
        int mid = (start + end)/2;
        if(array[mid] == k) {
            if(mid == 0 || array[mid - 1] != k) //��ֹԽ��
                return mid;
            else
                end = mid - 1;
        }
        else if(array[mid] > k)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int get_last_k(int *array, int n, int k)
{
    int start = 0;
    int end = n-1;
    
    while(start <= end) {
        int mid = (start + end)/2;
        if(array[mid] == k) {
            if(mid == n-1 || array[mid + 1] != k)
                return mid;
            else
                start = mid + 1;
        }
        else if(array[mid] > k)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;

}

int get_num_of_k(int *array, int n, int k)
{
    int count = 0;
    
    if(array == NULL || n <= 0)
        return -1;

    int first = get_first_k(array, n, k);
    int last = get_last_k(array, n, k);
    
    if(first > -1 && last > -1)
        count = last - first + 1;

    return count;
}

int main(int argc, char **argv)
{
    int a[10] = {1,2,2,3,3,3,3,3,4,5};
    int count = get_num_of_k(a, 10, 4);
    printf("%d\n", count);
}
