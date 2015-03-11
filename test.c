#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
  
int ContinueMax(char * output, const char * input)  
{  
    if (NULL == input)return 0;  
    const char* begin = NULL;  
    int max_len = 0;  
    const char * p = input;
    for (;*p != '\0';)
    {  
        if (!isdigit(*p))  
        {  
            p++;  
            continue;  
        }  
        int sum  = 0;  
        const char * tmp = p;  
        for(;isdigit(*p); p++, sum++);  
        if (sum > max_len)  
        {  
            begin = tmp;  
            max_len = sum;  
        }  
    }  
    memcpy(output, begin, max_len);  
    return max_len;  
}  
  
  
  int main(int argc, char **argv)
  {
      char a[40] = "hello12356wo12345io1238p19ui123456123";
      char b[40];
      int max_len = ContinueMax(b,a);
      printf("%s, the length is %d\n", b, max_len);
  }

