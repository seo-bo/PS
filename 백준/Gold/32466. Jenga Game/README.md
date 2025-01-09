# [Gold IV] Jenga Game - 32466 

[문제 링크](https://www.acmicpc.net/problem/32466) 

### 성능 요약

메모리: 2024 KB, 시간: 36 ms

### 분류

게임 이론

### 제출 일자

2024년 11월 3일 19:53:30

### 문제 설명

<p>Yesyes and Nono are playing the Jenga game. Jenga has the following rules:</p>

<p>There is a tower consisting of $n$ layers of blocks. Each layer consists of three long blocks. The blocks in each layer lie parallel to each other. The blocks in two neighboring layers are perpendicular to each other. Some blocks might be missing at the start of the game. Two players make their moves alternately. During one move a player must choose a block and remove it from the tower if it remains stable afterward. The tower is stable if all the following conditions are met:</p>

<ul>
	<li>Each layer contains at least one block.</li>
	<li>If a layer contains exactly one block, it’s the middle one.</li>
	<li>The top layer consists of three blocks.</li>
</ul>

<p style="text-align: center;"><img alt="" src="" style="width: 200px; height: 226px;"></p>

<p>A player who is unable to make any move loses. Given the starting state of the tower, possibly with some blocks already removed, it is always guaranteed that the initial state of the given Jenga tower is stable. Your task is to determine which player will win. Both players always use the best strategy to win against each other. Yesyes plays first. Yesyes and Nono are experts at Jenga, so they don’t make any mistakes while removing a block.</p>

<p>Notice that in this version of Jenga, players do not put the blocks on the top of the tower.</p>

### 입력 

 <p>The first line of input contains the number of test cases $T$.</p>

<p>The first line of input for each test case contains the initial height of the Jenga tower $N$.</p>

<p>Each of the next $N$ lines contains the initial state of each layer as a string of length 3 consisting of <code>0</code>s and <code>1</code>s, starting from the top layer. <code>0</code> means that there is no block at that position and <code>1</code> means there is a block at that position. It is always guaranteed that the initial state of the given Jenga tower is stable.</p>

### 출력 

 <p>Print the winner in one line for each test case.</p>

