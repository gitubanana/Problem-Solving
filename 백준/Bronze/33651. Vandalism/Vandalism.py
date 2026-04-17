str = list("UAPC")
for ch in input():
    str.remove(ch)

print(*str, sep='')
