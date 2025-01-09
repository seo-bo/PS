# [Platinum IV] 순정$N$련보등 - 33047 

[문제 링크](https://www.acmicpc.net/problem/33047) 

### 성능 요약

메모리: 41328 KB, 시간: 424 ms

### 분류

자료 구조, 누적 합, 세그먼트 트리, 스위핑

### 제출 일자

2024년 12월 28일 16:50:26

### 문제 설명

<p style="text-align: center;"><img alt="preview" src="" style="display: block; margin: 0 auto; width: 960px; max-width: 100%;"></p>

<p><strong>구련보등</strong><sup>九蓮寶燈</sup>은 마작의 역 중 하나로 ‘$9$개의 연꽃 보배 등잔’이라는 뜻을 가지고 있습니다.</p>

<p>구련보등의 형태 중 하나인 <strong>순정구련보등</strong><sup>純正九蓮寶燈</sup>은 한 종류의 수패로 $1$과 $9$를 각각 $3$장씩, $2$부터 $8$을 각각 $1$장씩 손에 가지고 있는 상태에서 같은 종류의 수패 $1$부터 $9$ 사이의 아무 패를 한 장 더 가져와 완성하면 되는 역입니다. 이렇게 손에 $1$과 $9$가 각각 $3$장씩, $2$부터 $8$이 각각 $1$장씩 있어 남은 한 장을 더 가져오면 완성할 수 있는 상태를 ‘순정구련보등 텐파이’라고 하는데, 이 때 패를 비내림차순으로 정리하면 다음과 같은 형태가 됩니다.</p>

<p style="text-align: center;"><img alt="1" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="1" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="1" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="2" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="3" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="4" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="5" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="6" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="7" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="8" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="9" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="9" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="9" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"></p>

<p>개척단 훈련소 마장에서 플레이하는 ‘순정$N$련보등 마작’은 수패 중에서도 만수패만 사용하며 $1$부터 $N$까지 총 $N$종류의 만수패가 존재합니다. 순정$N$련보등 마작에서의 ‘순정$N$련보등 텐파이’는 $1$이 $3$장, $2,\dots ,N-1$이 한 장씩, $N$이 $3$장이 연속되게 $N+4$장 있는 형태를 말합니다. 이때, 패에 적혀 있는 수는 반드시 비내림차순이 되어야 합니다.</p>

<p>여러분은 바닥에 일렬로 놓여진 $K$장의 패를 확인하다가 패를 적절히 교체하여 순서대로 정리된 순정$N$련보등 텐파이 형태가 있도록 만들 수 있는지 궁금해졌습니다.</p>

<p>패를 교체하는 것은 어려운 일입니다. 따라서 패를 교체할 때는 한 장의 패를 골라 해당 패에 적힌 수와 $1$ 차이가 나는 인접한 수가 적힌 패로만 교체할 수 있고, $1$보다 작거나 $N$보다 큰 수의 패로는 교체할 수 없습니다. 같은 위치의 패를 여러 번 교체하는 것은 허용됩니다.</p>

<p>바닥에 놓여진 패들이 주어졌을 때, 하나 이상의 길이 $N+4$의 구간이 순정구련보등 텐파이 형태가 되기 위해 필요한 최소 교체 횟수를 구해 주세요.</p>

### 입력 

 <p>첫 번째 줄에 마작패의 종류 수 $N$과 바닥에 놓여진 패의 개수 $K$가 공백으로 구분되어 주어집니다. $(3 \le N \le 399\,996;$ $N \equiv 0 \pmod{3};$ $N+4 \le K \le 400\,000)$</p>

<p>두 번째 줄에 바닥에 놓여진 패의 종류를 나타내는 $K$개의 정수 $A_1, \dots, A_K$가 공백으로 구분되어 주어집니다. $i$번째 수는 $i$번째로 놓여 있는 패에 적혀 있는 수입니다. $(1 \le A_i \le N)$</p>

### 출력 

 <p>하나 이상의 구간을 순정$N$련보등 텐파이 형태로 만들기 위한 최소 교체 횟수를 출력합니다.</p>

<p>하나도 교체하지 않아도 순정$N$련보등 텐파이 형태가 존재한다면 <code><span style="color:#e74c3c;">0</span></code>을 출력합니다.</p>

