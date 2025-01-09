# [Platinum II] Heating Up - 23774 

[문제 링크](https://www.acmicpc.net/problem/23774) 

### 성능 요약

메모리: 55788 KB, 시간: 1300 ms

### 분류

자료 구조, 연결 리스트, 매개 변수 탐색

### 제출 일자

2024년 3월 29일 01:10:25

### 문제 설명

<p>Jonas just entered his first chilli-eating contest. He is presented with a pizza consisting of $n$ slices, numbered from $1$ to $n$, each containing a selection of chilli peppers. Initially slices $i$ and $i+1$ are adjacent on the plate (where $1 \leq i < n$), and so are slices $1$ and $n$. According to the contest rules only one slice can be consumed at a time, and the slice must be finished in its entirety before a new slice is started. Jonas is allowed to pick any slice to eat first, but after that he is only allowed to eat slices that have at most one remaining adjacent slice.</p>

<p>The spiciness of each slice is measured in Scoville Heat Units (SHU). Jonas has a certain spiciness tolerance, also measured in SHU, which corresponds to the spiciness of the spiciest slice that Jonas can tolerate eating. He has also noticed that, after eating a slice of $k$ SHU, his tolerance immediately increases by $k$.</p>

<p>In order to win the contest, Jonas would like to finish all the slices of his pizza. Help him determine the minimum initial spiciness tolerance necessary to do so while abiding by the contest rules.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with an integer $n$ ($3 \le n \le 5 \cdot 10^{5}$), the number of pizza slices.</li>
	<li>One line with $n$ integers $s_{1}, s_{2}, \ldots, s_{n}$ ($0 \le s_{i} \le 10^{13}$), where $s_i$ is the spiciness of the $i$th slice in SHU.</li>
</ul>

### 출력 

 <p>Output the minimum initial spiciness tolerance in SHU that Jonas needs in order to be able to eat all slices of the pizza.</p>

