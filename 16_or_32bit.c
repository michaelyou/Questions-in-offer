#include <stdio.h>
#include <math.h>

/*�жϻ�����16λ����32λ*/
/*�ϸ�����������벻�ԣ���Ϊint��64λ������Ҳ��32bit*/

void main()
{
    //'~'�ǰ�λȡ��
    int i = ~0; 
    if((unsigned int)i == 65535)
        printf("this is a 16bit computer\n");
    else if((unsigned int)i == (pow(2, 32) - 1))
        printf("this is a 32bit computer\n");
    //�������ǲ��Եģ���64λ������intҲ��32�� 
//  else if((unsigned int)i == (pow(2, 64) - 1))            
//      printf("this is a 64bit computer\n");
}

