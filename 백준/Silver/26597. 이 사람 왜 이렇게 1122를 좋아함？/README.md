# [Silver II] 이 사람 왜 이렇게 1122를 좋아함? - 26597 

[문제 링크](https://www.acmicpc.net/problem/26597) 

### 성능 요약

메모리: 2020 KB, 시간: 24 ms

### 분류

구현

### 제출 일자

2024년 10월 7일 18:39:59

### 문제 설명

<p>ZOAC 5 대회 개최를 위해 준성이가 만든 문제를 검수하던 준호는 문뜩 그런 생각이 들었다.</p>

<blockquote>
<p><em>'이 사람 왜 이렇게 1122를 좋아함?'</em></p>
</blockquote>

<p><strong>하지만 사실 준성이의 최애 수는 1122가 아니다!!!</strong></p>

<p>준성이의 최애 수에 대해 알려진 사실은 구간 $\left[-10^{18}, 10^{18}\right]$에 있는 정수 중 하나라는 것뿐이다.</p>

<p>아무래도 이 사실을 믿을 수 없는 준호는 준성이에게 최애 수가 뭔지에 대해서 질문을 하려고 한다. 질의응답은 다음과 같이 이루어진다.</p>

<ol>
	<li>준호가 구간 $\left[-10^{18}, 10^{18}\right]$에 있는 정수를 하나 제시한다.</li>
	<li>준성이는 최애 수가 제시한 수보다 크다면 up, 작다면 down을 외친다.</li>
	<li>준호가 제시한 수가 최애 수와 똑같은 경우는 <strong>절대 </strong>일어나지 않는다.</li>
</ol>

<p>준호와 준성이의 검수는 아직 끝나지 않았기 때문에, 질의응답은 $Q$번만 하고 마저 검수를 하러 갔다.</p>

<p>대회가 시작된 지금 준호는 참가자들의 질문을 받느라 정신이 없다! 바쁜 준호를 위해 질의응답 내용을 확인하여 준성이의 최애 수를 대신 알아보도록 하자!</p>

### 입력 

 <p>첫째 줄에 질의응답을 진행한 횟수 $Q$가 주어진다. $\left(1 \leq Q \leq 111\,222\right)$</p>

<p>다음 $Q$ 개의 줄에 걸쳐서 질의응답에 대한 정보가 <code>x ^</code>또는 <code>x v</code>와 같은 형태로 한 줄에 하나씩 순서대로 주어진다. $\left(-10^{18} \leq x \leq 10^{18}\right)$</p>

<p><code>x ^</code>은 준성이의 최애 수가 $x$보다 크다는 것을 의미하고, <code>x v</code>는 준성이의 최애 수가 $x$보다 작다는 것을 의미한다.</p>

<p>주어지는 수는 모두 정수다.</p>

### 출력 

 <p>질의응답에 모순된 내용이 있다면 첫째 줄에 <code>Paradox!</code>를 출력하고, 둘째 줄에 처음으로 모순이 발견된 질의응답이 몇 번째인지 출력한다.</p>

<p>준성이의 최애 수가 무엇인지 정확히 알아낼 수 있다면 첫째 줄에 <code>I got it!</code>을 출력하고, 둘째 줄에 처음으로 정확히 알아낼 수 있었던 질의응답이 몇 번째인지 출력한다.</p>

<p>정확히 알아낼 수 없다면 첫째 줄에 <code>Hmm...</code>을 출력한다.</p>

