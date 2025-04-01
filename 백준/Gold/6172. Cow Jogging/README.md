# [Gold I] Cow Jogging - 6172 

[문제 링크](https://www.acmicpc.net/problem/6172) 

### 성능 요약

메모리: 2188 KB, 시간: 48 ms

### 분류

방향 비순환 그래프, 데이크스트라, 그래프 이론, 최단 경로

### 제출 일자

2025년 4월 1일 10:07:44

### 문제 설명

<p>Bessie has taken heed of the evils of sloth and has decided to get fit by jogging from the barn to the pond several times a week. She doesn't want to work too hard, of course, so she only plans to jog downhill to the pond and then amble back to the barn at her leisure.</p>

<p>Bessie also doesn't want to jog any too far either, so she generally takes the shortest sequence of cow paths to get to the pond. Each of the M (1 <= M <= 10,000) cow paths connects two pastures conveniently numbered 1..N (1 <= N <= 1000). Even more conveniently, the pastures are numbered such that if X>Y then the cow path from pasture X to pasture Y runs downhill. Pasture N is the barn (at the top of the hill) and pasture 1 is the pond (at the bottom).</p>

<p>Just a week into her regimen, Bessie has begun to tire of always taking the same route to get to the pond. She would like to vary her route by taking different cow paths on different days. Specifically, Bessie would like to take exactly K (1 <= K <= 100) different routes for variety. To avoid too much exertion, she wants these to be the K shortest routes from the barn to the pond. Two routes are considered different if they comprise different sequences of cow paths.</p>

<p>Help Bessie determine how strenuous her workout will be by determining the lengths of each of the K shortest routes on the network of pastures. You will be supplied a list of downhill cow paths from X_i to Y_i along with the cow path's length: (X_i, Y_i, D_i) where (1 <= Y_i < X_i; Y_i < X_i <= N). Cowpath i has length D_i (1 <= D_i <= 1,000,000).</p>

### 입력 

 <ul>
	<li>Line 1: Three space-separated integers: N, M, and K</li>
	<li>Lines 2..M+1: Line i+1 describes a downhill cow path using three space-separated integers: X_i, Y_i, and D_i</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Lines 1..K: Line i contains the length of the i-th shortest route or -1 if no such route exists. If a shortest route length occurs multiple times, be sure to list it multiple times in the output.</li>
</ul>

