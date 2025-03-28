# [Silver II] 수학 선생님의 고민(Hard) - 28242 

[문제 링크](https://www.acmicpc.net/problem/28242) 

### 성능 요약

메모리: 1128 KB, 시간: 0 ms

### 분류

브루트포스 알고리즘, 수학

### 제출 일자

2024년 2월 18일 04:23:45

### 문제 설명

<p><strong>이 문제는 수학 선생님의 고민(Easy)의 상위 문제이고, 수학 선생님의 고민(Easy)에 이 문제의 정답 코드를 제출하여 맞힐 수 있다.</strong></p>

<p>차형준 선생님은 여느 때와 같이 재밌는 문제를 고민하다가 다음과 같이 양의 정수 $n$에 대한 이차식 $n x^2 + (n+1) x - (n+2)$을 정수 범위에서 인수분해 하는 문제를 고안하게 되었다.</p>

<p>$n$이 작을 때에는 쉽게 손으로 계산할 수 있었지만, $n$이 커짐에 따라 문제는 버거워졌다.</p>

<p>따라서 선생님은 수학은 잘 못해도 시키는 대로 코딩은 하는 도훈이에게 문제를 맡겼다. 하지만 도훈이는 사실 ChatGPT가 알려준 코드를 복사-붙여넣기 해왔을 뿐이라 실상은 "Hello World!" 정도나 출력할 줄 안다. 그래서 도훈이는 늘 하던 대로 ChatGPT에게 코딩을 부탁했다.</p>

<p>하지만 답변 받는 도중 인터넷이 끊겨버렸다..!</p>

<p style="text-align: center;"><img alt="" height="193" src="" width="516"></p>

<p style="text-align: center;">ChatGPT에게 프로그램을 만들어달라고 하다가 인터넷이 끊긴 모습이다.</p>

<p>도훈이를 도와 $n x^2 + (n+1) x - (n+2)$를 정수 범위에서 인수분해 하는 프로그램을 작성하여라.</p>

### 입력 

 <p>첫 번째 줄에 양의 정수 $n$이 주어진다.</p>

### 출력 

 <p>첫 번째 줄에 주어진 $n$에 대해 이차식 $n x^2 + (n+1) x - (n+2)$가 정수 범위에서 인수분해가 불가능하다면 <code><span style="color:#e74c3c;">-1</span></code>을 출력하고, 가능하다면 인수분해 한 결과를 나타내는 네 정수 $a$, $b$, $c$, $d$를 공백으로 구분하여 출력한다. 이 네 정수는 $(ax+b)(cx+d)=n x^2 + (n+1) x - (n+2)$임을 의미한다. 가능한 $(a,b,c,d)$ 쌍이 여러 가지라면 그중 아무것이나 출력한다.</p>

