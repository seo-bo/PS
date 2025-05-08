# [Diamond III] Do use segment tree - 22487 

[문제 링크](https://www.acmicpc.net/problem/22487) 

### 성능 요약

메모리: 80976 KB, 시간: 688 ms

### 분류

자료 구조, 트리, 세그먼트 트리, 느리게 갱신되는 세그먼트 트리, Heavy-light 분할, 최대 부분 배열 문제

### 제출 일자

2025년 5월 9일 04:47:59

### 문제 설명

<p>Given a tree with <var>n</var> <var>(1 ≤ n ≤ 200,000)</var> nodes and a list of <var>q</var> <var>(1 ≤ q ≤ 100,000)</var> queries, process the queries in order and output a value for each output query. The given tree is connected and each node on the tree has a weight <var>w<sub>i</sub></var> <var>(-10,000 ≤ w<sub>i</sub> ≤ 10,000)</var>.</p>

<p>Each query consists of a number <var>t<sub>i</sub></var> <var>(t<sub>i</sub> = 1, 2)</var>, which indicates the type of the query , and three numbers <var>a<sub>i</sub></var>, <var>b<sub>i</sub></var> and <var>c<sub>i</sub></var> <var>(1 ≤ a<sub>i</sub>, b<sub>i</sub> ≤ n, -10,000 ≤ c<sub>i</sub> ≤ 10,000)</var>. Depending on the query type, process one of the followings:</p>

<ul>
	<li>
	<p>(<var>t<sub>i</sub> = 1</var>: modification query) Change the weights of all nodes on the shortest path between <var>a<sub>i</sub></var> and <var>b<sub>i</sub></var> (both inclusive) to <var>c<sub>i</sub></var>.</p>
	</li>
	<li>
	<p>(<var>t<sub>i</sub> = 2</var>: output query) First, create a list of weights on the shortest path between <var>a<sub>i</sub></var> and <var>b<sub>i</sub></var> (both inclusive) in order. After that, output the maximum sum of a non-empty continuous subsequence of the weights on the list. <var>c<sub>i</sub></var> is ignored for output queries.</p>
	</li>
</ul>

### 입력 

 <p>The first line contains two integers <var>n</var> and <var>q</var>. On the second line, there are <var>n</var> integers which indicate <var>w<sub>1</sub></var>, <var>w<sub>2</sub></var>, ... , <var>w<sub>n</sub></var>.</p>

<p>Each of the following <var>n - 1</var> lines consists of two integers <var>s<sub>i</sub></var> and <var>e<sub>i</sub></var> <var>(1 ≤ s<sub>i</sub>, e<sub>i</sub> ≤ n)</var>, which means that there is an edge between <var>s<sub>i</sub></var> and <var>e<sub>i</sub></var>.</p>

<p>Finally the following <var>q</var> lines give the list of queries, each of which contains four integers in the format described above. Queries must be processed one by one from top to bottom.</p>

### 출력 

 <p>For each output query, output the maximum sum in one line.</p>

