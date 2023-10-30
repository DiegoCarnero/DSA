'''
Given s1, s2 s3 find whether s3 is formed by an interleaving of all other strings.

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
'''

def isInterleaveable_memo(s1, s2, s3):
    dp = {}

    def dfs(i, j):
        if i == len(s1) and j == len(s2):
            return True
        if (i, j) in dp:
            return dp[(i, j)]
        # ndx in bounds AND char matches s3 char AND same for next char
        if i < len(s1) and s1[i] == s3[i + j] and dfs(i + 1, j):
            return True
        if j < len(s2) and s2[j] == s3[i + j] and dfs(i, j + 1):
            return True
        dp[(i, j)] = False
        return False
    return dfs(0,0)

def isInterleaveable_dynamic(s1, s2, s3):
    dp = {}

    if len(s1) + len(s2) != len(s3):
        return False

    dp = [[False] * (len(s2) + 1) for i in range(len(s1) + 1)]
    dp[len(s1)][len(s2)] = True

    for i in range(len(s1), -1, -1):
        for j in range(len(s2), -1, -1):
            if i < len(s1) and s1[i] == s3[i + j] and dp[i + 1][j]:
                dp[i][j] = True
            if j < len(s2) and s2[j] == s3[i + j] and dp[i][j + 1]:
                dp[i][j] = True
    
    return dp[0][0]

print(isInterleaveable_dynamic('aabcc','dbbca','aadbbcbcac'))
print(isInterleaveable_memo('aabcc','dbbca','aadbbcbcac'))