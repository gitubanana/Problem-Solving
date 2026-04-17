# [Gold IV] Lost On Campus - 34398 

[문제 링크](https://www.acmicpc.net/problem/34398) 

### 성능 요약

메모리: 1276 KB, 시간: 0 ms

### 분류

그래프 이론, 그래프 탐색, 너비 우선 탐색, 최단 경로, 데이크스트라, 0-1 너비 우선 탐색

### 제출 일자

2026년 04월 17일 09:55:45

### 문제 설명

<p>You were wandering around the campus at Colorado School of Mines, but you ended up getting lost in some building that you don't recognize. To get out, you'll need to traverse the corridors of the building until you find an exit.</p>

<p>Luckily, while wandering, you're able to find a map of the building that shows you the floor plan (your input). Now you can find a way out!</p>

<p>There's just one problem, however: you have a tragic fear of doors. On the way out of the building, you'll want to go through as few doors as possible.</p>

<p>Given the floor plan of the building, what is the fewest doors you can go through while still reaching an exit?</p>

### 입력 

 <p>The first line of your input will contain two integers: $W$ and $H$, representing the width and height, respectively, of the map. For all inputs, $3 \leq W \leq 100$ and $3 \leq H \leq 100$.</p>

<p>The following $H$ lines will each contain $W$ characters, representing the map. The map itself uses the following characters to represent each object:</p>

<ul>
	<li><code>.</code> (period): Floor</li>
	<li><code>#</code> (pound sign): Wall</li>
	<li><code>D</code> (upper-case D): Door</li>
	<li><code>E</code> (upper-case E): Exit</li>
	<li><code>*</code> (asterisk): Starting Point (You are here!)</li>
</ul>

<p>When traversing the map, you can only move from a given tile to its four adjacent tiles: up, down, left, and right.</p>

<p>Additionally, each map will have walls along every edge, and there can be several different exits in the map, which may or may not be adjacent to the edges of the map.</p>

### 출력 

 <p>Your output should be a single integer, representing the fewest doors you can go through while still reaching an exit. Also note that going through an exit does not count as going through a door.</p>

<p>If it is impossible to navigate to an exit, output "NOT POSSIBLE".</p>

