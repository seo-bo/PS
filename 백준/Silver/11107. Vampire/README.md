# [Silver II] Vampire - 11107 

[문제 링크](https://www.acmicpc.net/problem/11107) 

### 성능 요약

메모리: 2216 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍, 수학, 확률론

### 제출 일자

2025년 4월 1일 11:40:02

### 문제 설명

<p>Vampire is a popular roleplaying game. As most roleplaying games, Vampire uses dice to determine random events. The most common use of the dice is to determine if you succeed or fail at a specific task. A task might be shooting another player, avoid falling out of a window, dodge a hit from an opponent etc.</p>

<p>The dice used in Vampire is 10-sided and the rules are as follows: You are allowed to roll x dice and you need y or more points to succeed. If a dice shows 8, 9 or 10 you get one point. This means that 1 through 7 gives no points. In addition, if you are lucky enough to roll a 10 you get one extra dice roll. This means that it is possible to get 2 or even more points even if you started out with only one dice.</p>

<p>An example: Truls tries to avoid falling into a trap. To see if she succeeds she has to roll 4 or more successes on 5 dice. The first roll gives her two 10s, one 4, one 6 and one 3. This means she only got two successes, but because she got two 10s she gets to roll two more dice. This time she rolls another 10 and a 2. She now has three successes and one more dice roll. The last roll lands on 5 and Truls falls into a big pit and dies.</p>

<p>But how big was Truls’ chance of avoding death in the first place? Truls asks you to device a program that for a given number of dice and a point requirement tells her her chance of surviving.</p>

### 입력 

 <p>The first line gives 1 ≤ n ≤ 100, the number of cases. Then follow two numbers x and y on each line, where 0 ≤ x ≤ 100 is the number of dice and 0 ≤ y ≤ 100 is the number of points needed to succeed.</p>

### 출력 

 <p>The output should consist of one line per case with the chance that the rolls succeed. It should be rounded to three decimal places.</p>

