#include <stdio.h>

/*在32位系统中size_t是4字节的，在64位系统中，size_t是8字节的*/
/*size_t是标准C库中定义的，应为unsigned int，
  在64位系统中为 long unsigned int
  它是一个基本的无符号整数的C/C++类型，它是sizeof操作符返回的结果类型
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
