# [Diamond V] 수열과 쿼리 10 - 13557 

[문제 링크](https://www.acmicpc.net/problem/13557) 

### 성능 요약

메모리: 15376 KB, 시간: 288 ms

### 분류

자료 구조, 세그먼트 트리

### 제출 일자

2025년 4월 10일 22:43:25

### 문제 설명

<p>길이가 N인 수열 A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>N</sub>이 주어진다. 이때, 다음 쿼리를 수행하는 프로그램을 작성하시오.</p>

<ul>
	<li><code>x1 y1 x2 y2</code>: x1 ≤ i ≤ y1, x2 ≤ j ≤ y2, i ≤ j인 모든 (i, j)에 대해서 A<sub>i</sub> + ... + A<sub>j</sub>의 최댓값을 출력한다. (1 ≤ x1 ≤ x2 ≤ N, 1 ≤ y1 ≤ y2 ≤ N, x1 ≤ y1, x2 ≤ y2)</li>
</ul>

### 입력 

 <p>첫째 줄에 수열의 크기 N (1 ≤ N ≤ 100,000)가 주어진다.</p>

<p>둘째 줄에는 A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>N</sub>이 주어진다. (-100,000 ≤ A<sub>i</sub> ≤ 100,000)</p>

<p>셋째 줄에는 쿼리의 개수 M (1 ≤ M ≤ 100,000)이 주어진다.</p>

<p>넷째 줄부터 M개의 줄에는 쿼리 x1, y1, x2, y2가 한 줄에 하나씩 주어진다.</p>

### 출력 

 <p>각각의 쿼리마다 정답을 한 줄에 하나씩 출력한다.</p>

