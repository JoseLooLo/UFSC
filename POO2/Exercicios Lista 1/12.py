a = int(input())
if a % 2 == 0:
    print("Não primo")
else:
    for i in range(3,int(a**(1/2)+1)):
        if a % i == 0:
            print("não primo")
            exit(0)
    print("primo")
