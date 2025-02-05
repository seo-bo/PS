# [Silver I] Stock Market - 5447 

[문제 링크](https://www.acmicpc.net/problem/5447) 

### 성능 요약

메모리: 10016 KB, 시간: 72 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2025년 2월 5일 14:22:29

### 문제 설명

<p>The bankers of PigsBank, Inc. have collected day-to-day data of the daily profits (and losses) of the shares they hold. Based on these numbers they decide to calculate which days would have been the most profitable to buy and sell their shares, so they can compare that with their actual gain.</p>

<p>Your task is to write a program that computes the optimal ‘run’ in the sequence of numbers, the subsequence that maximizes the profit. The subsequence you compute is represented by the indexes of the first and last numbers in the subsequence, where we start counting indexes by 1: PigsBank, Inc. bankers are not C programmers. We are asking for exactly one date to buy and one date to sell shares since otherwise the solution would be simple: keep your shares on dates that the profit is non-negative.</p>

<p>Unfortunately that will not help PigsBank, Inc. to avoid the losses they had in the past. Instead they can use it to show future customers how profitable the market could have been if they had been taking the right decisions.</p>

### 입력 

 <p>The first line of the input contains a single number: the number of test cases to follow. Each test case has the following format:</p>

<ul>
	<li>One line with a single integer N, satisfying 1 ≤ N ≤ 1, 000, 000: the length of the sequence to follow.</li>
	<li>One line with N integers pi, satisfying −1, 000 ≤ pi ≤ 1, 000: the profit (or loss) on date i. The integers are separated by single spaces. At least one of the integers is positive.</li>
</ul>

### 출력 

 <p>For every test case the output contains a single line with two integers i and j, satisfying 1 ≤ i ≤ j ≤ N, such that the sum of the i-th until the j-th integer is maximized, boundaries included. When i and j have different solutions, choose minimal i and minimal j.</p>

