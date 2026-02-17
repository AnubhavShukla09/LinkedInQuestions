class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0); // store exclusive time
        stack<int> st;         // track running functions
        int prevTime = 0;      // last processed timestamp
        for(string &log : logs) {
            // parse log: id:start/end:time
            int first = log.find(':');
            int second = log.find(':', first + 1);
            int id = stoi(log.substr(0, first));
            string type = log.substr(first + 1, second - first - 1);
            int time = stoi(log.substr(second + 1));
            // start of function
            if(type == "start") {
                // if some function already running → update its time
                if(!st.empty()) {
                    res[st.top()] += time - prevTime;
                }
                st.push(id);      // start new function
                prevTime = time;  // update previous time
            }
            // end of function
            else {
                // update current function time (+1 because inclusive)
                res[st.top()] += time - prevTime + 1;
                st.pop();          // function finished
                prevTime = time + 1; // next time starts after this
            }
        }
        return res;
    }
};
