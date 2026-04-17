# [Gold IV] Fastest Thing Alive - 33224 

[문제 링크](https://www.acmicpc.net/problem/33224) 

### 성능 요약

메모리: 6056 KB, 시간: 20 ms

### 분류

다이나믹 프로그래밍, 그래프 이론, 그래프 탐색, 너비 우선 탐색, 격자 그래프, 역추적

### 제출 일자

2026년 04월 17일 09:55:45

### 문제 설명

<p>The villainous Doctor Pearman (though some prefer to call him Dr. Mechanic) is up to no good once again. With his newest machine, he has cracked the surface of the earth to tap into the ancient power hidden below and use it to rule the world. After seeing this, the great hero Shonic immediately departs along Dragon Road to reach the Doctor and put a stop to his plan.</p>

<p>Along the road, Shonic the Marmot comes across a spikefield of $n$ rows, divided along $m$ lanes. Each space in this spikefield contains either a spike trap, or is blank. Shonic is all out of his magic rings, so coming across a single spike would instantly kill him and have Doctor Pearman's plan succeed. Because of that, Shonic needs to go through a blank field in every row of the spikefield. Because he's moving very fast, Shonic can only make one horizontal move when moving to the next row of the spikefield. He can either go left and move down one row, right and move down one row, or stay in the same lane and move down one row. Additionally, he cannot leave the spikefield (he can't move to the left when in the leftmost lane). When initially entering the spikefield, Shonic can choose which field of the first row he starts in (though the field he starts in needs to be blank). A successful solution has Shonic treverse every row, starting with the first, and ending on a free field in the last. Help Shonic find a way to reach the end of the spikefield.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>A line with two integers $n$ ($2 \leq n \leq 10^3$) and $m$ ($2 \leq m \leq 10^3$), the number of rows and number of columns in the spikefield, respectively.</li>
	<li>$n$ lines consisting of a single string of length $m$ - the spikefield. An "<code>*</code>" (asterisk) signifies that a field contains a spike trap and an "<code>\_</code>" (underscore) signifies that the field is empty and traversable by Shonic.</li>
</ul>

### 출력 

 <p>The output consists of either:</p>

<ul>
	<li>A single integer $l$ ($1\leq l\leq n$), showing which lane Shonic starts in.</li>
	<li>A single string consisting of $n - 1$ characters ("<code>L</code>", "<code>R</code>" and "<code>F</code>", standing for left, right and forward respectively) showing the series of directions Shonic can take to reach the end of the spikefield unharmed.</li>
</ul>

<p>or the string "<code>impossible</code>" in case a valid path through the spikefield does not exist.</p>

<p>If there are multiple valid solutions, you may output any one of them.</p>

