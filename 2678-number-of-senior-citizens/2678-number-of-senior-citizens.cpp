class Solution {
public:
    int countSeniors(vector<string>& details) {
        int older_passengers = 0;
        for(auto detail: details){
            string age_str = detail.substr(11, 2);
            int age = stoi(age_str);
            if (age > 60) {
            older_passengers++;
        }
        }

        return older_passengers;
    }
};