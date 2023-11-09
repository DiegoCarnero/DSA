'''
Example 1:

    Input: nums = [3,1,5,8]
    Output: 167
    Explanation:
        nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
        coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

Example 2:

Input: nums = [1,5]
Output: 10
'''

'''
def maxCoins(nums):
    nums = [1] + nums + [1]
    dp = {}

    def dfs(l, r):
        if l > r:
            return 0    # no quedan globos
        if (1, r) in dp:
            return dp[(1, r)]
        
        dp[(l, r)] = 0
        for i in range(l, r + 1):
            coins = nums[l - 1] * nums[i] * nums[r + 1]
            coins += dfs(l, i - 1) + dfs(i + 1, r)
            dp[(l, r)] = max(dp[(l, r)], coins)
        return dp[(l, r)]

    return dfs(1, len(nums)-2)
'''

def maxCoins(balloons):
    N = len(balloons)
    A = [1] + balloons + [1]# Add Bordering Balloons
    dp = [[0 for x in range(N + 2)] for y in range(N + 2)]# Declare DP Array
     
    for length in range(1, N + 1):
        for left in range(1, N-length + 2):
            right = left + length -1
 
            # For a sub-array from indices left, right
            # This innermost loop finds the last balloon burst
            for last in range(left, right + 1):
                dp[left][right] = max(dp[left][right], \
                                      dp[left][last-1] + \
                                      A[left-1]*A[last]*A[right + 1] + \
                                      dp[last + 1][right])
    return(dp[1][N])


A = [1, 2, 3, 4]
print(maxCoins(A))