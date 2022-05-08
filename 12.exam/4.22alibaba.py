
# # --coding:utf-8--


# # s = input()
# # print(s)

# chessBoard = ["...",".*$",".$."]
# op = "WDSDA"
# # 不会处理输入

# # 获取初始的位置
# def getPos(chessBoard):
#     for i in range(len(chessBoard)):
#         for j in range(len(chessBoard[i])):
#             if chessBoard[i][j] == '*':
#                 posX = i
#                 posY = j
#     return posX, posY

# posX, posY = getPos(chessBoard)
# ans = 0
# print(chessBoard)
# for i in range(len(op)):
#     subOp = op[i]
#     if subOp == 'W' and posX - 1 >= 0:
#         posX = posX - 1
#     if subOp == 'A' and posY - 1 >= 0:
#         posY = posY - 1
#     if subOp == 'S' and posX + 1 < len(chessBoard):
#         posX = posX + 1
#     if subOp == 'D' and posY + 1 < len(chessBoard):
#         posY = posY + 1  
#     if chessBoard[posX][posY] == '$':
#         ans = ans + 1
#         chessBoard[posX][posY].replace("$",".")
#     print(chessBoard)
# print(ans)




# def lengthOfLIS(nums):
#     if len(nums) <= 1:
#         return len(nums)
#     dp = [1] * len(nums)
#     result = 0
#     for i in range(1, len(nums)):
#         for j in range(0, i):
#             if nums[i] > nums[j]:
#                 dp[i] = max(dp[i], dp[j] + 1)
#         result = max(result, dp[i]) #取长的子序列
#     return result

# nums = [1,3,1,2,4,5]
# subLen = lengthOfLIS(nums)
# print(len(nums)-subLen)

a = ".$."
a[1] = "*"
print(a)

chessBoard = ["...",".*$",".$."]

chessBoard2 = [['.','.','.'],[],[]]