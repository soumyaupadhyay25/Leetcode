#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<string, vector<int>> memo;

    vector<int> diffWaysToCompute(string expression) {
        // If the result for this expression is already computed, return it
        if (memo.find(expression) != memo.end()) {
            return memo[expression];
        }

        vector<int> result;
        int n = expression.size();
        
        // Iterate through the expression to find operators
        for (int i = 0; i < n; ++i) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                // Split the expression into left and right subexpressions
                string leftExpr = expression.substr(0, i);
                string rightExpr = expression.substr(i + 1);

                // Recursively compute all results for left and right parts
                vector<int> leftResults = diffWaysToCompute(leftExpr);
                vector<int> rightResults = diffWaysToCompute(rightExpr);

                // Combine the results from the left and right subexpressions
                for (int left : leftResults) {
                    for (int right : rightResults) {
                        if (c == '+') {
                            result.push_back(left + right);
                        } else if (c == '-') {
                            result.push_back(left - right);
                        } else if (c == '*') {
                            result.push_back(left * right);
                        }
                    }
                }
            }
        }
        
        // If the expression contains only a number, convert it to an integer and return
        if (result.empty()) {
            result.push_back(stoi(expression));
        }

        // Memoize the result for this expression
        memo[expression] = result;
        return result;
    }
};
