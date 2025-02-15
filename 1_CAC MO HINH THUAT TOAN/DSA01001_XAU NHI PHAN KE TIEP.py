def TestCase():
    s = list(input()) 
    i = len(s) - 1
    while i >= 0 and s[i] == '1': 
        s[i] = '0'
        i -= 1
    if i >= 0: 
        s[i] = '1'
    print("".join(s))  

T = int(input()) 
for _ in range(T):
    TestCase()
