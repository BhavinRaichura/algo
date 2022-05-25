// gfg
//  Job Sequencing Problem 
// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

error
// Isme ek condition missed ho gayi hai
// isme jo job me profit jyada hai vo job priority ke sath hogi but
// agar kisi job ki deadline near hai aur us time pr koi aur job ki current deadline nahi hai to 
// jiski deadline near hai use pahele complete kr sakta hu bhale uska profit km ho   

//------------------------------------------------method 1 ---using sort according to sorting function sort(dead-line, and profit)

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        // soring me function laga kr dead-line and profit ke base pr sort krna hai 
        sort(arr,arr+n,[](Job j1,Job j2){
            if(j1.dead==j2.dead) return j1.profit > j2.profit;
            return j1.dead<j2.dead;
        });
        
        priority_queue<int,vector<int>,greater<int>>q;
        for (int i=0;i<n;i++){
            if(arr[i].dead> q.size()){
                q.push(arr[i].profit);
            }
            else if(q.top()< arr[i].profit){
                q.pop();
                q.push(arr[i].profit);
            }
        }
        int cnt = 0, profit = 0;
        while (!q.empty()) {
            cnt++;
            profit += q.top();
            q.pop();
        }
        return {cnt, profit};
    }

};

//---------------------------------------------------------------------method 2 -- normal sorting
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        // your code here
        priority_queue<int,vector<int>,greater<int>>q;
        vector<pair<int, int>> a;
        for (int i=0;i<n;i++){
            a.push_back({arr[i].dead,arr[i].profit});
        }
        
        sort(a.begin(),a.end());
       
        for (int i=0;i<n;i++){
            if(q.size()<a[i].first){
                q.push(a[i].second);
            }
            else if(q.top()<a[i].second){
                q.pop();
                q.push(a[i].second);
            }
        }
        
        vector<int>ans(2);
        ans[0]=0;
        ans[1]=0;

        while(!q.empty()){
            ans[0]++;
            ans[1]+=q.top();
            q.pop();
        }
         

        return ans;

    }

};

/*

//------------------------------------------- practice kia tha kuchh errors hai  
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        // your code here
        stack<pair<int,int>>st;
        vector<pair<int, int>> a;
        for (int i=0;i<n;i++){
            a.push_back({arr[i].profit,arr[i].dead});
        }
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        int cnt =0;

        for (int i=0;i<n;i++){
            
            if(!st.empty()){
                if (cnt < a[i].second){
                    st.push(a[i]);
                    cnt++;
                    
                }
            }
            else{
                st.push(a[i]);
                cnt++;
            }
            
            
        }
        vector<int>ans(2);
        ans[0]=0;
        ans[1]=0;

        while(!st.empty()){
            ans[0]++;
            ans[1]+=st.top().first;
            st.pop();
        }
         

        return ans;

    }
};
*/
