def area():
    h, w = map(int, input().split())
    return h*w

print(max([area() for _ in range(int(input()))]))