# [Gold II] Ingredients - 15414 

[문제 링크](https://www.acmicpc.net/problem/15414) 

### 성능 요약

메모리: 20144 KB, 시간: 1124 ms

### 분류

자료 구조, 다이나믹 프로그래밍, 그래프 이론, 그래프 탐색, 배낭 문제, 위상 정렬, 트리를 사용한 집합과 맵, 방향 비순환 그래프

### 제출 일자

2024년 5월 9일 09:40:27

### 문제 설명

<p style="text-align:center"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/15414/1.png" style="height:158px; width:685px"></p>

<p>The chef of a restaurant aspiring for a Michelin star wants to display a selection of her signature dishes for inspectors. For this, she has allocated a maximum budget B for the cumulated cost, and she wants to maximize the cumulated prestige of the dishes that she is showing to the inspectors.</p>

<p>To measure the prestige of her dishes, the chef maintains a list of recipes, along with their costs and ingredients. For each recipe, a derived dish is obtained from a base dish by adding an ingredient. The recipe mentions two extra pieces of information: the cost of applying the recipe, on top of the cost of the base dish, and the prestige the recipe adds to the prestige of the base dish. The chef measures the prestige by her own units, called “prestige units.”</p>

<p>For example, a recipe list for making pizza looks like:</p>

<ul>
	<li><code>pizza_tomato pizza_base tomato 1 2</code></li>
	<li><code>pizza_classic pizza_tomato cheese 5 5</code></li>
</ul>

<p>Here, <code>pizza_base</code> is an elementary dish, a dish with no associated recipe, a dish so simple that its cost is negligible (set to 0) and its prestige also 0. The chef can obtain the derived dish <code>pizza_tomato</code> by adding the ingredient <code>tomato</code> to the base dish <code>pizza_base</code>, for a cost of 1 euro and a gain of 2 prestige units. A <code>pizza_classic</code> is obtained from a <code>pizza_tomato</code> by adding cheese, for an added cost of 5, and a prestige of 5 added to the prestige of the base dish; this means the total cost of <code>pizza_classic</code> is 6 and its total prestige is 7.</p>

<p>A signature dish selection could for instance include both a <code>pizza_tomato</code> and a <code>pizza_classic</code>. Such a selection would have cumulated total prestige of 9, and cumulated total cost of 7.</p>

<p>Armed with the list of recipes and a budget B, the chef wants to provide a signature dish selection to Michelin inspectors so that the cumulated total prestige of the dishes is maximized, keeping their cumulated total cost at most B.</p>

<p>Important Notes</p>

<ul>
	<li>No dish can appear twice in the signature dish selection.</li>
	<li>Any dish that does not appear as a derived dish in any recipe is considered to be an elementary dish, with cost 0 and prestige 0.</li>
	<li>A dish can appear more than once as a resulting dish in the recipe list; if there is more than one way to obtain a dish, the one yielding the smallest total cost is always chosen; if the total costs are equal, the one yielding the highest total prestige should be chosen.</li>
	<li>The recipes are such that no dish D can be obtained by adding one or more ingredients to D itself.</li>
</ul>

### 입력 

 <ul>
	<li>The first line consists of the budget B, an integer.</li>
	<li>The second line consists of the number N of recipes, an integer.</li>
	<li>Each of the following N lines describes a recipe, as the following elements separated by single spaces: the derived dish name (a string); the base dish name (a string); the added ingredient (a string); the added price (an integer); the added prestige (an integer).</li>
</ul>

<p>Limits</p>

<ul>
	<li>0 ≤ B ≤ 10 000;</li>
	<li>0 ≤ N ≤ 1 000 000;</li>
	<li>there can be at most 10 000 different dishes (elementary or derived);</li>
	<li>costs and prestiges in recipes are between 1 and 10 000 (inclusive);</li>
	<li>strings contain at most 20 ASCII characters (letters, digits, and ’_’ only).</li>
</ul>

### 출력 

 <p>The output should consist of two lines, each with a single integer. On the first line: the maximal cumulated prestige within the budget. On the second line: the minimal cumulated cost corresponding to the maximal cumulated prestige, necessarily less than or equal to the budget.</p>

