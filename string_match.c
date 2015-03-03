/*�ַ���ƥ���㷨������ƥ���㷨��KMP�㷨*/

#include <stdio.h>
#include <string.h>

/*����ƥ���㷨*/
/*1.�����ǰ�ַ�ƥ��ɹ�����S[i] == P[j]������i++��j++������ƥ����һ���ַ���
  2.���ʧ�䣨��S[i]! = P[j]������i = i - (j - 1)��j = 0��
  �൱��ÿ��ƥ��ʧ��ʱ��i ���ݣ�j ����Ϊ0
  */
int voilent_match(char *s, char *p) {
    int plen = strlen(p);
    int slen = strlen(s);

    int i = 0;
    int j = 0;

    while(i < slen && j < plen) {
        if(s[i] == p[j]) {
            i++;
            j++;
        }
        else {
            i = i - j + 1;
            j = 0;
        }
    }

    /*ƥ��ɹ�������ƥ�䵽�ַ�����ԭ�ַ����е�λ��*/
    if(j == plen)
        return i-j;
    else
        return -1;
}


/*KMPƥ���㷨*/
//�Ż������next ������  
void GetNextval(char* p, int next[])  
{  
    int pLen = strlen(p);  
    next[0] = -1;  
    int k = -1;  
    int j = 0;  
    while (j < pLen - 1)  
    {  
        //p[k]��ʾǰ׺��p[j]��ʾ��׺    
        if (k == -1 || p[j] == p[k])  
        {  
            ++j;  
            ++k;  
            //��֮ǰnext�����󷨣��Ķ�������4��  
            if (p[j] != p[k])  
                next[j] = k;   //֮ǰֻ����һ��  
            else  
                //��Ϊ���ܳ���p[j] = p[ next[j ]]�����Ե�����ʱ��Ҫ�����ݹ飬k = next[k] = next[next[k]]  
                next[j] = next[k];  
        }  
        else  
        {  
            k = next[k];  
        }  
    }  
} 

int KmpSearch(char* s, char* p)  
{  
    int i = 0;  
    int j = 0;  
    int sLen = strlen(s);  
    int pLen = strlen(p);
    int next[pLen];
    GetNextval(p, next);
    
    while (i < sLen && j < pLen)  
    {  
        //�����j = -1�����ߵ�ǰ�ַ�ƥ��ɹ�����S[i] == P[j]��������i++��j++      
        if (j == -1 || s[i] == p[j])  
        {  
            i++;  
            j++;  
        }  
        else  
        {  
            //�����j != -1���ҵ�ǰ�ַ�ƥ��ʧ�ܣ���S[i] != P[j]�������� i ���䣬j = next[j]      
            //next[j]��Ϊj����Ӧ��nextֵ        
            j = next[j];  
        }  
    }  
    if (j == pLen)  
        return i - j;  
    else  
        return -1;  
} 


/***********text************/

int main(int argc, int argv)
{
    char s[11] = "helloworld";
    char p[6] = "rld";
    int result = KmpSearch(s, p);
    if(result != -1)
        printf("%d\n", result);
}
