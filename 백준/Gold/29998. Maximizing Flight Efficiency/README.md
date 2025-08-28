# [Gold IV] Maximizing Flight Efficiency - 29998 

[문제 링크](https://www.acmicpc.net/problem/29998) 

### 성능 요약

메모리: 1160 KB, 시간: 4 ms

### 분류

그래프 이론, 그리디 알고리즘, 정렬, 최단 경로, 플로이드–워셜

### 제출 일자

2025년 8월 28일 09:47:44

### 문제 설명

<p>In the kingdom of Quadradonia, the king wants to review the prices of flights. For this purpose, he asked his accountant for a table with proposals for new prices.</p>

<p>However, the king studied at the Institute of Computing and Programming of Chapec´o (ICPC) and has sufficient knowledge to demand coherence in the table. The table is considered coherent if no multi-stop route is cheaper than a direct flight.</p>

<p>Once the coherence of the table has been verified, the king would like to decrease the number of direct flights, without increasing the costs of the trips.</p>

<p>Your problem is to verify the coherence of the table and, if it is coherent, inform the king how many direct flights can be eliminated without increasing the cost of any trip.</p>

### 입력 

 <p>The first line of input contains an integer N (1 ≤ N ≤ 100), the number of cities in Quadradonia served by flights. Following there are N more lines, L<sub>1</sub>, L<sub>2</sub>, . . . , L<sub>N</sub>. Line L<sub>i</sub> contains N integers, C<sub>i1</sub>, C<sub>i2</sub>, . . . , C<sub>iN</sub>, where C<sub>ij</sub> is the cost of the direct flight between cities i and j.</p>

<p>The cost for an outbound and a return flight between two cities is always the same, meaning C<sub>ij</sub> = C<sub>ji</sub> for all pairs i, j where 1 ≤ i ≤ N and 1 ≤ j ≤ N. When i = j, C<sub>ij</sub> = 0. When i ≠ j, 1 ≤ C<sub>ij</sub> ≤ 10<sup>3</sup>.</p>

### 출력 

 <p>Print a single line containing an integer. If the table is incoherent, the integer should be -1. If the table is coherent, the integer should be equal to the maximum number of direct flights that can be removed without increasing the costs of the trips for the passengers.</p>

