keyCnt, descriptionCnt = map(int, input().split())
salaryByWord = dict()
for _ in range(keyCnt):
    word, salary = input().split()
    salaryByWord[word] = int(salary)

for _ in range(descriptionCnt):
    totalSalary = 0
    while True:
        line = input()
        if line == '.':
            break

        for word in line.split():
            totalSalary += salaryByWord.get(word, 0)

    print(totalSalary)