#include<stdio.h>
#include<stdlib.h>

int main() {
    int n1 = 0, n2 = 0, total = 0, tmp = 0;
    int* arr;
    scanf("%d", &n1); // 개수 입력 받기(n1)

    for (int i = 0; i < n1; i++) {
        total = tmp = 0;
        scanf("%d", &n2); // 학생 수 입력 받기(n2)
        arr = (int*)malloc(sizeof(int) * n2);
        for (int j = 0; j < n2; j++) {
            scanf("%d", &arr[j]); // 점수 입력받기
            total += arr[j]; // 합계
        }
        for (int j = 0; j < n2; j++)
            if (arr[j] > total / n2) { tmp++; }
        printf("%.3lf%s", tmp / (double)n2 * 100,"%");
        printf("\n");
    }
}