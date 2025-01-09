# [Silver II] TPS - 32402 

[문제 링크](https://www.acmicpc.net/problem/32402) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

구현, 시뮬레이션

### 제출 일자

2024년 9월 28일 20:23:51

### 문제 설명

<p>TPS(3인칭 슈팅 게임)는 주인공의 1인칭 시점이 아닌 주인공을 관찰하는 카메라의 3인칭 시점으로 플레이하는 게임을 의미한다. TPS 게임의 플레이어는 자유롭게 움직이는 카메라의 시점으로 게임을 플레이하기 때문에 더욱 다양한 시점에서 게임을 즐길 수 있다. 다음과 같은 TPS 게임을 시뮬레이션해서 입력에 따라 주인공과 카메라의 위치가 어떻게 변하는지 알아보자.</p>

<p style="display:flex;flex-direction:column;align-items:center;"><img src="" style="max-height:24em;max-width:100%"> <span style="text-align:center;">주인공과 카메라</span></p>

<p>이 TPS 게임에는 2차원 좌표계에 위치한 주인공과 카메라가 존재한다. 주인공과 카메라의 위치를 정수 좌표 $(x,y)$로 나타낼 수 있다. 게임이 시작할 때 주인공은 $(0,0)$에 위치해 있다. 카메라는 항상 주인공을 중심으로 하는 반지름이 $1$인 원 위에 위치하며, 게임이 시작할 때 카메라는 $(0,-1)$에 위치해 있다. 카메라는 항상 주인공이 위치한 방향을 바라본다.</p>

<p>이 게임의 플레이어가 키보드나 마우스를 통해서 입력할 때마다 주인공 혹은 카메라(혹은 둘 다)의 위치가 다음과 같이 바뀐다. 이동 후에도 주인공과 카메라는 정수 좌표에 위치한다.</p>

<ul>
	<li><span style="color:#e74c3c;"><code>W</code></span> 키를 입력하면 주인공과 카메라 모두 카메라가 바라보는 방향을 앞으로 하여 앞으로 $1$만큼 이동한다.</li>
	<li><span style="color:#e74c3c;"><code>A</code></span> 키를 입력하면 주인공과 카메라 모두 카메라가 바라보는 방향을 앞으로 하여 왼쪽으로 $1$만큼 이동한다.</li>
	<li><span style="color:#e74c3c;"><code>S</code></span> 키를 입력하면 주인공과 카메라 모두 카메라가 바라보는 방향을 앞으로 하여 뒤로 $1$만큼 이동한다.</li>
	<li><span style="color:#e74c3c;"><code>D</code></span> 키를 입력하면 주인공과 카메라 모두 카메라가 바라보는 방향을 앞으로 하여 오른쪽으로 $1$만큼 이동한다.</li>
	<li>마우스를 오른쪽으로 움직이면 카메라는 주인공을 중심으로 하는 반지름이 $1$인 원 위에서 시계 방향으로 $90^{\circ}$만큼 회전한다.</li>
	<li>마우스를 왼쪽으로 움직이면 카메라는 주인공을 중심으로 하는 반지름이 $1$인 원 위에서 반시계 방향으로 $90^{\circ}$만큼 회전한다.</li>
</ul>

<p>게임이 시작한 후의 플레이어 입력이 입력한 순서대로 주어질 때, 각각의 입력에 대해 입력이 끝난 후의 주인공과 카메라의 위치를 구해보자.</p>

### 입력 

 <p>첫째 줄에 정수 $N(1\le N\le 100)$이 주어진다.</p>

<p>둘째 줄부터 $N$개의 줄에 걸쳐 플레이어 입력이 입력한 순서대로 주어진다. 플레이어 입력은 <span style="color:#e74c3c;"><code>W</code></span>, <span style="color:#e74c3c;"><code>A</code></span>, <span style="color:#e74c3c;"><code>S</code></span>, <span style="color:#e74c3c;"><code>D</code></span>, <span style="color:#e74c3c;"><code>MR</code></span>, <span style="color:#e74c3c;"><code>ML</code></span> 중 하나이다. <span style="color:#e74c3c;"><code>W</code></span>, <span style="color:#e74c3c;"><code>A</code></span>, <span style="color:#e74c3c;"><code>S</code></span>, <span style="color:#e74c3c;"><code>D</code></span>는 키보드의 해당하는 키를 입력했음을 의미하고, <span style="color:#e74c3c;"><code>MR</code></span>은 마우스를 오른쪽으로, <span style="color:#e74c3c;"><code>ML</code></span>은 마우스를 왼쪽으로 움직였음을 의미한다.</p>

### 출력 

 <p>$N$개의 줄에 걸쳐 $i(1\le i\le N)$번째 입력이 끝난 후에 주인공의 좌표가 $(x_p,y_p)$, 카메라의 좌표가 $(x_c,y_c)$일 때, $x_p,y_p,x_c,y_c$를 공백으로 구분하여 출력한다.</p>

