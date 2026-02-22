#include <iostream>      // For input/output
#include <string>        // For using strings
using namespace std;

const int MAX_MEDICINES = 100;  // Max limit of medicines stored in memory

// Class to represent a Medicine
class Medicine {
public:
    // Attributes of each medicine
    string name, description, category, supplier, expiryDate;
    double price;
    int quantity;

    // Function to take input from user for one medicine
    void input() {
        cin.ignore();  // Clear the input buffer
        cout << "Enter Medicine Name: ";
        getline(cin, name);  // Take complete line input
        cout << "Enter Description: ";
        getline(cin, description);
        cout << "Enter Category: ";
        getline(cin, category);
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Quantity: ";
        cin >> quantity;
        cin.ignore();  // Clear buffer before getline
        cout << "Enter Supplier Name: ";
        getline(cin, supplier);
        cout << "Enter Expiry Date (DD-MM-YYYY): ";
        getline(cin, expiryDate);
    }

    // Function to display details of a medicine
    void display() const {
        cout << "\n---------- Medicine Details ----------\n";
        cout << "Name        : " << name << "\n";
        cout << "Description : " << description << "\n";
        cout << "Category    : " << category << "\n";
        cout << "Price       : $" << price << "\n";
        cout << "Quantity    : " << quantity << "\n";
        cout << "Supplier    : " << supplier << "\n";
        cout << "Expiry Date : " << expiryDate << "\n";
    }
};

// Class to manage list of medicines
class MedicineManager {
private:
    Medicine medicines[MAX_MEDICINES];  // Array to store medicines
    int count = 0;  // Count of current medicines

public:
    // Function to add a new medicine
    void addMedicine() {
        if (count >= MAX_MEDICINES) {  // Check if storage is full
            cout << "Medicine storage full!\n";
            return;
        }
        medicines[count].input();  // Take input
        count++;  // Increase count
        cout << "? Medicine added successfully!\n";
    }

    // Function to edit an existing medicine
    void editMedicine() {
        string name;
        cout << "Enter the name of the medicine to edit: ";
        cin.ignore();
        getline(cin, name);

        // Search for medicine by name
        for (int i = 0; i < count; i++) {
            if (medicines[i].name == name) {
                cout << "Current details:\n";
                medicines[i].display();  // Show current details
                cout << "\nEnter new details:\n";
                medicines[i].input();    // Take new input
                cout << "? Medicine updated successfully!\n";
                return;
            }
        }
        cout << "? Medicine not found!\n";
    }

    // Function to delete a medicine
    void deleteMedicine() {
        string name;
        cout << "Enter the name of the medicine to delete: ";
        cin.ignore();
        getline(cin, name);

        // Search for medicine
        for (int i = 0; i < count; i++) {
            if (medicines[i].name == name) {
                // Shift all next elements one step back
                for (int j = i; j < count - 1; j++) {
                    medicines[j] = medicines[j + 1];
                }
                count--;  // Reduce count
                cout << "? Medicine deleted successfully!\n";
                return;
            }
        }
        cout << "? Medicine not found!\n";
    }

    // Function to search a medicine by name
    void searchMedicine() const {
        string name;
        cout << "Enter the name of the medicine to search: ";
        cin.ignore();
        getline(cin, name);

        for (int i = 0; i < count; i++) {
            if (medicines[i].name == name) {
                cout << "? Medicine Found:\n";
                medicines[i].display();
                return;
            }
        }
        cout << "? Medicine not found!\n";
    }

    // Function to display all medicines
    void displayAllMedicines() const {
        if (count == 0) {
            cout << "No medicines available!\n";
            return;
        }

        for (int i = 0; i < count; i++) {
            medicines[i].display();
        }
    }

    // Function to sort medicines by name, price or description
    void sortMedicines() {
        int choice;
        cout << "Sort by:\n1. Name\n2. Price\n3. Description\nEnter choice: ";
        cin >> choice;

        for (int i = 0; i < count - 1; i++) {
            for (int j = i + 1; j < count; j++) {
                bool swapNeeded = false;
                switch (choice) {
                    case 1:
                        if (medicines[i].name > medicines[j].name) swapNeeded = true;
                        break;
                    case 2:
                        if (medicines[i].price > medicines[j].price) swapNeeded = true;
                        break;
                    case 3:
                        if (medicines[i].description > medicines[j].description) swapNeeded = true;
                        break;
                    default:
                        cout << "? Invalid choice!\n";
                        return;
                }
                if (swapNeeded) {
                    Medicine temp = medicines[i];
                    medicines[i] = medicines[j];
                    medicines[j] = temp;
                }
            }
        }

        cout << "? Medicines sorted successfully!\n";
        displayAllMedicines();  // Show sorted list
    }

    // Function to display exit message
    void exitProgram() {
        cout << "Exiting program. Goodbye!\n";
    }
};

// Main function (Program starts here)
int main() {
    MedicineManager manager;  // Create manager object

    int choice;
    do {
        // Display menu
        cout << "\n===== Medicine Management System =====\n";
        cout << "1. Add Medicine\n";
        cout << "2. Edit Medicine\n";
        cout << "3. Search Medicine\n";
        cout << "4. Delete Medicine\n";
        cout << "5. Display All Medicines\n";
        cout << "6. Sort Medicines\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Perform action based on choice
        switch (choice) {
            case 1: manager.addMedicine(); break;
            case 2: manager.editMedicine(); break;
            case 3: manager.searchMedicine(); break;
            case 4: manager.deleteMedicine(); break;
            case 5: manager.displayAllMedicines(); break;
            case 6: manager.sortMedicines(); break;
            case 7: manager.exitProgram(); break;
            default: cout << "? Invalid choice! Try again.\n";
        }

    } while (choice != 7);  // Repeat until user chooses to exit

    return 0;
}
   
