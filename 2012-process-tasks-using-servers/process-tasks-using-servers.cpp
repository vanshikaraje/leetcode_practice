
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> freeServers;

        // {finish time, server index}
        priority_queue<pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>> busyServers;

        for(int i = 0; i < n; i++) {
            freeServers.push({servers[i], i});
        }

        vector<int> ans(m);
        long long time = 0;

        for(int j = 0; j < m; j++) {

            time = max(time, (long long)j);

            // Release all servers available at current time
            while(!busyServers.empty() &&
                  busyServers.top().first <= time) {

                int idx = busyServers.top().second;
                busyServers.pop();

                freeServers.push({servers[idx], idx});
            }

            // If no server is free, move time forward
            if(freeServers.empty()) {
                time = busyServers.top().first;

                while(!busyServers.empty() &&
                      busyServers.top().first <= time) {

                    int idx = busyServers.top().second;
                    busyServers.pop();

                    freeServers.push({servers[idx], idx});
                }
            }

            // Select the best server
            auto [weight, idx] = freeServers.top();
            freeServers.pop();

            ans[j] = idx;

            // Mark server as busy
            busyServers.push({time + tasks[j], idx});
        }

        return ans;
    }
};
