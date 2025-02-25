# [Gold V] For the Peace - 13808 

[문제 링크](https://www.acmicpc.net/problem/13808) 

### 성능 요약

메모리: 2156 KB, 시간: 92 ms

### 분류

자료 구조, 그리디 알고리즘, 구현, 시뮬레이션, 스택

### 제출 일자

2025년 2월 18일 22:52:03

### 문제 설명

<p>This is a story of a world somewhere far from the earth. In this world, the land is parted into a number of countries ruled by empires. This world is not very peaceful: they have been involved in army race.</p>

<p>They are competing in production of missiles in particular. Nevertheless, no countries have started wars for years. Actually they have a reason they can’t get into wars — they have missiles much more than enough to destroy the entire world. Once a war would begin among countries, none of them could remain.</p>

<p>These missiles have given nothing but scare to people. The competition has caused big financial and psychological pressure to countries. People have been tired. Military have been tired. Even empires have been tired. No one wishes to keep on missile production.</p>

<p>So empires and diplomats of all countries held meetings quite a few times toward renouncement of missiles and abandon of further production. The meetings were quite difficult as they have different matters. However, they overcame such difficulties and finally came to the agreement of a treaty. The points include:</p>

<ul>
	<li>Each country will dispose all the missiles of their possession by a certain date.</li>
	<li>The war potential should not be different by greater than a certain amount d among all countries.</li>
</ul>

<p>Let us describe more details on the second point. Each missile has its capability, which represents how much it can destroy the target. The war potential of each country is measured simply by the sum of capability over missiles possessed by that country. The treaty requires the difference to be not greater than d between the maximum and minimum potential of all the countries.</p>

<p>Unfortunately, it is not clear whether this treaty is feasible. Every country is going to dispose their missiles only in the order of time they were produced, from the oldest to the newest. Some missiles have huge capability, and disposal of them may cause unbalance in potential.</p>

<p>Your task is to write a program to see this feasibility.</p>

### 입력 

 <p>The input is a sequence of datasets. Each dataset is given in the following format: </p>

<pre>n d 
m<sub>1</sub> c<sub>1,1</sub> .. . c<sub>1,m1 </sub>
.. . 
m<sub>n</sub> c<sub>n,1</sub> .. . c<sub>n,mn</sub></pre>

<p>The first line contains two positive integers n and d, the number of countries and the tolerated difference of potential (n ≤ 100, d ≤ 1000). Then n lines follow. The i-th line begins with a non-negative integer mi , the number of the missiles possessed by the i-th country. It is followed by a sequence of mi positive integers. The j-th integer ci,j represents the capability of the j-th newest missile of the i-th country (c<sub>i,j</sub> ≤ 1000). These integers are separated by a single space. Note that the country disposes their missiles in the reverse order of the given sequence.</p>

<p>The number of missiles is not greater than 10000. Also, you may assume the difference between the maximum and minimum potential does not exceed d in any dataset.</p>

<p>The input is terminated by a line with two zeros. This line should not be processed.</p>

### 출력 

 <p>For each dataset, print a single line. If they can dispose all their missiles according to the treaty, print “Yes” (without quotes). Otherwise, print “No”.</p>

<p>Note that the judge is performed in a case-sensitive manner. No extra space or character is allowed.</p>

