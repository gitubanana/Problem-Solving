# [Gold II] Cash Cow - 9441 

[문제 링크](https://www.acmicpc.net/problem/9441) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

구현, 그래프 이론, 그래프 탐색, 시뮬레이션, 너비 우선 탐색

### 제출 일자

2026년 04월 17일 09:55:45

### 문제 설명

<p>Years before Candy Crush became the wildly popular game that may lead developer Saga to a multi-billion dollar IPO, there was an online game named Cash Cow, which remains part of the Webkinz platform.</p>

<p>This single-player game has a board with 12 rows and 10 columns, as shown in Figure 1. We label the rows 1 through 12, starting at the bottom, and the columns <em>a</em> through <em>j</em>, starting at the left. Each grid location can either have a colored circle or be empty. (We use uppercase characters to denote distinct colors, for example with B=blue, R=red, and Y=yellow.) On each turn, the player clicks on a circle. The computer determines the largest "cluster" to which that circle belongs, where a cluster is defined to include the initial circle, any of its immediate horizontal and vertical neighbors with matching color, those circles' neighbors with matching colors, and so forth. For example, if a user were to click on the blue circle at cell (h10) in Figure 1, its cluster consists of those cells shown with empty circles in Figure 2.</p>

<table class="table table-bordered" style="height:204px; text-align:center; width:406px">
	<tbody>
		<tr>
			<td><img src=""></td>
			<td><img src=""></td>
			<td><img src=""></td>
		</tr>
		<tr>
			<td>Figure 1</td>
			<td>Figure 2</td>
			<td>Figure 3</td>
		</tr>
		<tr>
			<td colspan="3">Processing a click on cell h10.</td>
		</tr>
	</tbody>
</table>

<p>The player's turn is processed as follows. If the indicated grid cell belongs to a cluster of only one or two circles (or if there is no circle at that cell), the turn is wasted. Otherwise, with a cluster of 3 or more circles, all circles in the cluster are removed from the board. Remaining circles are then compacted as follows:</p>

<ol>
	<li>Circles fall vertically, to fill in any holes in their column.</li>
	<li>If one or more columns have become empty, all remaining columns slide leftward (with each nonempty column remaining intact), such that they are packed against the left edge of the board.</li>
</ol>

<p>For example, Figure 3 shows the board after the cluster of Figure 2 was removed after the click on (h10).</p>

<p>As another example, Figure 4 below, portrays the processing of a subsequent click on cell (j1). During that turn, column (e) becomes empty, and the resulting columns (f) through (j) slide to become columns (e) through (i), respectively. Figure 5 provides one further example in which several columns are compacted.</p>

<table class="table table-bordered" style="height:204px; text-align:center; width:406px">
	<tbody>
		<tr>
			<td><img src=""></td>
			<td><img src=""></td>
			<td><img src=""></td>
		</tr>
		<tr>
			<td colspan="3">Figure 4: Processing a click on cell j1.</td>
		</tr>
	</tbody>
</table>

<table class="table table-bordered" style="height:204px; text-align:center; width:406px">
	<tbody>
		<tr>
			<td><img src=""></td>
			<td><img src=""></td>
			<td><img src=""></td>
		</tr>
		<tr>
			<td colspan="3">Figure 5: Processing a click on cell g2.</td>
		</tr>
	</tbody>
</table>

### 입력 

 <p>The input will consist of multiple games, each played with a new board. For each game, the input begins with a number <em>T</em> that denotes the number of turns that the player will be making, with 1 ≤ <em>T</em> ≤ 20. Following that will be an initial board configuration, which always has 12 rows and 10 columns per row, with uppercase letters used to denote distinct colors. There will never be empty cells within the initial board. Following the presentation of the initial board will be <em>T</em> additional lines of input, each designating a cell of the grid; we rely on the coordinate system illustrated in the above figures, with a lowercase letter, from <code>a</code> to <code>j</code>, denoting a column and a number from 1 to 12 that denotes a row. We note that if a player clicks on a grid cell that does not currently have any circle, that turn is simply wasted.</p>

<p>The end of the entire input will be designated by a line with the number 0.</p>

### 출력 

 <p>For each game, output a single line designating the the number of circles that remain on the board after all of the player's turns are processed.</p>

