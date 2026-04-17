morseByChar = dict()
for _ in range(26):
    char, morse = input().split()
    morseByChar[char] = morse

wordByMorse = dict()
for _ in range(int(input())):
    word = input()
    morse = ''
    for ch in word:
        morse += morseByChar[ch]

    wordByMorse[morse] = word

def printWords():
    global cnt, wordByMorse

    words = []
    while cnt > 0:
        cnt -= 1
        morse = input()
        words.append(wordByMorse[morse])

    print(*words)

def skipLines():
    global cnt

    for _ in range(cnt):
        input()

while True:
    cnt = int(input())
    if cnt == 0:
        break

    try:
        printWords()
    except KeyError as e:
        skipLines()
        print(f'{str(e)[1:-1]} not in dictionary.')
