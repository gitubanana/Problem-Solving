# [Gold I] Roadblocks - 6197 

[문제 링크](https://www.acmicpc.net/problem/6197) 

### 성능 요약

메모리: 4284 KB, 시간: 40 ms

### 분류

데이크스트라, 그래프 이론, 최단 경로

### 제출 일자

2025년 4월 13일 09:06:46

### 문제 설명

<p>Bessie has moved to a small farm and sometimes enjoys returning to visit one of her best friends. She does not want to get to her old home too quickly, because she likes the scenery along the way. She has decided to take the second-shortest rather than the shortest path. She knows there must be some second-shortest path.</p>

<p>The countryside consists of R (1 <= R <= 100,000) bidirectional roads, each linking two of the N (1 <= N <= 5000) intersections, conveniently numbered 1..N. Bessie starts at intersection 1, and her friend (the destination) is at intersection N.</p>

<p>The second-shortest path may share roads with any of the shortest paths, and it may backtrack i.e., use the same road or intersection more than once. The second-shortest path is the shortest path whose length is longer than the shortest path(s) (i.e., if two or more shortest paths exist, the second-shortest path is the one whose length is longer than those but no longer than any other path).</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers: N and R</li>
	<li>Lines 2..R+1: Each line contains three space-separated integers: A, B, and D that describe a road that connects intersections A and B and has length D (1 <= D <= 5000)</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Line 1: The length of the second shortest path between node 1 and node N</li>
</ul>

