#include <iostream>
#include <vector>
#include <algorithm>

typedef struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}s_TreeNode;

#define SPEC 65536

class Solution {
	private: void ldfs(s_TreeNode *root, std::vector<int> &vec){ 
			 if (root==NULL){
				 vec.push_back(SPEC);
				return;
			 }
			vec.push_back(root->val);
			ldfs(root->left, vec);
			ldfs(root->right, vec);
		}
		void rdfs(s_TreeNode *root, std::vector<int> &vec){
			 if (root==NULL){
				 vec.push_back(SPEC);
				return;
			 }
			vec.push_back(root->val);
			rdfs(root->right, vec);
			rdfs(root->left, vec);
		}
	public:
		bool isSymmetric(s_TreeNode* root) {
			//check left child and right child, if the same go
			if(root == NULL)
				return true;
			if(root->left == NULL&&root->right == NULL)
				return true;
			else if(root->left==NULL)
				return false;
			else if(root->right==NULL)
				return false;
			if(root->left->val !=root->right->val)
				return false;
			//search left tree using DFS
			std::cout<<"stp1"<<"\n";
			s_TreeNode *left = root->left;
			s_TreeNode *right = root->right;
			std::vector<int> lvec;
			std::vector<int> rvec;
			ldfs(left,lvec);
			rdfs(right,rvec);
			if(lvec.size()!=rvec.size())
				return false;
			for(auto it=lvec.begin(); it!=lvec.end(); it++){
				auto dist = it-lvec.begin();
				std::cout<<"left"<<*it<<" \n";
				std::cout<<"right"<<*(rvec.begin()+dist)<<" \n";
				if(*it!=*(rvec.begin()+dist))
					return false;
			}
			return true;
		}
};

int main(){
	s_TreeNode n1(1);
	s_TreeNode n2(2);
	s_TreeNode n3(2);
	s_TreeNode n4(3);
	s_TreeNode n5(3);

	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n3.left = &n5;
	Solution s;
	s.isSymmetric(&n1);
}
