'''
https://labuladong.gitbook.io/algo-en/i.-dynamic-programming/regularexpression
Given input string (s) and pattern (p), implement regex matching 
with support for '.' (any single char) and '*' (zero or moore of the preceeding element)

Matching should cover the entire input

Input:
    s = "aa"
    p = "a*"
Output:
    true
Explanation:
    '*' represents matching zero or more characters before the "*". 
    "a*" can either match "a" or "aa".

Input:
    s = "aab"
    p = "c*a*b"
Output:
    true
Explanation:
    'c' and 'a' can appear zero time or more than one times.

Input:
    s = "ab"
    p = ".*"
Output:
    true
Explanation:
    ".*" means matching zero or more('*') arbitrary character('.').
'''

def is_match(s, p):
    # empezamos ignorandop wildcards
    '''
    i = 0   # indice en s
    j = 0   # indice en p

    while j < len(p):
        if i >= len(s):
            return False
        i += 1
        j += 1
        if p[j] != s[i]:
            return False
    
    return j == len(s)
    '''
    # lo de arriba pero recursivo
    '''
    if p == '':
        return True
    first_match = (s != '') and p[0] == s[0]
    return first_match and is_match(s[1:], p[1:])
    '''
    # primero soporte para '.'
    if not bool(p):
        return not bool(s)
    first_match = bool(s) and p[0] in [s[0], '.']
    return first_match and is_match(s[1:], p[1:])
    # ahora soporte para '*'
    '''
    if not bool(p):
        return not bool(s)
    first_match = bool(s) and p[0] in [s[0], '.']
    if len(p) >= 2 and p[1] == '*': # solo debemos preocuparnos si se repite 0 o 1 veces. La recursión se encarga del resto
        return is_match(s, p[2:]) or first_match and is_match(s[1:], p[1:])
    '''

def is_match_memo(s, p):
    memo = {}

    def dp(i, j):
        if (i,j) in memo:
            return memo[(i,j)]
        if j == len(p):
            return i == len(s)
        
        first = i < len(s) and p[j] in [s[i], '.']

        if j <= len(p) - 2 and p[j + 1] == '*':
            ans = dp(i, j + 2) or first and dp(i + 1, j)
        else:
            ans = first and dp(i + 1, j)
        
        memo[(i, j)] = ans
        return ans

    return dp(0,0)

def is_match_recursive(s, p):
    if not bool(p):
        return not bool(s)
    first = bool(s) and p[0] in [s[0], '.']

    if len(p) >= 2 and p[1] == '*':
        return is_match_recursive(s, p[2:]) or first \
            and is_match_recursive(s[1:], p)
    else:
        return first and is_match_recursive(s[1:], p[1:])

def matches_memo(i, j, s, p, cache):
    if (i ==-1 and j == -1) or p[0:j+1] == '*':
        return True
    elif (i==-1) or (j==-1):
        return False
    
    if cache[i][j]:
        return cache[i][j]

    if s[i] == p[j]:
        cache[i][j] = matches_memo(i-1, j-1, s, p, cache)
        return cache[i][j]
    elif p[j] == '.':
        cache[i][j] = matches_memo(i-1, j-1, s, p, cache)
        return cache[i][j]
    elif p[j] == '*':
        cache[i][j] = matches_memo(i-1, j, s, p, cache) or matches_memo(i, j-1, s, p, cache)
        return cache[i][j]
    
    return False

def matches_memo_intro(s, p):
    m = len(s)
    n = len(p)
    cache = [[None for _ in range(m+1)] for _ in range(n+1)]
    return matches_memo(m-1,n-1, s, p, cache)

print(is_match('diego', 'diego'))
print(is_match_recursive('diego', 'di.go'))
print(matches_memo_intro('diego', 'di.go'))