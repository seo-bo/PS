# [Silver II] 트리 긋기 - 29757 

[문제 링크](https://www.acmicpc.net/problem/29757) 

### 성능 요약

메모리: 2156 KB, 시간: 0 ms

### 분류

애드 혹, 정렬

### 제출 일자

2024년 5월 31일 16:30:57

### 문제 설명

<p>$2$차원 평면 위에 $N$개의 점이 주어진다. 선분 $N - 1$개를 그어 트리를 만드시오. 단, 그은 선분 중 어떠한 두 선분도 서로 교차하면 안 된다.</p>

<p>어떤 선분의 끝점이 다른 선분 위에 있는 것은 교차하는 경우이다. 두 선분이 끝점에서 만나는 것은 교차하는 경우가 아니다.</p>

### 입력 

 <p>첫 번째 줄에 점의 개수 $N$이 주어진다. $(2 \le N \le 1\,000)$</p>

<p>두 번째 줄부터 $N$개의 줄에 걸쳐 점의 좌표가 주어진다. 그중 $i$번째 줄에는 $i$번 점의 좌표 정수 $x_i$, $y_i$가 공백으로 구분되어 주어진다. $(-10^9 \le x_i, y_i \le 10^9)$</p>

<p>주어지는 모든 점의 좌표는 서로 다르다.</p>

### 출력 

 <p>$N - 1$개의 줄에 걸쳐 트리를 구성하는 선분을 출력한다. 각 줄에는 선분을 이루는 두 점의 번호를 공백으로 구분하여 출력한다.</p>

<p>트리를 긋는 방법이 여럿인 경우는 그중 아무거나 하나를 출력한다.</p>

