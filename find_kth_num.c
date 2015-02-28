/*Ѱ�����������ĵ�k����*/

/*���ݽ��ٵ�ʱ��������������ַ��������ݶ��ʱ��Ӧ���ö����򣬾���
�����⣬Ѱ������k������Ӧ�ý���һ��k��С��С����
 */

#include <stdio.h>
#include <stdlib.h>

int swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


int partition(int *array, int length, int left, int right)
{
    if(array == NULL || length <= 0 || left < 0 || 
       right >= length || left >= length)
        exit(-1);

        
    if(left < right){
        int k = (left + right) / 2;
        int key = array[k];
        swap(&array[k], &array[right]);
        int i = left + 1;
        int j = right;

        while(1) {
            while((i < right) && (array[i] < key))
                i++;
            while((j > left) && (array[j] > key))
                j--;

            if(i < j) {
                swap(&array[i], &array[j]);

                if(array[i] == array[j] && array[i] == key)
                    i++;
            }
            else
                break;
        }
        
        swap(&array[i], &array[right]);

        return i;
    }
}

int find_least_kth_num(int *array, int n, int k)
{
    int index;
    int start = 0;
    int end = n-1;
    index = partition(array, n, start, end);
    while(index != k-1) {
        if(index < k-1) {
            start = index + 1;
            index = partition(array, n, start, end);
        }
        else {
            end = index - 1;
            index = partition(array, n, start, end);
        }
    }

    int i;
    for(i = 0; i <= index; i++)
        printf("%4d", array[i]);

    printf("\n");    
}



int main(int argc, char **argv)
{
    int a[11] = {2,4,6,7,1,23,12,2,4,6,9};
    find_least_kth_num(a,11,10);
}
