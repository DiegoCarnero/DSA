'''
In how many ways can we solve the sum of the coins
Time Complexity: m^n
'''
from collections import defaultdict

def how_many_ways(m, coins):
    memo = defaultdict(lambda: 0)
    memo[0] = 1

    for i in range(1, m+ 1):
        # memo[i] = 0

        for coin in coins:
            subproblem = i - coin
            if subproblem < 0:
                continue

            memo[i] = memo[i] + memo[subproblem]

        return memo[m]

def how_many_ways2(m, coins):
    cache = {}

    def dfs(i, a):
        if a == m:
            return 1
        if a > m:
            return 0
        if i == len(coins):
            return 0
        if (i, a) in cache:
            return cache[(i, a)]
        
        cache[(i,a)] = dfs(i, a + coins[i]) + dfs(i + 1, a)
        return cache[(i, a)]
    
    return dfs(0,0)

def how_many_ways3(m, coins):
    '''
    Time and space complex: O(m*n)
    '''
    dp = [[0] * (len(coins) + 1) for i in range(m + 1)]
    dp[0] = [1] * (len(coins) + 1)

    for a in range(1, m + 1):
        for i in range(len(coins) - 1, -1, -1):
            dp[a][i] = dp[a][i + 1]
            if a - coins[i] >= 0:
                dp[a][i] += dp[a - coins[i]][i]
    return dp[m][0]

def how_many_ways4(m, coins):
    '''
    Save space by traversing the matrix in different order
    Space complexity: O(n)
    '''
    dp = [0] * (m + 1)
    dp[0] = 1

    for i in range(len(coins) - 1, -1, -1):
        nextDP = [0] * (m + 1)
        nextDP[0] = 1

        for a in range(1, m + 1):
            nextDP[a] = dp[a]
            if a - coins[i] >= 0:
                nextDP[a] += nextDP[a - coins[i]]
        dp = nextDP

    return dp[m]

print(how_many_ways(5, [1, 4, 5]))

print(how_many_ways(87, [1, 4, 5, 8]))

print(how_many_ways2(5, [1, 4, 5]))