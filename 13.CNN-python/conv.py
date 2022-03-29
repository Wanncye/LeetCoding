# --coding:utf-8--
# https://blog.csdn.net/u012684062/article/details/78267847
import numpy as np

def conv_forward_naive(x, w, b, conv_param):
	"""
	A naive implementation of the forward pass for a convolutional layer.
	The input consists of N data points, each with C channels, height H and width
	W. We convolve each input with F different filters, where each filter spans
	all C channels and has height HH and width HH.
	Input:
	- x: Input data of shape (N, C, H, W)
	- w: Filter weights of shape (F, C, HH, WW)
	- b: Biases, of shape (F,)
	- conv_param: A dictionary with the following keys:
	- 'stride': The number of pixels between adjacent receptive fields in the
		horizontal and vertical directions.
	- 'pad': The number of pixels that will be used to zero-pad the input.
	Returns a tuple of:
	- out: Output data, of shape (N, F, H', W') where H' and W' are given by
	H' = 1 + (H + 2 * pad - HH) / stride
	W' = 1 + (W + 2 * pad - WW) / stride
	- cache: (x, w, b, conv_param)
	"""
	out = None
	N,C,H,W = x.shape
	F,_,HH,WW = w.shape
	S = conv_param['stride']
	P = conv_param['pad']
	Ho = 1 + (H + 2 * P - HH) / S
	Wo = 1 + (W + 2 * P - WW) / S
	x_pad = np.zeros((N,C,H+2*P,W+2*P))
	x_pad[:,:,P:P+H,P:P+W]=x
	out = np.zeros((N,F,Ho,Wo))

	for f in range(F):   #F个卷积核	
		for i in range(Ho):
			for j in range(Wo):
				# N*C*HH*WW, C*HH*WW = N*C*HH*WW, sum -> N*1
				# tmp1=x_pad[:, :, i*S : i*S+HH, j*S : j*S+WW]
				# print(tmp1.shape)
				# tmp2=w[f, :, :, :]
				# print(tmp2.shape)
				out[:,f,i,j] = np.sum(x_pad[:, :, i*S : i*S+HH, j*S : j*S+WW] * w[f, :, :, :], axis=(1, 2, 3)) 
		out[:,f,:,:]+=b[f]
	cache = (x, w, b, conv_param)
	return out, cache

def conv_backward_naive(dout, cache):
	"""
	A naive implementation of the backward pass for a convolutional layer.
	Inputs:
	- dout: Upstream derivatives.
	- cache: A tuple of (x, w, b, conv_param) as in conv_forward_naive
	Returns a tuple of:
	- dx: Gradient with respect to x
	- dw: Gradient with respect to w
	- db: Gradient with respect to b
	"""
	dx, dw, db = None, None, None

	N, F, H1, W1 = dout.shape
	x, w, b, conv_param = cache
	N, C, H, W = x.shape
	HH = w.shape[2]
	WW = w.shape[3]
	S = conv_param['stride']
	P = conv_param['pad']


	dx, dw, db = np.zeros_like(x), np.zeros_like(w), np.zeros_like(b)
	x_pad = np.pad(x, [(0,0), (0,0), (P,P), (P,P)], 'constant') #pad(array, pad_width, mode, **kwargs), pad_width——表示每个轴（axis）边缘需要填充的数值数目。
	# print(x.shape)
	# print(x_pad.shape)
	dx_pad = np.pad(dx, [(0,0), (0,0), (P,P), (P,P)], 'constant')
	print(dout)
	db = np.sum(dout, axis=(0,2,3))
	print(db)

	for n in range(N):
		for i in range(H1):
			for j in range(W1):
				# Window we want to apply the respective f th filter over (C, HH, WW)
				x_window = x_pad[n, :, i * S : i * S + HH, j * S : j * S + WW]
				for f in range(F):
					dw[f] += x_window * dout[n, f, i, j] #F,C,HH,WW
					#C,HH,WW
					dx_pad[n, :, i * S : i * S + HH, j * S : j * S + WW] += w[f] * dout[n, f, i, j]

	dx = dx_pad[:, :, P:P+H, P:P+W]

	return dx, dw, db

x_shape = (2, 3, 4, 4)
w_shape = (2, 3, 3, 3)
x = np.ones(x_shape)
w = np.ones(w_shape)
b = np.array([1,2])
 
conv_param = {'stride': 1, 'pad': 0}
 
Ho = (x_shape[3]+2*conv_param['pad']-w_shape[3])/conv_param['stride']+1
Wo = Ho
 
dout = np.ones((x_shape[0], w_shape[0], Ho, Wo))
 
out, cache = conv_forward_naive(x, w, b, conv_param)
dx, dw, db = conv_backward_naive(dout, cache)
 
print("out shape",out.shape)
print("dw==========================")
print(dw.shape)
print("dx==========================")
print(dx.shape)
print("db==========================")
print(db.shape)