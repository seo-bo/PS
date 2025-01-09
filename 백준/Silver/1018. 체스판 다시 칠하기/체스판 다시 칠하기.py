x, y = map(int, input().strip().split(' '))
bord = []
for _ in range(x):
    bord.append(list(input()))
result = []
#질문 게시판 디버깅용
for i in range(x - 7):
    for j in range(y - 7):
        count = 0
        count2 = 0
        for k in range(8):
            for t in range(8):
                if (k + t) % 2 == 0:
                    if bord[i + k][j + t] != 'W':
                        count += 1
                    if bord[i + k][j + t] != 'B':
                        count2 += 1
                else:
                    if bord[i + k][j + t] != 'B':
                        count += 1
                    if bord[i + k][j + t] != 'W':
                        count2 += 1
        result.append(min(count, count2))

print(min(result))