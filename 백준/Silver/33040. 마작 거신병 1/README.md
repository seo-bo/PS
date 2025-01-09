# [Silver I] 마작 거신병 1 - 33040 

[문제 링크](https://www.acmicpc.net/problem/33040) 

### 성능 요약

메모리: 2084 KB, 시간: 4 ms

### 분류

해 구성하기, 그리디 알고리즘

### 제출 일자

2024년 12월 28일 13:51:46

### 문제 설명

<p>여러분은 마작에서 이기기 위해 마작 거신병을 소환하려고 합니다.</p>

<p>마작 거신병은 총 $H \times W$장의 마작패로 이루어진 $H$행 $W$열의 직사각형 모양입니다.</p>

<p>아름다운 마작 거신병을 소환하기 위해, <img alt="" src="" style="vertical-align: middle; height: 3em; display: inline-block;" class="no-responsive"> <strong>1만</strong>과 <img alt="" src="" style="vertical-align: middle; height: 3em; display: inline-block;" class="no-responsive"> <strong>9만</strong>으로만 이루어진 마작 거신병을 만들고자 합니다. 1만에는 $1$이, 9만에는 $9$가 하나씩 쓰여 있습니다.</p>

<p>마작 거신병의 안정적인 구조를 위해, 아래 행에 쓰여 있는 모든 수의 합은 위 행에 쓰여 있는 모든 수의 합보다 커야 합니다. 다시 말해:</p>

<ul>
	<li>$i$행에 놓여 있는 마작패들에 쓰여 있는 수의 합을 $S_i$라고 했을 때, $1 \le i<j \le H$인 정수 $i$, $j$에 대해 $S_i<S_j$여야 합니다.</li>
</ul>

<p>여러분이 가지고 있는 $C$장의 <img alt="" src="" style="vertical-align: middle; height: 3em; display: inline-block;" class="no-responsive"> 1만과 $D$장의 <img alt="" src="" style="vertical-align: middle; height: 3em; display: inline-block;" class="no-responsive"> 9만으로 안정적인 아름다운 마작 거신병을 소환해 주세요.</p>

### 입력 

 <p>첫 번째 줄에 마작 거신병의 모양을 나타내는 두 정수 $H$와 $W$가 공백으로 구분되어 주어집니다. $(H,W \ge 1;$ $H\times W \le 100\,000)$</p>

<p>두 번째 줄에 가지고 있는 <img alt="" src="https://upload.acmicpc.net/b7f895f8-786a-4241-af72-345c477c2ead/-/preview/" style="vertical-align: middle; height: 3em; display: inline-block;" class="no-responsive"> 1만의 개수와 <img alt="" src="https://upload.acmicpc.net/299003f8-0f68-4788-988c-86affd7cee94/-/preview/" style="vertical-align: middle; height: 3em; display: inline-block;" class="no-responsive"> 9만의 개수 $C$와 $D$가 공백으로 구분되어 주어집니다. $(C,D \ge 0;$ $C+D=H\times W)$</p>

### 출력 

 <p>안정적인 아름다운 마작 거신병의 구조를 출력합니다.</p>

<ul>
	<li>출력은 $H$개의 줄로 이루어집니다.</li>
	<li>$i$번째 줄에는 마작 거신병의 $i$행에 놓을 마작패 $W$장을 공백으로 구분하여 순서대로 출력합니다. <img alt="" src="https://upload.acmicpc.net/b7f895f8-786a-4241-af72-345c477c2ead/-/preview/" style="vertical-align: middle; height: 3em; display: inline-block;" class="no-responsive"> 1만이라면 $1$, <img alt="" src="https://upload.acmicpc.net/299003f8-0f68-4788-988c-86affd7cee94/-/preview/" style="vertical-align: middle; height: 3em; display: inline-block;" class="no-responsive"> 9만이라면 $9$를 출력합니다.</li>
	<li>$i$행에 놓여 있는 마작패들에 쓰여 있는 수의 합을 $S_i$라고 했을 때, $1 \le i<j \le H$인 정수 $i$, $j$에 대해 $S_i<S_j$여야 합니다.</li>
</ul>

<p>여러 가지 방법이 있다면 그 중 하나를 출력합니다. 어떻게 해도 안정적인 아름다운 마작 거신병을 만들 수 없다면, 대신 <span style="color:#e74c3c;"><code>-1</code></span>을 출력합니다.</p>

