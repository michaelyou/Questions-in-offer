/*ʵ��strcmp���ַ����Ƚϳ���*/
#include <stdio.h>
#include <stdlib.h>


int strcmp(const char *src, const char *sub) {
    if(src == NULL || sub == NULL)
        return -1;


    //while((*src != '\0') && (*sub != '\0') && (*src == *sub)) {
    while(*src && *sub && (*src == *sub)) {
        sub++;
        src++;
    };

    /*ֻ�ǱȽ����Ƿ����
    if(*src == '\0' && (*sub == '\0'))
        return 0;
    else 
        return -1;
     */

    return *src - *sub;
}

int main(int argc, char **argv)
{
    char a[10] = "hello";
    char b[7] = "hello";

    if(strcmp(a,b) == 0)
        printf("they are the same\n");
    else
        printf("they are different\n");
}


