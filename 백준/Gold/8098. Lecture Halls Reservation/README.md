# [Gold V] Lecture Halls Reservation - 8098 

[문제 링크](https://www.acmicpc.net/problem/8098) 

### 성능 요약

메모리: 2224 KB, 시간: 92 ms

### 분류

다이나믹 프로그래밍, 정렬

### 제출 일자

2024년 9월 25일 13:09:57

### 문제 설명

<p>We have a lecture hall at our disposal. Lecturers place orders in which they specify at what time their lecture begins and at what time it ends. We want to make maximal use of the hall. We accept some orders and reject others and our aim is to achieve the longest possible time of lectures in the hall. We assume that at the moment when one lecture ends another can begin.</p>

<p>Write a program that:</p>

<ul>
	<li>reads orders of lecturers from the standard input,</li>
	<li>computes the maximal possible time of lectures,</li>
	<li>writes the result to the standard output.</li>
</ul>

### 입력 

 <p>In the first line of the standard input there is written one positive integer n, (n ≤ 10,000), which is the number of orders.</p>

<p>In each of the following n lines there are written two integers p and k, separated by a single space, 0 ≤ p < k ≤ 30,000. Such a pair of integers represents an order for the hall. The lecture is to begin at time p and end in time k (a lecturer needs the hall in time represented by an open interval).</p>

### 출력 

 <p>In the first line of the standard output there should be written the maximal possible time of lectures.</p>

