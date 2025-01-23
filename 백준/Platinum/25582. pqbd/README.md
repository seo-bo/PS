# [Platinum III] pqbd - 25582 

[문제 링크](https://www.acmicpc.net/problem/25582) 

### 성능 요약

메모리: 12468 KB, 시간: 100 ms

### 분류

매내처, 문자열

### 제출 일자

2025년 1월 23일 15:14:32

### 문제 설명

<p>천재적인 수학적 재능을 타고난 7살 철수의 영어 교육을 위해 철수의 어머니는 알파벳 소문자 모양 장난감 블럭을 구입하였다. 하지만 철수는 영어 공부보단 알파벳의 생김새에 대한 기하학적 고찰에 더 관심이 있다.</p>

<p>철수는 알파벳 블럭을 가지고 놀던 중 서로 모양이 거울 대칭 또는 점 대칭을 이루는 몇 가지 알파벳들을 발견하였다. 대표적으로 알파벳 p, q, b, d간의 관계를 들 수 있다. p와 q는 서로 거울 대칭이고, p와 d는 서로 점 대칭이다. b와 d는 서로 거울 대칭이고, b와 q는 서로 점 대칭이다. 알파벳 u와 n의 경우 또한 서로 점 대칭을 이룬다. 또한 i, m, v, w과 같은 알파벳은 그 자체로 거울 대칭이고, s, z는 그 자체로 점 대칭이다. l, o, x는 점 대칭이자 거울 대칭인 알파벳이다. 그리고 그 외의 대칭 관계는 존재하지 않는다.</p>

<p>이렇게 서로 대칭인 알파벳 사이의 관계를 활용하면 가운데를 기점으로 서로 거울 대칭 또는 점 대칭을 이루는 단어를 만들 수 있다. 예를 들어 bbdd, ppqq, ddbb, bwwd 등은 거울 대칭을, bbqq, ppdd, ddpp, boq, bsq는 점 대칭을 이루는 단어이다. 이러한 대칭 단어에 호기심이 생긴 철수는 알파벳 블럭으로 문자열을 만들고, 이중에서 가장 긴 부분 대칭 단어를 찾으려고 한다. 부분 대칭 단어는 점 대칭 또는 거울 대칭을 이루는 연속된 부분 문자열을 의미한다.</p>

<p>가령, 나열된 문자열이 <strong>abboqqppoddk</strong> 일 경우, 이 문자열의 부분 대칭 단어 목록은 아래와 같다.</p>

<ul>
	<li>거울 대칭: 'o', 'qp', 'qqpp', 'oqqppo', 'boqqppod', 'bboqqppodd'</li>
	<li>점 대칭: 'o', 'boq', 'bboqq', 'pod', 'ppodd'</li>
</ul>

<p>이중 가장 긴 부분 대칭 단어인 <strong>bboqqppodd</strong> 가 가장 긴 부분 대칭 단어가 된다.</p>

<p>나열된 알파벳 블럭 문자열의 정보가 주어질 때, 가장 긴 부분 대칭 단어의 길이를 구하는 프로그램을 구현하시오.</p>

### 입력 

 <p>첫 번째 줄에 길이가 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>이고 소문자 알파벳으로 구성된 문자열이 주어진다. <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c33"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c35"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mn>3</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><mn>500</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>000</mn><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$(3 ≤ N ≤ 500\,000)$</span> </mjx-container></p>

### 출력 

 <p dir="auto">첫 번째 줄에 입력에 주어진 문자열의 가장 긴 부분 대칭 단어의 길이를 출력한다.</p>

<p dir="auto">부분 대칭 단어가 존재하지 않을 경우, <code>NOANSWER</code>를 출력한다.</p>

