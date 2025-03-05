# [Gold IV] The Mailbox Manufacturers Problem - 6713 

[문제 링크](https://www.acmicpc.net/problem/6713) 

### 성능 요약

메모리: 2616 KB, 시간: 32 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2025년 3월 5일 20:24:58

### 문제 설명

<p>In the good old days when Swedish children were still allowed to blow up their fingers with fire-crackers, gangs of excited kids would plague certain smaller cities during Easter time, with only one thing in mind: To blow things up. Small boxes were easy to blow up, and thus mailboxes became a popular target. Now, a small mailbox manufacturer is interested in how many fire-crackers his new mailbox prototype can withstand without exploding and has hired you to help him. He will provide you with k (1 ≤ k ≤ 10) identical mailbox prototypes each fitting up to m (1 ≤ m ≤ 100) crackers. However, he is not sure of how many firecrackers he needs to provide you with in order for you to be able to solve his problem, so he asks you. You think for a while and then say, “Well,if I blow up a mailbox I can’t use it again, so if you would provide me with only k = 1 mailboxes, I would have to start testing with 1 cracker, then 2 crackers, and so on until it finally exploded. In the worst case, that is if it does not blow up even when filled with m crackers, I would need 1 + 2 + 3 + … + m = m × (m + 1) ⁄ 2 crackers. If m = 100 that would mean more than 5000 fire-crackers!” “That’s too many,” he replies. “What if I give you more than k = 1 mailboxes? Can you find a strategy that requires less crackers?”</p>

<p>Can you? And what is the minimum number of crackers that you should ask him to provide you with?</p>

<p>You may assume the following:</p>

<ol>
	<li>If a mailbox can withstand x fire-crackers, it can also withstand x − 1 fire-crackers.</li>
	<li>Upon an explosion, a mailbox is either totally destroyed (blown up) or unharmed, which means that it can be reused in another test explosion.</li>
</ol>

<p>Note: If the mailbox can withstand a full load of m fire-crackers, then the manufacturer will of course be satisfied with that answer. But otherwise he is looking for the maximum number of crackers that his mailboxes can withstand.</p>

### 입력 

 <p>The input starts with a single integer N (1 ≤ N ≤ 10) indicating the number of test cases to follow. Each test case is described by a line containing two integers: k and m, separated by a single space.</p>

### 출력 

 <p>For each test case print one line with a single integer indicating the minimum number of fire-crackers that is needed, in the worst case, in order to figure out how many crackers the mailbox prototype can withstand.</p>

