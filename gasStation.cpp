/* There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1. */

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i=0;
        int index;
        int diff =  INT_MIN;
        int count = 0, circle = 0,c=0;
        int n = gas.size();
        while(count<n){
            if(gas[i]-cost[i]>=0){
                index = i;
                diff = gas[i]-cost[i];
                circle = 1;
                while(diff>=0 && circle < n){
                    i = (i+1)%n;
                    diff = diff + gas[i]-cost[i];
                    circle++;
                    count++;
                }
                if(diff>=0 && circle == n)
                    return index; 
            }
            i++;
            count++;
        } 
        return -1;
    }
};
