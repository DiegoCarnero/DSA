'''
Given an NxM grid, in how many ways can a rabbit get to the from the top-left to the bottom-right corner if it can only move down or right.
[🐇][ ][ ]
[  ][ ][ ]
Solution = 3
    right right down
    right down right
    down right right
Each move swrinks the grid.
When the rabbit reaches the lowest row, it can move down anymore, same thing for moving right and the right-most column
'''

def grid_paths(n, m):
    memo = {}

    for i in range(1, n + 1):
        memo[(i, 1)] = 1
    for j in range(1, m + 1):
        memo[(1, j)] = 1
    
    for i in range(2, n + 1):
        for j in range(2, m + 1):
            memo[(i, j)] = memo[(i - 1, j)] + memo[(i, j - 1)]

    return memo[(n, m)]

print(grid_paths(18, 6))
print(grid_paths(75, 19))