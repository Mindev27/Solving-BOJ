# [Gold IV] Product Triplets - 23983 

[문제 링크](https://www.acmicpc.net/problem/23983) 

### 성능 요약

메모리: 3724 KB, 시간: 308 ms

### 분류

브루트포스 알고리즘, 많은 조건 분기, 자료 구조, 해시를 사용한 집합과 맵, 수학

### 제출 일자

2025년 2월 6일 20:11:22

### 문제 설명

<p>Given <b>N</b> integers <b>A</b><sub>1</sub>, <b>A</b><sub>2</sub>, ..., <b>A</b><sub><b>N</b></sub>, count the number of triplets (x, y, z) (with 1 ≤ x < y < z ≤ <b>N</b>) such that at least one of the following is true:</p>

<ul>
	<li><b>A</b><sub>x</sub> = <b>A</b><sub>y</sub> × <b>A</b><sub>z</sub>, and/or</li>
	<li><b>A</b><sub>y</sub> = <b>A</b><sub>x</sub> × <b>A</b><sub>z</sub>, and/or</li>
	<li><b>A</b><sub>z</sub> = <b>A</b><sub>x</sub> × <b>A</b><sub>y</sub></li>
</ul>

### 입력 

 <p>The first line of the input gives the number of test cases, <b>T</b>. <b>T</b> test cases follow. Each begins with one line containing an integer <b>N</b>: the number of integers in array <b>A</b>. The second line consists of <b>N</b> integers <b>A</b><sub>i</sub>; the i-th of these is the value of the i-th integer, as described above.</p>

### 출력 

 <p>For each test case, output one line containing <code>Case #x: y</code>, where <code>x</code> is the test case number (starting from 1) and <code>y</code> is the number of triplets satisfying the condition given in the problem statement.</p>

