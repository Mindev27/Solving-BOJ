# [Silver II] Subsequence Update - 33311 

[문제 링크](https://www.acmicpc.net/problem/33311) 

### 성능 요약

메모리: 4080 KB, 시간: 20 ms

### 분류

그리디 알고리즘, 정렬, 애드 혹

### 제출 일자

2025년 11월 25일 17:17:14

### 문제 설명

<p style="text-align: center;"><small><em>After Little John borrowed expansion screws from auntie a few hundred times, eventually she decided to come and take back the unused ones.</em></small></p>

<p style="text-align: center;"><small><em>But as they are a crucial part of home design, Little John decides to hide some in the most unreachable places --- under the eco-friendly wood veneers.</em></small></p>

<p>You are given an integer sequence $a_1, a_2, \ldots, a_n$, and a segment $[l,r]$ ($1 \le l \le r \le n$).</p>

<p>You must perform the following operation on the sequence <strong>exactly once</strong>.</p>

<ul>
	<li>Choose any <strong>subsequence</strong><sup>1</sup> of the sequence $a$, and reverse it. Note that the subsequence does not have to be contiguous.</li>
</ul>

<p>Formally, choose any number of indices $i_1,i_2,\ldots,i_k$ such that $1 \le i_1 < i_2 < \ldots < i_k \le n$. Then, change the $i_x$-th element to the original value of the $i_{k-x+1}$-th element simultaneously for all $1 \le x \le k$.</p>

<p>Find the <strong>minimum value</strong> of $a_l+a_{l+1}+\ldots+a_{r-1}+a_r$ after performing the operation.</p>

<hr>
<p><sup>1</sup>A sequence $b$ is a subsequence of a sequence $a$ if $b$ can be obtained from $a$ by the deletion of several (possibly, zero or all) element from arbitrary positions.</p>

### 입력 

 <p>Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.</p>

<p>The first line of each test case contains three integers $n$, $l$, $r$ ($1 \le l \le r \le n \le 10^5$) --- the length of $a$, and the segment $[l,r]$.</p>

<p>The second line of each test case contains $n$ integers $a_1,a_2,\ldots,a_n$ ($1 \le a_{i} \le 10^9$).</p>

<p>It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.</p>

### 출력 

 <p>For each test case, output the minimum value of $a_l+a_{l+1}+\ldots+a_{r-1}+a_r$ on a separate line.</p>

