#include <stdio.h>
#include <time.h>

/*递归非常慢*/
long fibonacci(unsigned int n)
{
    if(n <= 0)
        return 0;

    if(n == 1)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

/*用循环实现*/
long fibonacci_iterator(unsigned int n)
{
    int result[2] = {0, 1};
    if(n < 2)
        return result[n];

    long long fib_one = 0;
    long long fib_two = 1;

    long long fib_num = 0;
    int i;
    for(i = 2; i <= n; i++) {
        fib_num = fib_one + fib_two;
        fib_one = fib_two;
        fib_two = fib_num;
    }

    return fib_num;
}

#define n 50
int main(int argc, char **argv)
{
    clock_t start, end;
    double times = 0;

    start = clock();
    printf("fibonacci(%d) = %lld\n", n, fibonacci(n));
    end = clock();
    times = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The fibonacci took %fs\n", times);
    start = clock();
    printf("fibonacci(%d) = %lld\n", n, fibonacci_iterator(n));
    end = clock();
    times = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The fibonacci_iterator took %fs\n", times);
}
