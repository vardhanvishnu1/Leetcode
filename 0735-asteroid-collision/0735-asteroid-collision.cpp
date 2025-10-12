class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids) {
            bool destroyed = false;

            // While collision can occur (right-moving asteroid meets left-moving one)
            while (!st.empty() && st.top() > 0 && a < 0) {
                if (st.top() < -a) {
                    // top asteroid is smaller → destroyed
                    st.pop();
                    continue;
                } else if (st.top() == -a) {
                    // both are same → both destroyed
                    st.pop();
                }
                destroyed = true; // current asteroid 'a' destroyed
                break;
            }

            if (!destroyed) {
                st.push(a);
            }
        }

        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};
