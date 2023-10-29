'''
Given a set of coins={c1, c2,... ck} and a target sum of money m, what's the minimum number of coins that form the sum m?

minimum_coins(coins, m) returns the minimum number of coins required for a sum m
    minimum_coins(coins, 0) = 0
    minimum_coins(coins, m) = ?
'''
def min_ignore_none(a,b):
    if a is None:
        return b
    if b is None:
        return a
    return min(a,b)

def minimum_coins(coins, m):
    if m == 0:
        answer = 0
    else:
        answer = None
        for coin in coins:
            subproblem = m - coin
            if subproblem < 0:
                # Skip solutions where we try to reach [m] from a negative subproblem
                continue
            answer = min_ignore_none(
                answer,
                minimum_coins(coins, subproblem) + 1)
    return answer

memo = {}

def minimum_coins_memo(coins, m):
    if m in memo:
        return memo[m]

    if m == 0:
        answer = 0
    else:
        answer = None
        for coin in coins:
            subproblem = m - coin
            if subproblem < 0:
                # Skip solutions where we try to reach [m] from a negative subproblem
                continue
            answer = min_ignore_none(
                answer,
                minimum_coins(coins, subproblem) + 1)
    memo[m] = answer
    return answer

def minimum_coins_memo_non_recursive(coins, m):
    memo = {}

    memo[0] = 0
    for i in range(1, m + 1):
        for coin in coins:
            subproblem = i - coin
            if subproblem < 0:
                continue
            memo[i] =  min_ignore_none(memo.get(i), memo.get(subproblem) + 1)   # get returns None
    return memo[m]

print(minimum_coins([1, 4, 5], 13))

print(minimum_coins_memo_non_recursive([1, 4, 5], 150))

'''
Time complexity memo: O(M*K)
'''