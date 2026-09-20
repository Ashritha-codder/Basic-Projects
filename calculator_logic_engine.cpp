#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

// Stores calculation history
vector<string> history;

// Clears invalid input from the input buffer
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Adds a calculation to history
void addHistory(string result) {
    history.push_back(result);
}

// Displays calculation history
void showHistory() {
    cout << "\n========================================\n";
    cout << "           CALCULATION HISTORY\n";
    cout << "========================================\n";

    if (history.empty()) {
        cout << "No calculations available.\n";
        return;
    }

    for (int i = 0; i < history.size(); i++) {
        cout << i + 1 << ". " << history[i] << endl;
    }
}

// Clears calculation history
void clearHistory() {
    history.clear();
    cout << "\nHistory cleared successfully.\n";
}

// Arithmetic Operations
void arithmetic() {
    int choice;
    double a, b, result;

    cout << "\n========================================\n";
    cout << "          ARITHMETIC OPERATIONS\n";
    cout << "========================================\n";

    cout << "1. Addition (+)\n";
    cout << "2. Subtraction (-)\n";
    cout << "3. Multiplication (*)\n";
    cout << "4. Division (/)\n";
    cout << "5. Modulus (%)\n";
    cout << "6. Back to Main Menu\n";

    cout << "\nEnter your choice: ";

    if (!(cin >> choice)) {
        clearInput();
        cout << "Invalid input. Please enter a number.\n";
        return;
    }

    if (choice == 6)
        return;

    if (choice < 1 || choice > 5) {
        cout << "Invalid choice.\n";
        return;
    }

    cout << "Enter first number: ";
    if (!(cin >> a)) {
        clearInput();
        cout << "Invalid number.\n";
        return;
    }

    cout << "Enter second number: ";
    if (!(cin >> b)) {
        clearInput();
        cout << "Invalid number.\n";
        return;
    }

    switch (choice) {

        case 1:
            result = a + b;
            cout << "\nResult = " << result << endl;
            addHistory(to_string(a) + " + " + to_string(b)
                       + " = " + to_string(result));
            break;

        case 2:
            result = a - b;
            cout << "\nResult = " << result << endl;
            addHistory(to_string(a) + " - " + to_string(b)
                       + " = " + to_string(result));
            break;

        case 3:
            result = a * b;
            cout << "\nResult = " << result << endl;
            addHistory(to_string(a) + " * " + to_string(b)
                       + " = " + to_string(result));
            break;

        case 4:
            if (b == 0) {
                cout << "\nError: Division by zero is not allowed.\n";
            } else {
                result = a / b;
                cout << "\nResult = " << result << endl;
                addHistory(to_string(a) + " / " + to_string(b)
                           + " = " + to_string(result));
            }
            break;

        case 5:
            if ((int)b == 0) {
                cout << "\nError: Modulus by zero is not allowed.\n";
            } else {
                int x = (int)a;
                int y = (int)b;
                int modResult = x % y;

                cout << "\nResult = " << modResult << endl;

                addHistory(to_string(x) + " % " + to_string(y)
                           + " = " + to_string(modResult));
            }
            break;
    }
}

