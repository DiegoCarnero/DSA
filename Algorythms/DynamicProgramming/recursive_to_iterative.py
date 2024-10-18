'''
Part1: https://www.youtube.com/watch?v=gK8KmTDtX8E
Part2: https://youtu.be/NA7u5GTh6fw

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
- len(coins) small
- coins[i] and amount medium
- coins are unique
- coins are positive
Return the number of combinations that make up that amount. 
- counting
- combinatorics formula
combination?
221 vs 122
- avoid duplicates
  - same elements
    - keep track of counts
  - different orders
    - pick any ordering and stick with it
    - allowed to sort
If that amount of money cannot be made up by any combination of the coins, return 0.
- divisibility or gcd??
You may assume that you have an infinite number of each kind of coin.
- resuse couns
- when to stop? chekc before going negative

Decision:
Find number of ways to make 5(amount) using 1, 2 and 5(coins)

Starting with the i-th coin, what are my actions?

Take i-th coin:
 - have to make 5 -1 = 4
 -              amount - coins[i], coins[i] <= amount
Skip i-th coin
 - have to move to i+1-th coin

take i -> amount - coins[i] actions: take 1, skip 1
skip -> i + 1, actions: take i + 1, skip i + 1

Recurrence relation - has side effects
amount: [0, amount]
i: [0, len(coins)]
size = O(len(coins) * amount)
cached complexity = take and skip are O(1)
time complexity = O(len(coins) * amount)
'''
from functools import cache
from collections import List


class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        # # Observation, simulation, recursion
        # @cache
        # def numWays_startingWith_toMake(i: int, x: int) -> int:
        #     if i == len(coins):
        #         return 1 if x == 0 else 0
        #     take = 0
        #     if coins[i] <= x:
        #         # Recursive calls must lead to a base case. Ya que un momento este if no se cumplirá, esta llamada es su propio case base
        #         take = numWays_startingWith_toMake(i, x - coins[i])
        #     skip = numWays_startingWith_toMake(i + 1, x)
        #     return take + skip
        # return numWays_startingWith_toMake(0, amount)
        '''
        Bounds:
            i: [0, len(coins)]
            x: [0, amount]
        Order
            Term i, x requires:
                take: i, x - coins[i]
                    - i does not change
                    - x-coins[i] before x
                    - small before big
                    - 0 before  amount
                skip: i + 1, x:
                    - x does not change
                    - i+1 before i
                    - big before small
                    - len(coins) before 0
        '''

        # # Base
        # num_ways_values = [[None] * (amount + 1) for i in range(len(coins) + 1)]

        # def numWays_startingWith_toMake(i: int, x: int) -> int:
        #     if i == len(coins):
        #         return 1 if x == 0 else 0
        #     take = 0
        #     if coins[i] <= x:
        #         take = num_ways_values[i][x - coins[i]]
        #     skip = num_ways_values[i + 1][x]
        #     return take + skip

        # # Bound.Order.take
        # for x in range(0, amount + 1):
        #     # Bound.Order.skip
        #     for i in range(len(coins), -1, -1):
        #         num_ways_values[i][x] = numWays_startingWith_toMake(i, x)

        # return num_ways_values[0][amount]

        # Optimized
        dp = [[None] * (amount + 1) for i in range(len(coins) + 1)]
        for x in range(0, amount + 1):
            for i in range(len(coins), -1, -1):
                if i == len(coins):
                    dp[i][x] = 1 if x == 0 else 0
                    continue
                take = 0
                if coins[i] <= x:
                    take = dp[i][x - coins[i]]
                skip = dp[i+1][x]
                dp[i][x] = take + skip
        return dp[0][amount]

        # Moar optimized
        dp = [[0] * (amount + 1) for i in range(len(coins) + 1)]
        dp[len(coins)][0] = 1

        for x in range(0, amount + 1):
            for i in range(len(coins)-1, -1, -1):
                dp[i][x] = dp[i + 1][x]
                if coins[i] <= x:
                    dp[i][x] += dp[i][x - coins[i]]
        return dp[0][amount]

        # Optimized-est
        # Values that are contant relative to the parameters
        # i+1 relativo a i. Para eso el bucle exterior debe ser el de i
        # dp[i][x] -> dp_i[x]
        # dp[i + 1] -> dp_i1 = dp_i al final del bucle exterior
        # 


