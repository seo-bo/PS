# [Gold II] Jumbled Letters - 5380 

[문제 링크](https://www.acmicpc.net/problem/5380) 

### 성능 요약

메모리: 10660 KB, 시간: 216 ms

### 분류

비트마스킹, 자료 구조, 해시를 사용한 집합과 맵, 구현, 정렬, 문자열, 집합과 맵

### 제출 일자

2025년 5월 24일 14:40:08

### 문제 설명

<p>In the game of Scrabble you are given a number of tiles with letters on them. The challenge is to create a word using some (or all) of these tiles. Write a program which, with the help of a dictionary, determines the longest word you can make with the given letters. Those of you who know this game may note that we ignore the board upon which the letters are placed, as well as the value of the letters.</p>

### 입력 

 <p>The input file consists of:</p>

<ul>
	<li>one line with an integer n (1 ≤ n ≤ 100 000): the number of words in the dictionary.</li>
	<li>n distinct lines, each with one word consisting of between 2 and 10 lower-case letters.</li>
	<li>one line with an integer c (1 ≤ c ≤ 10 000): the number of test cases.</li>
	<li>c lines, each with a string consisting of between 2 and 10 lower-case letters: the letters you have to make a word with.</li>
</ul>

<p>The words in the dictionary are given in alphabetical order.</p>

### 출력 

 <p>Per test case:</p>

<ul>
	<li>one line with the longest word from the dictionary you can make with the given letters. If there are multiple words, give the first one in alphabetical order. If there are no words you can make, output the word ”IMPOSSIBLE”.</li>
</ul>

