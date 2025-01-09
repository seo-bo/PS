# [Silver I] Nothing Everything - 32760 

[문제 링크](https://www.acmicpc.net/problem/32760) 

### 성능 요약

메모리: 2772 KB, 시간: 16 ms

### 분류

애드 혹, 해 구성하기, 그래프 이론

### 제출 일자

2024년 12월 4일 11:13:48

### 문제 설명

<p>정점이 $N$개이고 간선이 $M$개인 무방향 그래프 $G$가 주어진다. 처음에 그래프에는 $1$번 정점이 존재한다. 다음 두 연산을 $N - 1$번 사용해 그래프 $G$를 만들 수 있는지 판별하고, 만들 수 있다면 연산 과정을 순서대로 출력하라.</p>

<ul>
	<li>$i$번째 연산이 <strong>Nothing</strong>이라면, $i+1$번 정점을 추가한다. $i+1$번 정점에는 아무런 간선을 잇지 않는다.</li>
	<li>$i$번째 연산이 <strong>Everything</strong>이라면, $i+1$번 정점을 추가한다. $i+1$번 정점에는 $i$번 이하의 모든 정점과 간선을 잇는다.</li>
</ul>

### 입력 

 <p>첫 번째 줄에 $N$, $M$이 공백으로 구분되어 주어진다.</p>

<p>두 번째 줄부터 $M$개의 줄에 걸쳐 간선의 정보가 주어진다. 그중 $i$번째 줄에는 $a_i$와 $b_i$가 공백으로 구분되어 주어진다. 이는 그래프 $G$에 $a_i$번 정점과 $b_i$번 정점을 잇는 간선이 존재한다는 의미이다. 그래프 $G$에 중복된 간선은 존재하지 않는다.</p>

### 출력 

 <p>만약 두 연산으로 주어진 그래프 $G$를 만들 수 있다면 첫 번째 줄에 길이가 $N - 1$이고 <span style="color:#e74c3c;"><code>N</code></span> 혹은 <span style="color:#e74c3c;"><code>E</code></span>로만 구성된 문자열을 출력한다. 이는 $j$번째 문자가 <span style="color:#e74c3c;"><code>N</code></span>이라면 $j$번째 연산이 <strong>Nothing</strong>임을, $j$번째 문자가 <span style="color:#e74c3c;"><code>E</code></span>라면 $j$번째 연산이 <strong>Everything</strong>임을 의미한다. 가능한 연산 과정이 여러 가지라면 그중 아무거나 하나를 출력한다.</p>

<p>만약 두 연산으로 주어진 그래프 $G$를 만들 수 없다면 <span style="color:#e74c3c;"><code>-1</code></span>을 대신 출력한다.</p>

