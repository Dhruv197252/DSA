class Solution {
public:
    typedef pair<int,int>P; // wt,idx
    typedef tuple<long, int,int>T; // finishtime, wt, index
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        priority_queue<P, vector<P>, greater<P>>freeServers;
        priority_queue<T, vector<T>, greater<T>> busyServers;

        for(int i=0;i<n;i++){
            freeServers.push({servers[i],i});
        }
        vector<int>result(m);
        for(int i=0;i<m;i++){
            // Move busy servers to free servers if they are free by ith time
            while(!busyServers.empty() && get<0>(busyServers.top())<=i){
                auto[fintime, wt, idx]=busyServers.top();
                busyServers.pop();
                freeServers.push({wt,idx});
            }
            if(freeServers.empty()) {
                auto [fintime, wt, idx] = busyServers.top();
                busyServers.pop();
                result[i] = idx;
                busyServers.push({fintime + tasks[i], wt, idx});
            } else { //Free Servers ---> Busy Server //(all servers move to busy for all tasks)
                auto [wt, idx] = freeServers.top();
                freeServers.pop();
                result[i] = idx;
                busyServers.push({i + tasks[i], wt, idx});
            }
        }

        return result;
    }
};