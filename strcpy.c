/*实现内存拷贝函数strcpy*/

#include <stdio.h>
#include <stdlib.h>

#if 0
void strcpy(void*dst, char * src, size_t len)
{
    if(dst == NULL || src == NULL)
        exit(-1);

    while(*src && len > 0) {  //这里最后的'\0'没有拷贝
        *dst = *src;
        dst++;
        src++;
        len--;
    }        //没有返回值，而dst现在指向字符串尾
}
#endif

char *my_memcpy(char *dst,const char *src,unsigned int count)
{
     if(dst == NULL || src == NULL) 
        return NULL;
     char * ret = dst;
     //源地址和目的地址不重叠，低字节向高字节拷贝
     if (dst <= src || dst >= (src + count))
	 {
		 while(count--)
		 {
			 *dst = *src;
			 dst++;
			 src++;
		 }
	 }
	 //源地址和目的地址重叠，高字节向低字节拷贝
	 //这个时候src字符串的值会被改变，声明为const只是说不能通过
	 //src修改src指向的值。这里是通过dst改变了src的值，这是允许的。
	 else		
	 { 
		 dst = dst + count - 1;
		 src = src + count - 1; 
		 while(count--) 
		 {
			 *dst = *src;
			 dst--;
			 src--;
		 }
    }
	return ret;
}

int main(int argc, char **argv)
{
    char a[10] = "helloword";
    
    char *b = &a[2];
    char *c = my_memcpy(b, a, 9);
    printf("%s\n", a);
    printf("%s\b", c);
    
}


