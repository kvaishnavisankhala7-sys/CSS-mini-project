#include <iostream>
#include <string>

using namespace std;

class LibraryFineCalculator {
private:
    string memberName;
    string bookTitle;
    string dueDate;
    string returnDate;
    int daysOverdue;
    double totalFine;

public:
    LibraryFineCalculator() {
        daysOverdue = 0;
        totalFine = 0.0;
    }

    void inputDetails() {
        cout << "--- Library Fine System ---" << endl;
        
        // FIX: Use getline for full names with spaces
        cout << "Enter member name: ";
        getline(cin, memberName); 
        
        cout << "Enter due date (DD/MM/YYYY): ";
        cin >> dueDate;

        cout << "Enter return date (DD/MM/YYYY): ";
        cin >> returnDate;

        // FIX: Clear buffer before switching back to getline
        cin.ignore(); 

        cout << "Enter Book Name: ";
        getline(cin, bookTitle); // Allows titles like "The Great Gatsby"
        
        cout << "Enter number of days the book is overdue: ";
        cin >> daysOverdue;
    }

    void calculateFine() {
        if (daysOverdue <= 0) {
            totalFine = 0;
        } 
        else if (daysOverdue <= 5) {
            totalFine = daysOverdue * 5.0; 
        } 
        else if (daysOverdue <= 10) {
            // First 5 days cost 25. Add remaining days * 10
            totalFine = 25.0 + ((daysOverdue - 5) * 10.0);
        } 
        else {
            // First 5 days (25) + Next 5 days (50) = 75. Add remaining * 20
            totalFine = 75.0 + ((daysOverdue - 10) * 20.0);
        }
    }

    void displayReceipt() {
        cout << "\n-----------------------------" << endl;
        cout << "       FINE RECEIPT" << endl;
        cout << "-----------------------------" << endl;
        cout << "Name of Member: " << memberName << endl;    
        cout << "Book Name     : " << bookTitle << endl;
        cout << "Due Date      : " << dueDate << endl;
        cout << "Return Date   : " << returnDate << endl;
        cout << "Days Overdue  : " << daysOverdue << endl;
        cout << "Total Fine    : " << totalFine << " Rupees " << endl;
        cout << "-----------------------------" << endl;
    }
};

int main() {
    LibraryFineCalculator calculator;
    
    calculator.inputDetails();
    calculator.calculateFine();
    calculator.displayReceipt();

    return 0;
}