#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) 
    {
        int n = arr.size();
        vector<int> val(n,-1);
        stack<int> s;
        
        for(int i = 0 ;i < n ; i++)
        {
            while(!s.empty() && (arr[i] > arr[s.top()]))
            {
                int index = s.top();
                s.pop();
                val[index] = arr[i];
            }
            s.push(i);
        }
        return val;
    }
};

int main(){
    Solution S;
    vector<int> arr = {1,5,7,9};
    vector<int> out = S.nextLargerElement(arr);
    cout << "Nearest larger elements: ";
    for (int x : out) {
        cout << x << " ";
    }
    cout << endl;
}