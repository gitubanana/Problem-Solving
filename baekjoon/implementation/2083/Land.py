import sys

while True:
    line = sys.stdin.readline().split()
    if line[0] == '#':
        break
    
    print(line[0], end=' ')
    if int(line[1]) > 17 or int(line[2]) >= 80:
        print('Senior')
    else:
        print('Junior')
