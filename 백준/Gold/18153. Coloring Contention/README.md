# [Gold IV] Coloring Contention - 18153 

[문제 링크](https://www.acmicpc.net/problem/18153) 

### 성능 요약

메모리: 7352 KB, 시간: 60 ms

### 분류

그래프 이론, 그래프 탐색, 너비 우선 탐색

### 제출 일자

2026년 04월 17일 09:55:45

### 문제 설명

<p>Alice and Bob are playing a game on a simple connected graph with N nodes and M edges.</p>

<p>Alice colors each edge in the graph red or blue.</p>

<p>A path is a sequence of edges where each pair of consecutive edges have a node in common. If the first edge in the pair is of a different color than the second edge, then that is a “color change.”</p>

<p>After Alice colors the graph, Bob chooses a path that begins at node 1 and ends at node N. He can choose any path on the graph, but he wants to minimize the number of color changes in the path. Alice wants to choose an edge coloring to maximize the number of color changes Bob must make. What is the maximum number of color changes she can force Bob to make, regardless of which path he chooses?</p>

### 입력 

 <p>The first line contains two integer values N and M with 2 ≤ N ≤ 100 000 and 1 ≤ M ≤ 100 000. The next M lines contain two integers a<sub>i</sub> and b<sub>i</sub> indicating an undirected edge between nodes a<sub>i</sub> and b<sub>i</sub> (1 ≤ a<sub>i</sub>, b<sub>i</sub> ≤ N, a<sub>i</sub> ≠ b<sub>i</sub>).</p>

<p>All edges in the graph are unique.</p>

### 출력 

 <p>Output the maximum number of color changes Alice can force Bob to make on his route from node 1 to node N.</p>

