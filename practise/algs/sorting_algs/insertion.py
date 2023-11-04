from .swap import swap_elements

def insertion_sort(arr):
    n = len(arr)

    for i in range(1, n):
        j = i
        while arr[j] < arr[j - 1] and j > 0:
            swap_elements(arr, j, j - 1)
            j -= 1

    print("insertion sort: ", end = "")
