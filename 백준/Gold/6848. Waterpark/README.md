# [Gold V] Waterpark - 6848 

[문제 링크](https://www.acmicpc.net/problem/6848) 

### 성능 요약

메모리: 1764 KB, 시간: 4 ms

### 분류

다이나믹 프로그래밍, 그래프 이론

### 제출 일자

2025년 7월 11일 11:22:27

### 문제 설명

<p>The local waterpark has a great slide complex, with many paths crisscrossing down the hill. There is one start point and one end point, but at various points one can turn and take different paths. Walter and Wanda are wondering exactly how many different ways there are to go down the slide. Can you solve their problem?</p>

<p>More precisely, there are n marked points (including the start at 1 and the end at n) where the paths down the hill may split or merge. All paths move down the hill to higher numbered positions; some paths will actually cross over others without meeting but we don’t have to worry about that. We won’t worry about the collisions between sliders that can happen either. Our problem is simply to determine the number of different sequences of marked points we can follow down the hill.</p>

<p>For example, at one small waterpark, there are 4 points with direct slides from 1 to points 2 and 4; from 2 to 3 and 4; and from 3 to 4. There are 3 ways down the hill. You can check this by seeing that we can go (1,2,3,4), (1,2,4) or (1,4).</p>

<p>(Here is a hint: think about starting at the bottom of the slide.)</p>

### 입력 

 <p>Input begins with a single integer n (1 ≤ n ≤ 9999), on a line by itself, indicating the number of marked points. The next lines contain point pairs of the of the form x y, where 1 ≤ x < y ≤ n. For example, 1234 8765 indicates a direct slide from point 1234 to point 8765. The last line of input will be indicated by point pair 0 0.</p>

### 출력 

 <p>The output is an integer, which is the number of different paths from point 1 to point n. You can assume that the number of paths will be less than 2 30. It is possible that there is no path from point 1 to point n, in which case the number of paths is 0.</p>

