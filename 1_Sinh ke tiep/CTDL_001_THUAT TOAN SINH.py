def sinh(n):
    giua = (n - 1) // 2
    a = [0] * (giua + 1)
    while True:
        print(*a, *a[n // 2 - 1 :: -1])
        # Sinh xâu tiếp theo
        i = giua
        while a[i] == 1 and i >= 0:
            a[i] = 0
            i -= 1
        if i < 0:
            break
        a[i] = 1
n = int(input())
sinh(n)
