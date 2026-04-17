# [Bronze III] Dice - 31125 

[문제 링크](https://www.acmicpc.net/problem/31125) 

### 성능 요약

메모리: 56836 KB, 시간: 1228 ms

### 분류

수학, 사칙연산

### 제출 일자

2026년 04월 17일 09:55:45

### 문제 설명

<p>Khodislav is playing a tabletop role-playing game. He has finally chosen his weapons to deal with a monster and casts the crushing strike. To do this, he rolls dice, calculates the sum of numbers on their faces, and says it aloud to the game master.</p>

<p>Rolling a group of identical dice is characterized by three numbers $n$, $f$, and $m$, where $n$ is the number of the dice, $f$ is the number of faces on each die, and $m$ is the modifier. The faces carry all numbers from $1$ through $f$, and each and any face can be rolled; all rolls are independent. For instance, if $n = 3$, $f = 8$, $m = 5$, to define the sum, the player must roll three eight-faced dice, sum up the results, and add five: this is usually written as $3d8 + 5$.</p>

<p>The game master wants to check if Khodislav could get the sum he has reported after rolling the dice.</p>

### 입력 

 <p>The first line of the input file contains a single integer $B$ --- the number of strikes ($1 \le B \le 10^5$) cast by Khodislav. The following lines describe the strikes, one per line. First comes an integer $S$ --- the sum reported by Khodislav. It is followed by three integers: $n$, $f$ and $m$ describing the group of dice ($1 \le S \le 300$, $1 \le n \le 10$, $2 \le f \le 20$, $0 \le m \le 10$).</p>

### 출력 

 <p>For each strike in a separate line, in the same order as in the input file, print <code>YES</code>, if the sum was achievable, and <code>NO</code> otherwise.</p>

