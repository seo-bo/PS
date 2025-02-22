# [Gold II] Post Office - 5504 

[문제 링크](https://www.acmicpc.net/problem/5504) 

### 성능 요약

메모리: 2616 KB, 시간: 8 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2025년 2월 22일 18:13:52

### 문제 설명

<p>There is a straight highway with villages alongside the highway. The highway is represented as an integer axis, and the position of each village is identified with a single integer coordinate. There are no two villages in the same position. The distance between two positions is the absolute value of the difference of their integer coordinates.</p>

<p>Post offices will be built in some, but not necessarily all of the villages. A village and the post office in it have the same position. For building the post offices, their positions should be chosen so that the total sum of all distances between each village and its nearest post office is minimum.</p>

<p>You are to write a program which, given the positions of the villages and the number of post offices, computes the least possible sum of all distances between each village and its nearest post office, and the respective desired positions of the post offices.</p>

### 입력 

 <p>The first line contains two integers: the first is the number of villages V, 1 ≤ V ≤ 300, and the second is the number of post offices P, 1 ≤ P ≤ 30, P ≤ V. The second line contains V integers in increasing order. These V integers are the positions of the villages. For each position X it holds that 1 ≤ X ≤ 10000.</p>

### 출력 

 <p>The first line contains one integer S, which is the sum of all distances between each village and its nearest post office as reported in the second line. The second line contains P integers in increasing order. These integers are the locations of the distinct villages in which the post offices will be built. There may be several different solutions for the locations, and your program needs to output only one of them.</p>

