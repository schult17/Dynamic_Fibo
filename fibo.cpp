#include <iostream>

using namespace std;

//memoizing
int fibo(int n, int*& memo)
{
    if(memo[n] != -1)   return memo[n];
    
    int f;
    if(n <= 2)  f = 1;
    else    f = fibo(n - 1, memo) + fibo(n - 2, memo);
    
    memo[n] = f;
    return f;
}
//

//recursive
int Rfibo(int n)
{
    if(n <= 2)  return 1;
    
    return (Rfibo(n - 1) + Rfibo(n - 2));
}
//

int main()
{
    int n;
    cout << "Enter the fibonacci number to be calculated" << endl;
    cin >> n;
    
    //Bottom Up Approach
    int fib[n+1];
    for(int i = 0; i <= n; i++)
    {
        int f;
        if(i <= 2)  f = 1;
        else    f = fib[i - 1] + fib[i - 2];
        
        fib[i] = f;
    }
    cout << "Result from bottom up is: " << fib[n] << endl;
    //
    
    //initializing for memoize
    int* memo = new int[n + 1];
    for(int j = 0; j <= n; j++) memo[j] = -1;
    cout << "Result from memoized is: " << fibo(n, memo) << endl;
    //
    
    cout << "Result from recursion is: " << Rfibo(n) << endl;
    return 0;
}
