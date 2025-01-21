# [Gold V] Breeding - 27030 

[문제 링크](https://www.acmicpc.net/problem/27030) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

자료 구조, 다이나믹 프로그래밍, 해시를 사용한 집합과 맵, 수학, 정수론

### 제출 일자

2025년 1월 21일 22:13:04

### 문제 설명

<p>Farmer John is breeding his cows (no bulls are necessary in these days of modern breeding techniques using long-dead prize-winning bulls).  By carefully choosing the amount of food they receive, Farmer John can control the number of calves each cow in his herd will produce.  Since he feeds each cow the same amount, each cow will produce the same number of calves.  Farmer John starts with a single cow and wants to expand to a herd of N cows after some number of generations of breeding.</p>

<p>For example, if N = 12, then Farmer John could feed his original cow enough to produce 3 calves.  When this next generation grows old enough to produce calves, he feeds them each enough to produce 4 calves, yielding 12 cows in the final generation.  Once a cow produces offspring she is sold, so Farmer John only keeps the cows in the most recent generation.</p>

<p>During each generation, each cow produces no fewer than 2 calves, and there is no upper limit on the number of calves a cow can have (Farmer John uses a very strong breed of cow).</p>

<p>Given an integer N (1 ≤ N ≤ 2,000,000,000), how many different ways can Farmer John eventually obtain N cows, if he starts with only 1?  The number of ways of obtaining N will not exceed 2,000,000,000.</p>

### 입력 

 <ul>
	<li>Line 1: The integer N.</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: The number of ways to obtain N cows.</li>
</ul>

