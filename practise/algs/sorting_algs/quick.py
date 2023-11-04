from .swap import swap_elements

def partition(arr, low, high):
    i = low - 1
    pivot = arr[high]

    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            swap_elements(arr, j, i)

    swap_elements(arr, high, i + 1)
    return i + 1

def quick_sort(arr, low, high):
    if low < high:
        pivot = partition(arr, low, high)
        quick_sort(arr, low, pivot - 1)
        quick_sort(arr, pivot + 1, high)

def quick_sort2(arr, left, right):
    mid = (left + right) // 2
    pivot = arr[mid]

    swap_elements(arr, mid, right)

    i = left
    j = right - 1
    while 1:
        while arr[i] < pivot:
            i += 1
        while arr[j] > pivot:
            j -= 1

        if i >= j:
            break
        swap_elements(arr, i, j)
        
    swap_elements(arr, i, right)

    if i < right:
        quick_sort2(arr, i + 1, right)
    if j > left:
        quick_sort2(arr, left, j)
    
