n = int(input())

def nextPermutation(arr):
   
      # find the length of the array
    n = len(arr)
     
    # start from the right most digit and find the first
    # digit that is smaller than the digit next to it.
    k = n - 2
    while k >= 0:
        if arr[k] < arr[k + 1]:
            break
        k -= 1
         
    # reverse the list if the digit that is smaller than the
    # digit next to it is not found.
    if k < 0:
        arr = arr[::-1]
    else:
       
          # find the first greatest element than arr[k] from the
        # end of the list
        for l in range(n - 1, k, -1):
            if arr[l] > arr[k]:
                break
 
        # swap the elements at arr[k] and arr[l     
        arr[l], arr[k] = arr[k], arr[l]
         
        # reverse the list from k + 1 to the end to find the
        # most nearest greater number to the given input number
        arr[k + 1:] = reversed(arr[k + 1:])
 
    return arr

for i in range(n):
    c = int(input())
    num = [int(x) for x in input().split()]
