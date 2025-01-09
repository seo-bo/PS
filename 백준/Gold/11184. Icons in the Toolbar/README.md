# [Gold V] Icons in the Toolbar - 11184 

[문제 링크](https://www.acmicpc.net/problem/11184) 

### 성능 요약

메모리: 25468 KB, 시간: 96 ms

### 분류

브루트포스 알고리즘, 그리디 알고리즘, 누적 합

### 제출 일자

2024년 10월 19일 12:21:30

### 문제 설명

<p>Gunnar is not satisfied with the graphic tools currently available for LATEX, so he’s working on his own graphics editor. For every editor function he has also created an icon which is a square image. These icons will be placed in a toolbar with two rows and N columns. The height of a toolbar row is the same as the size of the biggest icon in the row. Similarly, the width of a column is the same as the size of the biggest icon in the column. The height of the toolbar is the sum of heights of all rows and the width of the toolbar is the sum of widths of all columns. Gunnar now wonders how he should order the icons so that the area of the toolbar is as small as possible.</p>

<table class="table table-bordered">
	<tbody>
		<tr>
			<td>100</td>
			<td>99</td>
			<td>98</td>
		</tr>
		<tr>
			<td>3</td>
			<td>1</td>
			<td>2</td>
		</tr>
	</tbody>
</table>

<p>Figure F.1: The height of this toolbar is 100 + 3 and the width 100 + 99 + 98. The total area is (100 + 3)·(100 + 99 + 98) = 30 591. This example corresponds to Sample Input 1.</p>

<p>You will be given a sorted integer sequence s<sub>1</sub>, . . . , s<sub>2N</sub> denoting that the i-th icon has dimensions s<sub>i</sub> × s<sub>i</sub>. Your task is to calculate the smallest possible area of a toolbar with 2 rows and N columns.</p>

### 입력 

 <p>The first line of the input contains one integer N, 1 ≤ N ≤ 1 000 000. Each of the next 2N lines contains one integer s<sub>i</sub> denoting the size of an icon. You can assume that 1 000 000 ≥ s<sub>1</sub> ≥ s<sub>2</sub> ≥ . . . ≥ s<sub>2N</sub> ≥ 1.</p>

### 출력 

 <p>The output consist of a single line with one integer – the smallest possible area of the toolbar.</p>

