# [Platinum IV] Fox and Card Game - 12885 

[문제 링크](https://www.acmicpc.net/problem/12885) 

### 성능 요약

메모리: 2160 KB, 시간: 0 ms

### 분류

애드 혹, 게임 이론, 그리디 알고리즘

### 제출 일자

2025년 5월 1일 18:04:15

### 문제 설명

<p>여우 Ciel은 그녀의 친구, Jiro와 함께 카드게임을 하고 있다. 책상 위에는 총 n개의 카드 묶음이 있으며, 각 카드에는 양의 정수가 하나씩 쓰여 있다.</p>

<p>각 플레이어는 번갈아 턴을 갖게 된다. Ciel의 턴에는 Ciel이 하나의 카드 묶음을 골라 가장 위에 있는 카드를 한 장 가진다. 반대로, Jiro의 턴에는 Jiro가 하나의 카드 묶음을 골라 가장 밑에 있는 카드를 한 장 가진다. 이렇게 번갈아 카드를 한 장씩 가져가다가, 책상 위에 더 이상 카드가 남지 않으면 게임은 종료된다.</p>

<p>게임이 종료되었을 때, 각 플레이어의 점수는 그 플레이어가 가져간 카드에 적힌 자연수들의 합이 된다. (만약 한 장의 카드도 가져가지 못한 플레이어가 있다면, 그 플레이어의 점수는 0이다.)두 플레이어는 모두 점수를 최대한 많이 얻고 싶어한다. 두 플레이어 모두 최적의 전략으로 카드를 가져올 때, Ciel과 Jiro가 받게 되는 점수는 각각 얼마일까?</p>

### 입력 

 <p>첫 번째 줄에는 카드 묶음의 개수 n (1 ≤ n ≤ 100)이 입력으로 주어진다.</p>

<p>다음 n개의 줄에는 각각 자연수 s<sub>i</sub>와, s<sub>i</sub>개의 자연수 c<sub>ij</sub>가 주어진다. (1 ≤ s<sub>i</sub> ≤ 100; 1 ≤ c<sub>ij </sub>≤ 1000) 이는 i번째 카드 묶음에 카드가 총 s<sub>i</sub>장 있으며, 그 순서가 입력으로 주어진 순서와 같다는 것이다. 처음 주어진 자연수가 카드 묶음의 맨 위에, 마지막에 주어진 자연수가 맨 아래 있는 카드이다.</p>

### 출력 

 <p>두 플레이어가 최적의 플레이를 했을 때, 게임이 끝난 후 Ciel과 Jiro의 점수를 출력한다.</p>

