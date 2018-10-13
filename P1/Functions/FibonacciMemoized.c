#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define size_max 100

int def_fib(int n,int memo[]){
    int result;

    if (memo[n] != NULL) return memo[n];
    
    if(n == 1 || n == 2) result = 1;

    else result = def_fib(n-1,memo) + def_fib(n-2,memo);

    memo[n] = result;

    return result;
}

int main()
{
    int memo[size_max] = {NULL};
    int n;
    scanf("%d", &n);
    printf("The number is :%d", def_fib(n,memo));
    return 0;
}
