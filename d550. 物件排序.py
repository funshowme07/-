n,m=map(int,input().split())
arr = [ ]
for i in range(n):
    a = list(map(int,input().split()))
    arr.append(a)
arr.sort()
for i in range(n):
    print(*arr[i])