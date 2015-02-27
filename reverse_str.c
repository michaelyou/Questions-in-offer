/*ʵ���ַ�����ת���������κ�ϵͳ��������ʱ�临�Ӷ���С*/

#include<stdio.h>

char *reverse_str(char *str) 
{
    int len = 0;
    char *start = str;
    while(str[len] != '\0')
        len++;
        
    char *end = start + len - 1;

    char tmp_ch;

    if(str != NULL) {
        while(start < end) {
            tmp_ch = *start;
            *start = *end;
            *end = tmp_ch;
            start++;
            end--;
        }
    }
    return str;
}

int main(int argc, char **argv)
{
    char a[10] = "helloworl";
    char *str = reverse_str(a);
    printf("%s", str);
    printf("\n");
    char *str2 = reverse_str(str);
    printf("%s", str2);
    printf("\n");
}
