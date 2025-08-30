# [Gold III] Model Railroad - 13151 

[문제 링크](https://www.acmicpc.net/problem/13151) 

### 성능 요약

메모리: 5152 KB, 시간: 80 ms

### 분류

그래프 이론, 최소 스패닝 트리

### 제출 일자

2025년 8월 30일 09:28:56

### 문제 설명

<p>Since childhood you have been fascinated by model railroads. Designing your own tracks, complicated intersections, train stations with miniatures of travellers, train operators, luggage is so much fun! However, it also needs a lot of space. Since your house is more than full by now, you decide to move to the garden.</p>

<p>You have already moved all your completed tracks outside when you notice an important flaw: Since different tracks were in different rooms before, there are stations which cannot be reached from each other. That has to change!</p>

<p>Since you have already fixed the exact positions of the stations, you know the lengths for all possible connections you can build and also which stations are connected already. All connections can be used in both directions. You can decide to remove some existing connections and instead build new ones of at most the same total length. Is it possible to rearrange the railroads so that every station is reachable from all other stations?</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>one line with three integers n (2 ≤ n ≤ 5 · 10<sup>4</sup>), m (0 ≤ m ≤ 2.5 · 10<sup>5</sup>) and ℓ (0 ≤ ℓ ≤ m), where n is the number of stations, m is the number of possible connections and ℓ is the number of connections already built;</li>
	<li>m lines describing the connections. Each connection is described by:
	<ul>
		<li>one line with three integers a, b (1 ≤ a, b ≤ n), and c (0 ≤ c ≤ 5 · 10<sup>3</sup>) describing that there is a connection from station a to station b of length c.</li>
	</ul>
	</li>
</ul>

<p>The first ℓ of those connections already exist.</p>

### 출력 

 <p>Output “possible” if it is possible to construct a connected network as described above, otherwise output “impossible”.</p>

