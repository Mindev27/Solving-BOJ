# [Diamond IV] Two trees, twelve forests - 32026 

[문제 링크](https://www.acmicpc.net/problem/32026) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

애드 혹, 해 구성하기

### 제출 일자

2024년 7월 29일 10:34:27

### 문제 설명

<p>1번부터 <em>N</em>번까지 <em>N</em>개 정점과 <em>M</em>개 간선으로 이루어진 가중치 있는 무방향 단순 그래프 <em>G</em>에 대해 <strong>숲 점수</strong>를 다음과 같이 정의한다:</p>

<ol>
	<li><em>F</em><sub>1</sub>, <em>F</em><sub>2</sub>, <em>F</em><sub>3</sub>, ⋯, <em>F</em><sub><em>M</em></sub> 각각을 1번부터 <em>N</em>번까지 <em>N</em>개 정점으로 이루어져 있으며 간선이 없는 그래프라 하자.</li>
	<li><em>G</em>의 간선들을 가중치 오름차순으로 <em>e</em><sub>1</sub>, <em>e</em><sub>2</sub>, ⋯, <em>e</em><sub><em>M</em></sub>이라 할 때, <em>i</em> = 1, 2, ⋯, <em>M</em>에 대해 순서대로 다음을 시행한다:
	<ul>
		<li><em>F</em><sub><em>j</em></sub>에 <em>e</em><sub><em>i</em></sub>를 추가했을 때 사이클이 생기지 않는 최소의 양의 정수 <em>j</em>를 찾아 <em>F</em><sub><em>j</em></sub>에 <em>e</em><sub><em>i</em></sub>를 추가한다. 여기서 <em>e</em><sub><em>i</em></sub>를 추가한다는 것은 <em>e</em><sub><em>i</em></sub>의 양 끝 정점의 번호가 <em>u</em><sub><em>i</em></sub>, <em>v</em><sub><em>i</em></sub>일 때 <em>F</em><sub><em>j</em></sub>에 <em>u</em><sub><em>i</em></sub>번 정점과 <em>v</em><sub><em>i</em></sub>번 정점을 잇는 간선을 추가하는 것을 뜻한다.</li>
	</ul>
	</li>
	<li><em>F</em><sub><em>i</em></sub>가 하나 이상의 간선을 가지는 가장 큰 <em>i</em>를 그래프 <em>G</em>의 <strong>숲 점수</strong>라 한다.</li>
</ol>

<p>당신은 양의 정수 <em>k</em>에 대해 숲 점수가 정확히 <em>k</em>이고 정점이 2024개 이하인 그래프 <em>G</em>를 생성하라는 임무를 받았다.</p>

<p>이 문제가 너무 쉬웠던 당신에게는 다음과 같은 추가적인 조건을 만족하는 <em>G</em>를 찾는 것이 더 흥미롭게 느껴졌다.</p>

<ul>
	<li><em>G</em>의 정점의 개수를 <em>N</em>이라 하면, 간선의 개수는 (2<em>N</em> − 2)이다.</li>
	<li><em>G</em>의 간선 중 (<em>N</em> − 1)개는 빨간색, 다른 (<em>N</em> − 1)개는 파란색으로 칠해서 빨간색 간선만 남겼을 때 트리가 되고, 파란색 간선만 남겨도 트리가 되도록 할 수 있다.</li>
</ul>

<p><em>k</em>가 주어질 때, 조건을 만족시키는 <em>G</em>를 구하여 출력해 보자.</p>

### 입력 

 <p>첫 줄에 정수 <em>k</em>가 주어진다. (2 ≤ <em>k</em> ≤ 12)</p>

### 출력 

 <p>첫 줄에 그래프 <em>G</em>의 정점의 개수 <em>N</em>을 출력한다. (2 ≤ <em>N</em> ≤ 2024)</p>

<p>둘째 줄부터 (2<em>N</em> − 2)개의 줄에 걸쳐 <em>i</em>번째 줄에 세 정수 <em>a</em><sub><em>i</em></sub>, <em>b</em><sub><em>i</em></sub>, <em>c</em><sub><em>i</em></sub>를 공백을 사이에 두고 출력한다. (1 ≤ <em>a</em><sub><em>i</em></sub>, <em>b</em><sub><em>i</em></sub> ≤ <em>N</em>; <em>a</em><sub><em>i</em></sub> ≠ <em>b</em><sub><em>i</em></sub>; 1 ≤ <em>c</em><sub><em>i</em></sub> ≤ 10<sup>9</sup>) 이는 <em>a</em><sub><em>i</em></sub>번 정점과 <em>b</em><sub><em>i</em></sub>번 정점을 잇는 가중치 <em>c</em><sub><em>i</em></sub>인 간선이 존재함을 나타낸다.</p>

<p><em>G</em>는 다음 조건들을 충족해야 한다.</p>

<ul>
	<li>모든 간선의 가중치는 서로 다르다. 즉, <em>c</em><sub><em>i</em></sub>끼리는 서로 다르다.</li>
	<li>출력한 첫 (<em>N</em> − 1)개의 간선은 트리를 이룬다. 마찬가지로, 그 뒤에 출력한 (<em>N</em> − 1)개 간선도 트리를 이룬다.</li>
	<li>두 개 이상의 간선으로 직접 연결된 정점 쌍이 존재하지 않는다.</li>
	<li><em>G</em>의 숲 점수는 <em>k</em>이다.</li>
</ul>

