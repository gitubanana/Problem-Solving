# [Gold I] Formica Sokobanica - 21935 

[문제 링크](https://www.acmicpc.net/problem/21935) 

### 성능 요약

메모리: 31528 KB, 시간: 128 ms

### 분류

깊이 우선 탐색, 그래프 이론, 그래프 탐색, 트리

### 제출 일자

2025년 3월 5일 09:55:04

### 문제 설명

<p>A new species of ant, named <em>Formica sokobanica</em>, was discovered recently. It attracted entomologists’ attention due to its unique habit. These ants do not form colonies. Rather, individuals make up their private nests and keep their food, nuts, in the nests. A nest comprises a lot of small rooms connected with tunnels. They build the rooms only a little bigger than a nut leaving just enough space for air flow; they cannot enter a room with a nut in it. To save the labor, tunnels are so narrow that it exactly fits the size of a nut, and thus nuts should not be left in the tunnels to allow air flow through.</p>

<p>To enter a room with a nut in it, the nut has to be pushed away to any of the vacant rooms adjacent to that room through the tunnel connecting them. When no adjacent rooms are vacant except the room which the ant came from, the nut cannot be pushed away, and thus the ant cannot enter the room.</p>

<p>Dr. Myrmink, one of the entomologists enthused about the ants, has drawn a diagram of a typical nest. The diagram also shows which rooms store nuts in them, and which room the ant is initially in. Your job is to write a program that counts up how many rooms the ant can reach and enter. Pushing a nut into one of the vacant adjacent rooms may make some of the rooms unreachable, while choosing another room to push into may keep the rooms reachable. There can be many combinations of such choices. In such cases, all the rooms should be counted that are possibly reached by one or more choice combinations.</p>

<p>You may assume that there is no nut in the room the ant is initially in, and that there is no cyclic path in the nest.</p>

### 입력 

 <p>The input consists of a single test case of the following format, representing the diagram of a nest.</p>

<pre>n m
x<sub>1</sub> y<sub>1</sub>
.
.
.
x<sub>n−1</sub> y<sub>n−1</sub>
a<sub>1</sub>
.
.
.
a<sub>m</sub></pre>

<p>Here, n and m are the numbers of rooms and nuts. They satisfy 1 ≤ n ≤ 2×10<sup>5</sup> and 0 ≤ m < n. Rooms are numbered from 1 to n. The ant is initially in the room 1.</p>

<p>Each of the following n − 1 lines has two integers x<sub>i</sub> and y<sub>i</sub> (1 ≤ i ≤ n − 1) indicating that a tunnel connects rooms numbered x<sub>i</sub> and y<sub>i</sub>. 1 ≤ x<sub>i</sub> ≤ n, 1 ≤ y<sub>i</sub> ≤ n, and x<sub>i</sub> ≠ y<sub>i</sub> hold. No two tunnels connect the same pair of rooms.</p>

<p>Each of the remaining m lines has an integer a<sub>k</sub> (1 ≤ k ≤ m, 2 ≤ a<sub>k</sub> ≤ n) which indicates that the room numbered a<sub>k</sub> has a nut in it. The numbers a<sub>k</sub>’s are all distinct.</p>

### 출력 

 <p>The output should be a single line containing a single integer, the number of rooms that the ant can reach and enter.</p>

