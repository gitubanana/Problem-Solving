# [Bronze II] Broken Swords - 24809 

[문제 링크](https://www.acmicpc.net/problem/24809) 

### 성능 요약

메모리: 17784 KB, 시간: 124 ms

### 분류

사칙연산, 구현, 수학

### 제출 일자

2024년 11월 20일 11:18:38

### 문제 설명

<p>Ken is a fencer with a big problem: he swings too hard!</p>

<p>Whenever Ken gets a new sword, he's sure to break it sooner rather than later. It's occurred to him that this habit is costing him quite a bit of money, since he normally buys a new sword whenever his current sword breaks. However, he's heard from a fellow club member that he could instead make new swords out of his old swords!</p>

<p>Each bamboo sword Ken uses has four bamboo 'slats' which help to cushion each blow for the receiving partner. Whenever Ken breaks his sword, he breaks either one, two, three, or all four slats.</p>

<p>When Ken first tried to put a sword together with the remains of two broken swords, he realized that not all slats are equivalent. When the slats are bundled together, they conform to the shape of the slat which sits opposite!</p>

<p>Ken doesn't want an uncomfortable grip, so he will put only an old slat in a new position if it is of the same or opposite type.  There are four possible slats "top" (<code>T</code>), "bottom" (<code>B</code>), "left" (<code>L</code>), and "right" (<code>R</code>). When looking at a sword head on, these slats form the following configuration:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/f2e07817-da28-4a42-86ad-833d4a941fef/-/preview/" style="width: 100px; height: 104px;"></p>

<p>As an example, Ken will only replace a top slat with a top or bottom slat.</p>

<p>After collecting broken swords for quite a while, Ken has decided to build as many swords as possible.  Write a program to compute how many swords he will be able to build and how many slats he'll have left over!</p>

### 입력 

 <p>The input consists of a single test case. On the first line, you are given <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>, the number of swords Ken has broken.  On each of the next <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container> lines, you are given four characters. The characters correspond to the following slat ordering: <code>TBLR</code>. If the character in a position is <code>0</code>, then the slat is not broken, and if it is a <code>1</code>, Ken is out of luck!</p>

### 출력 

 <p>Output three numbers: the total number of swords Ken can make, the sum of the numbers of the remaining T and B slats, and the sum of the numbers of the remaining L and R slats, respectively.</p>

