class Codec {
public:
    queue<TreeNode*>q;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "#";
        string ans = "";
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(!node)ans+="#,";
            else {
                ans+=to_string(node->val)+",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="#")return nullptr;
        vector<string>d;
        string temp = "";
        int n = data.size();
        for(int i= 0; i < n; i++) {
            if(data[i]==',') {
                d.push_back(temp);
                temp="";
            } else {
                temp+=data[i];
            }
        }
        n = d.size();
        int i = 1;
        TreeNode *root = new TreeNode(stoi(d[0]));
        q.push(root);
        while(i<n and !q.empty()) { 
            TreeNode *curr = q.front();
            q.pop();
            if(d[i]!="#") {
                curr->left = new TreeNode(stoi(d[i]));
                q.push(curr->left);
            }
            i++;
            if(i<n and d[i]!="#") {
                curr->right = new TreeNode(stoi(d[i]));
                q.push(curr->right);
            }
            i++;
        }
        return root;
    }
};
