#include <stdio.h>

/*��32λϵͳ��size_t��4�ֽڵģ���64λϵͳ�У�size_t��8�ֽڵ�*/
/*size_t�Ǳ�׼C���ж���ģ�ӦΪunsigned int��
  ��64λϵͳ��Ϊ long unsigned int
  ����һ���������޷���������C/C++���ͣ�����sizeof���������صĽ������
  */
void main()
{
    int i = sizeof(size_t);
    switch(i) {
        case 4:
            printf("this computer is 32 bit\n");
            break;
        case 8:
            printf("this computer is 64 bit\n");
            break;
        default:
            printf("other\n");
            break;
    }
}
