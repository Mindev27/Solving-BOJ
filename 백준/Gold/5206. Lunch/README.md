# [Gold V] Lunch - 5206 

[문제 링크](https://www.acmicpc.net/problem/5206) 

### 성능 요약

메모리: 2032 KB, 시간: 0 ms

### 분류

너비 우선 탐색, 그래프 이론, 그래프 탐색, 구현

### 제출 일자

2025년 1월 9일 21:25:19

### 문제 설명

<p>USC has a bunch of quite yummy lunch options.<sup>2</sup> Sometimes, when you go for lunch, you want to meet your friends, and for that, there are some great meeting spots on campus, such as Tommy Trojan. But you have to carefully plan where you meet, depending on which restaurant you go to, to minimize the total distance you walk.</p>

<p>More precisely, you will be given a map of campus, with certain spots marked as meeting spots, and others as restaurants. In addition, you are given the starting points for yourself and the friends you are having lunch with. If you have selected a meeting point and a restaurant, this means that you and all your friends will be walking from your respective locations to the meeting point, then to the restaurant, and back to your respective starting locations. Naturally, you want to select the pair of meeting point and restaurant which minimizes the sum of walking distances for you and all your friends.</p>

<p><sup>2</sup>If you haven’t done so, check out Parkside Restaurant and Galen Athletic Center.</p>

### 입력 

 <p>The first line contains a number K ≥ 1, which is the number of input data sets in the file. This is followed by K data sets of the following form:</p>

<p>The first line of each data set contains numbers h and w, the height and width of the campus map (1 ≤ h, w ≤ 30). This is followed by h lines of w characters each. Each character is one of the following:</p>

<ul>
	<li>X means that the square is inaccessible (building or fence or such).</li>
	<li>. means that the square is accessible.</li>
	<li>R means that the square contains a restaurant. You cannot walk through a restaurant. But you can enter it from (or leave it to) any unobstructed adjacent square.</li>
	<li>M means that the square is a meeting point. You can walk through meeting points.</li>
	<li>S means that the square is a starting point for you or one of your friends. You can walk through starting points.</li>
</ul>

<p>Notice that you can only move up, down, left, or right on this map, not diagonally.</p>

### 출력 

 <p>For each data set, first output “Data Set x:” on a line by itself, where x is its number. Then, output the total length traveled by you and all your friends together for the best pair of meeting point and restaurant. (You do not need to output the sequence.)</p>

<p>If there is no meeting point, or no restaurant, accessible from all starting points, then output “Impossible” instead of the total length.</p>

