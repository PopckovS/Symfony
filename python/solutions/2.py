"""Реализация алгоритма быстрой сортировки массива в python"""


def quicksort(array):
    if len(array) < 2:
        return array
    else:
        pivot = array[0]
        less = [i for i in array[1:] if i <= pivot]
        grester = [i for i in array[1:] if i > pivot]
        return quicksort(less) + [pivot] + quicksort(grester)

array = [10, 5, 2, 3]
result = quicksort(array)
print(result)













