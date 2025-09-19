# [Gold V] Subsequences Summing to Sevens - 11974 

[문제 링크](https://www.acmicpc.net/problem/11974) 

### 성능 요약

메모리: 17932 KB, 시간: 1440 ms

### 분류

수학, 누적 합

### 제출 일자

2025년 9월 19일 10:12:06

### 문제 설명

<p>Farmer John's \(N\) cows are standing in a row, as they have a tendency to do from time to time. Each cow is labeled with a distinct integer ID number so FJ can tell them apart. FJ would like to take a photo of a contiguous group of cows but, due to a traumatic childhood incident involving the numbers \(1 \ldots 6\), he only wants to take a picture of a group of cows if their IDs add up to a multiple of 7.</p>

<p>Please help FJ determine the size of the largest group he can photograph.</p>

### 입력 

 <p>The first line of input contains \(N\) (\(1 \leq N \leq 50,000\)). The next \(N\) lines each contain the \(N\) integer IDs of the cows (all are in the range \(0 \ldots 1,000,000\)).</p>

### 출력 

 <p>Please output the number of cows in the largest consecutive group whose IDs sum to a multiple of 7. If no such group exists, output 0.</p>

<p>You may want to note that the sum of the IDs of a large group of cows might be too large to fit into a standard 32-bit integer. If you are summing up large groups of IDs, you may therefore want to use a larger integer data type, like a 64-bit "long long" in C/C++.</p>

