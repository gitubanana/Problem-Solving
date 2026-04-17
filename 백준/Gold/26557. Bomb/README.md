# [Gold IV] Bomb - 26557 

[문제 링크](https://www.acmicpc.net/problem/26557) 

### 성능 요약

메모리: 2028 KB, 시간: 0 ms

### 분류

그래프 이론, 최단 경로, 데이크스트라, 0-1 너비 우선 탐색

### 제출 일자

2026년 04월 17일 09:55:45

### 문제 설명

<p>You decide to create a game involving a 3D maze with destructible walls, where all the character has to work with is bombs. In order to determine the number of bombs to provide for each level, you need to know the minimum amount necessary to reach the exit and base it off of that. Your task is to write a program that will find the smallest number of bombs necessary to reach the exit. Each bomb can destroy one wall, leaving a blank space in its place.</p>

### 입력 

 <p>The first line will contain a single integer n that indicates the number of data sets that follow. Each data set will start with three integers f, r, and c, representing the number of layers, rows, and columns, respectively. The next f sets of r lines will be the maze, with every set of r lines being one layer of the maze.</p>

<p>The # represents a destructible wall, . represents an open space, S is the start location, and E is the exit location. You can only move up, down, left, and right (i.e., you cannot move diagonally). You can move freely between layers, but a move between layers stays in the same relative grid location.</p>

### 출력 

 <p>Output the smallest number of bombs necessary to escape the maze. There will be no trailing white space.</p>

