import numpy as np
def NMS(dects,threshhold):
    """
    detcs:二维数组(n_samples,5)
    5列：x1,y1,x2,y2,score
    threshhold: IOU阈值
    """
    x1=dects[:,0]
    y1=dects[:,1]
    x2=dects[:,2]
    y2=dects[:,3]
    score=dects[:,4]
    ndects=dects.shape[0]#box的数量
    area=(x2-x1+1)*(y2-y1+1)
    order=score.argsort()[::-1] #score从大到小排列的indexs,一维数组
    keep=[] #保存符合条件的index
    suppressed=np.array([0]*ndects) #初始化为0，若大于threshhold,变为1，表示被抑制
    
    for _i in range(ndects):
        i=order[_i]  #从得分最高的开始遍历
        if suppressed[i]==1:
            continue
        keep.append(i) 
        for _j in range(i+1,ndects):
            j=order[_j]
            if suppressed[j]==1: #若已经被抑制，跳过
                continue
            xx1=np.max(x1[i],x1[j])#求两个box的交集面积interface
            yy1=np.max(y1[i],y1[j])
            xx2=np.min(x2[i],x2[j])
            yy2=np.min(y2[i],y2[j])
            w=np.max(0,xx2-xx1+1)
            h=np.max(0,yy2-yy1+1)
            interface=w*h
            overlap=interface/(area[i]+area[j]-interface) #计算IOU（交/并）
            
            if overlap>=threshhold:#IOU若大于阈值，则抑制
                suppressed[j]=1
    return keep