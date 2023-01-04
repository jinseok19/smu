
def quick_sort(arry, start, end):

    if start >= end:
        return
    pivot = start
    left = start + 1
    right = end

    while left <= right:
        while left <= end and array[left] <=array[pivot]:

            left +=1
        while right > start and array[right] >= array[pivot]:
            right -= 1

        if left > right:

            array[right], array[pivot] = array[pivot], array[right]

        else:
            array[left], array[right] = array[right], array[left]
    print(array)

    quick_sort(array, start, right -1)
    quick_sort(array, right+1, end)
    
array = [7,2,9,4,3,5,6,1]
quick_sort(array, 0, len(array)-1)

print("최종 정렬", array)
