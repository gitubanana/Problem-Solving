# [Gold V] Hacking - 3978 

[문제 링크](https://www.acmicpc.net/problem/3978) 

### 성능 요약

메모리: 1528 KB, 시간: 64 ms

### 분류

자료 구조, 문자열, 브루트포스 알고리즘, 집합과 맵

### 제출 일자

2025년 8월 18일 09:20:53

### 문제 설명

<p>A coach of one of the soccer world finals teams (lets call him Hugo Hacker) wants to find out secret information about an opposing team before the game. The coach of the opposing team has a website with public information about his team. Hugo suspects that also secret information is stored on the computer which hosts the website.</p>

<p>The website contains a form which allows to search for key words and returns a chunk of a text file which contains the key word. Hugo has found out that by entering words which cannot be found in the documents publicly available, he can exploit a bug in the search and get access to other files on the computer. He already knows the publicly available documents. However the search box has a restriction on the maximum length of a word and the characters which can be entered. Can you tell him a word which can be entered in the search box and which does not occur as a substring in the documents?</p>

### 입력 

 <p>The first line of the input consists of the number of test cases which are to follow. Each test case consists of two lines: in the first line there are three integers n (1 ≤ n ≤ 10 000), m (1 ≤ m ≤ 100) and k (1 ≤ k ≤ 26), where n is the length of the publicly available documents, m is the maximum allowed length of words which can be entered in the search box, and k specifies that the search box allows only the first k characters of the alphabet. The second line of each test case describes the publicly available documents and consists of n lower-case letters. </p>

### 출력 

 <p>For each test case in the input, print one line in the output containing a word which does not occur as a substring in the given text. The word should have at most m lower-case characters from the first k letters in the alphabet. You may assume that for each given test case, there is always at least one such word (you may print any such word).</p>

