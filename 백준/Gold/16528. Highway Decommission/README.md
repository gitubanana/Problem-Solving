# [Gold I] Highway Decommission - 16528 

[문제 링크](https://www.acmicpc.net/problem/16528) 

### 성능 요약

메모리: 6320 KB, 시간: 80 ms

### 분류

그래프 이론, 최단 경로, 데이크스트라, 역추적

### 제출 일자

2026년 04월 17일 09:55:45

### 문제 설명

<p>Nlogonia’s government is eager to cut down public debt. One of the measures about to take place is the decommission of some highways as most of them incur a high maintenance cost. Each highway connects two different cities and can be traveled in both directions. Using the existing highways it is possible to reach any city from any other city.</p>

<p>Government promises that the impact of the decommission will be minimal in the lives of Nlogonians. In particular they guarantee that after the decommission, for each city the minimum distance needed to travel from that city to the capital of the country will remain the same as it is now, when all the highways can be used.</p>

<p>The Department of Roads of Nlogonia believes that interns are not there just to get coffees or run errands but should do meaningful work instead and that’s why you are assigned the following task. Given the length and maintenance cost of each highway, you must decide which highways will be kept active and which will be decommissioned. As you might guess, the sum of maintenance costs for the remaining highways must be minimum.</p>

### 입력 

 <p>The first line contains two integers N (2 ≤ N ≤ 10<sup>4</sup>) and M (1 ≤ M ≤ 10<sup>5</sup>), indicating respectively the number of cities and the number of highways. Cities are identified by distinct integers from 1 to N, where city 1 is the capital of Nlogonia. Each of the following M lines describes a highway with four integers A, B, L and C (1 ≤ A, B ≤ N, A ≠ B and 1 ≤ L, C ≤ 10<sup>9</sup>), indicating that there is a highway between cities A and B that has length L and maintenance cost C. Using the existing highways it is possible to reach any city from any other city.</p>

### 출력 

 <p>Output a single line with an integer indicating the minimum possible sum of maintenance costs for a set of highways to be kept active. This set of highways must ensure that for each city the minimum distance needed to travel from that city to the capital of Nlogonia remains the same using only those highways.</p>

