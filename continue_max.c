/*���ַ������ҳ�����������ִ�������������ĳ��ȷ��أ�
�����������ִ���������һ����������outputstr��ָ�ڴ档
���磺"abcd12345ed125ss123456789"���׵�ַ����intputstr��
����������9��*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int continue_max(char *input_str, char *output_str)
{
    if(input_str == NULL || output_str == NULL)
        return -1;
        
    int max_len = 0;
    char *p = input_str;
    char *begin = NULL;

    //�ҵ������Ӵ��ĵ�һ�����֣�λ�ü�¼��tmp��
    while(*p != '\0') {
        while(!isdigit(*p)) {
            p++;
        }
        char *tmp = p; 

        //��������Ӵ��ĳ���
        int sum = 0;
        while(isdigit(*p)) {
            sum++;
            p++;
        }

        //�������Ӵ���֮ǰ�������Ӵ��������޸ı���
        //����󳤶Ⱥ��Ӵ��ĳ�ʼλ��
        if(sum > max_len) {
            begin = tmp;
            max_len = sum;
        }
    }

    //memcpy���out_put�ַ������û��'\0'
    memcpy(output_str, begin, max_len);
    output_str[max_len] = '\0'; 

    return max_len;
}

int main(int argc, char **argv)
{
    char a[40] = "hello12356wo12345io1238p19ui123456123";
    char b[40];
    int max_len = continue_max(a,b);
    printf("%s, the length is %d\n", b, max_len);
}
