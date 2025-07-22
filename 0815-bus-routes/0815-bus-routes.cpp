class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
        if (source == target)
            return 0;

        map<int, vector<int>> stopToRoutes;

        for (int i = 0; i < routes.size(); i++) {
            for (auto stop : routes[i]) {
                stopToRoutes[stop].push_back(i);
            }
        }

        queue<int> q;
        set<int> seenBus;

        for (auto bus : stopToRoutes[source]) {
            q.push(bus);
            seenBus.insert(bus);
        }

        int Bustaken = 1;

        while (!q.empty()) {
            int qsize = q.size();

            for (int i = 0; i < qsize; i++) {
                int currBus = q.front();
                q.pop();

                for (auto stop : routes[currBus]) {
                    if (stop == target)
                        return Bustaken;

                    for (auto bus : stopToRoutes[stop]) {
                        if (seenBus.find(bus) == seenBus.end()) {
                            q.push(bus);
                            seenBus.insert(bus);
                        }
                    }
                }
            }

            Bustaken++;
        }

        return -1;
    }
};