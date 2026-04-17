import sys

words = set()
for word in input().split():
    if word in words:
        print('no')
        sys.exit()
    words.add(word)

print('yes')
