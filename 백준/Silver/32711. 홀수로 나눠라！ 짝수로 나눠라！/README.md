# [Silver III] 홀수로 나눠라! 짝수로 나눠라! - 32711 

[문제 링크](https://www.acmicpc.net/problem/32711) 

### 성능 요약

메모리: 3584 KB, 시간: 20 ms

### 분류

애드 혹

### 제출 일자

2024년 11월 24일 14:46:44

### 문제 설명

<p>양의 정수로 이루어진 길이 $N$의 수열 $A$가 주어졌을 때, 연속된 원소들을 묶어 수열을 한 개 이상의 집합으로 나누어야 한다. 집합을 나눌 때는 <strong>홀수로 나누기 </strong>혹은 <strong>짝수로 나누기</strong> 중 하나의 방법을 선택할 수 있다. 또한, 수열의 모든 원소는 나눈 집합 중 정확히 하나에 속해야 한다.</p>

<ul>
	<li><strong>홀수로 나누기</strong>

	<ul>
		<li>각 집합을 이루는 원소의 합은 홀수여야 한다.</li>
		<li>수열을 홀수 개의 집합으로 나누어야 한다.</li>
	</ul>
	</li>
	<li><strong>짝수로 나누기</strong>
	<ul>
		<li>각 집합을 이루는 원소의 합은 짝수여야 한다.</li>
		<li>수열을 짝수 개의 집합으로 나누어야 한다.</li>
	</ul>
	</li>
</ul>

<p>둘 중 하나의 방법을 선택하여 주어진 수열을 한 개 이상의 집합으로 나눌 수 있는지를 판별해 보자.</p>

### 입력 

 <p>첫째 줄에 수열 $A$의 길이 $N$이 주어진다. $\left(1\leq N\leq 200,000\right)$</p>

<p>둘째 줄에 수열의 원소 $A_i$가 공백으로 구분되어 주어진다. $\left(1\leq A_i\leq 10^9\right)$</p>

### 출력 

 <p>주어진 방법 중 하나를 선택하여 수열을 한 개 이상의 집합으로 나눌 수 있다면 <span style="color:#e74c3c;"><code>1</code></span>, 아니라면 <span style="color:#e74c3c;"><code>0</code></span>을 출력한다.</p>

