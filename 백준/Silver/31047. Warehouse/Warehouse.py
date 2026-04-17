for _ in range(int(input())):
    toys = dict()
    for _ in range(int(input())):
        name, cnt = input().split()
        toys[name] = toys.get(name, 0) + int(cnt)

    print(len(toys))
    for key, value in sorted(toys.items(), key=lambda item: (-item[1], item[0])):
        print(key, value)
