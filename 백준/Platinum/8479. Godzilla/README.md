# [Platinum V] Godzilla - 8479 

[문제 링크](https://www.acmicpc.net/problem/8479) 

### 성능 요약

메모리: 42092 KB, 시간: 92 ms

### 분류

그래프 이론, 그리디 알고리즘

### 제출 일자

2024년 11월 9일 15:00:49

### 문제 설명

<p>The evil monster Godzilla has decided to visit Byteburg again. Each day the monster crawls out of the ocean, reaches one of the city's sky-scrapers and eats it together with everyone who lives inside the building. It takes Godzilla a whole day to eat the sky-scraper; afterwards it goes back into the blue. When walking through the city, the monster accidentally destroys with its tail all the sky-scrapers it passes on its way.</p>

<p>Obviously, the citizens of Byteburg find this situation difficult to bear. That is why each night from each sky-scraper one citizen escapes to the countryside.</p>

<p>The sky-scrapers in Byteburg are located at junctions. A every junction there is exactly one sky-scraper. The junctions are connected with bidirectional streets. One of the junctions is located just next to the ocean - it is where Godzilla starts its deadly journey each day. On every journey the monster moves only along streets.</p>

<p>Godzilla noticed that it must hurry up with its feast and choose both the sky-scrapers to eat and the streets on its way really carefully. Of course it cannot choose to eat a sky-scraper that has already been eaten or destroyed on the way. What is the maximum number of people that Godzilla can eat before the city gets totally uninhabited?</p>

### 입력 

 <p>The first line of input contains two integers n and m (1 ≤ n ≤ 100 000, 0 ≤ m ≤ 500 000) that represent the number of junctions and the number of streets respectively. The junctions are numbered 1 through n, the junction number 1 is the one located next to the ocean. The next line contains a sequence of n integers k<sub>i</sub> (0 ≤ k<sub>i</sub> ≤ 100 000) that describe the number of people who live in the sky-scrapers next to the respective junctions. Each of the following m lines contains two integers a<sub>i</sub> and b<sub>i</sub> (1 ≤ a<sub>i</sub>, b<sub>i</sub> ≤ n, a<sub>i</sub> ≠ b<sub>i</sub>) which mean that there is a street connecting the junctions no. a<sub>i</sub> and no. b<sub>i</sub>. Each junction is reachable from the junction number 1.</p>

### 출력 

 <p>Your program should print the number of people eaten by Godzilla provided that it chooses its eating and moving plan optimally.</p>

