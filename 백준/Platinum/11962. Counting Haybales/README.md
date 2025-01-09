# [Platinum IV] Counting Haybales - 11962 

[문제 링크](https://www.acmicpc.net/problem/11962) 

### 성능 요약

메모리: 28588 KB, 시간: 156 ms

### 분류

자료 구조, 느리게 갱신되는 세그먼트 트리, 세그먼트 트리

### 제출 일자

2024년 4월 3일 00:14:51

### 문제 설명

<p>Farmer John is trying to hire contractors to help rearrange his farm, but so far all of them have quit when they saw the complicated sequence of instructions FJ wanted them to follow. Left to complete the project by himself, he realizes that indeed, he has made the project perhaps more complicated than necessary. Please help him follow his instructions to complete the farm upgrade.</p>

<p>FJ's farm consists of \(N\) fields in a row, conveniently numbered \(1 \ldots N\). In each field there can be any number of haybales. Farmer John's instructions contain three types of entries:</p>

<p>1) Given a contiguous interval of fields, add a new haybale to each field.</p>

<p>2) Given a contiguous interval of fields, determine the minimum number of haybales in a field within that interval.</p>

<p>3) Given a contiguous interval of fields, count the total number of haybales inside that interval.</p>

### 입력 

 <p>The first line contains two positive integers, \(N\) (\(1 \leq N \leq 200,000\)) and \(Q\) (\(1 \leq Q \leq 100,000\)).</p>

<p>The next line contains \(N\) nonnegative integers, each at most 100,000, indicating how many haybales are initially in each field.</p>

<p>Each of the next \(Q\) lines contains a single uppercase letter, either M, P or S, followed by either two positive integers \(A\) and \(B\) (\(1 \leq A \leq B \leq N\)), or three positive integers \(A\), \(B\), and \(C\) (\(1 \leq A \leq B \leq N\); \(1 \leq C \leq 100,000\)). There will be three positive integers if and only if the uppercase letter is P.</p>

<p>If the letter is M, print the minimum number of haybales in the interval of fields from \(A \ldots B\).</p>

<p>If the letter is P, put \(C\) new haybales in each field in the interval of fields from \(A \ldots B\).</p>

<p>If the letter is S, print the total number of haybales found within interval of fields from \(A \ldots B\).</p>

### 출력 

 <p>A line in the output should appear in response to every 'M' or 'S' entry in FJ's instructions.</p>

