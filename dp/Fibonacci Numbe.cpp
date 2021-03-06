// leetcode- 509. Fibonacci Number

/*
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.

Given n, calculate F(n).

 

Example 1:
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
*/


class Solution {
public:
    int fib(int n) {
        if (n<=1)
            return n;
        int f[n+1];
        f[0]=0;
        f[1]=1;
        
        for(int i=2;i<=n;i++)
            f[i]=f[i-1]+f[i-2];
        return f[n];
        
    }
};
