print("Hello, Python!")
num = int(input("please input a number:\n"))
start = 1
end = 100
cnt = 0
while start <= end:
    mid = start + (end - start)/2
    cnt = cnt + 1
    print('I guess %d' %mid)
    if mid == num:
        print("input is %d" %num)
        break
    elif mid > num:
        end = mid - 1
    else:
        start = mid + 1
print('cnt is %d' %cnt)    