result = 'S'
for bit in input().split():
    if bit == '9':
        result = 'F'
        break

print(result)