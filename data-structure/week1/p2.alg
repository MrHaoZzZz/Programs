for i = 2 to n:
    key = a[i]
    j = i - 1
    // in next line where loop condition from oringal "a[j] > key" changes to "a[j] < key"
    while j > 0 and a[j] < key:
        a[j + 1] = a[j]
        j = j - 1
    a[j + 1] = key