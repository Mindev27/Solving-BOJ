# [Gold I] Moving Furniture - 16339 

[문제 링크](https://www.acmicpc.net/problem/16339) 

### 성능 요약

메모리: 2684 KB, 시간: 364 ms

### 분류

그리디 알고리즘

### 제출 일자

2024년 5월 14일 10:45:43

### 문제 설명

<p>Binary Casino had been open nonstop for a long period of time. It desperately needed renovation as the substantial damage to its carpet and furniture did not look good. While renovation took place, four-legged game tables from all game rooms were deposited in a storage room.</p>

<p>Your task is not difficult. You were asked by your boss to move the game tables to the exactly same place where they were positioned before. Each game table desk is a square and the table legs are located exactly under the corners of the desk. A good thing is that there are small hollows made by the table legs in the carpet at places where the game tables were standing before renovation and you know how many tables were in the room. Another good thing is that your boss does not remember where exactly were the tables placed. The bad thing is that your boss knows the total area of all game tables in the room and insists on the number being preserved.</p>

<p>You have to use every hollow in the carpet to place the game tables, placing one table leg into each hole. The tables cannot overlap.</p>

### 입력 

 <p>The first line of input contains an integer N (1 ≤ N ≤ 3 · 10<sup>3</sup>), the number of game tables. After that 4N lines follow, each containing two integers X and Y (−10<sup>9</sup> ≤ X, Y < 10<sup>9</sup>) which represent coordinates of a hollow in the carpet. The hollows are listed in an arbitrary order and no two hollows may have the same coordinates.</p>

### 출력 

 <p>Output a single number – the sum of areas of all game tables in the room. The output will be considered correct if it differs by at most 10<sup>−3</sup> from the correct answer.</p>

