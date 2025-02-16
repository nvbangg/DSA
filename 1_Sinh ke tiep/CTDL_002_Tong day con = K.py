# Nhập dữ liệu
n, k = map(int, input().split())
a = list(map(int, input().split()))
b = [0] * n
cnt = 0
def solve():
    global cnt 
    tong = 0
    for i in range(n):
        tong += a[i] * b[i]  
    if tong == k:
        cnt += 1
        for i in range(n):
            if b[i] == 1:
                print(a[i], end=" ")  
        print()  
def Try(i):
    for j in range(2):  
        b[i] = j
        if i == n - 1:
            solve()  
        else:
            Try(i + 1) 
Try(0)
print(cnt)  
