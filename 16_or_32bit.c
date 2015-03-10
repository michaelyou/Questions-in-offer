#include <stdio.h>
#include <math.h>

/*判断机器是16位还是32位*/
/*严格来讲这个代码不对，因为int在64位机器上也是32bit*/

void main()
{
    //'~'是按位取反
    int i = ~0; 
    if((unsigned int)i == 65535)
        printf("this is a 16bit computer\n");
    else if((unsigned int)i == (pow(2, 32) - 1))
        printf("this is a 32bit computer\n");
    //这两句是不对的，在64位机器上int也是32的 
//  else if((unsigned int)i == (pow(2, 64) - 1))            
//      printf("this is a 64bit computer\n");
}

