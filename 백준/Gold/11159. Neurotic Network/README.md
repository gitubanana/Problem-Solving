# [Gold IV] Neurotic Network - 11159 

[문제 링크](https://www.acmicpc.net/problem/11159) 

### 성능 요약

메모리: 19048 KB, 시간: 196 ms

### 분류

다이나믹 프로그래밍, 트리에서의 다이나믹 프로그래밍, 트리

### 제출 일자

2024년 12월 3일 11:12:12

### 문제 설명

<p>In this problem, a neural net is represented by a rooted tree with weighted edges. The neural net processes information by a cascade of signals that begins at the leaf nodes: Each node in the tree computes an output value based on its upstream neighbors, and passes this value on to its downstream neighbor. The output value computed by a node is the sum of the output of each of its upstream neighbors multiplied by the weight of the edge from the upstream neighbor to the node itself. A node with no upstream neighbors (leaf nodes) always has 1 as output. All neural nets in this problem have exactly one final output node (the root node).</p>

<p>Sometimes, a neural net can go haywire and become what is more commonly known as a neurotic network. Consider this your chance to launch a second career in psychiatry. The scenario is that someone just came in with a neurotic network in their head. What this means is that if the output of their neural net is an even number, the person will freak out and will set fire to a kitten. Therefore, it is of vital importance that you can know ahead of time whether or not a given person is safe. If it is safe, print their neural output modulo 1,000,000,007. If you wouldn’t trust the person to be around kittens who’re not wrapped in fire retardant, print the string “FREAK OUT” (without the quotes).</p>

### 입력 

 <p>The first line of input is T, the number of test cases. For each of the T cases, the first line will be the integer N, the number of nodes in the tree. The next line contains N − 1 integers a<sub>1</sub>, a<sub>2</sub>, · · · , a<sub>N−1</sub> where a<sub>i</sub> is the downstream neighbour of the node with ID i. Then follows a line with N − 1 integers w<sub>1</sub>, w<sub>2</sub>, · · · , w<sub>N−1</sub> where w<sub>i</sub> is the weight of the neural connection going out from the node with ID i. Note that the node with ID 0 will always be the output node.</p>

<ul>
	<li>0 < T ≤ 50</li>
	<li>0 < N ≤ 10000</li>
	<li>0 < w<sub>i</sub> ≤ 10</li>
	<li>0 ≤ a<sub>i</sub> < N</li>
	<li>The graph is guaranteed to be a tree.</li>
	<li>This is an I/O-heavy problem. For Java programmers, this means that you should use <code>BufferedReader</code> for input reading (not <code>Scanner</code>).</li>
</ul>

### 출력 

 <p>Output “FREAK OUT” (without the quotes) if the final value of the neural net’s output node is even. Otherwise, output the final value of the output node, modulo 1,000,000,007.</p>

