#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Function to evaluate a Boolean expression
bool evaluateExpression(const string& expr, unordered_map<char, bool>& variables) {
    string expression = expr;
    
    // Replace variables with their boolean values
    for (auto& pair : variables) {
        char var = pair.first;
        bool value = pair.second;
        size_t pos = 0;
        while ((pos = expression.find(var, pos)) != string::npos) {
            expression.replace(pos, 1, value ? "1" : "0");
            pos += 1;
        }
    }

    // Evaluate the expression using bitwise operations
    int result = 0;
    for (char c : expression) {
        if (c == '1') {
            result |= 1;  // OR operation
        } else if (c == '0') {
            result &= ~1; // AND operation
        }
        result <<= 1;
    }
    result >>= 1; // Shift back to correct position
    
    return result != 0;
}

int main() {
    unordered_map<char, bool> variables; // Store variables and their values

    // Example usage:
    variables['A'] = true;
    variables['B'] = false;
    
    // Example Boolean expression
    string expression = "(A & B) | (A ^ B)";

    // Evaluate the expression
    bool result = evaluateExpression(expression, variables);

    // Output the result
    cout << "Result of expression '" << expression << "' is: " << result << endl;

    return 0;
}