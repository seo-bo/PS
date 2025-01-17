# [Gold I] 레벨 디자인 - 33012 

[문제 링크](https://www.acmicpc.net/problem/33012) 

### 성능 요약

메모리: 7380 KB, 시간: 16 ms

### 분류

애드 혹, 해 구성하기

### 제출 일자

2024년 12월 29일 19:21:03

### 문제 설명

<p>$0$번부터 $N+1$번까지 번호가 붙은 $N+2$개의 레벨이 있다. 각 레벨은 $0, 1, 2, \cdots, N, N+1$번 순서대로 배치되어 있고, 플레이어는 $0$번 레벨에서 시작해 $N+1$번 레벨까지 순서대로 진행한다. 이전에 방문했던 레벨로 돌아가거나, 어떤 레벨을 건너뛰는 것은 불가능하다.</p>

<p>$0$번 방과 $N+1$번 방을 제외한 나머지 $N$개의 방에는 점수를 올려주는 아이템이 하나씩 놓여 있다. 플레이어가 $i$번 방에 놓여있는 아이템을 획득할 경우에는 $i$ 만큼의 점수를 얻을 수 있다. 플레이어는 각 레벨에서 아이템을 들고 갈지 여부를 자유롭게 정할 수 있으나, <strong>연속한 두 개의 레벨에서 모두 아이템을 들고 가는 것은 불가능</strong>하다.</p>

<p>병윤이는 플레이어가 얻을 수 있는 <strong>최대 점수가 최소화되도록</strong> 아이템을 재배치하고자 한다. 이때, 재배치가 만족해야 하는 조건들은 다음과 같다.</p>

<ul>
	<li>$1, 2, \cdots, N$번 방에 아이템이 정확히 하나씩 있어야 한다.</li>
	<li>재배치한 이후 $i$번 방에 놓여있는 아이템이 올려주는 점수를 $S_i$라 하자. $S_1, S_2, \cdots, S_N$은 $1$부터 $N$까지의 수가 정확히 한 번씩 등장하는 순열이어야 한다.</li>
</ul>

<p>위 조건을 만족하는 아이템 배치를 아무거나 하나 구하고, 해당 배치에서 플레이어가 얻을 수 있는 최대 점수를 구해보자.</p>

### 입력 

 <p>첫째 줄에 정수 $N$이 주어진다. $(1 \le N \le 200\ 000)$</p>

### 출력 

 <p>첫째 줄에는 $S_1, S_2, \cdots, S_N$을 공백으로 구분하여 출력한다.</p>

<p>둘째 줄에는 해당 레벨 배치에서 플레이어가 얻을 수 있는 최대 점수를 출력한다.</p>

<p>조건을 만족하는 배치가 여러 가지라면 어떤 것을 출력해도 정답으로 인정된다.</p>

