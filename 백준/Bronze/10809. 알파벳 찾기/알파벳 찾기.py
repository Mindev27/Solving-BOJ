S = input()
a = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
b = []
for i in a:
    b.append(S.find(i))
for i in b:
    print(i, end=" ")