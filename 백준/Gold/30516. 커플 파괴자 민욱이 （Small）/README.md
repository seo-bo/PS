# [Gold IV] 커플 파괴자 민욱이 (Small) - 30516 

[문제 링크](https://www.acmicpc.net/problem/30516) 

### 성능 요약

메모리: 2428 KB, 시간: 0 ms

### 분류

애드 혹, 해 구성하기

### 제출 일자

2024년 11월 12일 07:57:39

### 문제 설명

<p><strong>Small 버전에서는 가능한 방법 중 아무거나 $1$가지만 출력한다.</strong></p>

<p>'커플 파괴자 민욱이'는 솔로이기 때문에 커플끼리 함께 있는 모습을 보기 싫어한다. 그러한 민욱이가 사람들 $N$명이 일렬로 서 있는 대기 줄 하나를 발견했다. 민욱이는 이 대기 줄을 $M$개의 묶음으로 나눈 뒤, 묶음의 순서를 바꾸어 어떠한 커플끼리도 이웃하지 않게 할 것이다. 단, 같은 묶음에 있는 사람들끼리의 순서를 바꾸거나 거꾸로 뒤집을 수는 없다. 각 묶음의 사람 수는 일정하지 않고 서로 달라도 된다.</p>

<p>$M$이 크다면 묶음의 순서를 바꾸는 민욱이의 머리가 아플 것이기 때문에 $M$이 최소가 되게 하려고 한다. 그리고 민욱이는 $M$이 최소일 때의 가능한 여러 가지 방법 중 아무거나 $1$가지만 구하려고 한다.</p>

### 입력 

 <p>$1$번째 줄에 사람들의 수를 나타내는 정수 $N(1 \le N \le 10^{3})$이 주어진다.</p>

<p>$2$번째 줄에 각 사람의 정보를 나타내는 정수 $a_{1}, a_{2}, a_{3}, \cdots, a_{N}$ $(0 \le a_{i} \le 10^{3})$이 공백으로 구분되어 주어진다. $a_{i}$는 대기 줄의 앞에서부터 $i$번째에 서 있는 사람의 정보를 나타낸다. $a_{i} = 0$이라면 그 사람이 솔로임을, $a_i = a_j$이고 $a_i \ne 0$이라면 두 사람이 커플임을 의미한다. $0$이 아닌 수가 $a_{1}, a_{2}, a_{3}, \cdots, a_{N}$에 존재한다면 그 수는 무조건 두 번 존재한다.</p>

### 출력 

 <p>각 묶음의 번호를 대기 줄의 앞에서부터 $1, 2, 3, \cdots, M$이라고 매길 때, 아래의 형식에 맞춰 가능한 방법을 출력한다.</p>

<p>$1$번째 줄에는 $M$의 최솟값을 출력한다.</p>

<p>$2$번째 줄에는 $1$번 묶음, $2$번 묶음, $3$번 묶음, $\cdots$, $M$번 묶음의 사람 수를 공백으로 구분하여 출력한다.</p>

<p>$3$번째 줄에는 묶음의 순서를 바꿨을 때 대기 줄의 앞에서부터 묶음의 번호를 출력한다.</p>

<p>만약 대기 줄을 몇 묶음으로 나누고 어떻게 배열하더라도 항상 한 커플 이상이 이웃한다면 $1$번째 줄에 $-1$을 출력하고 그다음 줄부터는 아무것도 출력하지 않는다.</p>

