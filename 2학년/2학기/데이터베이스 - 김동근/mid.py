import pymysql


def print_row(result):
    for re in result:
        print(re)
    print()


# 데이터베이스명은 변경하지 말아주세요
# 데이터베이스 이름은 counsel 입니다
def connect():
    conn = pymysql.Connect(host="localhost", user="root", password="root", database="counsel", port=3305)
    return conn.cursor(), conn


cursor, conn = connect()


# Select_Data(sql)함수 내용은 변경하지 말아주세요
def Select_Data(sql):
    global conn, cursor
    cursor.execute(sql)
    result_data = cursor.fetchall()
    print_row(result_data)


# 문항별로 함수를 추가하여 작성해주세요
# 1번 문항
def exam1():
    # 아래 sql구문은 예제입니다. 문항에 맞는 구문으로 작성해주세요
    exam_sql_1 = "select stu_name, stu_dept, stu_grade, stu_scholar from student where stu_scholar >= 1000000"
    # 함수 이름은 변경하지 말아주세요
    Select_Data(exam_sql_1)

# 2번 문항
def exam2():
    # 아래 sql구문은 예제입니다. 문항에 맞는 구문으로 작성해주세요
    exam_sql_2 = "select counsel_stu, counsel_prof, counsel_datetime, counsel_room, counsel_note from counsel where counsel_datetime > '2022-10-1'"
    # 함수 이름은 변경하지 말아주세요
    Select_Data(exam_sql_2)

# 3번 문항
def exam3():
    exam_sql_3 = "select count(*) as '상담횟수 합게' from counsel"

    Select_Data(exam_sql_3)


# 4번 문항
def exam4():
    exam_sql_4 = "select counsel_stu, count(*) as '상담시행 총횟수' from counsel group by counsel_stu"

    Select_Data(exam_sql_4)


# 5번 문항
def exam5():
    select_sql_5 = "select counsel_prof, counsel_stu, count(*) from counsel group by counsel_prof,counsel_stu"

    Select_Data(select_sql_5)


# 6번 문항
def exam6():
    select_sql_6 = "select counsel.counsel_prof, professor.prof_dept, counsel.counsel_datetime, counsel.counsel_note from counsel,professor " \
                   "where counsel.counsel_stu = '김이선' and counsel.counsel_prof = professor.prof_name"

    Select_Data(select_sql_6)

# 함수 호출입니다. 작성한 문항별로 함수 호출해주세요
exam1()
exam2()
exam3()
exam4()
exam5()
exam6()



