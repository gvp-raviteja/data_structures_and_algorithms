
/**
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node ) return NULL;
        UndirectedGraphNode *clone,*temp,*head;
        map<int,UndirectedGraphNode *> visit; 
        queue<UndirectedGraphNode *> que;
        if(node!=NULL){
            head = new UndirectedGraphNode(node->label);
            que.push(node);
            visit[node->label] = head;
        }
        while(!que.empty()){
            temp = que.front();
            clone = visit[temp->label];
            que.pop();
            for(int i=0;i<temp->neighbors.size();i++){
                if(visit.find(temp->neighbors[i]->label)==visit.end()){
                    que.push(temp->neighbors[i]);
                    visit[temp->neighbors[i]->label] = new UndirectedGraphNode(temp->neighbors[i]->label);
                }
                clone->neighbors.push_back(visit[temp->neighbors[i]->label]);
            }
        }
        return head;
    }
};
