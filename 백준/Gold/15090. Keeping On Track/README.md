# [Gold IV] Keeping On Track - 15090 

[문제 링크](https://www.acmicpc.net/problem/15090) 

### 성능 요약

메모리: 16708 KB, 시간: 264 ms

### 분류

다이나믹 프로그래밍, 트리에서의 다이나믹 프로그래밍, 그래프 이론, 그래프 탐색, 트리

### 제출 일자

2024년 12월 1일 23:10:57

### 문제 설명

<p>Acmar and Ibmar are at war! You are in charge of a rail network that transports important supplies throughout the great state of Acmar during this delicate time. The rail system is made up of a set of rail lines which meet at various junction points. While there is no limit to the number of rail lines that can meet at a junction, the network is set up so that there is only one path between any two junctions. You’ve tried to argue for some redundancy in the system, i.e., extra rail lines so that there are two or more paths connecting some junctions, but it’s wartime and budgets are tight.</p>

<p>However, this may soon change as you’ve just been given some terrible news from double agents working in Ibmar: within the next month enemy spies plan to blow up one of the junctions! Unfortunately, the exact junction is not known, but knowing your enemy well you are certain that they will undoubtedly strike the critical junction, specifically the junction whose removal disconnects the most pairs of other remaining junctions in the system. You don’t have much time to act, so the most you can do is add one new line connecting two currently unconnected junctions, thereby reducing the number of disconnected pairs after the critical junction has been destroyed. Your job is to determine how to make the number of disconnected pairs as small as possible by adding in the best possible rail line.</p>

### 입력 

 <p>Input starts with a line containing an integer n (2 ≤ n ≤ 10 000) indicating the number of rail lines in the system. Following that are n lines of the form i<sub>1</sub> i<sub>2</sub> indicating that a rail line connects junctions i<sub>1</sub> and i<sub>2</sub>. Junctions are numbered consecutively starting at 0. All rail lines are two-way and no rail line appears more than once in the input. There is exactly one path between any two junction points given in the input.</p>

### 출력 

 <p>Display two values n<sub>1</sub> and n<sub>2</sub>, where n<sub>1</sub> is the number of pairs of junctions which will be disconnected when the enemy destroys the critical junction, and n<sub>2</sub> is the number of pairs of junctions still disconnected after you add in the best possible rail line. There will never be more than one critical junction.</p>

