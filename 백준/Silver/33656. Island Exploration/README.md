# [Silver II] Island Exploration - 33656 

[문제 링크](https://www.acmicpc.net/problem/33656) 

### 성능 요약

메모리: 12664 KB, 시간: 76 ms

### 분류

그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색, 격자 그래프, 플러드 필

### 제출 일자

2025년 9월 16일 09:30:52

### 문제 설명

<p>Oh no! You just washed ashore after a shipwreck! Time to put all of those survival skills you have learned in video games to the test.</p>

<p>Some items washed ashore with you, including a map of the area! The map is very crude, the region is represented by a grid and each cell is simply indicated to be “land” or “sea”. After looking at your surroundings a bit, you know which grid cell you are currently standing on. You are able to walk between two land grid cells if they are directly adjacent, i.e. either up, down, left, or right of your current cell (you cannot hop diagonally to a land cell).</p>

<p>The first thing you want to know is how much of the region you are able to explore. That is, your task is to determine how many land cells you are able to walk to.</p>

### 입력 

 <p>The first line of input contains two integers $R$ ($3≤R≤100$) and $C$ ($3≤C≤100$). The next $R$ lines contain exactly $C$ characters each. The $i$’th character on the $j$’th such line is <code>#</code> if the corresponding grid cell is land, <code>.</code> if the corresponding grid cell is sea, or <code>S</code> if you are currently standing on the grid cell.</p>

<p>There will be exactly one <code>S</code> in the input and that cell is also a land cell. Also, the entire boundary of the region will consist of sea cells. That is, the first and last line will consist entirely of <code>.</code> as will the first and last character of every line describing the region.</p>

### 출력 

 <p>Output a single integer indicating the number of land cells you are able to walk to from your starting cell. This count should also include the land cell you are initially standing on.</p>

