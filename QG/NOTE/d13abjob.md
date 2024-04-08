/*
ghep cho tung dinh
for i: 1 -> m
tim duong di xuat phat o i ket thuc ben phai o j la dinh tu do
tu trai sang phai => di bang canh do thi
tu phai sang trai => di bang canh cua cap ghep

adj[i] danh sach cac dinh ben phai ghep duoc voi dinh i ben trai
trai[i] = j -> dinh i ghep voi j 
phai[j] = i -> dinh j ghep voi i
=> trai[i] = 0 || phai[j] = 0 nghia la chua ghep voi dinh nao

GHEP DINH
cnt = 0
for i: 1 -> m:
    memset(d, 0, sizeof(d))
    if (ghep_duoc(i)) cnt++

d[i] da nho nhuong cho dinh i

bool ghep_duoc(i)
    if d[i] > 0 -> neu da nhuong cho dinh i truoc do thi khong the nhuong duoc tiep
        return false
    
    d[i] = 1 -> danh dau da nhuong
    for (j : adj[i])
        if phai[j] chua duoc ghep || ghep_duoc(phai[j]) -> phai[j] dong y nhuong cho i
            trai[i] = j
            phai[j] = i
            return true
    
    return false

CAI TIEN

cnt = 0
time = 0
memset(d, 0, sizeof(d))

for i: 1 -> m:
    time++;
    if (ghep_duoc(i)) cnt++

bool ghep_duoc(i)
    if d[i] == time -> neu da nhuong cho dinh i truoc do thi khong the nhuong duoc tiep
        return false
    
    d[i] = time -> danh dau da nhuong
    for (j : adj[i])
        if phai[j] chua duoc ghep || ghep_duoc(phai[j]) -> phai[j] dong y nhuong cho i
            trai[i] = j
            phai[j] = i
            return true
    
    return false

CAI TIEN v2

chay for time
*/