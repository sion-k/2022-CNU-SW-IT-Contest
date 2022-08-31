from sys import stdin
input = stdin.readline
n = int(input())
nums = [0] + list(map(int,input().split()))

q = int(input())

for i in range(q):
    order, l, r = (map(int,input().split()))
    if(order==1):
        nums[l] = r
    else: # order 2
        # l, r
        first = nums[l]
        Mini = nums[l]
        Maxi = nums[l]
        for i in range(l,r+1):
            Mini = min(nums[i],Mini)
            Maxi = max(nums[i],Maxi)
        print(Maxi-Mini)
