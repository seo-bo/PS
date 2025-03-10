# [Diamond V] 정육면체를 사랑하는 사람 - 14708 

[문제 링크](https://www.acmicpc.net/problem/14708) 

### 성능 요약

메모리: 2036 KB, 시간: 36 ms

### 분류

브루트포스 알고리즘, 수학

### 제출 일자

2024년 7월 3일 17:47:14

### 문제 설명

<p>지학이는 정육면체를 정말 사랑한다. 정육면체 없이는 하루도 살아갈 수 없다. 그래서 자기 집에 정육면체를 산더미처럼 쌓아놓고 매일 그 정육면체들을 바라보며 행복한 인생을 살고 있다.</p>

<p>지학이가 자꾸 집에 정육면체를 들여놓자 집안이 엉망이 되어버려 화가 난 석환이는 지학이에게 특단의 조치를 내렸다. 집에 늘어놓은 정육면체들을 당장 정리하지 않으면 집에서 내쫓겠다는 것이다!</p>

<p>지학이는 가로, 세로, 높이가 1cm인 K개의 정육면체들을 직육면체의 박스 1개에 모두 담아 정리해야 한다. 게다가 석환이는 까다로운 성격이라 다음과 같은 조건을 요구했다: 정육면체들의 각 면이 박스의 각 면과 평행하도록 놓여야 하고, 정육면체들끼리는 서로 맞닿아 있을 수는 있지만 서로 겹치거나 박스의 테두리를 뚫고 나오도록 놓을 수는 없다. 정육면체들을 어떻게 쌓고 배열하냐에 따라 필요한 직육면체 박스의 크기가 바뀌게 된다는 것을 알 수 있다.</p>

<p>마지막 한 줄기 자비심이 남아있는 석환이는 정육면체들을 정리하는데 필요한 직육면체 박스를 직접 사다 주겠다고 했다. 대신 석환이의 돈을 쓰는 것이기 때문에 박스의 가격을 최소한으로 줄이는 방법을 알아내야 한다. 만약 가격이 최소가 아니라면 석환이는 박스를 사러 가지 않을 것이고 결국 지학이는 집에서 쫓겨나게 된다. 박스의 가격은 직육면체의 겉넓이에 비례하므로 결국 겉넓이가 최소가 되는 박스의 크기를 석환이에게 알려주어야 한다.</p>

<p>지학이가 집에서 쫓겨나게 되지 않도록 필요한 직육면체 박스의 겉넓이가 최소가 되는 크기를 구해 지학이에게 알려주자.</p>

### 입력 

 <p>첫 번째 줄에 자연수 1개가 주어지는데, 이는 정육면체의 개수 K (1 ≤ K ≤ 10<sup>18</sup>) 를 나타낸다.</p>

### 출력 

 <p>첫 번째 줄에 가격이 최소가 되는 직육면체 박스의 가로, 세로, 높이를 cm 단위로 출력한다. 가격이 최소가 되는 직육면체 박스가 여러 개라면 (가로, 세로, 높이) 로 순서쌍을 만들었을 때 사전 순으로 제일 앞서는 것을 출력한다.</p>

