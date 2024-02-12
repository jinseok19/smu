def up(target, now):
    
    for i in range(now, target+1):
        print("현재 {0} 층 입니다.".format(i))

    print("{0} 층에 도착했습니다.".format(target))
    
        
def down(target, now):
    
    for i in range(now, target-1,-1):
        print("현재 {0} 층 입니다.".format(i))

    print("{0} 층에 도착했습니다. goodbye".format(target))
    
        
target=int(input("도착 층:"))
now=int(input("현재 층:"))

if target == now or target<1 or target>6 or now<1 or now>6:
    print("다른 층 선택하세요.")

elif target > now:
    up(target, now)
else:
    down(target, now)
