/*请实现一个函数，把字符串中的每个空格替换成"%20"。
 *例如输入"We are happy."，则输出"We%20are%20happy."。
 */

#include <stdio.h>

#define LEN 100
 /*length 为字符数组string的总容量*/
 void ReplaceBlank(char string[], int length)
 {
     if(string == NULL && length <= 0)
         return;
 
     /*originalLength 为字符串string的实际长度*/
     int originalLength = 0;
     int numberOfBlank = 0;
     int i = 0;
     while(string[i] != '\0')
     {
         ++ originalLength;
 
         if(string[i] == ' ')
             ++ numberOfBlank;
 
         ++ i;
     }
 
     /*newLength 为把空格替换成'%20'之后的长度*/
     int newLength = originalLength + numberOfBlank * 2;
     if(newLength > length)
         return;
 
     int indexOfOriginal = originalLength;
     int indexOfNew = newLength;
     while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
     {
         if(string[indexOfOriginal] == ' ')
         {
             string[indexOfNew --] = '0';
             string[indexOfNew --] = '2';
             string[indexOfNew --] = '%';
         }
         else
         {
             string[indexOfNew --] = string[indexOfOriginal];
         }
 
         -- indexOfOriginal;
     }
 }
 
 void Test(char* testName, char string[], int length, char expected[])
 {
     if(testName != NULL)
         printf("%s begins: ", testName);
 
     ReplaceBlank(string, length);
 
     if(expected == NULL && string == NULL)
         printf("passed.\n");
     else if(expected == NULL && string != NULL)
         printf("failed.\n");
     else if(strcmp(string, expected) == 0)
         printf("passed.\n");
     else
         printf("failed.\n");
 }
 
 // 空格在句子中间
 void Test1()
 {
    
     char string[LEN] = "hello world";
     Test("Test1", string, LEN, "hello%20world");
 }
 
 // 空格在句子开头
 void Test2()
 {
   
     char string[LEN] = " helloworld";
     Test("Test2", string, LEN, "%20helloworld");
 }
 
 // 空格在句子末尾
 void Test3()
 {
     
     char string[LEN] = "helloworld ";
     Test("Test3", string, LEN, "helloworld%20");
 }
 
 // 连续有两个空格
 void Test4()
 {
     
     char string[LEN] = "hello  world";
     Test("Test4", string, LEN, "hello%20%20world");
 }
 
 // 传入NULL
 void Test5()
 {
     Test("Test5", NULL, 0, NULL);
 }
 
 // 传入内容为空的字符串
 void Test6()
 {
     
     char string[LEN] = "";
     Test("Test6", string, LEN, "");
 }
 
 //传入内容为一个空格的字符串
 void Test7()
 {
     
     char string[LEN] = " ";
     Test("Test7", string, LEN, "%20");
 }
 
 // 传入的字符串没有空格
 void Test8()
 {
    
     char string[LEN] = "helloworld";
     Test("Test8", string, LEN, "helloworld");
 }
 
 // 传入的字符串全是空格
 void Test9()
 {
     
     char string[LEN] = "   ";
     Test("Test9", string, LEN, "%20%20%20");
 }
 
 int main(int argc, char* argv[])
 {
     Test1();
     Test2();
     Test3();
     Test4();
     Test5();
     Test6();
     Test7();
     Test8();
     Test9();
 
     return 0;
 }
 
