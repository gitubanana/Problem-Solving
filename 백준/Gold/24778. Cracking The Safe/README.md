# [Gold III] Cracking The Safe - 24778 

[문제 링크](https://www.acmicpc.net/problem/24778) 

### 성능 요약

메모리: 2400 KB, 시간: 12 ms

### 분류

너비 우선 탐색, 브루트포스 알고리즘, 그래프 이론, 그래프 탐색

### 제출 일자

2025년 7월 29일 10:56:13

### 문제 설명

<p><img alt="" src="https://upload.acmicpc.net/097b6f04-065d-422a-9eec-7b42c74e3dba/-/preview/" style="width: 200px; height: 210px; float: right;">Your little sister misplaced the code for her toy safe - can you help her?</p>

<p>This particular safe has 9 buttons with digital displays. Each button shows a single digit in the range <code>0..3</code>. When you push one of the buttons, the number it displays is incremented by 1, circling around from 3 to 0.  However, pushing a button will also increment the other digits in the same row and the same column as the button pushed.</p>

<p>The safe opens when the display shows nine zeros.</p>

<p>For instance, if you pushed the top-left, center, center, and middle-right buttons, in this order, the safe's display would change like so:</p>

<pre>3 1 2     0 2 3     0 3 3     0 0 3     0 0 0
0 1 1  -> 1 1 1  -> 2 2 2  -> 3 3 3  -> 0 0 0
3 2 3     0 2 3     0 3 3     0 0 3     0 0 0
</pre>

<p>Write a program to determine if the safe can be opened, and if so, how many button pushes it would take!</p>

### 입력 

 <p>The input is a single test case, given as 9 digits <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D451 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>d</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$d$</span></mjx-container>, (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D451 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c33"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn><mo>≤</mo><mi>d</mi><mo>≤</mo><mn>3</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$0 \le d \le 3$</span></mjx-container>) on 3 lines, representing the digits that are initially displayed on the safe's buttons. Your program will be run multiple times on different inputs.</p>

### 출력 

 <p>Output the number of times buttons need to be pushed to open the safe! (The same button may need to be pushed more than once, and you do not have to output which buttons must be pushed.) If the safe cannot be opened, output <code>-1</code>.</p>

