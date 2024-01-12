import sys


def is_acceptable(password: str) -> bool:
    serial = 'eo'
    vowels = 'aeiou'

    vowel_cnt = (vowels.find(password[0]) != -1)
    consonant_cnt = (vowel_cnt == 0)
    include_vowel = (vowel_cnt > 0)

    len_ = len(password)
    for i in range(1, len_):
        if (password[i - 1] == password[i]
                and serial.find(password[i]) == -1):
            return False

        if vowels.find(password[i]) != -1:
            vowel_cnt += 1
            consonant_cnt = 0
            include_vowel = True
        else:
            consonant_cnt += 1
            vowel_cnt = 0

        if vowel_cnt == 3 or consonant_cnt == 3:
            return False

    return include_vowel


if __name__ == '__main__':
    msg = ('not acceptable', 'acceptable')

    while True:
        password = sys.stdin.readline().strip()
        if password == 'end':
            break
        print(f'<{password}> is {msg[is_acceptable(password)]}.')
