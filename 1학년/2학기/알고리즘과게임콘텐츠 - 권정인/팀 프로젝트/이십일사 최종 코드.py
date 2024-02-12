
def menu_select():
    print("\n==================================메    뉴==================================")
    print("1. 단어장 보기  2. 단어 추가하기  3. 단어 삭제하기  4. 시험보기  5. 종료하기")
    print("============================================================================")
    num=int(input("실행할 기능의 번호를 누르세요 : "))
    
    return num


def main_menu(data):
    while True:
        num = menu_select()
        if num == 1:
            if len(data) == 0:
                print("[단어장이 비어 있습니다. 단어를 추가해주세요]")
            else:

                while True:
                    print(data)

                    num_read = input("메뉴로 돌아가려면 y를 누르세요 : ")
                    if num_read == 'y':
                        break

        elif num == 2:
            while True:
                print("\n1.단어 추가하기 \t 2.메뉴로 돌아가기")
                num_add=int(input("실행할 기능의 번호를 누르세요 : "))
                
                if num_add == 1:
                    eng , kor = input("영어 한글 형식으로 입력 : ").split()
                    if eng in data:
                        print("이미 단어가 있습니다. 단어의 뜻이 업데이트 되었습니다.")
                        data[eng] = kor
                    data[eng] = kor

                elif num_add ==2:
                    break
                    
        elif num ==3:
            while True:
                print("\n1. 영어로 삭제하기  2. 메뉴로 돌아가기")
                num_del=int(input("실행할 기능의 번호를 누르세요 : "))
                if num_del == 1:
                    
                        del_word=input("삭제할 영어 단어 입력 : ")
                        if del_word not in data:
                            print("삭제할 단어가 없습니다.")
                            continue
                        print("{0}가(이) 삭제되었습니다.".format(del_word))
                        del data[del_word]
                       
                    
                        
                   

                elif num_del == 2:
                    break


        elif num ==4:
            while True:
                print("\n1. 한글 시험  2. 영어 시험  3. 메뉴로 돌아가기") # 시험 문항 수 정하고 채점까지
                num_test = int(input("실행할 기능의 번호를 누르세요 : "))

                if num_test == 1:
                    
                    user_answer = [] # 사용자의 정답 입력 받는 list
                    check_list = [] # 답을 확인하는 리스트
                    O = X = 0 # 정답이면 O 틀리면 X의 개수를 늘림
                    i = 0
                    for key in data.keys(): # 영어
                        i+=1
                        User=input("{0}. {1} : ".format(i, key)) # ex: 1. english : 
                        user_answer.append(User) # 그 결과를 사용자 리스트에 추가
                    
                    
                            
                    for i, check in enumerate(data.values()): # enumerate 함수 설명 : data dict의 값을 인덱스와 값으로 출력(인덱스, data.values(한글))
                        check_list.append(check) # 값은 정답 리스트에 추가
                        if user_answer[i] == check: # 사용자 입력 값과 답이 값으면
                            O += 1 
                        else:
                            X += 1
                    
                    
                    print("맞은 문항 수 {0}개 틀린 문항 수 {1}입니다.".format(O, X))
                    num_result = int(input("1. 제출 및 답 보기  2. 메뉴로 돌아가기\n실행할 기능의 번호를 누르세요 : "))

                    if num_result == 1:

                        print("[[[내 제출 및 답 보기]]]")
                        print("내 제출 : {0}".format(user_answer))
                        print("답 : {0}".format(check_list))

                    elif num_result == 2:
                        break
       
                elif num_test == 2: # 위에 부분과 동일
                    
                        O = X = 0
                        user_answer = []
                        check_list = []
                        
                        i = 0
                        for key in data.values():
                            i+=1
                            User=input("{0}. {1} : ".format(i, key))
                            user_answer.append(User)
                        
                        
                        for i, check in enumerate(data.keys()):
                            check_list.append(check)
                            if user_answer[i] == check:
                                O += 1
                            else:
                                X += 1
                            
                        print("맞은 문항 수 {0}개 틀린 문항 수 {1}".format(O, X))
                        num_result = int(input("1. 제출 및 답 보기 \t 2. 메뉴로 돌아가기\n실행할 기능의 번호를 누르세요 : "))

                        if num_result == 1:

                            print("[[[내 제출 및 답 보기]]]")
                            print("내 제출 : {0}".format(user_answer))
                            print("답 : {0}".format(check_list))
                            
                        elif num_result == 2:
                            break

                    
                elif num_test == 3:
                    break

        elif num==5:
            print("[나만의 영단어 사전을 종료합니다.]")
            break

data = {}
main_menu(data)

