# --coding:utf-8--
import numpy as np

# https://blog.csdn.net/qq_27370437/article/details/119569007
# https://zhuanlan.zhihu.com/p/100672008

class MyBN:
    def __init__(self, momentum, eps, num_features):
        """
        初始化参数值
        :param momentum: 追踪样本整体均值和方差的动量
        :param eps: 防止数值计算错误
        :param num_features: 特征数量
        """
        # 对每个batch的mean和var进行追踪统计
        self._running_mean = 0
        self._running_var = 1
        # 更新self._running_xxx时的动量
        self._momentum = momentum
        # 防止分母计算为0
        self._eps = eps
        # 对应论文中需要更新的beta和gamma，采用pytorch文档中的初始化值
        self._beta = np.zeros(shape=(num_features, ))
        self._gamma = np.ones(shape=(num_features, ))

    def batch_norm(self, x):
        """
        BN向传播
        :param x: 数据
        :return: BN输出
        """
        self.x_mean = x.mean(axis=0)
        self.x_var = x.var(axis=0)
        # 对应running_mean的更新公式
        self._running_mean = (1-self._momentum)*self.x_mean + self._momentum*self._running_mean
        self._running_var = (1-self._momentum)*self.x_var + self._momentum*self._running_var
        # 对应论文中计算BN的公式
        self.x_hat = (x-self.x_mean)/np.sqrt(self.x_var+self._eps)
        self.y = self._gamma*self.x_hat + self._beta
        return self.y

    def backward(self,dout):
        '''
        dout:前一层传过来的导数
        '''
        print(dout.shape)
        print(self.x_hat.shape)
        self.dgamma = np.sum(dout * self.x_hat, axis=0)
        self.dbeta = np.sum(dout, axis=0)
        
        dy = dout * self._gamma
        dx = 1/self.x_var * (dy - np.mean(dy, axis=0) - self.x_hat * np.mean(dy * self.x_hat, axis=0))

data = np.array([[1, 2],
                 [1, 3],
                 [1, 4]]).astype(np.float32)
my_bn = MyBN(momentum=0.01, eps=0.001, num_features=2)
bn_output = my_bn.batch_norm(data, )
print(bn_output)
dout = np.random.random((3,2))
my_bn.backward(dout)
