# [Gold III] Ocean Currents - 4184 

[문제 링크](https://www.acmicpc.net/problem/4184) 

### 성능 요약

메모리: 7040 KB, 시간: 244 ms

### 분류

그래프 이론, 최단 경로, 데이크스트라, 0-1 너비 우선 탐색

### 제출 일자

2026년 04월 17일 09:55:45

### 문제 설명

<p>For a boat on a large body of water, strong currents can be dangerous, but with careful planning, they can be harnessed to help the boat reach its destination. Your job is to help in that planning.</p>

<p>At each location, the current flows in some direction. The captain can choose to either go with the flow of the current, using no energy, or to move one square in any other direction, at the cost of one energy unit. The boat always moves in one of the following eight directions: north, south, east, west, northeast, northwest, southeast, southwest. The boat cannot leave the boundary of the lake. You are to help him devise a strategy to reach the destination with the minimum energy consumption.</p>

### 입력 

 <p>The lake is represented as a rectangular grid. The first line of input contains two integers r and c, the number of rows and columns in the grid. The grid has no more than 1000 rows and no more than 1000 columns. Each of the following r lines contains exactly c characters, each a digit from 0 to 7 inclusive. The character 0 means the current flows north (i.e. up in the grid, in the direction of decreasing row number), 1 means it flows northeast, 2 means east (i.e. in the direction of increasing column number), 3 means southeast, and so on in a clockwise manner:</p>

<pre>7 0 1
 \|/
6-*-2
 /|\
5 4 3</pre>

<p>The line after the grid contains a single integer n, the number of trips to be made, which is at most 50. Each of the following n lines describes a trip using four integers rs, cs, rd, cd, giving the row and column of the starting point and the destination of the trip. Rows and columns are numbered starting with 1.</p>

### 출력 

 <p>For each trip, output a line containing a single integer, the minimum number of energy units needed to get from the starting point to the destination.</p>

