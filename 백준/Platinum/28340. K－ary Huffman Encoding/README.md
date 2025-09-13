# [Platinum IV] K-ary Huffman Encoding - 28340 

[문제 링크](https://www.acmicpc.net/problem/28340) 

### 성능 요약

메모리: 2404 KB, 시간: 8 ms

### 분류

자료 구조, 그리디 알고리즘, 트리, 우선순위 큐

### 제출 일자

2025년 9월 13일 12:18:31

### 문제 설명

<p>Huffman 나라의 문자는 $N$개의 문자로 이루어져 있다. <code>0</code>과 <code>1</code>로 이루어진 이진 인코딩이 발달한 대한민국과는 달리, Huffman 나라에서는 $0$부터 $K - 1$까지의 숫자로 이루어진 $K$진법 인코딩이 발달했다.</p>

<p>우리는 Huffman 나라의 언어를 $K$진법으로 인코딩하려 한다. 이 때 다음 조건을 만족해야 한다.</p>

<ol>
	<li>$N$개의 각 문자에 $K$진법 문자열을 하나씩 배정해야 한다.</li>
	<li>배정된 $K$진법 문자열들이 서로의 접두사 (prefix)일 수 없다.</li>
</ol>

<p>예를 들어 아래의 표는 <code>!</code>, <code>@</code>, <code>#</code>, <code>+</code> $4$개의 문자를 $3$진법으로 올바르게 인코딩한 예이다.</p>

<table class="table table-bordered table-center-20 th-center td-center">
	<thead>
		<tr>
			<th>문자</th>
			<th>인코딩</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td><code>! </code></td>
			<td><code>012</code></td>
		</tr>
		<tr>
			<td><code>@ </code></td>
			<td><code>120</code></td>
		</tr>
		<tr>
			<td><code># </code></td>
			<td><code>201</code></td>
		</tr>
		<tr>
			<td><code>+ </code></td>
			<td><code>210</code></td>
		</tr>
	</tbody>
</table>

<p>$4$개의 문자 각각에 서로의 접두사가 아닌 3진법 문자열을 할당했음을 확인해 볼 수 있다. 반면,</p>

<table class="table table-bordered table-center-20 th-center td-center">
	<thead>
		<tr>
			<th>문자</th>
			<th>인코딩</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td><code>! </code></td>
			<td><code>013</code></td>
		</tr>
		<tr>
			<td><code>@ </code></td>
			<td><code>120</code></td>
		</tr>
		<tr>
			<td><code># </code></td>
			<td><code>201</code></td>
		</tr>
		<tr>
			<td><code>+ </code></td>
			<td><code>210</code></td>
		</tr>
	</tbody>
</table>

<p>은 <code>!</code>에 <code>013</code>을 배정해서 첫 번째 조건을 만족하지 않고,</p>

<table class="table table-bordered table-center-20 th-center td-center">
	<thead>
		<tr>
			<th>문자</th>
			<th>인코딩</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td><code>! </code></td>
			<td><code>012</code></td>
		</tr>
		<tr>
			<td><code>@ </code></td>
			<td><code>120</code></td>
		</tr>
		<tr>
			<td><code># </code></td>
			<td><code>201</code></td>
		</tr>
		<tr>
			<td><code>+ </code></td>
			<td><code>20</code></td>
		</tr>
	</tbody>
</table>

<p>은 <code>+</code>이 <code>#</code>의 접두사이기 때문에 두 번째 조건을 만족하지 않는다.</p>

<p>Huffman 나라 언어 문자열이 하나 주어졌을 때, 이 문자열을 $K$진법으로 인코딩한 결과를 가장 짧게 만들면 길이가 어떻게 될까? 예를 들어 “<code>!!!@@@@#####++++++</code>” 과 같이 <code>!</code>가 $3$번, <code>@</code>가 $4$번, <code>#</code>가 $5$번, <code>+</code>가 $6$번 문자열에 나타났다면, 첫 번째 표에서 제시한 인코딩을 적용한 경우 총 길이는 $54$가 된다 ($3 \times 3+4\times 3+5\times 3+6\times 3 = 54$).</p>

### 입력 

 <p>입력은 $T$개의 테스트 케이스로 구성된다. 입력의 첫 줄에는 $T$가 주어진다.</p>

<p>각 테스트 케이스 첫 줄에는 두 정수 $N$ ($2 ≤ N ≤ 10\,000$), $K$ ($2 ≤ K ≤ 10\,000$)가 공백으로 구분되어 주어진다. $N$은 Huffman 나라의 문자의 수이고 $K$는 인코딩할 진법을 나타낸다. 다음 줄에는 각 문자가 문자열에 몇 번이나 나타나는지를 의미하는 $N$개의 정수 $C_i$ ($0 ≤ C_i ≤ 100\,000$)가 공백으로 구분되어 주어진다.</p>

### 출력 

 <p>각 테스트 케이스마다 한 줄에 하나씩 주어진 문자열의 가능한 최소 $K$진법 인코딩의 길이를 출력한다.</p>

