#在线困难样本挖掘的代码，收藏一下，感觉在分类任务中也能用到
import torch
import torch.nn as nn

ce_loss=nn.CrossEntropyLoss(reduce=False)

def topK_loss(gt_label, pred_label):
    loss_wise = ce_loss(pred_label, gt_label)
    loss_sorted=loss_wise/loss_wise.sum()
    loss_sorted=loss_sorted.sort(descending=True)
    ratio=0.0
    break_point=0
    for i,v in enumerate(loss_sorted[0]):
        break_point=i
        if ratio>=0.7:
            break
        ratio+=v.data.numpy()
    need_bp=loss_sorted[1][:break_point]
    loss_topk=loss_wise[need_bp].mean()
    
