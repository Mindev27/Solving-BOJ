# [Diamond V] Instructions (Easy) - 18716 

[문제 링크](https://www.acmicpc.net/problem/18716) 

### 성능 요약

메모리: 4528 KB, 시간: 0 ms

### 분류

비트마스킹

### 제출 일자

2024년 5월 7일 14:23:36

### 문제 설명

<p>The wannabe scientist Kleofáš has recently developed a new processor. The processor has got 26 registers, labeled A to Z. Each register is a 64-bit unsigned integer variable.</p>

<p>This new processor is incredibly simple. It only supports the instructions specified in the table below. (In all instructions, R is a name of a register, and X is either the name of a register, or a 64-bit unsigned integer constant.)</p>

<table class="table table-bordered">
	<tbody>
		<tr>
			<th>syntax</th>
			<th>semantics</th>
		</tr>
		<tr>
			<td>mov R X</td>
			<td>Store the value X into R.</td>
		</tr>
		<tr>
			<td>and R X</td>
			<td>Compute the bitwise and of the values R and X, and store it in R.</td>
		</tr>
		<tr>
			<td>or R X</td>
			<td>Compute the bitwise or of the values R and X, and store it in R.</td>
		</tr>
		<tr>
			<td>xor R X</td>
			<td>Compute the bitwise xor of the values R and X, and store it in R.</td>
		</tr>
		<tr>
			<td>not R</td>
			<td>Compute the bitwise not of the value R, and store it in R.</td>
		</tr>
		<tr>
			<td>shl R X</td>
			<td>Take the value in R, shift it to the left by X bits, and store the result in R.</td>
		</tr>
		<tr>
			<td>shr R X</td>
			<td>Take the value in R, shift it to the right by X bits, and store the result in R.</td>
		</tr>
	</tbody>
</table>

<p>Notes:</p>

<ul>
	<li>After any instruction other than not, if the second argument was a register name, its content remains unchanged.</li>
	<li>If shl or shr is called with a non-zero second argument, the shifted value of the first argument is padded with zeroes. Note that this means that if the second argument is 64 or more, the result will always be zero, regardless of the first argument.</li>
</ul>

<p>Example task:</p>

<p>Assume that the register A contains an arbitrary input number between 0 and 15, and that all the other registers contain zeroes. Write a program that will set Z to 1 if the number of set bits in A is odd, and to 0 otherwise.</p>

<p>Easy task:</p>

<p>Assume that the register A contains an arbitrary input number, and that all the other registers contain zeroes. Write a program that will increase the value in A by 8 (computing modulo 2<sup>64</sup>, if necessary). After your program terminates, the other registers are allowed to contain anything. Your program must have less than 64 instructions.</p>

### 입력 

 <p>This problem has no input.</p>

### 출력 

 <p>Send us your program as a text file. Each line of the file may either contain one complete instruction, or just whitespace.</p>

