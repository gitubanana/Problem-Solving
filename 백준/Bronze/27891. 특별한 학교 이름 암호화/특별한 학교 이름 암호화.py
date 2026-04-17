import sys

cipherText = input()
cmpNames = ("nor", "bra", "kor", "stj")
names = ("NLCS", "BHA", "KIS", "SJA")
for k in range(0, 26):
    decrypted = "".join([chr(ord('a') + (ord(cipherText[i]) - ord('a') + k + 26) % 26) for i in range(0, 3)])
    for i in range(len(cmpNames)):
        if cmpNames[i] == decrypted:
            print(names[i])
            sys.exit()
