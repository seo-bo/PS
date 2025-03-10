# [Gold II] 용액 2 - 32178 

[문제 링크](https://www.acmicpc.net/problem/32178) 

### 성능 요약

메모리: 25468 KB, 시간: 244 ms

### 분류

그리디 알고리즘, 누적 합, 정렬

### 제출 일자

2024년 8월 31일 15:45:42

### 문제 설명

<p>중앙대학교에 숨겨진 화학연구소에는 산성과 염기성을 띠는 용액 $N$개가 일렬로 나열되어 있다. 푸앙이는 용액의 특성값이 $0$보다 크면 산성, $0$보다 작으면 염기성이라 생각한다. 또한 특성값의 절댓값이 작을수록 중성에 가깝다고 생각한다. $i$번 용액의 특성값은 $s_i$이다.</p>

<p>특성값이 $a$, $b$인 두 용액을 섞으면 화학 반응에 의해 특성값이 $a + b$인 용액이 된다고 한다. 푸앙이는 나열된 $N$개의 용액 중 연속적인 구간의 용액들을 섞어 중성에 가까운 용액을 만들고자 한다. 푸앙이가 만들 수 있는 가장 중성에 가까운 용액의 특성값과 그 용액을 만드는 방법을 구해보자.</p>

### 입력 

 <p>첫 번째 줄에 양의 정수 $N$이 주어진다.</p>

<p>두 번째 줄에 정수 $s_1$, $s_2$, $s_3$, $\cdots$, $s_N$이 공백으로 구분되어 주어진다.</p>

### 출력 

 <p>첫 번째 줄에 푸앙이가 만들 수 있는 가장 중성에 가까운 용액의 특성값을 출력한다.</p>

<p>두 번째 줄에 양의 정수 $L$, $R$을 공백으로 구분하여 출력한다. $L$번부터 $R$번까지의 용액을 섞었다는 뜻이다.</p>

<p>가능한 경우가 여러 가지라면 그중 아무거나 하나를 출력한다.</p>

