import re

def main():
    maxWord = ''
    for word in re.findall('[A-Z\-a-z]+', open(0).read()[:-1]):
        if len(maxWord) < len(word):
            maxWord = word

    print(maxWord.lower())

main()
