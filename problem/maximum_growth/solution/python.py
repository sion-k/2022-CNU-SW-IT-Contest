import sys
input = sys.stdin.readline
print = sys.stdout.write

n = int(input())
a = [*map(int, input().split())]
dp = [0] * n
ret = 0
l = 0
for j in range(n):
    dp[j] = a[j]
    if j - 1 >= l:
        dp[j] = min(dp[j - 1], dp[j])
    ret = max(ret, a[j] - dp[j])

print(str(ret)+'\n')
