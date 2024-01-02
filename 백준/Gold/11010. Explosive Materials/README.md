# [Gold II] Explosive Materials - 11010 

[문제 링크](https://www.acmicpc.net/problem/11010) 

### 성능 요약

메모리: 7956 KB, 시간: 940 ms

### 분류

이분 그래프, 다이나믹 프로그래밍, 그래프 이론, 그래프 탐색, 배낭 문제

### 제출 일자

2023년 7월 4일 00:56:35

### 문제 설명

<p>Erik is going to send samples of n kinds of materials (numbered from 1 to n) to his laboratory for purity analysis. He will put these samples into several packages of the same capacity, and a package has capacity c if it is able to contain c kinds of materials. Some of these materials cannot be put in the same package, since their chemical reactions may cause an explosion. Erik finds that if putting k kinds of materials a1,...,ak in a package will explode, then putting any two of them will also explode. Erik has made a complete list of pairs of materials that will lead to an explosion. He finds that their are m pairs on the list.</p>

<p>Since all possible explosions are caused by two materials, Erik wonders if two packages of the same capacity are su!cient to send these materials to his laboratory safely. If so, what is the minimum capacity of the package?</p>

### 입력 

 <p>The first line contains a positive integer T (T ≤ 20) indicating the number of test cases. The first line of each test case contains two integer n and m (n ≤ 1000, 0 ≤ m ≤ min(n(n-1)/2 , 105432)) where n is the number of kinds of materials and m is the number of pairs on the list. Each of the following m lines contains two integer a and b indicating that material a and material b will cause an explosion if they are put in the same package.</p>

### 출력 

 <p>For each test case, output an integer. If it is impossible to send the materials by two packages, then output -1. Otherwise, output the minimum capacity of the package.</p>

