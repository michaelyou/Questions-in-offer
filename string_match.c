/*字符串匹配算法，暴力匹配算法和KMP算法*/

#include <stdio.h>
#include <string.h>

/*暴力匹配算法*/
/*1.如果当前字符匹配成功（即S[i] == P[j]），则i++，j++，继续匹配下一个字符；
  2.如果失配（即S[i]! = P[j]），令i = i - (j - 1)，j = 0。
  相当于每次匹配失败时，i 回溯，j 被置为0
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

    /*匹配成功，返回匹配到字符串在原字符串中的位置*/
    if(j == plen)
        return i-j;
    else
        return -1;
}


/*KMP匹配算法*/
//优化过后的next 数组求法  
void GetNextval(char* p, int next[])  
{  
    int pLen = strlen(p);  
    next[0] = -1;  
    int k = -1;  
    int j = 0;  
    while (j < pLen - 1)  
    {  
        //p[k]表示前缀，p[j]表示后缀    
        if (k == -1 || p[j] == p[k])  
        {  
            ++j;  
            ++k;  
            //较之前next数组求法，改动在下面4行  
            if (p[j] != p[k])  
                next[j] = k;   //之前只有这一行  
            else  
                //因为不能出现p[j] = p[ next[j ]]，所以当出现时需要继续递归，k = next[k] = next[next[k]]  
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
        //①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++      
        if (j == -1 || s[i] == p[j])  
        {  
            i++;  
            j++;  
        }  
        else  
        {  
            //②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]      
            //next[j]即为j所对应的next值        
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