// Relational Operations
void relational() {
    int choice;
    double a, b;
    bool result;

    cout << "\n========================================\n";
    cout << "          RELATIONAL OPERATIONS\n";
    cout << "========================================\n";

    cout << "1. Greater than (>)\n";
    cout << "2. Less than (<)\n";
    cout << "3. Greater than or equal (>=)\n";
    cout << "4. Less than or equal (<=)\n";
    cout << "5. Equal to (==)\n";
    cout << "6. Not equal (!=)\n";
    cout << "7. Back to Main Menu\n";

    cout << "\nEnter your choice: ";

    if (!(cin >> choice)) {
        clearInput();
        cout << "Invalid input.\n";
        return;
    }

    if (choice == 7)
        return;

    if (choice < 1 || choice > 6) {
        cout << "Invalid choice.\n";
        return;
    }

    cout << "Enter first number: ";
    if (!(cin >> a)) {
        clearInput();
        cout << "Invalid number.\n";
        return;
    }

    cout << "Enter second number: ";
    if (!(cin >> b)) {
        clearInput();
        cout << "Invalid number.\n";
        return;
    }

    string operation;

    switch (choice) {

        case 1:
            result = a > b;
            operation = " > ";
            break;

        case 2:
            result = a < b;
            operation = " < ";
            break;

        case 3:
            result = a >= b;
            operation = " >= ";
            break;

        case 4:
            result = a <= b;
            operation = " <= ";
            break;

        case 5:
            result = a == b;
            operation = " == ";
            break;

        case 6:
            result = a != b;
            operation = " != ";
            break;
    }

    cout << "\nResult = " << boolalpha << result << endl;

    addHistory(to_string(a) + operation + to_string(b)
               + " = " + (result ? "true" : "false"));
}

// Logical Operations
void logical() {
    int choice;
    bool a, b;
    bool result;

    cout << "\n========================================\n";
    cout << "            LOGICAL OPERATIONS\n";
    cout << "========================================\n";

    cout << "1. Logical AND (&&)\n";
    cout << "2. Logical OR (||)\n";
    cout << "3. Logical NOT (!)\n";
    cout << "4. Back to Main Menu\n";

    cout << "\nEnter your choice: ";

    if (!(cin >> choice)) {
        clearInput();
        cout << "Invalid input.\n";
        return;
    }

    if (choice == 4)
        return;

    if (choice < 1 || choice > 3) {
        cout << "Invalid choice.\n";
        return;
    }

    if (choice == 3) {

        cout << "Enter value (0 = false, 1 = true): ";

        if (!(cin >> a) || (a != 0 && a != 1)) {
            clearInput();
            cout << "Please enter only 0 or 1.\n";
            return;
        }

        result = !a;

        cout << "\nResult = " << boolalpha << result << endl;

        addHistory("NOT " + string(a ? "true" : "false")
                   + " = " + (result ? "true" : "false"));

        return;
    }

    cout << "Enter first value (0 = false, 1 = true): ";

    if (!(cin >> a) || (a != 0 && a != 1)) {
        clearInput();
        cout << "Please enter only 0 or 1.\n";
        return;
    }

    cout << "Enter second value (0 = false, 1 = true): ";

    if (!(cin >> b) || (b != 0 && b != 1)) {
        clearInput();
        cout << "Please enter only 0 or 1.\n";
        return;
    }

    string operation;

    switch (choice) {

        case 1:
            result = a && b;
            operation = " AND ";
            break;

        case 2:
            result = a || b;
            operation = " OR ";
            break;
    }

    cout << "\nResult = " << boolalpha << result << endl;

    addHistory(string(a ? "true" : "false") + operation
               + string(b ? "true" : "false")
               + " = " + (result ? "true" : "false"));
}

// Main Menu
void displayMenu() {

    cout << "\n\n========================================\n";
    cout << "       CALCULATOR & LOGIC ENGINE\n";
    cout << "========================================\n";

    cout << "1. Arithmetic Operations\n";
    cout << "2. Relational Operations\n";
    cout << "3. Logical Operations\n";
    cout << "4. View Calculation History\n";
    cout << "5. Clear Calculation History\n";
    cout << "6. Exit\n";

    cout << "========================================\n";
    cout << "Enter your choice: ";
}

int main() {

    int choice;

    cout << "\n****************************************\n";
    cout << "   WELCOME TO CALCULATOR & LOGIC ENGINE\n";
    cout << "****************************************\n";

    do {

        displayMenu();

        if (!(cin >> choice)) {
            clearInput();
            cout << "\nInvalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {

            case 1:
                arithmetic();
                break;

            case 2:
                relational();
                break;

            case 3:
                logical();
                break;

            case 4:
                showHistory();
                break;

            case 5:
                clearHistory();
                break;

            case 6:
                cout << "\nThank you for using Calculator & Logic Engine!\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}