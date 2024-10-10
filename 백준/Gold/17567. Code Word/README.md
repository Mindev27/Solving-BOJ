# [Gold II] Code Word - 17567 

[문제 링크](https://www.acmicpc.net/problem/17567) 

### 성능 요약

메모리: 3084 KB, 시간: 40 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2024년 10월 10일 16:10:15

### 문제 설명

<p>Following on from the engineering success of Left Pad, Ltd, Lynn started a new venture: Internet of Security, Inc. The company’s flagship product will be a device for entering passcodes.</p>

<p>The chief innovation of this device will be in its ability to reject attempts to set insecure passwords. An insecure passcode is defined as a sequence of digit presses such that at least two consecutive presses are either directly or diagonally adjacent.</p>

<p>Lynn, ever-vigilant for the future, is worried that this system might not allow enough unique passcodes to support a large company with trillions of employees. For a given digit pad grid size, and fixed length of password, calculate the number of allowed passwords.</p>

<p>Since the number might be very large in some cases, output your answer mod 1 000 000 007.</p>

### 입력 

 <ul>
	<li>The first line contains the integers r and c (1 ≤ r, c ≤ 100), the number of rows and columns of buttons on the pad.</li>
	<li>The second line contains the integer l (1 ≤ l ≤ 200), the single allowed length for any passcode.</li>
</ul>

### 출력 

 <p>Output the number of legal passcodes, mod 1 000 000 007.</p>

