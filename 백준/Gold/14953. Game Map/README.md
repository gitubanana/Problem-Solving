# [Gold IV] Game Map - 14953 

[문제 링크](https://www.acmicpc.net/problem/14953) 

### 성능 요약

메모리: 101844 KB, 시간: 644 ms

### 분류

다이나믹 프로그래밍, 그래프 이론, 그래프 탐색

### 제출 일자

2025년 7월 12일 09:02:28

### 문제 설명

<p><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/14953/1.png" style="float:right; height:217px; margin-left:15px; width:339px">The ICPC-World is the most popular RPG game for ACM-ICPC contestants, whose objective is to conquer the world. A map of the game consists of several cities. There is at most one road between a pair of cities. Every road is bidirectional. If there is a road connecting two cities, they are called neighbors. Each city has one or more neighbors and all cities are connected by one or more roads. A player of the game can start at any city of the world. After conquering a city that the player stays, the player can proceed to any neighbor city which is the city the player to conquer at the next stage.</p>

<p>Chansu, a mania of the game, enjoys the game in a variety of ways. He always determines a list of cities which he wants to conquer before he starts to play the game. In this time, he wants to choose as many cities as possible under the following conditions: Let (c<sub>0</sub>, c<sub>1</sub>, …, c<em><sub>m</sub></em><sub>-1</sub>)be a list of cities that he will conquer in order. All cities of the list are distinct, i.e., c<em><sub>i</sub></em> ≠ c<em><sub>j</sub></em> if <em>i</em> ≠ <em>j</em>, c<em><sub>i</sub></em> and c<em><sub>i</sub></em><sub>+1</sub> are neighbors to each other, and the number of neighbors of c<em><sub>i</sub></em><sub>+1</sub> is greater than the number of neighbors of c<em><sub>i</sub></em> for <em>i</em> = 0, 1, …, <em>m</em>-2.</p>

<p>For example, let’s consider a map of the game shown in the figure below. There are six cities on the map. The city 0 has two neighbors and the city 1 has five neighbors. The longest list of cities satisfying the above conditions is (2,5,4,1) with 4 cities.</p>

<p style="text-align:center"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/14953/2.png" style="height:167px; width:284px"></p>

<p>In order to help Chansu, given a map of the game with <em>n</em> cities, write a program to find the maximum number of cities that he can conquer, that is, the length of the longest list of cities satisfying the above conditions.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing two integers, <em>n</em> and <em>m</em> (1 ≤ <em>n</em> ≤ 100,000, <em>n</em>-1 ≤ <em>m</em> ≤ 300,000), where <em>n</em> is the number of cities on the game map and <em>m</em> is the number of roads. All cities are numbered from 0 to <em>n</em>-1. In the following <em>m</em> lines, each line contains two integers <em>i</em> and j (0 ≤ <em>i</em> ≠ <em>j</em> ≤ <em>n</em>-1) which represent a road connecting two cities <em>i</em> and <em>j</em>.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line. The line should contain the maximum number of cities which Chansu can conquer.</p>

