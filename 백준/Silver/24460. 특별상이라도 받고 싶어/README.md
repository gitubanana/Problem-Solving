# [Silver III] 특별상이라도 받고 싶어 - 24460 

[문제 링크](https://www.acmicpc.net/problem/24460) 

### 성능 요약

메모리: 159648 KB, 시간: 536 ms

### 분류

분할 정복, 재귀

### 제출 일자

2024년 10월 16일 09:22:29

### 문제 설명

<p>HCPC 2021에 참석한 $N \times N$명의 사람들이 의자가 정사각형 형태로 배치된 대회장에서 대회를 한다. 모든 의자에는 서로 다른 추첨번호가 적혀있으며 HCPC 2021의 마지막에는 아래에 설명된 규칙에 따라 특별상을 받을 사람 한 명을 정한다.</p>

<ol>
	<li>특별상을 받을 수 있는 사람이 한 명이라면, 그 사람이 뽑힌다.</li>
	<li>그렇지 않은 경우, 대회장을 같은 크기의 정사각형 네 개로 나누어 각 구역에서 이 규칙을 재귀적으로 적용해서 구역마다 한 명씩 총 네 명을 뽑는다.</li>
	<li>뽑힌 네 명 중 의자에 적힌 추첨번호가 두 번째로 작은 사람이 뽑힌다.</li>
</ol>

<p>HCPC 2021에 참가한 지원이는 자신의 실력이 부족해서 수상권이 아니라고 생각하였고, 실력과 무관하게 받을 수 있는 특별상을 노리고 있다.</p>

<p>아래 예시를 참고하자.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/4ac072f3-4143-4ea0-b6b8-bcf5eee3d847/-/preview/" style="height: 394px; width: 700px;"></p>

<p>위와 같은 의자 배열이 있다고 가정하자. 이를 네 개의 구역으로 나누면 아래와 같다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/a97397ab-f9de-49d9-b528-097bfee40e9b/-/preview/" style="height: 394px; width: 700px;"></p>

<p>나누어진 구역의 왼쪽 위 구역을 다시 네 개의 구역으로 나누면 아래와 같다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/9bc698f1-b0fe-4fd4-a97b-5d6def59dac0/-/preview/" style="height: 394px; width: 700px;"></p>

<p>여기에서 추첨번호가 두 번째로 낮은 사람을 고르면 아래와 같다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/9e87ed70-e9f0-4265-a7ab-bc683bb09bfb/-/preview/" style="height: 394px; width: 700px;"></p>

<p>이와 같은 작업을 모든 영역에 대해 실행하면 아래와 같다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/48969422-120b-4f08-a569-5ba3a2986bd5/-/preview/" style="height: 394px; width: 700px;"></p>

<p>따라서 특별상을 받는 추첨번호는 아래와 같다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/15ca0a46-e06a-496b-8a02-5c79e58a2b18/-/preview/" style="height: 394px; width: 700px;"></p>

<p>따라서, 추첨번호 $3$이 적힌 의자에 앉은 참가자가 특별상을 받는다.</p>

<p>의자 각각에 적혀 있는 추첨번호가 주어질 때, 지원이가 HCPC 2021에서 경품을 받을 수 있으려면 어떤 의자에 앉아야 하는지 계산하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫 번째 줄에는 정수 $N$이 주어진다. (단, $N = 2^m$, $0 \le m \le 10$, $m$은 정수)</p>

<p>두 번째 줄부터 $N$개 줄의 $i$번째 줄에는 $i$번째 줄에 있는 의자에 적힌 추첨번호가 주어진다. 각 줄에는 $N$개의 추첨번호가 공백으로 구분되어 주어진다.</p>

<p>추첨번호는 $2^{31}$ 보다 작은 음이 아닌 정수이고, 모든 추첨번호는 서로 다름이 보장된다.</p>

### 출력 

 <p>지원이가 HCPC 2021에서 경품을 받기 위해 앉아야 하는 의자에 적힌 추첨번호를 출력한다.</p>

