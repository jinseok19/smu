# 읽고 쓰기 함수
# 파일 겍체
# 파일로 만들고 저장된다.
import time

def FileTest():
    
    inFile = None
    inList = []
    inString = ""
    time_start = time.time()
    inFile = open('rlawlstjr.txt','r')
    inList = inFile.readlines()

    for inString in inList:
        print(inString, end="")


    inFile.close()
    time_end = time.time()
    return time_start,time_end
#FileTest()

def FileTest2():
    outFile = None
    outString = ''
    outFile = open('0519124.txt','w',encoding='utf8')
    
    while True:
        outString = input("\n메모하세요:")
        
        if outString !="":
            outFile.writelines(outString+"\n")
        else:
            break
    outFile.close()

#FileTest2()

def FileTest11():
  inFile = None
  inString = ""
  inlist = []
  inFile = open('rlawlstjr.txt', 'r')
  inlist = inFile.readlines()
  
  for inString in inlist:
    print(inString, end="")
  
  inFile.close()
  
#FileTest11()
  
def FIleTest22():
  outFile = None
  outString = ""
  outFile = open('rlawlstjr11.txt','w')
  
  while True:
    outString = input()
    
    if outString !="":
      outFile.writelines(outString+'\n')
    else:
      break
  outFile.close()
FIleTest22()