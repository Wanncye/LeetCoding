import matplotlib.pyplot as plt
import numpy as np

# t为句子中的单词长度
seq_len = 5
# d 为词向量的编码长度,为了方便看,把维度变小了
d = 10

x = np.linspace(0, d-1, d)
y = [[] for _ in range(seq_len)]
print(x)
index = 0
for t in range(seq_len):
    for i in range(d):
        if i % 2 == 0:
            index = i//2
            y[t].append(np.sin(t/((10000)**(2*index/d))))
        else:
            y[t].append(np.cos(t/((10000)**(2*index/d))))
    
    plt.plot(x, y[t],label=f"t={t}")
    plt.xticks(np.arange(d))
    plt.ylim(-1, 1)
    plt.xlabel('depth')
    plt.ylabel('t')
    plt.legend() 
plt.show()
