radiusByColor = dict()
for _ in range(int(input())):
    a, b = input().split()
    if a.isdigit():
        radiusByColor[b] = int(a) // 2
    else:
        radiusByColor[a] = int(b)

for color in sorted(radiusByColor, key=radiusByColor.get):
    print(color)
