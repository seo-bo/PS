# [Gold III] 타임머신 - 32936 

[문제 링크](https://www.acmicpc.net/problem/32936) 

### 성능 요약

메모리: 16240 KB, 시간: 68 ms

### 분류

너비 우선 탐색, 많은 조건 분기, 그래프 이론, 그래프 탐색, 최단 경로

### 제출 일자

2024년 12월 7일 19:49:34

### 문제 설명

<p>정점이 $N$개, 간선이 $M$개인 방향 그래프가 주어진다. 각 간선을 통해 이동하는데 걸리는 시간은 $1$이다. 또한, $a$번 정점에는 타임머신이 있다. 타임머신을 이용하면 $b$번 정점으로 이동하게 되며, 시간이 $c$만큼 되돌아가게 된다. 타임머신을 이용하는 횟수에는 제한이 없다. 시간 $0$에서 시작해 $1$번 정점에서 $N$번 정점까지 갈 때 도착시간의 최솟값을 구하여라. 단, $N$번 정점에 도착한 이후에도 움직일 수 있다.</p>

### 입력 

 <p>첫째 줄에 $N$, $M$, $a$, $b$, $c$가 공백으로 구분되어 주어진다. $(1 \leq N,M \leq 200\ 000; 1 \leq a,b \leq N; 1 \leq c \leq 10^9)$</p>

<p>둘째 줄에서 $M+1$번째 줄까지 $i+1$번째 줄에 간선을 나타내는 두 정수 $u_i$, $v_i$가 주어진다. 이는 $i$번째 간선이 $u_i$에서 $v_i$로 이동하는 간선임을 의미한다. $(1 \leq u_i, v_i \leq N; u_i \neq v_i)$</p>

### 출력 

 <p>첫째 줄에 도착시간의 최솟값을 출력한다. 만약 $N$번 정점까지 가는것이 불가능하다면 <span style="color:#e74c3c;"><code>x</code></span>, 도착시간을 무한히 작게 만드는것이 가능하다면 <span style="color:#e74c3c;"><code>-inf</code></span>를 출력한다.</p>

