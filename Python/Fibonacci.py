def fib(n):
    if n <= 2:
        result = 1
    else:
        result = fib(n - 1) + fib(n - 2)
    return result


def fib_memoization(n):
    memo = {}

    if n in memo:
        return memo[n]
    
    if n <= 2:
        result = 1
    else:
        result = fib(n - 1) + fib(n - 2)

    memo[n] = result
    return result


def fib_memo_non_recursive(n):
    memo = {}

    for i in range(1, n + 1):
        if i <= 2:
            result = 1
        else:
            result = memo[i - 1] + memo[i - 2]

        memo[i] = result
    return memo[n]

print(fib_memo_non_recursive(60))

'''
Problema: fib(5)
1. calcula fib(4)
    1.1 calcula fib(3)
        1.1.1 calcula fib(2) = 1
        1.1.2 calcula fib(1) = 1
    1.2 calcula fib(2) = 1
2. calcula fib(3)
    2.1 calcula fib(2) = 1
    2.2 calcula fib(1) = 1

Time complexity: 
    T_n = T_(n-1) + T_(n-2) + O(1) = ((1+sqrt(5))/2)^n
    T_n = 2 * T_(n-2). At least O(2^(n/2))

    ---

Time complexity memoization: O(N)
'''