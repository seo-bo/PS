# [Gold III] 부등호 퍼즐 - 31854 

[문제 링크](https://www.acmicpc.net/problem/31854) 

### 성능 요약

메모리: 64620 KB, 시간: 380 ms

### 분류

방향 비순환 그래프, 그래프 이론, 위상 정렬

### 제출 일자

2024년 5월 25일 00:16:10

### 문제 설명

<p>부등호 퍼즐은 $1$부터 $N^2$까지의 정수를 모두 이용하여 $N \times N$ 격자판을 채우는 퍼즐이다. 격자 칸 사이에는 부등호가 그려져 있는데, 인접한 두 격자 칸의 정수가 만족해야 하는 대소 관계를 의미한다. 예를 들어, 다음과 같은 $3 \times 3$ 부등호 퍼즐이 주어졌다고 하자.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 400px; height: 400px;"></p>

<p>맨 왼쪽 맨 위에 위치한 격자판을 보자. 가로로 인접한 격자판과 세로로 인접한 격자판 사이에는 부등호가 적혀있다. 이때 다음 그림과 같이 주어진 대소 관계를 만족하면서 격자판에 정수를 채워 넣을 수 있다.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 500px; height: 249px;"></p>

<p>이와 같이 주어진 격자판 간의 대소 관계를 만족하면서 $1$부터 $9$까지의 모든 정수를 이용하여 다음과 같이 퍼즐을 완성할 수 있다.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 400px; height: 400px;"></p>

<p>$N \times N$ 부등호 퍼즐이 주어질 때 퍼즐의 해답을 출력하는 프로그램을 작성하라. 가능한 답이 여러 가지라면 그중 아무거나 하나를 출력한다.</p>

### 입력 

 <p>첫 번째 줄에 $N$이 주어진다.</p>

<p>편의상, $N \times N$ 크기의 격자판을 다음과 같은 행렬 표현으로 서술하자.</p>

<p>$\begin{matrix} A_{1, 1} & A_{1, 2} & A_{1, 3} & \ldots & A_{1, N}\\ A_{2, 1} & A_{2, 2} & A_{2, 3} & \ldots & A_{2, N}\\ A_{3, 1} & A_{3, 2} & A_{3, 3} & \ldots & A_{3, N}\\ \vdots & \vdots & \vdots & \ddots & \vdots \\ A_{N, 1} & A_{N, 2} & A_{N, 3} & \ldots & A_{N, N}\\ \end{matrix}$  </p>

<p>두 번째 줄부터 가로로 인접한 격자 칸이 만족해야 하는 대소 관계를 나타내는 $N \times (N-1)$ 크기의 부등호 행렬 $R$이 주어진다.</p>

<p>$\begin{matrix} R_{1, 1} & R_{1, 2} & R_{1, 3} & \ldots & R_{1, N-1}\\ R_{2, 1} & R_{2, 2} & R_{2, 3} & \ldots & R_{2, N-1}\\ R_{3, 1} & R_{3, 2} & R_{3, 3} & \ldots & R_{3, N-1}\\ \vdots & \vdots & \vdots & \ddots & \vdots \\ R_{N, 1} & R_{N, 2} & R_{N, 3} & \ldots & R_{N, N-1}\\ \end{matrix}$</p>

<p>이때 부등호 행렬의 원소 $R_{r, c}$는 ‘<span style="color:#e74c3c;"><code><</code></span>’이거나 ‘<span style="color:#e74c3c;"><code>></code></span>’이며 각각의 의미는 다음과 같다.</p>

<ul>
	<li>‘<span style="color:#e74c3c;"><code><</code></span>’ 이면 $A_{r, c} < A_{r, c+1}$을 만족해야 한다.</li>
	<li>‘<span style="color:#e74c3c;"><code>></code></span>’ 이면 $A_{r, c} > A_{r, c+1}$을 만족해야 한다.</li>
</ul>

<p>이후에는 세로로 인접한 격자 칸이 만족해야 하는 대소관계를 나타내는 $(N-1) \times N$ 크기의 부등호 행렬 $C$가 주어진다.</p>

<p>$\begin{matrix} C_{1, 1} & C_{1, 2} & C_{1, 3} & \ldots & C_{1, N}\\ C_{2, 1} & C_{2, 2} & C_{2, 3} & \ldots & C_{2, N}\\ C_{3, 1} & C_{3, 2} & C_{3, 3} & \ldots & C_{3, N}\\ \vdots & \vdots & \vdots & \ddots & \vdots \\ C_{N-1, 1} & C_{N-1, 2} & C_{N-1, 3} & \ldots & C_{N-1, N}\\ \end{matrix}$</p>

<p>부등호 행렬의 원소 $C_{r, c}$는 ‘<span style="color:#e74c3c;"><code><</code></span>’이거나 ‘<span style="color:#e74c3c;"><code>></code></span>’이며 각각의 의미는 다음과 같다.</p>

<ul>
	<li>‘<span style="color:#e74c3c;"><code><</code></span>’ 이면 $A_{r, c} < A_{r+1, c}$을 만족해야 한다.</li>
	<li>‘<span style="color:#e74c3c;"><code>></code></span>’ 이면 $A_{r, c} > A_{r+1, c}$을 만족해야 한다.</li>
</ul>

<p>항상 풀이가 존재하는 입력이 주어진다.</p>

### 출력 

 <p>$N$개의 줄에 걸쳐 정수 $N$개를 공백으로 구분하여 출력한다. $i$번째 줄의 $j$번째 수는 $A_{i,j}$에 적혀야 할 정수를 뜻한다.</p>

