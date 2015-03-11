////���������������a1��a2���ڴ���a1��ĩβ���㹻���ʣ��ռ�����a2  
//ʵ��һ��������a2�����е����ֲ��뵽a1���������е�����������ġ� 
#include <stdio.h> 

#define SIZEOFMATRIX1 100

int mergaMatrix(int* matrix1,int* matrix2, 
                 int lenofmtrx1,int lenofmtrx2,int sizeofmatrix1) 
{ 
    if(sizeofmatrix1 != 0 && matrix1 != NULL && lenofmtrx1 !=0  
        &&  matrix2 != NULL && lenofmtrx2 != 0 )  
    { 

        int* pNewMatrix1 = matrix1 + lenofmtrx1 + lenofmtrx2 -1; 
        int* pMatrix1 = matrix1 + lenofmtrx1 - 1; 
        int* pMatrix2 = matrix2 +lenofmtrx2 - 1; 
   
        while(pMatrix1 >= matrix1 && pMatrix2 >= matrix2) 
        { 
            if(*pMatrix1 >= *pMatrix2) 
                *pNewMatrix1-- = *pMatrix1--; 
            else 
                *pNewMatrix1-- = *pMatrix2--; 
        } 
        while(pMatrix1 >= matrix1) 
        { 
            *pNewMatrix1-- = *pMatrix1--; 
        } 
        while(pMatrix2 >= matrix2) 
        { 
            *pNewMatrix1-- = *pMatrix2--; 
        } 
    } 
    return (lenofmtrx1 + lenofmtrx2); 
} 
   
//��Ԫ���� 
void test(int* matrix1,int* matrix2, 
          int lenofmtrx1,int lenofmtrx2,int sizeofmatrix1) 
{ 
    int i;
    if(matrix1 != NULL) 
    { 
        int i;
        for(i=0; i<lenofmtrx1;i++) 
        { 
            printf("%d ",*(matrix1+i)); 
        } 
    } 
    printf("\n"); 
    if(matrix2 != NULL){ 
        for(i=0; i<lenofmtrx2;i++) 
        { 
            printf("%d ",*(matrix2+i)); 
        } 
    } 
    printf("\n"); 
    mergaMatrix(matrix1,matrix2,lenofmtrx1,lenofmtrx2,sizeofmatrix1); 
    for(i=0; i<lenofmtrx1+lenofmtrx2;i++) 
    { 
        printf("%d ",*(matrix1+i)); 
    } 
    printf("\n"); 
} 
//һ����� 
void test1() 
{ 
    int lenofmtrx1 = 3; 
    int matrix1[SIZEOFMATRIX1] = {1,3,5}; 
    int lenofmtrx2 = 4; 
    int matrix2[] = {2,4,6,8}; 
    test(matrix1,matrix2,lenofmtrx1,lenofmtrx2,SIZEOFMATRIX1); 
} 
//����һ���������ȫ��С������һ�� 
void test2() 
{  
    int lenofmtrx1 = 3; 
    int matrix1[SIZEOFMATRIX1] = {1,3,5}; 
    int lenofmtrx2 = 4; 
    int matrix2[] = {6,7,8,9}; 
    test(matrix1,matrix2,lenofmtrx1,lenofmtrx2,SIZEOFMATRIX1); 
} 
//����һ��Ϊ�� 
void test3() 
{  
    int lenofmtrx1 = 3; 
    int matrix1[SIZEOFMATRIX1] = {1,3,5}; 
    test(matrix1,NULL,lenofmtrx1,0,SIZEOFMATRIX1); 
} 
//������Ϊ�� 
void test4() 
{ 
    test(NULL,NULL,0,0,SIZEOFMATRIX1); 
} 
int main() 
{ 
    test1(); 
    test2(); 
    test3(); 
    test4(); 
    return 0; 
} 

