Sắp xếp sao cho $h_1 \leq h_2 \leq \cdots \leq h_n$
<br>
Gọi $F_{ik}$ là số lượng $k$ cặp xét được khi tính đến vị trí thứ $i$
```
F[i][k] = min(F[i-1][k], F[i-2][k-1] + h[i]-h[i-1])
```

```
procedure calc(i, k) 
    if F[i][k] > -1 do
        return F[i][k]
    endif

    if k == 0 do
        return 0
    endif

    ll best = calc(i-2, k-1)

    if i-1 >= 2*k do
        best = min(best, calc(i-1, k))
    endif

    return F[i][k] = best
```