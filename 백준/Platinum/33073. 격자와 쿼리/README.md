# [Platinum III] 격자와 쿼리 - 33073 

[문제 링크](https://www.acmicpc.net/problem/33073) 

### 성능 요약

메모리: 14596 KB, 시간: 84 ms

### 분류

자료 구조, 세그먼트 트리

### 제출 일자

2025년 1월 6일 10:34:58

### 문제 설명

<p>크기 $N \times N$인 격자가 주어진다. 각각의 칸에는 수가 하나씩 써 있으며, 초기 상태에서 모든 칸에 $0$이 쓰여 있다. 다음 쿼리를 처리하라.</p>

<ul>
	<li><span style="color:#e74c3c;"><code>1 i v</code></span>: $i$번째 행의 모든 수를 $v$로 변경한다. $(1 \le i \le N, 1 \le v \le 10^9)$</li>
	<li><span style="color:#e74c3c;"><code>2 i v</code></span>: $i$번째 열의 모든 수를 $v$로 변경한다. $(1 \le i \le N, 1 \le v \le 10^9)$</li>
	<li><span style="color:#e74c3c;"><code>3 i</code></span>: $i$번째 행의 모든 수의 합을 출력한다. $(1 \le i \le N)$</li>
	<li><span style="color:#e74c3c;"><code>4 i</code></span>: $i$번째 열의 모든 수의 합을 출력한다. $(1 \le i \le N)$</li>
</ul>

<p>$1$개 이상의 <span style="color:#e74c3c;"><code>3 i</code></span> 또는 <span style="color:#e74c3c;"><code>4 i</code></span> 쿼리가 존재함이 보장된다.</p>

### 입력 

 <p>첫 번째 줄에 격자의 크기 $N$과 쿼리의 개수 $Q$가 주어진다.</p>

<p>이후 $Q$개의 줄에 걸쳐 각 쿼리가 주어진다.</p>

### 출력 

 <p>각각의 <span style="color:#e74c3c;"><code>3 i</code></span>와 <span style="color:#e74c3c;"><code>4 i</code></span> 쿼리에 대해 해당 행 또는 열의 수의 합을 한 줄에 하나씩 주어진 순서대로 출력한다.</p>

