"""Нахождение суммы эллементов массива при помощи метода
рекурсии и стека вызовов."""
def summ(array):
    if len(array) == 1:
        return array.pop(0)
    else:
        return array.pop(0) + summ(array)

array = [2, 4, 6]
result = summ(array)
print(result)
