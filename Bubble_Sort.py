def bubbleSort(arr):
    sorted = False  #To check if given array is already sorted or not
    for i in range(0,len(arr)-1):
        for j in range(0, len(arr)-i-1):
            if arr[j] > arr[j + 1]:
                sorted = True
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
        if not sorted:
          #If the given array is already sorted we can just end the processing of array
            break
    return
