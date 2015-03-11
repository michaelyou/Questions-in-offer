/*ʵ���ڴ濽������strcpy*/

#include <stdio.h>
#include <stdlib.h>

#if 0
void strcpy(void*dst, char * src, size_t len)
{
    if(dst == NULL || src == NULL)
        exit(-1);

    while(*src && len > 0) {  //��������'\0'û�п���
        *dst = *src;
        dst++;
        src++;
        len--;
    }        //û�з���ֵ����dst����ָ���ַ���β
}
#endif

char *my_memcpy(char *dst,const char *src,unsigned int count)
{
     if(dst == NULL || src == NULL) 
        return NULL;
     char * ret = dst;
     //Դ��ַ��Ŀ�ĵ�ַ���ص������ֽ�����ֽڿ���
     if (dst <= src || dst >= (src + count))
	 {
		 while(count--)
		 {
			 *dst = *src;
			 dst++;
			 src++;
		 }
	 }
	 //Դ��ַ��Ŀ�ĵ�ַ�ص������ֽ�����ֽڿ���
	 //���ʱ��src�ַ�����ֵ�ᱻ�ı䣬����Ϊconstֻ��˵����ͨ��
	 //src�޸�srcָ���ֵ��������ͨ��dst�ı���src��ֵ����������ġ�
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


