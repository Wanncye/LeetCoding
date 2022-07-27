#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

int preVal = __INT_MAX__;


bool isBST(TreeNode* root) {
    if(root == NULL) return true;

    bool left, right;

    isBST(root->left);

    if(preVal < root->val) preVal = root->val;
    else return false;

    isBST(root->right);


    return left && right;
}


int main(){
    TreeNode* root = new TreeNode(3);
    TreeNode* l1 = new TreeNode(1);
    TreeNode* r1 = new TreeNode(4);
    TreeNode* rl = new TreeNode(2);
    TreeNode* rr = new TreeNode(6);
    root->left = l1;
    root->right = r1;
    r1->left = rl;
    r1->right = rr;

    cout << isBST(root) << endl;
    return 0;
}





学生：
DROP TABLE IF EXISTS `student`;
CREATE TABLE `student` (
  `sno` int(3) NOT NULL AUTO_INCREMENT COMMENT '主键',
  `sname` varchar(10) NOT NULL COMMENT '姓名',
  `sage` int(4) DEFAULT NULL COMMENT '年龄',
  PRIMARY KEY (`sno`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;
INSERT INTO `student` VALUES ('1', '周杰伦', '18');
INSERT INTO `student` VALUES ('2', '周润发', '18');
INSERT INTO `student` VALUES ('3', '吴孟达', '25');
INSERT INTO `student` VALUES ('4', '刘德华', '25');
INSERT INTO `student` VALUES ('5', '李连杰', '29');

分数：
DROP TABLE IF EXISTS `score`;
CREATE TABLE `score` (
  `sno` int(3) NOT NULL COMMENT '学号主键',
  `cno` int(3) NOT NULL COMMENT '成绩主键',
  `score` int(4) NOT NULL COMMENT '分数'
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;
INSERT INTO `score` VALUES ('1', '1', '60');
INSERT INTO `score` VALUES ('1', '2', '61');
INSERT INTO `score` VALUES ('2', '1', '80');
INSERT INTO `score` VALUES ('2', '2', '70');

课程：
DROP TABLE IF EXISTS `cource`;
CREATE TABLE `cource` (
  `cno` int(3) NOT NULL AUTO_INCREMENT COMMENT '主键',
  `cname` varchar(10) NOT NULL COMMENT '课程名',
  PRIMARY KEY (`cno`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;
INSERT INTO `cource` VALUES ('1', '语文');
INSERT INTO `cource` VALUES ('2', '数学');
INSERT INTO `cource` VALUES ('3', '英语');