# [Gold III] Tree Cutting - 7045 

[문제 링크](https://www.acmicpc.net/problem/7045) 

### 성능 요약

메모리: 22608 KB, 시간: 268 ms

### 분류

센트로이드, 다이나믹 프로그래밍, 트리에서의 다이나믹 프로그래밍, 트리

### 제출 일자

2024년 11월 29일 11:38:49

### 문제 설명

<p>After Farmer John realized that Bessie had installed a "tree-shaped" network among his N (1 <= N <= 10,000) barns at an incredible cost, he sued Bessie to mitigate his losses. </p>

<p>Bessie, feeling vindictive, decided to sabotage Farmer John's network by cutting power to one of the barns (thereby disrupting all the connections involving that barn). When Bessie does this, it breaks the network into smaller pieces, each of which retains full connectivity within itself. In order to be as disruptive as possible, Bessie wants to make sure that each of these pieces connects together no more than half the barns on FJ. </p>

<p>Please help Bessie determine all of the barns that would be suitable to disconnect.</p>

### 입력 

 <ul>
	<li>Line 1: A single integer, N. The barns are numbered 1..N. </li>
	<li>Lines 2..N: Each line contains two integers X and Y and represents a connection between barns X and Y.</li>
</ul>

### 출력 

 <ul>
	<li>Lines 1..?: Each line contains a single integer, the number (from 1..N) of a barn whose removal splits the network into pieces each having at most half the original number of barns. Output the barns in increasing numerical order. If there are no suitable barns, the output should be a single line containing the word "NONE".</li>
</ul>