'''
OBSERVATION
Read the problem statement 
    - Reduce to your own words
    - Read samples
Identify key words and phrases
    - Make concrete definitions
    - What is possible?
    - What is not possible?
    - Tunnel vision Revisit as needed
Identify directions of processing
    - Does the problem force you to go in a certain direction?
    - If any direction is good, which one is simplest or optimal?
Statement -> Properties
Main Ideas:
    Problem solving is not "pure pattern matching" and you don't have to rely on just your base intuition and guessing.
    Observation is the heart of problem solving. New problems require careful study of the properties.
    If there are too many properties with too many observations, you will forget them. Write them down so you don't have to rediscover them.
Consider this:
    This idea applies to every field. Think about doctors, lawyers, detectives, researchers, even athletes. Anyone who problem solves starts with making observations.


SIMULATION
Pick an example and work through it
    - Write out the decision/decisions 
    - Pick a starting place based on your observations
    - Identify the actions that can be made 
    - Identify the consequences of each decisions
    - Simulate the entire problem enough to gain structure
Replace values with variables
    - Working with values allows you to study 1 example
    - Working with variables allows to study an entire class of examples
Properties -> Structure
Main Ideas:
    Figuring out what technique you need to use does not have to be a guessing game.
    Working with generalized examples builds structure to abstract ideas.
    Instead of guessing the techniques, let the structure and observations reveal it to you.
Consider this:
    Writing proofs is basically just working on examples that are generalized with variables. Realizing this made proving my solutions much more approachable as someone who doesn't have a strong math background.


RECURSION
Start with the recurrence relation
    - Base case??? For what problem?
    - Actions -> Recursive calls
    - Consequences -> Transitions
    - Contributions -> Return value
    - Affected variables -> Parameters
Obey the rules of recursion
    1. Base cases must be correct
    2. Recursive calls shrink to a base case 
    3. Assume recursive calls are correct
Build bases cases from the calls 
    - Name the function on it's promises! 
    - Avoid simulating/visualizing, it's painful 
    - Recursion is naturally inductive
    - Read aloud and see if it makes sense
Structure → Technique
Main Ideas:
    Technique requires a solid understanding of where, why, and how.
    Recursion
    Where: Subtasks have the same shape Why: To simplify a problem with induction How: Use induction!!!
    Do not think more than 1 recurrence down Name a function on it promises to do No prints or simulation, just read it aloud!
Consider this:
    You are one of two types of people: you can read recurrence relations or you are one of two types of people


BOUNDS
Identify a function's valid arguments
    - Usually can evaluate each individually
    - Base cases and starting args as endpoints

Should I use an array?
    - Extremely efficient: Great cache locality!
    - Requires non-negative integer bounds 
        * Consider adding if-checks
        * Consider 1-indexing
    - Great for compact bounds (tabulation)
    - Fastest option and can be allocated and initialized at compile time in C++ via constinit

Should I use a map/dict?
    - Extremely versatile: negatives and more!
    - @functools.cache uses this
    - Great for sparse bounds (memoization)
    - Great for complex arguments (strings)
    - Much slower than arrays


DEPENDENCIES
Identify the dependencies
    - The general term (parameters) depends on its recursive terms (call args)
    - Recursive terms must be calculated before the general term
Figure out the order
    - For every recursive term
    - At least 1 argument must match the direction of its parameters for loop
    - Outermost loop should have dependencies in only one direction
Unchanging parameters
    dp[i][j]: dp[i+1][j], dp[i][j-1]
        - dj does not change, i's order is now fixed
        - i does not change, j's order is now fixed
Directed graphs / rooted trees
    - Topsort / postorder traversal
    - Probably just do this recursively


SPACE SAVING TRICK
1 Identify constant dependencies
    - Which parameters only depend on arguments with constant changes?
    - That parameter must be outerloop-able (based on the dependencies earlier)
    - Applies recursively: after space saving one param, you can try to space the inner loops too
2 Replace with variables
    dp[p +- c] -> dp_pc
3 Move to outer loop and shift
    dp_pc = dp_p{c - 1}
4 Initialize everything you used
    - dp_p0 gets initialized inside, since it's calculated every loop
    - Everything else must be initialized outside

Time and Space Complexity

State/Term: numWays(i, x)
`i Bounds: [0, n] where n = len(coins)
Bounds: [0, amount]
How many terms do we have to compute?
    numWays(0, 0), numWays(0, 1) ... numWays (0, amount)
    numWays(1, 0), numWays(0, 1) ... numWays(0, amount)
    numWays(n, 0), numWays(n, 1) ... numWays (n, amount)
    O(n * amount) of unique states

How much local computation per term?
    Everything is trivially 0(1), except the recursive calls.
    Work to compute them is done at another term, so for the local work assume it's a cached value, so 0(1)
    0(1) of cached complexity

Total = O(n* amount) * 0(1) = 0(n * amount)
'''


