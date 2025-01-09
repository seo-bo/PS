# [Gold I] 이 시합에, 동2국은 오지 않아! 1 - 33044 

[문제 링크](https://www.acmicpc.net/problem/33044) 

### 성능 요약

메모리: 7900 KB, 시간: 60 ms

### 분류

백트래킹, 브루트포스 알고리즘, 조합론, 수학

### 제출 일자

2024년 12월 28일 15:44:22

### 문제 설명

<p>마작은 $14$장의 패를 모아 용을 만드는 게임입니다. 용을 만들기 위해서는 패, 머리, 몸통에 대해 알아야 합니다.</p>

<ul>
	<li><strong>패</strong><sup>牌</sup>: 마작에는 $1$ 이상 $9$ 이하의 수가 적힌 패가 각각 $4$장씩 있습니다.</li>
	<li><strong>머리</strong>: 같은 수가 적힌 패 $2$장의 조합을 말합니다(예: <img alt="4" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="4" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;">).</li>
	<li><strong>몸통</strong>: $1$씩 차이가 나는 연속된 수가 적힌 패 $3$장(예: <img alt="6" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="7" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="8" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;">) 혹은 같은 수가 적힌 패 $3$장(예: <img alt="2" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="2" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="2" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;">)의 조합을 말합니다. 패의 순서는 중요하지 않습니다.</li>
</ul>

<p>다음은 머리 혹은 몸통인 것과 그렇지 않은 것의 예를 나타냅니다.</p>

<table border="1" cellpadding="1" cellspacing="1" class="table table-bordered" style="width: 100%;">
	<thead>
		<tr>
			<th scope="col" style="text-align: center;"><strong>예시</strong></th>
			<th scope="col" style="text-align: center;"><strong>구분</strong></th>
			<th scope="col" style="text-align: center;"><strong>설명</strong></th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="text-align: center; word-break: keep-all; white-space: nowrap;"><img alt="2" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"></td>
			<td style="text-align: center; word-break: keep-all; white-space: nowrap;">-</td>
			<td>패가 $1$장이므로 머리도 몸통도 될 수 없습니다.</td>
		</tr>
		<tr>
			<td style="text-align: center; word-break: keep-all; white-space: nowrap;"><img alt="2" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="2" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"></td>
			<td style="text-align: center; word-break: keep-all; white-space: nowrap;">머리</td>
			<td>같은 패 $2$장이 있으므로 이 두 패의 조합은 머리입니다.</td>
		</tr>
		<tr>
			<td style="text-align: center; word-break: keep-all; white-space: nowrap;"><img alt="7" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="8" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="9" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"></td>
			<td style="text-align: center; word-break: keep-all; white-space: nowrap;">몸통</td>
			<td>$7,8,9$는 $1$씩 차이가 나는 연속된 수이므로 이 세 패의 조합은 몸통입니다.</td>
		</tr>
		<tr>
			<td style="text-align: center; word-break: keep-all; white-space: nowrap;"><img alt="1" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="3" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="5" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"></td>
			<td style="text-align: center; word-break: keep-all; white-space: nowrap;">-</td>
			<td>$1,3,5$는 $1$씩 차이가 나는 연속된 수가 아니므로 이 세 패의 조합은 몸통이 아닙니다.</td>
		</tr>
		<tr>
			<td style="text-align: center; word-break: keep-all; white-space: nowrap;"><img alt="8" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="9" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="1" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"></td>
			<td style="text-align: center; word-break: keep-all; white-space: nowrap;">-</td>
			<td>$9$와 $1$은 서로 연속된 수가 아닙니다.</td>
		</tr>
		<tr>
			<td style="text-align: center; word-break: keep-all; white-space: nowrap;"><img alt="9" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="9" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="9" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"></td>
			<td style="text-align: center; word-break: keep-all; white-space: nowrap;">몸통</td>
			<td>같은 패 $3$장이 있으므로 이 세 패의 조합은 몸통입니다.</td>
		</tr>
		<tr>
			<td style="text-align: center; word-break: keep-all; white-space: nowrap;"><img alt="4" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="5" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="4" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"></td>
			<td style="text-align: center; word-break: keep-all; white-space: nowrap;">-</td>
			<td>$4,4,5$는 $1$씩 차이가 나는 연속된 수가 아니므로 이 세 패의 조합은 몸통이 아닙니다.</td>
		</tr>
		<tr>
			<td style="text-align: center; word-break: keep-all; white-space: nowrap;"><img alt="8" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="8" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="8" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="8" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"></td>
			<td style="text-align: center; word-break: keep-all; white-space: nowrap;">-</td>
			<td>패가 $4$장이므로 머리도 몸통도 될 수 없습니다.</td>
		</tr>
	</tbody>
</table>

<p>이제 용을 만들기 위해서는 패 $14$장을 머리 $1$개와 몸통 $4$개 혹은 서로 다른 머리 $7$개의 조합으로 만들어야 합니다.</p>

<p>다음은 용과 용이 아닌 예를 나타냅니다.</p>

<table border="1" cellpadding="1" cellspacing="1" class="table table-bordered" style="width: 100%;">
	<tbody>
		<tr>
			<td><img alt="3" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="3" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="4" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="4" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="4" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="5" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="6" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="6" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="7" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="7" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="7" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="8" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="8" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="9" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;">: 용</td>
		</tr>
		<tr>
			<td>
			<ul>
				<li>머리 $(3,3)$과 몸통 $(4,4,4) ;(5,6,7) ;(6,7,8) ;(7,8,9)$로 이루어진 용입니다.</li>
			</ul>
			</td>
		</tr>
		<tr>
			<td><img alt="1" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="1" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="1" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="2" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="3" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="4" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="5" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="5" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="5" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="7" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="7" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="7" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="7" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="8" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;">: 용이 아님</td>
		</tr>
		<tr>
			<td>
			<ul>
				<li>어떻게 분할을 해도 머리 $1$개와 몸통 $4$개 혹은 머리 $7$개를 만들 수 없기 때문에 용이 아닙니다.</li>
				<li>같은 패가 $2$개 이상의 머리 혹은 몸통에 동시에 속해서는 안 됩니다.</li>
			</ul>
			</td>
		</tr>
		<tr>
			<td><img alt="1" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="1" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="2" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="2" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="3" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="3" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="5" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="5" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="7" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="7" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="8" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="8" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="9" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="9" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;">: 용</td>
		</tr>
		<tr>
			<td>
			<ul>
				<li>머리 $(5,5)$와 몸통 $(1,2,3) ;(1,2,3) ;(7,8,9) ;(7,8,9)$으로 이루어진 용입니다.</li>
				<li>서로 다른 머리 $7$개인 $(1,1) ;(2,2) ;(3,3) ;(5,5) ;(7,7) ;(8,8) ;(9,9)$로 이루어진 용으로 볼 수도 있습니다.</li>
			</ul>
			</td>
		</tr>
		<tr>
			<td><img alt="1" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="1" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="1" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="1" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="2" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="2" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="5" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="5" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="6" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="6" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="8" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="8" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="9" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;"><img alt="9" class="no-responsive" src="" style="vertical-align: middle; height: 3em; display: inline-block;">: 용이 아님</td>
		</tr>
		<tr>
			<td>
			<ul>
				<li>머리 $7$개를 만들기 위해서는 중복된 두 개의 머리 $(1,1)$을 만들어야 하기 때문에 머리가 $7$개인 용이 될 수 없습니다.</li>
				<li>어떻게 분할을 해도 머리 $1$개와 몸통 $4$개를 만들 수 없기 때문에 용이 아닙니다.</li>
			</ul>
			</td>
		</tr>
	</tbody>
</table>

<p>현재 패산에는 패가 $N$장 쌓여 있고, $i$번째 패에는 $A_i$가 적혀 있습니다. 여러분은 여기서 $14$장의 패를 뽑아 용을 만들 수 있는 경우의 수가 몇 가지인지 알고 싶어졌습니다.</p>

### 입력 

 <p>첫 번째 줄에 패산에 있는 패의 개수 $N$이 주어집니다. $(14\le N\le 36)$</p>

<p>두 번째 줄에 $A_1,A_2,\cdots ,A_N$이 공백으로 구분되어 주어집니다. $(1\le A_i\le 9)$ 한 종류의 패가 $4$장 초과로 주어지지 않습니다.</p>

### 출력 

 <p>패산에서 $14$장의 패를 뽑아 용을 만들 수 있는 경우의 수를 출력합니다.</p>

