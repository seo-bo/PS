# [Gold II] Job Scheduling - 3302 

[문제 링크](https://www.acmicpc.net/problem/3302) 

### 성능 요약

메모리: 9120 KB, 시간: 188 ms

### 분류

그리디 알고리즘, 매개 변수 탐색, 정렬

### 제출 일자

2025년 2월 26일 16:03:20

### 문제 설명

<p>The Central Engineering Organization, International (CEOI) has received M job requests for the next N days. To perform a job requires exactly one day by one machine. CEOI has access to several machines, each of which can perform at most one job per day, so the organization can do at most as many jobs a day as the number of available machines. CEOI aims to work with at most D days of delay, which means that if a client submits a job for processing on day S, then it will be finished no later than on day S+D.</p>

<p>You are to write a program that computes the minimum number of machines that the organization needs to process all jobs with at most D days of delay.</p>

### 입력 

 <p>The first line of the input contains three integers, N (1 ≤ N ≤ 100 000) is the number of days the organization performs jobs, D (0 ≤ D < N) is the maximum number of days permitted for the delay, and M (1 ≤ M ≤ 1 000 000) is the number of job requests. The days are numbered from 1 to N, and the requests are numbered from 1 to M. The second line contains exactly M integers separated by space, the ith number is the day when request i is submitted for processing. No jobs are submitted after day N–D.</p>

### 출력 

 <p>The first line of the output contains one integer, the minimum number of machines that the organization needs to be able to process all jobs with at most D days of delay. The next N lines describe a feasible schedule for processing the requests. The (i+1)th line contains the identifiers of the requests scheduled for day i. Numbers in a line must be separated by space and terminated by 0. If there are multiple solutions, your program should output only one; it does not matter which one.</p>

