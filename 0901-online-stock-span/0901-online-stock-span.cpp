#include <stack>
#include <utility>

class StockSpanner {
private:
    // Stack stores pairs of {price, span}
    std::stack<std::pair<int, int>> s;

public:
    StockSpanner() {}
    
    int next(int price) {
        int span = 1;
        // While stack is not empty and current price is higher than the top
        while (!s.empty() && s.top().first <= price) {
            // Add the span of the smaller/equal price to the current span
            span += s.top().second;
            s.pop();
        }
        // Push the current price and its total accumulated span
        s.push({price, span});
        
        return span;
    }
};
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */