# [Silver III] 순열 복원 - 32861 

[문제 링크](https://www.acmicpc.net/problem/32861) 

### 성능 요약

메모리: 2220 KB, 시간: 60 ms

### 분류

애드 혹, 구현

### 제출 일자

2024년 12월 5일 14:22:42

### 문제 설명

<p>길이가 $N$인 순열은 $1$부터 $N$까지의 정수가 정확히 한 번씩 등장하는 수열을 의미한다. 예를 들어, $[1]$, $[3,1,4,2,5]$ 등은 순열이지만, $[-1,0,1,3,2]$, $[1,3,5,4]$ 등은 순열이 아니다.</p>

<p>길이가 $N$인 순열 $P$에 대해 <strong>비교 행렬</strong>을 정의하자. 비교 행렬 $A$는 $N\times N$ 크기이며, 각 원소 $A_{ij}$는 $P_i$와 $P_j$의 상대적 크기에 따라 다음과 같이 정해진다.</p>

<ul>
	<li>$P_i>P_j$이면 $A_{ij}=-1$이다.</li>
	<li>$P_i=P_j$이면 $A_{ij}=0$이다.</li>
	<li>$P_i<P_j$이면 $A_{ij}=1$이다.</li>
</ul>

<p>비교 행렬 $A$가 주어질 때, 순열 $P$를 복원하는 프로그램을 작성하시오. 만약 비교 행렬이 $A$와 같은 순열이 존재하지 않는다면 <span style="color:#e74c3c;"><code>-1</code></span>을 출력한다.</p>

### 입력 

 <p>첫째 줄에 정수 $N$이 주어진다. $(1\leq N\leq 1\, 000)$</p>

<p>둘째 줄부터 $N$개의 줄에 걸쳐 비교 행렬 $A$가 주어진다. 그중 $i$번째 줄에는 $A$의 $i$번째 행 $A_{i1},A_{i2},\cdots ,A_{iN}$이 공백으로 구분되어 주어진다. 행렬의 모든 원소는 $-1$, $0$, $1$ 중 하나이다.</p>

### 출력 

 <p>비교 행렬 $A$를 만족하는 순열 $P$가 존재한다면 $P_1,P_2,\cdots ,P_N$을 공백으로 구분하여 차례대로 출력한다. 가능한 순열이 여러 가지라면 아무거나 출력한다.</p>

<p>존재하지 않으면 <span style="color:#e74c3c;"><code>-1</code></span>을 출력한다.</p>

