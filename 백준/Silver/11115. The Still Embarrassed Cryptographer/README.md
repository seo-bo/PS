# [Silver I] The Still Embarrassed Cryptographer - 11115 

[문제 링크](https://www.acmicpc.net/problem/11115) 

### 성능 요약

메모리: 2092 KB, 시간: 4 ms

### 분류

그래프 이론, 그래프 탐색, 수학, 정수론, 문자열

### 제출 일자

2025년 4월 1일 10:59:57

### 문제 설명

<p>The not so young any more, but still very promising cryptographer Børge is implementing a new security module for his company. There were a lot of problems with the old module last time Børge was on holiday, as nobody could understand his code. So his boss have ordered him to keep this new module much simpler.</p>

<p>In this system the secret encryption key is an injective function c from the alphabet onto itself, such that for a string S = s<sub>1</sub> . . . s<sub>m</sub>, we have crypt(S) = c(s<sub>1</sub>). . . c(s<sub>m</sub>). The secret decryption key c<sup>−1</sup> has the property c<sup>−1</sup>(c(s)) = s, and is used in the decryption crypt<sup>−1</sup>(T) = c<sup>−1</sup>(t<sub>1</sub>). . . c<sup>−1</sup>(t<sub>m</sub>). Børge’s functions crypt() and crypt<sup>−1</sup>() send each symbol with a Remote Procedure Call to where the secret keys are stored, deep inside a mountain.</p>

<p>A problem is that crypt<sup>q</sup>(crypt(S)) = S for some q, and the eager cracker can just keep on applying crypt() on the encrypted message until he gets a readable message. To make the system totally safe, Børge wants to make crypt() throw a <code>SecurityExceptionInAmundsCodeReally</code> if q is a small number. Help Børge implement this function.</p>

### 입력 

 <p>The first line of input gives 1 ≤ n ≤ 100, the number of test cases. Each test case consists of two lines, containing original string S and the encrypted string T respectively, such that crypt(S) = T. You have 1 ≤ |S| = |T| ≤ 1000. The strings are from the alphabet “A”. . . “Z”. The encryption function c is different in each test case.</p>

### 출력 

 <p>For each test case, output a line with the number q, or “mjau”, if this cannot be decided just from S and T.</p>

