import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def init(start,end,node):
    if (start == end):
        tree[node] = ary[start]
        return
    mid = (start+end) // 2
    init(start, mid, node * 2)
    init(mid + 1, end, node * 2 + 1)
    tree[node] = tree[node*2] + tree[node*2+1]

def update(start, end, node, idx, value):
    if (idx > end or idx < start):
        return
    if (idx <= start and end <= idx):
        tree[node] = value
        return
    mid = (start + end) // 2
    update(start, mid, node*2, idx, value)
    update(mid+1, end, node*2+1, idx, value)
    tree[node] = tree[node*2] + tree[node*2+1]

def query(start, end, node, left, right):
    if (left > end or right < start):
        return 0
    if (left <= start and end <= right):
        return tree[node]
    mid = (start + end) // 2
    return query(start,mid,node*2,left,right) + query(mid+1,end,node*2+1,left,right)

num, test = map(int,input().split())
ary = list(map(int,input().split()))
tree = [0] * num * 5
init(0,num-1,1)
for i in range(test):
    a,b,c,d = map(int,input().split())
    print(query(0,num-1,1,min(a,b)-1,max(a,b)-1))
    update(0,num-1,1,c-1,d)