# [Gold II] Tree Grafting - 4840 

[문제 링크](https://www.acmicpc.net/problem/4840) 

### 성능 요약

메모리: 3144 KB, 시간: 200 ms

### 분류

깊이 우선 탐색, 다이나믹 프로그래밍, 트리에서의 다이나믹 프로그래밍, 그래프 이론, 그래프 탐색, 트리

### 제출 일자

2025년 1월 29일 18:55:50

### 문제 설명

<p>Trees have many applications in computer science. Perhaps the most commonly used trees are rooted binary trees, but there are other types of rooted trees that may be useful as well. One example is ordered trees, in which the subtrees for any given node are ordered. The number of children of each node is variable, and there is no limit on the number. Formally, an ordered tree consists of a finite set of nodes T such that</p>

<ul>
	<li>there is one node designated as the root, denoted root(T);</li>
	<li>the remaining nodes are partitioned into subsets T1, T2, ..., Tm, each of which is also a tree (subtrees).</li>
</ul>

<p>Also, define root(T1), ..., root(Tm) to be the children of root(T), with root(Ti) being the i−th child. The nodes root(T1), ..., root(Tm) are siblings.</p>

<p>It is often more convenient to represent an ordered tree as a rooted binary tree, so that each node can be stored in the same amount of memory. The conversion is performed by the following steps:</p>

<ol>
	<li>remove all edges from each node to its children;</li>
	<li>for each node, add an edge to its first child in T (if any) as the left child;</li>
	<li>for each node, add an edge to its next sibling in T (if any) as the right child.</li>
</ol>

<p>This is illustrated by the following:</p>

<pre>         0                             0
       / | \                          /
      1  2  3       ===>             1
        / \                           \
       4   5                           2
                                      / \
                                     4   3
                                      \
                                       5
</pre>

<p>In most cases, the height of the tree (the number of edges in the longest root−to−leaf path) increases after the conversion. This is undesirable because the complexity of many algorithms on trees depends on its height.</p>

<p>You are asked to write a program that computes the height of the tree before and after the conversion.</p>

### 입력 

 <p>The input is given by a number of lines giving the directions taken in a depth−first traversal of the trees. There is one line for each tree. For example, the tree above would give dudduduudu, meaning 0 down to 1, 1 up to 0, 0 down to 2, etc. The input is terminated by a line whose first character is #. You may assume that each tree has at least 2 and no more than 10000 nodes.</p>

### 출력 

 <p>For each tree, print the heights of the tree before and after the conversion specified above. Use the format:</p>

<pre>Tree t: h1 => h2</pre>

<p>where t is the case number (starting from 1), h1 is the height of the tree before the conversion, and h2 is the height of the tree after the conversion.</p>

