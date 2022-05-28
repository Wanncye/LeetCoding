class Tree():
    def __init__(self,x):
        self.value=x
        self.left=None
        self.right=None
class Solution():
    def resolution(self,preorder,inorder):
        if not preorder:
            return None
        root = Tree(preorder[0])
        pos_root = inorder.index(preorder[0])
        root.left=self.resolution(preorder[1:pos_root+1],inorder[0:pos_root])
        root.right = self.resolution(preorder[pos_root+1:],inorder[pos_root+1:])
        return root
    def postTravel(self,root):
        if root !=None:
            self.postTravel(root.left)
            self.postTravel(root.right)
            print(root.value)
pre=[1,2,4,7,3,5,6,8]
tin=[4,7,2,1,5,3,8,6]
S=Solution()
root=S.resolution(pre,tin)
S.postTravel(root)