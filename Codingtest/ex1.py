array =[3, 5, 1, 2, 4] # 5개의 데이터(N = 5)
summary = 0 # 합계를 저장할 변수

# 모든 데이터를 하나씩 확인하며 합계를 계산
for x in array:
    summary += x

# 결과를 출력
print(summary)
# -------------------------------------------------------
array =[3, 5, 1, 2, 4] # 5개의 데이터(N = 5)

for i in array:
    for j in array:
        temp = i*j
        print(temp)
# --------------------------------------------------------
a = dict()
a['홍길동'] = 97
a['이순신'] = 98

print(a)

b = {
   '홍길동' : 97,
   '이순신' : 98
}

print(b)
print(b['이순순'])

key_list = list(b.keys())
print(key_list)