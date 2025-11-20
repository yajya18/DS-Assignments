class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<bool> found(temperatures.size(), false);
        vector<int> answer;
        for(int i=0;i<temperatures.size();i++){
            for(int j=i+1;j<temperatures.size();j++){
                if(temperatures[j]>temperatures[i]) {
                    found[i] = true;
                    answer.push_back(j-i);
                    break;
                }
            }
            if(!found[i]) {
                answer.push_back(0);
                found[i] = true;
            }
        }
        return answer;
    }
};