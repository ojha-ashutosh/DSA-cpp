vector<int> problem2(vector<int>v){
//     int n=v.size();
//     reverse(v.begin(),v.end());
//     vector<int>res(n,-1);
//     stack<int>s;//push index
//     s.push(0); 
//     for(int i=1;i<n;i++){
//         while(!s.empty()&& v[s.top()]<v[i]){
//             res[s.top()]=v[i];
//             s.pop();
//         }
//         s.push(i);
//     }
//     reverse(res.begin(),res.end());
//     return res;
// }