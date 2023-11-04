def counting_sort(arr, exp):
    n = len(arr)
    count_arr = [0] * 10

    for i in range(n):
        digit = arr[i] // exp % 10
        count_arr[digit] += 1

    for i in range(1, 10):
        count_arr[i] += count_arr[i - 1]

    out = [0] * n
    for i in range(n - 1, -1, -1):
        digit = arr[i] // exp % 10
        out[count_arr[digit] - 1] = arr[i]
        count_arr[digit] -= 1
    
    for i in range(n):
        arr[i] = out[i]

def radix_sort(arr):
    m = max(arr)

    exp = 1
    while m // exp > 0:
        counting_sort(arr, exp)
        exp *= 10

    print("Radix sort: ", end="")