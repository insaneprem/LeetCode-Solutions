class Solution {
public:
    void moon(int src, vector<int>& dist,vector<int>& edges) {
        int step = 0;

        while (src != -1 && dist[src] == INT_MAX) {
            dist[src] = step++;
            src = edges[src];
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> duri1(n, INT_MAX), duri2(n, INT_MAX);

        moon(node1, duri1, edges);
        moon(node2, duri2, edges);

        int chand = -1;
        int meh = INT_MAX;

        
        for (int i = 0; i < n; i++) {
            if (duri1[i] == INT_MAX || duri2[i] == INT_MAX) continue;
            int woh = max(duri1[i], duri2[i]);
            if (woh < meh) {
                meh = woh;
                chand = i;
            }
        }

        return chand;
    }
};
