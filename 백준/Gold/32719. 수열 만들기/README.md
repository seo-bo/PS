# [Gold II] 수열 만들기 - 32719 

[문제 링크](https://www.acmicpc.net/problem/32719) 

### 성능 요약

메모리: 2156 KB, 시간: 12 ms

### 분류

해 구성하기, 그리디 알고리즘, 수학

### 제출 일자

2024년 11월 29일 10:49:42

### 문제 설명

<p>수열의 길이 $N$이 주어졌을 때, 아래 조건을 만족하는 수열 $A$를 구해보자. 단, 수열의 원소는 $N$보다 작거나 같은 음이 아닌 정수여야 한다.</p>

<p>$A_l + A_{l + 1} + \cdots + A_{r - 1} + A_r$의 값이 $N$의 배수인 구간 $[l, r]$ $\left(1 \leq l \leq r \leq N\right)$의 개수가 정확히 $N$개이다.</p>

### 입력 

 <p>첫째 줄에 수열의 길이 $N$이 주어진다. $\left(1\leq N\leq 200,000\right)$</p>

### 출력 

 <p>조건을 만족하는 수열의 원소를 순서대로 공백으로 구분하여 출력한다. 만약, 조건을 만족하는 수열이 존재하지 않는다면 <span style="color:#e74c3c;"><code>-1</code></span>을 출력한다. 조건을 만족하는 수열이 여러 가지라면 아무거나 출력한다.</p>

