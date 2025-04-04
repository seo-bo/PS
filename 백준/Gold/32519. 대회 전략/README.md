# [Gold III] 대회 전략 - 32519 

[문제 링크](https://www.acmicpc.net/problem/32519) 

### 성능 요약

메모리: 2736 KB, 시간: 108 ms

### 분류

브루트포스 알고리즘, 다이나믹 프로그래밍, 누적 합, 두 포인터

### 제출 일자

2024년 11월 5일 23:17:02

### 문제 설명

<p>2024년도 국제정보올림피아드 Day 2를 말아먹은 은성이는, 자신의 부족한 실력을 인정하기 싫어서 자신의 대회에서 문제를 푸는 전략을 잘못 세워 제 실력을 발휘하지 못했다는 착각에 빠졌다. 은성이는 앞으로의 대회에서는 전략을 잘 세우기 위해서, 자신의 문제를 푸는데 걸리는 시간을 미리 알고 있을 때의 최적의 전략에 대해 고민해보았다. 하지만 대회 전에 문제를 푸는데 걸리는 시간을 알 수 있는 방법이 없으므로, 결국 은성이는 국제정보올림피아드 이후 한 발짝도 성장하지 못하고 있었다. 그러던 어느 날, 은성이는 2024년도 국제정보올림피아드 Day 2를 다시 치르는 꿈을 꾸었다. 놀랍게도 꿈 속의 은성이는 각 문제의 서브태스크를 해결하는 데 걸리는 시간을 정확하게 알고 있었다. 그래서 은성이는 꿈에서라도 대회를 잘 치르기 위해 점수를 최대화하는 방법을 고안하기로 했다.</p>

<p>대회에는 총 3문제가 출제되었고, 제한 시간은 $T$초이다. $3$개의 문제는 각각 $1$, $2$, $3$의 번호가 붙어 있고, 각 문제는 $1$부터 $N$까지의 번호가 붙어 있는 $N$개의 서브태스크를 가지고 있다. 은성이는 각 $1 \leq i \leq 3$과 $1 \leq j \leq N$에 대하여, $i$번 문제의 $j$번 서브태스크의 배점은 $P_{i, j}$이고 자신은 그 서브태스크를 해결하는 데 $t_{i, j}$초가 걸림을 알고 있다. 이때 놀랍게도 일부 서브태스크는 해결하면 점수가 감점된다. 즉 $P_{i, j}$는 음수일 수도 있다.</p>

<p>은성이는 주어진 $T$초의 대회 시간 동안, 특정 서브태스크를 풀거나 아무 것도 하지 않고 있을 수 있다. 이때, 서브태스크는 위계가 분명하기 때문에, 각 문제의 $j(2 \leq j \leq N)$번 서브태스크를 해결하기 위해서는 해당 문제의 $j-1$번 서브태스크를 해결한 상태여야 한다. 대회의 최종 점수는 해결한 모든 서브태스크의 배점의 합이라고 할 때, 은성이가 대회에서 얻을 수 있는 최대 점수를 구해보자.</p>

### 입력 

 <p>입력의 첫째 줄에 한 문제의 서브태스크의 개수 $N$과 대회 제한 시간 $T$가 공백을 사이에 두고 주어진다.</p>

<p>이어서 세 줄에 걸쳐서 각 문제의 서브태스크의 배점 정보가 주어진다. 각 $1 \leq i \leq 3$에 대하여, $1+i$번째 줄에는 $P_{i, 1}$, $P_{i, 2}$, $\cdots$, $P_{i, N}$이 공백을 사이에 두고 주어진다.</p>

<p>이어서 세 줄에 걸쳐서 각 문제의 서브태스크를 푸는데 걸리는 시간이 주어진다. 각 $1 \leq i \leq 3$에 대하여, $4+i$번째 줄에는 $t_{i, 1}$, $t_{i, 2}$, $\cdots$, $t_{i, N}$이 공백을 사이에 두고 주어진다.</p>

### 출력 

 <p>은성이가 얻을 수 있는 최대 점수를 하나의 정수로 출력한다.</p>

