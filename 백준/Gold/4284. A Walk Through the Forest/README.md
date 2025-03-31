# [Gold I] A Walk Through the Forest - 4284 

[문제 링크](https://www.acmicpc.net/problem/4284) 

### 성능 요약

메모리: 1660 KB, 시간: 16 ms

### 분류

방향 비순환 그래프, 자료 구조, 데이크스트라, 다이나믹 프로그래밍, 그래프 이론, 최단 경로, 위상 정렬

### 제출 일자

2025년 3월 31일 10:17:22

### 문제 설명

<p>Jimmy experiences a lot of stress at work these days, especially since his accident made working difficult. To relax after a hard day, he likes to walk home. To make things even nicer, his office is on one side of a forest, and his house is on the other. A nice walk through the forest, seeing the birds and chipmunks is quite enjoyable.</p>

<p>The forest is beautiful, and Jimmy wants to take a different route everyday. He also wants to get home before dark, so he always takes a path to make progress towards his house. He considers taking a path from A to B to be progress if there exists a route from B to his home that is shorter than any possible route from A. Calculate how many different routes through the forest Jimmy might take.</p>

### 입력 

 <p>Input contains several test cases followed by a line containing 0. Jimmy has numbered each intersection or joining of paths starting with 1. His office is numbered 1, and his house is numbered 2. The first line of each test case gives the number of intersections N, 1 < N ≤ 1000, and the number of paths M. The following M lines each contain a pair of intersections a b and an integer distance 1 ≤ d ≤ 1000000 indicating a path of length d between intersection a and a different intersection b. Jimmy may walk a path any direction he chooses. There is at most one path between any pair of intersections.</p>

### 출력 

 <p>For each test case, output a single integer indicating the number of different routes through the forest. You may assume that this number does not exceed 2147483647.</p>

