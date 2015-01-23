/*��ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"��
 *��������"We are happy."�������"We%20are%20happy."��
 */

#include <stdio.h>

#define LEN 100
 /*length Ϊ�ַ�����string��������*/
 void ReplaceBlank(char string[], int length)
 {
     if(string == NULL && length <= 0)
         return;
 
     /*originalLength Ϊ�ַ���string��ʵ�ʳ���*/
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
 
     /*newLength Ϊ�ѿո��滻��'%20'֮��ĳ���*/
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
 
 // �ո��ھ����м�
 void Test1()
 {
    
     char string[LEN] = "hello world";
     Test("Test1", string, LEN, "hello%20world");
 }
 
 // �ո��ھ��ӿ�ͷ
 void Test2()
 {
   
     char string[LEN] = " helloworld";
     Test("Test2", string, LEN, "%20helloworld");
 }
 
 // �ո��ھ���ĩβ
 void Test3()
 {
     
     char string[LEN] = "helloworld ";
     Test("Test3", string, LEN, "helloworld%20");
 }
 
 // �����������ո�
 void Test4()
 {
     
     char string[LEN] = "hello  world";
     Test("Test4", string, LEN, "hello%20%20world");
 }
 
 // ����NULL
 void Test5()
 {
     Test("Test5", NULL, 0, NULL);
 }
 
 // ��������Ϊ�յ��ַ���
 void Test6()
 {
     
     char string[LEN] = "";
     Test("Test6", string, LEN, "");
 }
 
 //��������Ϊһ���ո���ַ���
 void Test7()
 {
     
     char string[LEN] = " ";
     Test("Test7", string, LEN, "%20");
 }
 
 // ������ַ���û�пո�
 void Test8()
 {
    
     char string[LEN] = "helloworld";
     Test("Test8", string, LEN, "helloworld");
 }
 
 // ������ַ���ȫ�ǿո�
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
 
