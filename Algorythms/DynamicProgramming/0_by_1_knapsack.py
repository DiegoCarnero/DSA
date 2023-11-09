'''
Given N items each with some weight and profit, and bag of W max capacity.
Put items into the bad so the sum is the maximum possible 

Input: N = 3, W = 4, profit[] = {1, 2, 3}, weight[] = {4, 5, 1}
Output: 3

Input: N = 3, W = 3, profit[] = {1, 2, 3}, weight[] = {4, 5, 6}
Output: 0

Simple recursive: consider all subsets of smaller weight than W and calculate total weight and profit.

- Case 1 (include the Nth item): Value of the Nth item plus maximum value obtained by remaining N-1 items and remaining weight i.e. (W-weight of the Nth item).
- Case 2 (exclude the Nth item): Maximum value obtained by N-1 items and W weight.
- If the weight of the 'Nth' item is greater than 'W', then the Nth item cannot be included and Case 2 is the only possibility.
'''
t = list()

def knapsack_recursive(W, wt, val, n):
    if n == 0 or W == 0:
        return 0
    
    if wt[n-1] > W:
        return knapsack_recursive(W, wt, val, n-1)
    else:
        return max(
            val[n-1] + knapsack_recursive(W-wt[n-1], wt, val, n-1),
            knapsack_recursive(W, wt, val, n-1)
        )

def knapsack_memo(W, wt, val, n):
    if n == 0 or W == 0:
        return 0
    if t[n][W] != -1:
        return t[n][m]

    if wt[n-1] <= W:
        t[n][W] = max(
            val[n-1] + knapsack_memo(
                W-wt[n-1], wt, val, n-1),
                knapsack_memo(W, wt, val, n-1)
        )
        return t[n][W]
    elif wt[n-1] > W:
        t[n][W] = knapsack_memo(W, wt, val, n-1)
        return t[n][W]

def knapsack_dynamic(W, wt, val, n):
    K = [[0 for x in range(W + 1)] for x in range(n + 1)] 

    for i in range(n + 1):
        for w in range(W + 1):
            if i == 0 or w == 0:
                K[i][w] = 0
            elif wt[i-1] <= w:
                K[i][w] = max(
                    val[i-1] + K[i-1][w-wt[i-1]],
                    K[i-1][w]
                )
            else:
                K[i][w] = K[i-1][w]
    
    return K[n][W]

# se podría optimizar para space complexity O(W) ya que solo nos interesa la fila actual

if __name__ == "__main__":
    profit = [60, 100, 120]
    weight = [10, 20, 30]

    W = 50
    n = len(profit)
    t = [[-1 for i in range(W + 1)] for j in range(n + 1)] 
    print(knapsack_dynamic(W, weight, profit, n))

