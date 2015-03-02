/*统计一个数字在排序数组中出现的次数。
例如，输入排序数组{1,2,3,3,3,3,4,5}和数字3
由于3在这个数组中出现了4次，因此输出4.
 */

/*本题使用二分查找的方法，找出第一个k和最后一个k. P204*/
#include <stdio.h>

int get_first_k(int *array, int n, int k)
{
    int start = 0;
    int end = n-1;
    
    while(start <= end) {        //这里判断的=是不能少的
        int mid = (start + end)/2;
        if(array[mid] == k) {
            if(mid == 0 || array[mid - 1] != k) //防止越界
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
