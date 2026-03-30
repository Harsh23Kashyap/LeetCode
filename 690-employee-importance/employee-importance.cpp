/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
int pass(unordered_map<int, Employee*> &u, int id){

    int val=0;

    Employee* curr=u[id];
    val+=curr->importance;
    for(auto it:curr->subordinates){
        val+=pass(u,it);
    }
    return val;
}
    int getImportance(vector<Employee*> employees, int id) {
        
        unordered_map<int, Employee*> u;

        for(auto it:employees){
            u[it->id]=(it);
        }

        return pass(u,id);
    }
};