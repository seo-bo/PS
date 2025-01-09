import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

def init(start, end, node):
    if(start == end):
        if ary[start] % 2 == 0:
            even_tree[node] = 1
            odd_tree[node] = 0
        else:
            odd_tree[node] = 1
            even_tree[node] = 0
        return
    mid = (start + end) // 2
    init(start,mid,node*2)
    init(mid+1,end,node*2+1)
    even_tree[node] = even_tree[node*2] + even_tree[node*2+1]
    odd_tree[node] = odd_tree[node*2] + odd_tree[node*2+1]

def update(start, end, node, idx, value):
    if(idx > end or idx < start):
        return
    if (idx <= start and end <= idx):
        if value % 2 == 0:
            even_tree[node] = 1
            odd_tree[node] = 0
        else:
            odd_tree[node] = 1
            even_tree[node] = 0
        return
    mid = (start + end) // 2
    update(start,mid,node*2,idx,value)
    update(mid+1,end,node*2+1,idx,value)
    even_tree[node] = even_tree[node * 2] + even_tree[node * 2 + 1]
    odd_tree[node] = odd_tree[node * 2] + odd_tree[node * 2 + 1]
    
def even_query(start,end,node,left,right):
    if(left > end or right < start):
        return 0
    if (left <= start and end <= right):
        return even_tree[node]
    mid = (start + end) // 2
    return even_query(start,mid,node*2,left,right) + even_query(mid+1,end,node*2+1,left,right)

def odd_query(start,end,node,left,right):
    if(left > end or right < start):
        return 0
    if (left <= start and end <= right):
        return odd_tree[node]
    mid = (start + end) // 2
    return odd_query(start,mid,node*2,left,right) + odd_query(mid+1,end,node*2+1,left,right)

num = int(input().strip())
ary = list(map(int,input().split()))
even_tree = [0 for _ in range(num*5)]
odd_tree = [0 for _ in range(num*5)]
test = int(input().strip())
init(0,num-1,1)
for i in range(test):
    get = list(map(int,input().split()))
    match get[0]:
        case 1:
            update(0,num-1,1,get[1]-1,get[2])
        case 2:
            print(even_query(0,num-1,1,get[1]-1,get[2]-1))
        case 3:
            print(odd_query(0, num - 1, 1, get[1] - 1, get[2] - 1))