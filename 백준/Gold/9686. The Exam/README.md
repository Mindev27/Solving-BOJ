# [Gold IV] The Exam - 9686 

[문제 링크](https://www.acmicpc.net/problem/9686) 

### 성능 요약

메모리: 8292 KB, 시간: 84 ms

### 분류

해 구성하기, 그리디 알고리즘

### 제출 일자

2025년 2월 11일 22:40:48

### 문제 설명

<p>Professor Byteoni is preparing <i>Bit & Byte Theory</i> exam. He has already prepared n questions. Each of these questions has been ranked with an expected difficulty coefficient by the professor. This coefficient is a natural number ranging from 1 to n. Each of the questions holds a different coefficient.</p>

<p>Now the professor is considering the exam questions sequence. Professor wishes to determine whether his students are able to judge the question difficulty by themselves. For this purpose he plans to line up his questions in such a way, that coefficients of subsequent questions differ at least by k. Help the professor to find such a sequence.</p>

### 입력 

 <p>The first and only input line contains two integers n and k (2 ≤ n ≤ 1,000,000, 1 ≤ k ≤ n): the number of questions prepared by professor and the lower limit of the difficulty difference of subsequent exam questions.</p>

### 출력 

 <p>Your program should output one line containing sought question difficulty coefficients sequence, in other words a sequence of n pairwise distinct natural numbers ranging from 1 to n, where each two subsequent numbers differ at least by k. If there are numerous correct answers, your program should write any one of these. In case the sought sequence does not exist, your program should write only one word: <code>NIE</code> (Polish for <i>no</i>).</p>

