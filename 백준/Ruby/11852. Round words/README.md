# [Ruby V] Round words - 11852 

[문제 링크](https://www.acmicpc.net/problem/11852) 

### 성능 요약

메모리: 65388 KB, 시간: 120 ms

### 분류

다이나믹 프로그래밍, 문자열, 비트 집합, 최장 공통 부분 수열 문제, 비트 집합을 이용한 최장 공통 부분 수열 최적화

### 제출 일자

2026년 4월 20일 16:54:19

### 문제 설명

<p>After the recent apocalypse, Azamat, finally, learned about the largest common subsequences of two strings and now he is interested, what will be the largest common subsequence of two round words?</p>

<p>In a round word there is no difference from which symbol the word starts and in which direction it is read.</p>

<p>For instance, the round word "algorithm" can be read as "rithmalgo" and as "oglamhtir".</p>

<p>For usual words "algorithm" and "grammar" the longest common subsequence length is 3 (the word "grm"), and for round variant of the same word the length of the longest common subsequence is 4 (the word "grma").</p>

<p>Azamat quickly found out that the standard algorithm cannot get right answer for round words. Write the program which will do that for him.</p>

### 입력 

 <p>Two lines contain one word each. Words are non-empty and the length of each words doesn't exceed 2000 characters.</p>

### 출력 

 <p>The single line must contain one integer number - the length of the longest common subsequence of the given round words.</p>

