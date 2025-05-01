#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

// Function to check if the parentheses in a string are valid
bool isValidParentheses(const std::string& s) {
    std::stack<char> charStack;
    // Map to store matching closing brackets for opening brackets
    std::unordered_map<char, char> bracketMap = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            charStack.push(c);
        }
        // If it's a closing bracket
        else if (bracketMap.count(c)) {
            // Check if the stack is empty or the top doesn't match
            if (charStack.empty() || charStack.top() != bracketMap[c]) {
                return false;
            }
            charStack.pop(); // Matched, pop the opening bracket
        }
    }

    // If the stack is empty at the end, all brackets were matched correctly
    return charStack.empty();
}

int main() {
    std::string test1 = "([]{{()}})";
    std::string test2 = "({{}}[";
    std::string test3 = "(){";
    std::string test4 = "[][{}]";

    std::cout << test1 << ": " << (isValidParentheses(test1) ? "true" : "false") << std::endl;
    std::cout << test2 << ": " << (isValidParentheses(test2) ? "true" : "false") << std::endl;
    std::cout << test3 << ": " << (isValidParentheses(test3) ? "true" : "false") << std::endl;
    std::cout << test4 << ": " << (isValidParentheses(test4) ? "true" : "false") << std::endl;

}