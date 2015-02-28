#include <stdio.h>

#define ElementType int
/* Return median of left, Center and Right */  
/* Order these and hide the pivot */ 
#define Cutoff (2)

void   
InsertionSort( ElementType A[ ], int N )  
{  
    int j, P;  
  
    ElementType Tmp;  
    for ( P = 1; P < N; P++)  
    {  
        Tmp = A[ P ];  
        for ( j = P; j > 0 && A[ j - 1 ] > Tmp; j-- )  
            A[ j ] = A[ j - 1 ];  
        A[ j ] = Tmp;  
    }  
}


void Swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
ElementType   
Median3( ElementType A[ ], int Left, int Right )  
{  
    int Center = ( Left + Right ) / 2;  
  
    if ( A[ Left ] > A[ Center ] )  
        Swap( &A[ Left ], &A[ Center ] );  
    if ( A[ Left ] > A[ Right ] )  
        Swap( &A[ Left ], &A[ Right ] );  
    if ( A[ Center ] > A[ Right ] )  
        Swap( &A[ Center ], &A[ Right ] );  
  
    /* Invariant:A[ Left ] <= A[ Center ] <= A[ Right ] */  
  
    Swap( &A[ Center ], &A[ Right - 1 ] );  
    return A[ Right - 1 ];  
}  
  
void   
Qsort( ElementType A[ ], int Left, int Right )  
{  
    int i, j;  
    ElementType Pivot;  
  
    if ( Left < Right )  
    {  
        Pivot = (Left + Right) / 2;
        Swap(&A[Pivot], &A[Right]);
        i = Left; j = Right-1;  
        while(i < j)  
        {  
            while (i < Right && A[i] < Pivot) {i++;}  
            while (j > Left && A[j] > Pivot) {j--;}  
            if ( i < j )  
                Swap( &A[ i ], &A[ j] );    
        }  
        Swap( &A[ i ], &A[ Right ] ); /* Restore pivot */  
          
        Qsort( A, Left, i - 1 );  
        Qsort( A, i + 1, Right );  
    }  
}  

void swap(int *x,int *y)
{
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
}

int choose_pivot(int i,int j )
{
   return((i+j) /2);
}

void quick_sort(int list[],int left,int right)
{
   int key,i,j,k;
   if(left < right)
   {
      k = choose_pivot(left,right);
      swap(&list[right],&list[k]);
      key = list[right];
      i = left;
      j = right-1;
      
      while(1)
      {
         while((i < right) && (list[i] < key))
                i++;
         while((j > left) && (list[j] > key))
                j--;
         if( i < j) {
                swap(&list[i],&list[j]);
                #if 1
                if(list[i] == list[j] && list[i] == key) {
                    i++;
                    //j--;
                }
                #endif
         }
         else
            break;
      }
     // 交换两个元素的位置
      swap(&list[right],&list[i]);
     // 递归地对较小的数据序列进行排序
      quick_sort(list,left,i-1);
      quick_sort(list,i+1,right);
   }
} 
 


int main(int argc, char **argv) {
    //int a[1000] = {1,3,2,8,9,45,74,12,68,10,91,54,7,2,8,9};
    //merge_sort(a, 0, 12);
    int a[40] = {1,3,2,3,2,2,2,2,2,2,2,3,2,2,3,4};
    quick_sort(a, 0, 15);
    int i;
    for(i = 0; i < 16; i++)
        printf("%d ", a[i]);

    printf("\n");
}

