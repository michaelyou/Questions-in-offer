/*����a[N]�������1��N-1����������ĳ�����ظ�һ�Ρ�
дһ���������ҳ����ظ�������ʱ�临�Ӷȱ���Ϊo��N��*/

/*����һ������Ϊn-1�Ҿ�Ϊ'0'��ɵ��ַ�����
Ȼ���ͷ����a[n]���飬ȡÿ������Ԫ��a[i]��ֵ��
�����Ӧ���ַ����е���Ӧλ����1������Ѿ��ù�1�Ļ���
��ô���������ظ�������������λͼ��ʵ�ֵġ�*/

#include <stdio.h>
#include <stdlib.h>

int find_repeat(int *A, int n)
{
    //int tmp[n-1] = {0}; �ɱ䳤���鲻�ܱ���ʼ��
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
