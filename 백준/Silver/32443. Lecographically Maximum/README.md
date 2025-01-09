# [Silver IV] Lecographically Maximum - 32443 

[문제 링크](https://www.acmicpc.net/problem/32443) 

### 성능 요약

메모리: 3196 KB, 시간: 32 ms

### 분류

비트마스킹, 그리디 알고리즘

### 제출 일자

2024년 10월 7일 00:52:16

### 문제 설명

<p>A list of $N$ integers $a_1, \dots , a_N$ is stored in the memory of an electronic device. This device has a very peculiar operation available: bit swapping between numbers. More precisely, given integers $i$, $j$ and $k$, this operation swaps the $k$-th bit of the integer $a_i$ with the $k$-th bit of the integer $a_j$ (and vice-versa).</p>

<p>Very interesting phenomena can occur when performing this operation one or more times, such as obtaining numbers that did not even belong to the original list, or even numbers larger or smaller than all the original elements.</p>

<p>For this problem, we are interested in using the operation as many times as necessary to change the list of numbers so that the resulting list is the lexicographically maximum, that is, that $a_1$ is the largest possible, that $a_2$ is the largest possible among the possible solutions that maximize $a_1$, and so on.</p>

### 입력 

 <p>The first line of input contains an integer $N$ ($1 ≤ N ≤ 10^5$) and the second line contains $N$ integers, separated by spaces, corresponding to the list $a_1, \dots , a_N$ ($0 ≤ a_i ≤ 10^9$).</p>

### 출력 

 <p>Your program should print a single line containing $N$ space-separated integers corresponding to the lexicographically maximum obtainable sequence.</p>

