// Design an employee managemenent system.

#include <iostream>
using namespace std;

class Employee{

public:
    int id;
    string name;
    string department;
    Employee *left;
    Employee *right;

    Employee(int i, string n, string d){
        id = i;
        name = n;
        department = d;
        left = right = NULL;
    }
};

class EmployeeBST{

public:
    Employee *root;

    EmployeeBST(){
        root = NULL;
    }

    // Insert an employee
    void insertEmployee(int id, string name, string department){

        Employee *newEmployee = new Employee(id, name, department);

        if (root == NULL){
            root = newEmployee;
            return;
        }

        Employee *current = root;

        while (current != NULL){

            if (id == current->id){
                cout << "An employee with this id already exists" << endl;
                return;
            }

            if (id < current->id){
                if (current->left == NULL){
                    current->left = newEmployee;
                    return;
                }
                else{
                    current = current->left;
                }
            }

            else if (id > current->id){
                if (current->right == NULL){
                    current->right = newEmployee;
                    return;
                }
                else{
                    current = current->right;
                }
            }
        }
    }

    // Searching an employee
    int searchEmployee(int id){
        Employee *emp = root;

        while (emp != NULL && emp->id != id){
            if (id > emp->id){
                emp = emp->right;
            }
            else{
                emp = emp->left;
            }
        }

        if (emp == NULL){
            cout << "Employee with this id not found" << endl;
            return -1;
        }

        if (emp->id == id){
            cout << emp->name << " ";
            cout << emp->department << " ";
            return id;
        }
    }

    Employee *getIS(Employee *root){
        while (root != NULL && root->left != NULL){
            root = root->left;
        }
        return root;
    }

    // Delete Employee
    Employee *deleteEmployee(Employee *root, int id){

        if (root == NULL){
            cout << "Employee with this ID does not exist" << endl;
            return NULL;
        }

        if (id < root->id){
            root->left = deleteEmployee(root->left, id);
        }
        else if (id > root->id){
            root->right = deleteEmployee(root->right, id);
        }
        else{
            // root == id
            if (root->left == NULL){
                Employee *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL){
                Employee *temp = root->left;
                delete root;
                return temp;
            }
            else{

                Employee *IS = getIS(root->right);

                root->id = IS->id;
                root->name = IS->name;
                root->department = IS->department;

                root->right = deleteEmployee(root->right, IS->id);
            }
        }

        return root;
    }

    void inOrderTraversal(Employee *root){
        if (root == NULL){
            return;
        }

        inOrderTraversal(root->left);

        cout << "ID: " << root->id << ", Name: " << root->name << ", Department: " << root->department << endl;

        inOrderTraversal(root->right);
    }

    void findMin(){
        if (root == NULL){
            cout << "Tree is empty" << endl;
            return;
        }

        Employee *current = root;

        while (current->left != NULL){
            current = current->left;
        }

        cout << "Employee with MIN ID :" << endl;
        cout << "ID: " << current->id << ", Name: " << current->name << ", Department: " << current->department << endl;
    }

    void findMax(){
        if (root == NULL){
            cout << "Tree is empty" << endl;
            return;
        }

        Employee *current = root;

        while (current->right != NULL){
            current = current->right;
        }

        cout << "Employee with MAX ID :" << endl;
        cout << "ID: " << current->id << ", Name: " << current->name << ", Department: " << current->department << endl;
    }
};

int main() {
    EmployeeBST tree;
    int choice, id;
    string name, department;

    while (true) {
        cout << "\n\n===== Employee Management System =====\n";
        cout << "1. Insert Employee\n";
        cout << "2. Search Employee\n";
        cout << "3. Delete Employee\n";
        cout << "4. Display All Employees (In-order)\n";
        cout << "5. Find Employee with MIN ID\n";
        cout << "6. Find Employee with MAX ID\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter Employee Name: ";
            cin >> name;
            cout << "Enter Employee Department: ";
            cin >> department;
            tree.insertEmployee(id, name, department);
            break;

        case 2:
            cout << "Enter Employee ID to search: ";
            cin >> id;
            tree.searchEmployee(id);
            break;

        case 3:
            cout << "Enter Employee ID to delete: ";
            cin >> id;
            tree.root = tree.deleteEmployee(tree.root, id);
            break;

        case 4:
            cout << "\n--- Employee List (Sorted by ID) ---\n";
            tree.inOrderTraversal(tree.root);
            break;

        case 5:
            tree.findMin();
            break;

        case 6:
            tree.findMax();
            break;

        case 7:
            cout << "Exiting Program...\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
