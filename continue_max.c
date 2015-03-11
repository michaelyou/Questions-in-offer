/*在字符串中找出连续最长的数字串，并把这个串的长度返回，
并把这个最长数字串赋给其中一个函数参数outputstr所指内存。
例如："abcd12345ed125ss123456789"的首地址传给intputstr后，
函数将返回9，*/
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

    //找到数字子串的第一个数字，位置记录在tmp中
    while(*p != '\0') {
        while(!isdigit(*p)) {
            p++;
        }
        char *tmp = p; 

        //计算这个子串的长度
        int sum = 0;
        while(isdigit(*p)) {
            sum++;
            p++;
        }

        //如果这个子串比之前保存的最长子串长，就修改保存
        //的最大长度和子串的初始位置
        if(sum > max_len) {
            begin = tmp;
            max_len = sum;
        }
    }

    //memcpy后的out_put字符串最后没有'\0'
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
