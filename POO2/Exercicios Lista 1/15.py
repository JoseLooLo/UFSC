n = int(input())
if n >= 1:
    print("1")
if n >= 2:
    print("1")
a = 1
b = 1
for i in range(n-2):
    c = a
    a = b
    b = c+b
    print(b)
