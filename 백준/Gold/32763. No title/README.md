# [Gold V] No title - 32763 

[문제 링크](https://www.acmicpc.net/problem/32763) 

### 성능 요약

메모리: 13808 KB, 시간: 60 ms

### 분류

애드 혹, 사칙연산, 수학, 비둘기집 원리

### 제출 일자

2024년 11월 24일 20:13:34

### 문제 설명

<p>이 문제는 <strong>인터랙티브 </strong>문제이다.</p>

<p>모든 원소의 절댓값이 $1$ 이상 $10$ 이하의 정수인 길이 $N$의 수열 $A_1$, $A_2$, $\cdots$, $A_N$이 있다. 당신은 $A$의 원소들을 모르지만, 인터랙터에게 두 원소의 합 또는 곱의 부호를 질문할 수 있다.</p>

<p>$N$번 이하의 질문을 통해 모든 원소의 부호를 알아내 보자.</p>

### 입력 

 Empty

### 출력 

 <p>당신의 프로그램은 아래의 과정을 통해 표준 입출력으로 인터랙터와 상호작용을 해야 한다. 이 문제의 인터랙터는 비적응적이다.</p>

<p>첫째 줄에 수열의 길이 $N$이 주어진다. $(3 \leq N \leq 1\,000)$</p>

<p>인터랙터에게 다음과 같은 질문을 최대 $N$번 할 수 있다.</p>

<ul>
	<li><span style="color:#e74c3c;"><code>? i op j</code></span>: $op$가 <span style="color:#e74c3c;"><code>+</code></span>라면 $A_i + A_j$, <span style="color:#e74c3c;"><code>*</code></span>라면 $A_i \times A_j$의 부호를 질문한다. $(1 \leq i < j \leq N;$ $op \in \{+, *\})$</li>
</ul>

<p>각 질문은 한 줄에 출력하며, 각 줄의 마지막에 개행 문자를 출력한 뒤 표준 출력 버퍼를 비워야 한다.</p>

<p>각 질문 이후, 결과에 따라 한 줄에 문자 한 개가 주어진다. 계산한 값이 음수라면 <span style="color:#e74c3c;"><code>-</code></span>, $0$이라면 <span style="color:#e74c3c;"><code>0</code></span>, 양수라면 <span style="color:#e74c3c;"><code>+</code></span>가 주어진다.</p>

<p>만약 모든 원소의 부호를 알아냈을 경우, 다음을 한 줄에 공백으로 구분하여 출력한다.</p>

<ul>
	<li><span style="color:#e74c3c;"><code>! </code>$s_1$  $s_2$  $\cdots$  $s_N$</span>: $A_i$가 음수라면 $s_i$는 <span style="color:#e74c3c;"><code>-</code></span>, 양수라면 <span style="color:#e74c3c;"><code>+</code></span>이다.</li>
</ul>

<p>답을 출력한 뒤에는 개행 이후 표준 출력 버퍼를 비우고 프로그램을 즉시 종료해야 한다.</p>

<p>다음과 같은 경우에는 예상하지 못한 채점 결과를 받을 수 있음에 유의한다.</p>

<ul>
	<li>매 질문이나 답을 출력한 뒤 표준 출력 버퍼를 비우지 않았다.</li>
	<li>출력 형식을 어겼다.</li>
	<li>$N$번보다 많은 질문을 했다.</li>
	<li>올바르지 않은 답을 출력했다.</li>
	<li>답을 출력한 이후 프로그램을 즉시 종료하지 않았다.</li>
</ul>

