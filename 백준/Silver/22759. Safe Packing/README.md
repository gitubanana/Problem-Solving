# [Silver II] Safe Packing - 22759 

[문제 링크](https://www.acmicpc.net/problem/22759) 

### 성능 요약

메모리: 1228 KB, 시간: 8 ms

### 분류

이분 탐색, 그리디 알고리즘, 수학

### 제출 일자

2025년 9월 17일 10:51:10

### 문제 설명

<p>The manager of a packing warehouse, which specialises in packing breakable items, contracted a supplier for boxes of sizes from the Fibonacci sequence. I am not sure of the reason behind it, but it is rumoured to be related to the recent “Da Vinci code” movie. An item whose size is in the sequence can be packed in a box of the equal size without filling, but an item whose size is not in the sequence must be packed with sufficient filling material to fill the box and protect the item from breaking. An item cannot be split between two boxes, and each item must be packed separately in its own box. It is allowed to use multiple boxes of the same size.</p>

<p>The second twist in this story, which makes it more bizarre, is that the company only receives a daily filling material delivery of size F to be used. At the end of each day, any unused filling material is discarded. Unlike the items, the filling material can be split as needed</p>

<p> Your task is to maximize the number of items shipped each day for a given size of filling material F and a given list of items.</p>

<p>The Fibonacci sequence fib(n) is defined as: $$fib(n) = \begin{cases} n & \text{for } n < 2 \\ fib(n-1) + fib(n-2) & \text{for } n \ge 2 \end{cases}$$</p>

<p>Here are the first eleven numbers of Fibonacci sequence:</p>

<p style="text-align: center;">0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, . . .</p>

<p>Note that each number, with the exception of the first two, is obtained by adding the preceding two numbers.</p>

### 입력 

 <p>The input to this problem consists of packing tasks for one or more days. The tasks for each day are described by two lines as follows:</p>

<ul>
	<li>The first line consists of three integers: the number of items to be packed, W (0 < W < 1000); the available size of filling material, F (1 < F < 1000); and the maximum size of items, S (1 < S < 10<sup>8</sup>). The integers are separated by spaces.</li>
	<li>The following line contains W integers separated by spaces that describe the sizes of items to be packed.</li>
</ul>

<p>The input will be terminated by a line that consists of three zeros, separated by spaces. This line should not be processed.</p>

### 출력 

 <p>For each day, the output consists of one line that contains the number of items that can be packed for that day.</p>

