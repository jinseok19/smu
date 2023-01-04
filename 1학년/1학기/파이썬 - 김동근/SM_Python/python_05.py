friend = list(map(str, input().split()))

find_friend = input("찾고 싶은 친구 이름을 입력하세요 :")
'''
if find_friend in friend :
    print(find_friend)
else:
    print("못찾았다.")
'''
friend_count = 0

if find_friend in friend:
    for i in range(len(friend)):
      if friend[i] == find_friend:
          friend_count +=1
          if friend_count >=2:
              print(find_friend)
          else:
              print("같은 이름이 없다.")

      