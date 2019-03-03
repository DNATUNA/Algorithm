word = input()
while(word!="END"):
    for i in reversed(word): print(i, end='')
    print()
    word = input()