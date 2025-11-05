#include <iostream>
#include <string>
using namespace std;

int main() {
    int choice;

    do {
        cout << "\nChoose an operation to perform:\n";
        cout << "1. Check if input is a numeric constant\n";
        cout << "2. Identify operators in an expression\n";
        cout << "3. Check if input is a comment\n";
        cout << "4. Validate an identifier\n";
        cout << "5. Calculate average of numbers\n";
        cout << "6. Find min and max value from array\n";
        cout << "7. Concatenate First Name and Last Name\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Check if input is numeric constant
                string input;
                bool isNumeric = true;
                cout << "Enter something: ";
                cin >> input;
                for (int i = 0; i < input.length(); i++) {
                    if (input[i] < '0' || input[i] > '9') {
                        isNumeric = false;
                        break;
                    }
                }
                if (isNumeric)
                    cout << "This is a numeric constant." << endl;
                else
                    cout << "This is not numeric." << endl;
                break;
            }

            case 2: {
                // Identify operators in an expression
                string input;
                cout << "Enter an expression: ";
                cin >> input;
                cout << "Operators found:\n";
                int count = 0;
                for (int i = 0; i < input.length(); i++) {
                    char ch = input[i];
                    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=') {
                        count++;
                        cout << "operator" << count << ": " << ch << endl;
                    }
                }
                if (count == 0)
                    cout << "No operator found!" << endl;
                break;
            }

            case 3: {
                // Check if input is a comment
                string input;
                cout << "Enter a line: ";
                cin.ignore(); // Ignore leftover newline character
                getline(cin, input);

                if (input.substr(0, 2) == "//") {
                    cout << "This is a single-line comment." << endl;
                } else if (input.substr(0, 2) == "/*" && input.size() >= 4 && input.substr(input.size() - 2) == "*/") {
                    cout << "This is a multi-line comment." << endl;
                } else {
                    cout << "This is not a comment." << endl;
                }
                break;
            }

            case 4: {
                // Validate identifier
                string input;
                cout << "Enter an input: ";
                cin >> input;

                if (!(isalpha(input[0]) || input[0] == '_')) {
                    cout << "Not a valid identifier." << endl;
                    break;
                }

                for (int i = 1; i < input.length(); i++) {
                    if (!(isalnum(input[i]) || input[i] == '_')) {
                        cout << "Not a valid identifier." << endl;
                        break;
                    }
                }

                cout << "Valid identifier" << endl;
                break;
            }

            case 5: {
                // Calculate average of numbers
                int arr[100], n, i;
                float sum = 0, avg;
                cout << "Enter the number of elements: ";
                cin >> n;
                cout << "Enter " << n << " elements: ";
                for (i = 0; i < n; i++) {
                    cin >> arr[i];
                    sum += arr[i];
                }
                avg = sum / n;
                cout << "Average value of the elements = " << avg << endl;
                break;
            }

            case 6: {
                // Find min and max values in array
                int arr[100], n, i;
                int min, max;
                cout << "Enter the number of elements: ";
                cin >> n;
                cout << "Enter " << n << " elements: ";
                for (i = 0; i < n; i++) {
                    cin >> arr[i];
                }

                min = arr[0];
                max = arr[0];

                for (i = 1; i < n; i++) {
                    if (arr[i] < min)
                        min = arr[i];
                    if (arr[i] > max)
                        max = arr[i];
                }

                cout << "Minimum value = " << min << endl;
                cout << "Maximum value = " << max << endl;
                break;
            }

            case 7: {
                // Concatenate first name and last name
                string firstName, lastName, fullName;
                cout << "Enter your First Name: ";
                cin >> firstName;
                cout << "Enter your Last Name: ";
                cin >> lastName;
                fullName = firstName + " " + lastName;
                cout << "Full Name = " << fullName << endl;
                break;
            }

            case 8:
                cout << "Exiting the program..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
