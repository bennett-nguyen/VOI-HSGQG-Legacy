sort độ cao tăng dần
i -> j: min(hj - hi, pi) => pi + min(hj - hi - pi, 0)

nhận thấy đi từ 1 đến n -> giá khác 0
n -> 1 => độ cao luôn giảm dần -> giá luôn là 0

=> tìm chu trình đi qua tất cả các đỉnh -> tìm đường đi từ 1 đến n


