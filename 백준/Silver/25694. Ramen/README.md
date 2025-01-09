# [Silver III] Ramen - 25694 

[문제 링크](https://www.acmicpc.net/problem/25694) 

### 성능 요약

메모리: 2020 KB, 시간: 8 ms

### 분류

그리디 알고리즘, 누적 합

### 제출 일자

2024년 6월 23일 17:54:04

### 문제 설명

<p>Grammy likes to eat noodles. She divided a very long strip of noodle into $N$ parts of unit length. Each part $i$ has deliciousness $a_i$. She would like to fold the noodle into one piece of unit length before eating by repeating the following operation several (possibly, zero) times.</p>

<p>Let $n$ be the current length of the noodle. In each operation, Grammy can choose a length $\ell$ such that $2 \ell \leq n$ and $a_i > 0$ for all $i \leq \ell$, and fold the noodle $a_1, a_2, \ldots, a_\ell, a_{\ell + 1}, \ldots, a_{2 \ell}, a_{2 \ell + 1}, \ldots, a_n$ into $a_{\ell + 1} + a_\ell, a_{\ell + 2} + a_{\ell - 1}, \ldots, a_{2 \ell} + a_1, a_{2 \ell + 1}, \ldots, a_n$, where $n$ is the length of the noodle before the operation. After the operation, the length will become $n - \ell$.</p>

<p>Grammy wants to know whether she can fold the noodle to length $1$, can you tell her?</p>

### 입력 

 <p>The first line of input contains a single integer $N$ ($1 \leq N \leq 100\,000$).</p>

<p>The second line contains $N$ integers $a_i$ ($-20\,000 \leq a_i \leq 20\,000$), representing the deliciousness of each part of the noodle.</p>

### 출력 

 <p>If Grammy can fold the noodle to length $1$, output a single line with the word "<code>YES</code>". Otherwise, output a single line with the word "<code>NO</code>".</p>

