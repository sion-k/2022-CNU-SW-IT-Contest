import sys
input = sys.stdin.readline
print = sys.stdout.write

n = int(input())
a = [*map(int, input().split())]
q = int(input())
for i in range(q):
    o, l, r = map(int, input().split())
    if o == 1:
        a[l - 1] = r
    else:
        l -= 1
        r -= 1
        dp = [0] * n
        ret = 0
        for j in range(l, r + 1):
            dp[j] = a[j]
            if j - 1 >= l:
                dp[j] = min(dp[j - 1], dp[j])
            ret = max(ret, a[j] - dp[j])
        print(str(ret))
        print('\n')