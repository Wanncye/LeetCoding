import numpy as np
 
m = 'HELLO'  #明文
a = np.matrix([[1,2,3],[1,1,2],[0,1,2]])  #密钥LCTFXZUHR
num_m = []
temp = []
count = 1
for i in m:  #将明文分为三个一组
    temp.append(ord(i)-ord('A'))
    if count % 3 == 0:
        num_m.append(temp)
        temp = []
    count += 1
mat_m = [np.matrix(i).T for i in num_m]  #将明文分组转换为向量形式
mat_c = [a * i % 26 for i in mat_m]  #得到密文分组的向量形式
num_c = []
temp = []
for i in mat_c:  #将密文向量转换为列表形式，且合并到一个列表
    temp = i.tolist()
    for j in range(3):
        num_c.append(temp[j][0])
c = [chr(i+ord('A')) for i in num_c]
print(''.join(c))  #连接成字符串,输出密文