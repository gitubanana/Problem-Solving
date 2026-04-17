# [Bronze II] Fight Against Numbers - 35004 

[문제 링크](https://www.acmicpc.net/problem/35004) 

### 성능 요약

메모리: 1112 KB, 시간: 0 ms

### 분류

수학, 구현, 시뮬레이션, 비트마스킹

### 제출 일자

2026년 04월 17일 09:55:45

### 문제 설명

<p>Star and Marco got themselves into a world where they are being attacked by swarms of numbers! Fortunately, the friends know what to do.</p>

<p>Each number is first served with a shot from Marco's binary blaster to expose the number's binary notation. After that, Star performs a power move one or more times: she reverses the binary notation of the number and then subtracts one. When the number becomes zero, it shatters to pieces.</p>

<p>The heroes have just entered the fight with a number $n$. How many power moves would it take to shatter this number to pieces?</p>

<p>Reversing works as follows: the first digit of the binary notation exchanges places with the last one, the second with the second-to-last, and so on. If leading zeroes appear in the result, they are discarded.</p>

### 입력 

 <p>The first line contains an integer $n$ ($1 \le n \le 10^9$).</p>

### 출력 

 <p>Print a single integer: how many times would Star have to perform the power move so that the number $n$ becomes zero and shatters to pieces.</p>

