#include <iostream>
#include "DP/Q1.cpp"
#include "DP/Q2.cpp"
#include "DP/Q3.cpp"
#include "DP/Q4.cpp"
#include "DP/Q5.cpp"
#include "Greedy/Q1.cpp"
#include "Greedy/Q2.cpp"
#include "Greedy/Q3.cpp"
#include "Greedy/Q4.cpp"
#include "Greedy/Q5.cpp"
using namespace std;


int main() {
    int choice;

    while (true) {
        cout << "\nSelect a problem to execute:" << endl;
        cout << "Dynamic Programming Problems:" << endl;
        cout << "  1. Q1 - Dynamic Programming Problem 1" << endl;
        cout << "  2. Q2 - Dynamic Programming Problem 2" << endl;
        cout << "  3. Q3 - Dynamic Programming Problem 3" << endl;
        cout << "  4. Q4 - Dynamic Programming Problem 4" << endl;
        cout << "  5. Q5 - Dynamic Programming Problem 5" << endl;
        cout << "Greedy Problems:" << endl;
        cout << "  6. Q1 - Greedy Problem 1" << endl;
        cout << "  7. Q2 - Greedy Problem 2" << endl;
        cout << "  8. Q3 - Greedy Problem 3" << endl;
        cout << "  9. Q4 - Greedy Problem 4" << endl;
        cout << " 10. Q5 - Greedy Problem 5" << endl;
        cout << " 11. Exit" << endl;
        cout << "Enter the problem number (1-11): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "You selected Q1 - Dynamic Programming Problem 1" << endl;
                break;
            case 2:
                cout << "You selected Q2 - Dynamic Programming Problem 2" << endl;
                break;
            case 3:
                cout << "You selected Q3 - Dynamic Programming Problem 3" << endl;
                break;
            case 4:
                cout << "You selected Q4 - Dynamic Programming Problem 4" << endl;
                break;
            case 5:
            {
                int N;
                cout << "Enter the size of the array: ";
                cin >> N;
                vector<int> A(N);
                cout << "Enter the elements of the array: ";
                for (int i = 0; i < N; i++) {
                    cin >> A[i];
                }
                int result = Q5(A);
                cout << "Result: " << result << endl;
            }
                break;
            case 6:
                cout << "You selected Q1 - Greedy Problem 1" << endl;
                break;
            case 7:
                cout << "You selected Q2 - Greedy Problem 2" << endl;
                break;
            case 8:
                cout << "You selected Q3 - Greedy Problem 3" << endl;
                break;
            case 9:
                cout << "You selected Q4 - Greedy Problem 4" << endl;
                break;
            case 10:
                cout << "You selected Q5 - Greedy Problem 5" << endl;
                break;
            case 11:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 11." << endl;
                break;
        }
    }

}