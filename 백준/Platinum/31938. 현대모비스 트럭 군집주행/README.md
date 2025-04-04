# [Platinum V] 현대모비스 트럭 군집주행 - 31938 

[문제 링크](https://www.acmicpc.net/problem/31938) 

### 성능 요약

메모리: 37784 KB, 시간: 280 ms

### 분류

데이크스트라, 그래프 이론, 최단 경로

### 제출 일자

2024년 6월 3일 23:39:06

### 문제 설명

<p style="text-align: center;"><img alt="" src="" style="height: 282px; width: 600px;"></p>

<blockquote>
<p>현대모비스는 앞으로 미래 모빌리티 산업에서 소프트웨어와 하드웨어를 결합한 차별화된 모빌리티 솔루션을 제공하는 선도기업으로 도약하기 위해 노력하고 있으며, 이러한 연구개발과 생산능력 등 핵심역량을 바탕으로 스마트 모빌리티, UAM, 로보틱스 사업분야로 비즈니스를 확대해 나가고 있습니다.</p>
</blockquote>

<p>트럭 군집주행은 여러 대의 트럭이 줄지어 함께 이동하는 자율주행 운송 기술이다. 내륙 운송의 효율을 높이고 뒤따르는 트럭에 공기 저항이 최소화되면서 연료 효율 개선과 배출가스 저감 효과도 기대할 수 있다.</p>

<p>$1$번부터 $N$번까지 번호가 부여된 $N$개의 도시, 서로 다른 두 도시를 잇는 $M$개의 양방향 도로, $1$번 도시에서 출발하여 나머지 $N-1$개의 도시로 화물을 운송하는 $N-1$개의 트럭이 있다.</p>

<p>각 트럭은 목적지까지 <strong>최단 거리</strong>로 이동한다. 같은 도로를 따라 여러 트럭이 함께 이동하는 경우 트럭 군집주행을 통해 운송비를 절감할 수 있다. 기본 운송비는 거리와 같지만, 한 트럭이 다른 트럭을 뒤따라가는 경우 해당 도로의 운송비가 $10\%$ 절감되는 효과가 있다.</p>

<p>예를 들어 $3$대의 트럭이 거리가 $10$인 도로를 줄지어 함께 이동하는 경우, 가장 앞선 트럭은 $10$, 뒤따라오는 두 트럭은 각각 $9$의 운송비가 필요하므로 총 $28$의 운송비가 필요하다. 모든 트럭이 화물을 운송하는 데 필요한 운송비의 최솟값을 구해 보자.</p>

### 입력 

 <p>첫째 줄에 도시의 개수 $N$과 도로의 개수 $M$이 공백으로 구분되어 주어진다. $(2 \le N \le 200 \, 000;$ $1 \le M \le 300 \, 000)$</p>

<p>둘째 줄부터 $M$개 줄에 걸쳐 각 도로의 정보를 나타내는 세 정수 $a$, $b$, $c$가 공백으로 구분되어 주어진다. $a$번 도시와 $b$번 도시를 연결하는 길이 $c$의 도로를 의미한다. 도로의 길이 $c$는 $10$의 배수이다. $(1 \le a, b \le N;$ $10 \le c \le 1 \, 000 \, 000)$</p>

<p>트럭이 모든 화물을 운송하는 방법이 존재하는 입력만 주어진다.</p>

### 출력 

 <p>모든 트럭이 화물을 운송하는 데 필요한 운송비의 최솟값을 출력한다. 운송비의 최솟값은 $2^{63}-1$을 넘지 않는 양의 정수이다.</p>

