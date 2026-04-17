#include<stdio.h>
void mul3(long long sum, long long cnt) {
    long long total = 0;
    if (sum < 10) {
        fprintf(stdout, "%d\n",cnt+1);
        fprintf(stdout, "%s", sum == 3 || sum == 6 || sum == 9 ? "YES" : "NO");
        return;
    }
    while (sum > 0) {
        total += sum % 10;
        sum /= 10;
    }
    ++cnt;
    mul3(total, cnt);
}

int main() {
    char arr[1000001];
    long long i = 0, len = 0, sum = 0, cnt = 0;
    fscanf(stdin, "%s", arr);

    while (arr[i++] != '\0')
        len++;

    if (len == 1) {
        i = arr[0] - '0';
        fprintf(stdout, "0\n");
        fprintf(stdout, "%s", i == 3 || i == 6 || i == 9 ? "YES" : "NO");
        return 0;
    }

    for (i = 0; i < len; i++)
        sum += arr[i] - '0';

    mul3(sum, cnt);

}