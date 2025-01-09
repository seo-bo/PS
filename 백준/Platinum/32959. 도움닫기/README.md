# [Platinum V] 도움닫기 - 32959 

[문제 링크](https://www.acmicpc.net/problem/32959) 

### 성능 요약

메모리: 166996 KB, 시간: 1132 ms

### 분류

너비 우선 탐색, 그래프 이론, 그래프 탐색

### 제출 일자

2024년 12월 23일 18:48:27

### 문제 설명

<p>세로로 $N$칸, 가로로 $M$칸 크기의 격자가 주어진다. 격자의 각 칸은 빈 칸 혹은 함정이다. 이 격자에서, <strong>점프</strong>는 다음과 같이 도움닫기와 멀리뛰기를 차례로 하는 것으로 이루어진다.</p>

<ol>
	<li>(도움닫기) $1$ 이상의 정수 $x$를 고른 뒤, 현재 칸에서 상하좌우 중 한 방향을 골라 $1$칸만큼 $x$번 이동한다. 이때 이동 중에 함정이 있는 칸으로 가거나 격자 밖으로 나가서는 안 된다.</li>
	<li>(멀리뛰기) 이후 $0$ 이상 $x + 1$ 이하의 정수 $y$를 고른 뒤, 동일 방향으로 $y$칸만큼 뛰어서 이동한다. 이때 도착한 칸에 함정이 있거나 격자 밖으로 나가서는 안 된다.</li>
</ol>

<p>격자의 시작 빈 칸에서 출발해서, 임의의 횟수만큼 점프를 해서 끝 빈 칸에 도착할 수 있는지 판별하라.</p>

### 입력 

 <p>첫 번째 줄에 테스트 케이스의 개수 $T$가 주어진다. ($1 \le T \le 10\,000$)</p>

<p>이후 $T$개의 테스트 케이스가 주어지며, 각 테스트 케이스는 다음과 같은 형태이다.</p>

<p>첫 번째 줄에 정수 $N$, $M$이 차례대로 주어진다. ($1 \le N, M \le 2\,000$)</p>

<p>두 번째 줄부터 $N$개의 줄에 걸쳐 격자의 각 행을 표현하는 길이 $M$의 문자열이 주어진다. 각 문자는 <span style="color:#e74c3c;"><code>.</code></span>, <span style="color:#e74c3c;"><code>#</code></span>, <span style="color:#e74c3c;"><code>S</code></span>, <span style="color:#e74c3c;"><code>E</code></span> 중 하나이고, 다음을 의미한다.</p>

<ul>
	<li><span style="color:#e74c3c;"><code>.</code></span>: 빈 칸</li>
	<li><span style="color:#e74c3c;"><code>#</code></span>: 함정</li>
	<li><span style="color:#e74c3c;"><code>S</code></span>: 시작 빈 칸</li>
	<li><span style="color:#e74c3c;"><code>E</code></span>: 끝 빈 칸</li>
</ul>

<p><span style="color:#e74c3c;"><code>S</code></span>와 <span style="color:#e74c3c;"><code>E</code></span>는 각각의 테스트케이스에서 주어지는 격자마다 정확히 한 개씩 존재한다.</p>

<p>모든 테스트케이스에 대한 $N \times M$의 합은 $4\,000\,000$ 이하이다.</p>

### 출력 

 <p>각 테스트 케이스에 대해, $T$개의 줄에 걸쳐 <span style="color:#e74c3c;"><code>E</code></span>가 적힌 빈칸에 도달할 수 있으면 <span style="color:#e74c3c;"><code>YES</code></span>를, 불가능하다면 <span style="color:#e74c3c;"><code>NO</code></span>를 출력한다.</p>

