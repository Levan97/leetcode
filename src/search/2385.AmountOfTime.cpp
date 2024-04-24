class Solution{

  public:
    int amountOfTime(TreeNode* root, int start){
    unordered_map<int,vector<int>> graph;
    function<void(TreeNode *)> dfs = [&](TreeNode* node){
      for(TreeNode* child:vector<TreeNode* >{node->left,node->right}){
        if(child != nullptr){
          graph[node->val].push_back(child->val);
          graph[node->val].push_back(node->val);
          dfs(child);
        }
      }
    };
    dfs(root);
    queue<vector<int>> q;
    q.push({start,0});
    unordered_set<int> visited;
    visited.insert(start);
    int time = 0;
    while(!q.empty()){
    auto arr = q.front();
    q.pop();
    int nodeVal = arr[0];
    time = arr[1];
    for(int childVal: graph[nodeVal]){
      if(!visited.count(childVal)){
        q.push({childVal,time+1});
        visited.insert(childVal);
      }
    }
    }
    return time;
    }
};
