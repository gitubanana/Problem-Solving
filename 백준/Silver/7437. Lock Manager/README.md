# [Silver I] Lock Manager - 7437 

[문제 링크](https://www.acmicpc.net/problem/7437) 

### 성능 요약

메모리: 2692 KB, 시간: 8 ms

### 분류

자료 구조, 해시를 사용한 집합과 맵, 구현, 집합과 맵

### 제출 일자

2025년 6월 28일 16:36:24

### 문제 설명

<p>You are invited to be a part of the team that is developing yet another DBMS (Data Base Management System). You will be responsible for the Lock Manager.</p>

<p>Locks control concurrent access to data items by multiple transactions. Your DBMS is simple and uses only Shared (S) and Exclusive (X) mode locks. Each lock request contains a lock mode (S or X), a transaction identifier and a data item identifier. Multiple locks can be granted to the same data item as long as none of them <b>conflict</b>.</p>

<p>Two locks for the same data item conflict if:</p>

<ul>
	<li>they belong to different transactions, and</li>
	<li>at least one of them is exclusive (X) mode lock.</li>
</ul>

<p>At the earliest stages of development you are asked to write very simple lock manager that processes lock requests. The lock is granted if it does not conflict with previously granted locks for this data item. Your task is simple: locks, once granted, are never released or changed in any way. If lock request is denied due to conflict with some previously granted lock, then transaction making this request is blocked and all further requests from this transaction are ignored.</p>

### 입력 

 <p>The input file consists of a number of lock requests, each request on a different line. Requests have the following format:</p>

<p><code>MODE TRID ITEM</code></p>

<p>Where MODE is a single capital letter S or X denoting requested lock mode. TRID and ITEM are transaction identifier and data item identifier correspondingly. Both TRID and ITEM are integers, both are greater than zero, and both consist of at most 9 decimal digits.</p>

<p>There are at least one and at most 10000 requests in the input file.</p>

<p>The last request is followed by a line consisting of a single character '#'.</p>

### 출력 

 <p>Your program shall sequentially process all requests from the input file. For each request you should write one line that contains the response to the request. The following responses are allowed:</p>

<ul>
	<li>GRANTED - the lock request does not conflict with any previously granted locks and is granted.</li>
	<li>DENIED - the lock request conflicts with some previously granted lock and is denied, thus blocking the requesting transaction.</li>
	<li>IGNORED - the transaction was blocked on some request before this one.</li>
</ul>

<p>Responses shall appear in all capital letters exactly as shown above. An arbitrary number of blank lines can follow last response in the output file.</p>

