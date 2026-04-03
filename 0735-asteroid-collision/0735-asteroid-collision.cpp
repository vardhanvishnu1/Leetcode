
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int curr : asteroids) {
            bool destroyed = false;

            // Collision only happens if top is moving RIGHT (+) and current is moving LEFT (-)
            while (!st.empty() && st.top() > 0 && curr < 0) {
                if (abs(st.top()) < abs(curr)) {
                    // Top is smaller: Top explodes, current keeps moving
                    st.pop();
                    continue; 
                } else if (abs(st.top()) == abs(curr)) {
                    // Both are equal: Both explode
                    st.pop();
                    destroyed = true;
                    break;
                } else {
                    // Top is larger: Current explodes
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push(curr);
            }
        }

        // Convert stack to vector
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};