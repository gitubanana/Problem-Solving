# [Gold V] Binary Roads - 13213 

[문제 링크](https://www.acmicpc.net/problem/13213) 

### 성능 요약

메모리: 34712 KB, 시간: 744 ms

### 분류

그래프 이론, 그래프 탐색, 너비 우선 탐색

### 제출 일자

2026년 04월 17일 09:55:45

### 문제 설명

<p>Ali is out on a vacation and intends to visit a specific destination. However, he has trouble getting there in the shortest possible time and needs your help!</p>

<p>For simplicity, the place can be treated as a graph with N nodes (places) and E edges (roads). Nodes will be labelled from 0 to N-1 and all edges are bi-directional. It can be assumed that it will take 1 hour to travel any edge and all nodes and edges can be visited more than once.</p>

<p>Ali will start of at node 0 and his destination is node N-1. This seems like an easy problem, but things are much more complicated due to binary roads.</p>

<p>Unlike normal roads, all of the E edges are binary roads. They either contain a value of 0 or 1. Similarly, Ali will also have a value of 0 or 1. When Ali has a value of 0, he can only travel on edges with a value of 0. When Ali has a value of 1, he can only travel on those edges with a value of 1. However, after travelling on a single edge, the value of Ali will be flipped. If it was originally 0, it will become 1. If it was originally 1, it will become 0. It will then flip again after he travels on another edge.</p>

<p>Still, Ali wants to know the shortest possible time to reach his destination (in hours). Remember, Ali can choose to start with value 0 or 1 .</p>

### 입력 

 <p>The first line of input will contain 2 integers, N and E. (1 ≤ N ≤ 200,000, 0 ≤ E ≤ 1,000,000)</p>

<p>The next E line of input will contain 3 integers: A, B, and V. This means that there is a bi-directional edge from node A to node B with a value of V. It is guaranteed that there will not be more than one edge connecting the same two nodes with the same value.</p>

<p>It is guaranteed that A ≠ B, 0 ≤ A, B < N, V = 0 or 1 for all E lines describing the edges.</p>

### 출력 

 <p>Output a single integer, the shortest possible time for Ali to reach his destination (in hours). If it is not possible for Ali to reach his destination, output -1 instead.</p>

