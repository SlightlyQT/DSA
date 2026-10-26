class Solution {
public:

    vector<int> calender = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int datetonum(pair<int, int> x){
        if (x.first == 1){
            return x.second;
        }
        int ret = 0;
        for (int i=0; i<x.first-1; i++){
            ret += calender[i];
        }

        return ret+x.second;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        pair<int, int> aa = {stoi(arriveAlice.substr(0,2)), stoi(arriveAlice.substr(3,2))};
        pair<int, int> la = {stoi(leaveAlice.substr(0,2)), stoi(leaveAlice.substr(3,2))};
        pair<int, int> ab = {stoi(arriveBob.substr(0,2)), stoi(arriveBob.substr(3,2))};
        pair<int, int> lb = {stoi(leaveBob.substr(0,2)), stoi(leaveBob.substr(3,2))};

        int start = max(datetonum(aa), datetonum(ab));
        int end = min(datetonum(la), datetonum(lb));

        return max(0, end-start+1);
    }
};