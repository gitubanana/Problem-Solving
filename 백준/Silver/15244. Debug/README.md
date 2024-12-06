# [Silver II] Debug - 15244 

[문제 링크](https://www.acmicpc.net/problem/15244) 

### 성능 요약

메모리: 135728 KB, 시간: 1196 ms

### 분류

구현, 누적 합

### 제출 일자

2024년 12월 6일 10:55:28

### 문제 설명

<p dir="ltr">Seán is trying to debug a piece of his code. First he creates an array of N integers and fills it with zeros. Then he repeatedly calls the following procedure which he has written in C++:</p>

<pre dir="ltr">void something( int jump ) {
 int i = 0;
 while( i < N ) {
   seq[i] = seq[i] + 1;
   i = i + jump;
 }
}</pre>

<p>As you can see, this procedure increases by one all elements in the array whose indices are divisible by <code>jump</code>.</p>

<p>Seán calls the procedure exactly K times, using the sequence X<sub>1</sub> X<sub>2</sub> X<sub>3</sub> ... X<sub>k</sub> as arguments.</p>

<p>After this, Seán has a list of Q special parts of the array he needs to check to verify that his code is working as it should be. Each of this parts is defined by two numbers, L and R (L ≤ R) the left and right bound of the special part. To check the code, Seán must compute the sum of all elements of seq between and including L and R. In other words seq[L] + seq[L+1] + seq[L+2] + … + seq[R]. Since he needs to know the answer in advance in order to check it, he asked you to help him.</p>

### 입력 

 <p dir="ltr">The first line of input contains two integers, N (1 ≤ N ≤ 10<sup>6</sup>), size of the array, and K (1 ≤ K ≤ 10<sup>6</sup>), number of calls to <code>something</code> Seán makes.The second line contains K integers: X<sub>1</sub> X<sub>2</sub> X<sub>3</sub> ... X<sub>k</sub> , arguments passed to the procedure. (1 ≤ X<sub>i</sub> < N).</p>

<p>Next line contains one integer Q (1 ≤ Q ≤ 10<sup>6</sup>), number of special parts of the array Seán needs to check.</p>

<p>Next Q lines contain two integers each L<sub>i</sub> and R<sub>i</sub> (0 ≤ L<sub>i</sub> ≤ Ri < N), bounds of each special part.</p>

### 출력 

 <p dir="ltr">The output should contain exactly Q lines. The ith line should contain the sum of the elements seq[L<sub>i</sub>] + seq[L<sub>i</sub> +1] + seq[L<sub>i</sub> +2] + … + seq[R<sub>i</sub>].</p>

