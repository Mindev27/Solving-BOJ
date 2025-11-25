# [Gold II] Remove Exactly Two - 33312 

[문제 링크](https://www.acmicpc.net/problem/33312) 

### 성능 요약

메모리: 45324 KB, 시간: 276 ms

### 분류

그래프 이론, 자료 구조, 그리디 알고리즘, 트리, 집합과 맵, 트리를 사용한 집합과 맵

### 제출 일자

2025년 11월 25일 17:17:41

### 문제 설명

<p style="text-align: center;"><small><em>Recently, Little John got a tree from his aunt to decorate his house. But as it seems, just one tree is not enough to decorate the entire house. Little John has an idea. Maybe he can remove a few vertices from the tree. That will turn it into more trees! Right?</em></small></p>

<p>You are given a tree<sup>1</sup> of $n$ vertices. You must perform the following operation <strong>exactly twice</strong>.</p>

<ul>
	<li>Select a vertex $v$;</li>
	<li>Remove all edges incident to $v$, and also the vertex $v$.</li>
</ul>

<p>Please find the maximum number of connected components after performing the operation <strong>exactly twice</strong>.</p>

<p>Two vertices $x$ and $y$ are in the same connected component if and only if there exists a path from $x$ to $y$. For clarity, note that the graph with $0$ vertices has $0$ connected components by definition.<sup>2</sup></p>

<hr>
<p><sup>1</sup>A tree is a connected graph without cycles.</p>

<p><sup>2</sup>But is such a graph connected?</p>

### 입력 

 <p>Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.</p>

<p>The first line of each test case contains a single integer $n$ ($2 \le n \le 2 \cdot 10^5$).</p>

<p>Each of the next $n-1$ lines contains two integers $u_i$ and $v_i$, denoting the two vertices connected by an edge ($1 \le u_i,v_i \le n$, $u_i \neq v_i$). It is guaranteed that the given edges form a tree.</p>

<p>It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.</p>

### 출력 

 <p>For each test case, output the maximum number of connected components on a separate line.</p>

