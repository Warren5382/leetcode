struct state {
    TreeNode *node;
    int depth;
    state():depth(0),node(NULL) {}
};
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int>> result;
        vector<int> level;
        if(root == NULL) return result;
        queue<state> q;
        state now;
        state next;
        now.depth = 0;
        now.node = root;
        q.push(now);
        while(!q.empty()) {
            now = q.front();
            level.push_back(now.node->val);
            if(now.node->left != NULL) {
                next.node = now.node->left;
                next.depth = now.depth+1;
                q.push(next);
            }
            if(now.node->right != NULL) {
                next.node = now.node->right;
                next.depth = now.depth+1;
                q.push(next);
            }
            q.pop();
            if(q.empty()){
                result.push_back(level);
            }
            else {
                next = q.front();
                if(next.depth!=now.depth) {
                    result.push_back(level);
                    level.clear();
                }
            }
        }
        return result;
    }
};