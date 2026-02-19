# [Diamond II] Islands - 17970 

[문제 링크](https://www.acmicpc.net/problem/17970) 

### 성능 요약

메모리: 9720 KB, 시간: 24 ms

### 분류

애드 혹

### 제출 일자

2026년 2월 19일 19:29:36

### 문제 설명

<p>There are twin islands with convex coastlines in the southern sea of the Korean Peninsula. There are <em>n</em> villages on the coastline in each island. All villages are numbered from 1 to <em>n</em>. These numbers have been randomly assigned to villages regardless of their locations. A sequence of the village numbers in clockwise direction on the coastline of an island is called a coastline sequence. Considering a village as a point, the closed polyline connecting all villages in order of a coastline sequence forms the boundary of a convex polygon.</p>

<p>At a meeting of village representatives from both islands, they decided to construct a road inside each island satisfying the following three conditions.</p>

<ol>
	<li>Each road passes through all villages of each island exactly once.</li>
	<li>Each road is not self-intersecting.</li>
	<li>Two road sequences of both islands are same, where a road sequence is a sequence of the village numbers along the road from the start to the end.</li>
</ol>

<p>For example, suppose that there are six villages in each island and that two coastline sequences of two islands are (1, 5, 2, 4, 6, 3) and (3, 4, 5, 2, 6, 1), respectively. Then two roads with a road sequence (3, 1, 6, 4, 5, 2) satisfy the above conditions. See the figure below. If two coastline sequences are (1, 2, 3, 4, 5) and (1, 3, 5, 2, 4), there is no road sequence which satisfies the above conditions.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/6ebf8803-6fb2-44c3-903d-6ccba47079cd/-/preview/" style="width: 344px; height: 156px;"></p>

<p>Given two coastline sequences of two islands, write a program to find a road sequence satisfying the above conditions if it exists.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing an integer <em>n</em> (5 ≤ <em>n</em> ≤ 100,000), where <em>n</em> is the number of villages in each island. The villages are numbered from 1 to <em>n</em>. In the following two lines, each line contains <em>n</em> integers which represent a coastline sequence of each island.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line. The line should contain <em>n</em> integers which represent a road sequence satisfying above conditions if it exists, otherwise -1. If there are one or more solutions, then print an arbitrary one.</p>

