# Maximum Pairwise Product

The problem is as follows:
Find the maximum product of two distinct numbers in a sequence of non-negative integers.
**Input:** An integer n and a sequence of n non-negative integers.
**Output:** The maximum value that can be obtained by multiplying two different elements from the sequence.
$$\max_{1<=i!=j<=n} {a_i * a_j}$$

Note that i and j should be different, though it may be the case that $${a_i = a_j}$$

**Input format** The first line contains an integer n. The next line contains
n non-negative integers $${a_1}...{a_n}$$ separated by spaces.

**Output format** The maximum pairwise product.

**Constraints** $${2<=n<=2*10^5}; {0<=a_1...a_n<=2*10^5}$$

The naive solution would involve using two for loops to go through all the elements of the sequence and then finding two pairs of number by comparing values of currently known highest product. However this solution is very slow and will result in "Time Limit Exceeded".

A better solution still involves two for loops but they are two separate ones and not nested. Therefore it is much faster and it helps us to solve the problem. There is definitely ways to improve this solution. But this problem illustrates the problem of how a naive solution can be improved greatly just by implementing a faster algorithm.
