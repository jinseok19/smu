
name = input('이름을 입력하세요:')
address = input('주소를 입력하세요:')
hobby = input('취미를 입력하세요:')
print('안녕! {0} 님 반갑습니다!'.format(name))
print('{0} 님은 {1} 에 사시는군요.'.format(name, address))
print('{0} 님은 {1}를 좋아하는군요!'.format(name, hobby))


radius = 10
pi = 3.14159
print('반지름이', radius, ' 인 원의 넓이:',  radius*radius*pi)
radius += 10
print('반지름이', radius, ' 인 원의 넓이:',  radius*radius*pi)
radius +=10
print('반지름이', radius, ' 인 원의 넓이:',  radius*radius*pi)
radius +=10
print('반지름이', radius, ' 인 원의 넓이:',  radius*radius*pi)
radius +=10
print('반지름이', radius, ' 인 원의 넓이:',  radius*radius*pi)
