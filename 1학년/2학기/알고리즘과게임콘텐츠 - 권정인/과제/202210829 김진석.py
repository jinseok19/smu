drink = {'커피음료':7,'펜':3,'종이컵':2, 
        '우유':1,'콜라':4,'책':5}

print('제고품목 :',drink.keys())
goods=input('재고 수량을 알고 싶은 품목 입력 :')

print('{0}의 재고 숫자는 {1} 입니다.'.format(goods,drink[goods]))
