# [Silver II] 이미지 축소 - 22994 

[문제 링크](https://www.acmicpc.net/problem/22994) 

### 성능 요약

메모리: 3012 KB, 시간: 80 ms

### 분류

브루트포스 알고리즘, 유클리드 호제법, 구현, 수학, 정수론

### 제출 일자

2023년 9월 7일 22:20:51

### 문제 설명

<p>세로 $n$ 픽셀, 가로 $m$ 픽셀로 구성된 직사각형 형태의 이미지가 있다. 정휘는 적당한 자연수 $i, j$를 선택해서 이미지의 세로 길이를 $i$배, 가로 길이를 $j$배 확대해서 세로 $ni$ 픽셀, 가로 $mj$ 픽셀 이미지를 만들었다. 하지만 모종의 이유로 원본 이미지가 삭제되어 여러분들에게 원본 이미지 복원을 요청했다.</p>

<p>확대된 이미지가 주어지면 가능한 원본 이미지 중 가장 작은 원본 이미지를 구해서 출력하라. 이때, 구현의 편의를 위해 각 픽셀의 정보는 알파벳 소문자 (<code>a</code>, <code>b</code>, ... , <code>z</code>; <a href="https://ko.wikipedia.org/wiki/ASCII">아스키 코드</a> 97-122) 로 표현한다.</p>

### 입력 

 <p>첫째 줄에 확대된 이미지의 크기를 나타내는 정수 $ni, mj$가 공백으로 구분되어 주어진다.</p>

<p>둘째 줄부터 $ni$줄에 걸쳐, 각 줄마다 이미지의 각 픽셀 값을 나타내는 $mj$개의 알파벳이 주어진다.</p>

### 출력 

 <p>가능한 원본 이미지 중 넓이가 가장 작은 것을 출력한다.</p>

<p>첫째 줄에 원본 이미지의 세로 길이와 가로 길이를 의미하는 정수 $n, m$을 공백으로 구분해서 출력한다.</p>

<p>둘째 줄부터 $n$줄에 걸쳐, 각 줄마다 원본 이미지를 나타내는 $m$개의 알파벳을 출력한다.</p>

<p>가능한 답안이 여러 가지 있으면 아무거나 출력해도 된다.</p>

