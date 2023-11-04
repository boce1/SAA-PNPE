def count_sort(arr):
    n = len(arr)
    max_el = max(arr)
    count_arr = [0 for _ in range(max_el + 1)]

    for el in arr:
        count_arr[el] += 1

    for i in range(1, max_el + 1):
        count_arr[i] += count_arr[i - 1]

    out = [0] * n
    for i in range(n - 1, -1, -1):
        el = arr[i]
        out[count_arr[el] - 1] = el
        count_arr[el] -= 1

    for i in range(n):
        arr[i] = out[i]

    print("Count sort: ", end="")