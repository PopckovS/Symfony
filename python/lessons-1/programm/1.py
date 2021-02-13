#!/usr/bin/env python3

def maximum(x, y):
    """Находит и выводит наибольшее значение из 2 переменных"""
    if x > y:
        return x
    elif x == y:
        return 'равны'
    else:
        return y

print(maximum(3, 5))
print(maximum.__doc__)
print('-------------')
help(maximum)