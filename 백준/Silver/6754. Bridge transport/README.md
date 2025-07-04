# [Silver IV] Bridge transport - 6754 

[문제 링크](https://www.acmicpc.net/problem/6754) 

### 성능 요약

메모리: 732 KB, 시간: 56 ms

### 분류

누적 합, 슬라이딩 윈도우

### 제출 일자

2025년 7월 4일 18:56:38

### 문제 설명

<p>A train of railway cars attempts to cross a bridge. The length of each car is 10m but their weights might be different. The bridge is 40m long (thus can hold 4 train cars at one time). The bridge will crack if the total weight of the cars on it at one time is greater than a certain weight. The cars are numbered starting at 1, going up to N, and they cross the bridge in that order (i.e., 1 immediately followed by 2, which is immediately followed by 3, and so on).</p>

<p>What is the largest number T of railway cars such that the train of cars 1...T (in order) can cross the bridge?</p>

### 입력 

 <p>The first line of input is the maximum weight W (1 ≤ W ≤ 100000) that the bridge can hold at any particular time. The second line of input is the number N (1 ≤ N ≤ 100000) which is the number of railway cars that we wish to move across the bridge. On each of the next N lines of input, there will be a positive integer w<sub>i</sub> (1 ≤ i ≤ N, 1 ≤ w<sub>i</sub> ≤ 100000) which represents the weight of the ith railway car in the sequence.</p>

### 출력 

 <p>Your output should be a non-negative integer representing the maximum number of railway cars that can be brought across the bridge in the order specified.</p>

