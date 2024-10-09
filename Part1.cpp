#include <iostream>
#include <string>
using namespace std;

// Node class for the linked list
class node 
    {
    public:
        int value;
        node* next;
    };

// Function to create a new node
node* createNode(int a) 
    {
        node* newNode = new node();
        newNode->value = a;
        newNode->next = NULL;
        return newNode;
    }

// Stack class using a linked list
class Stack 
    {
    public:
        node* top;
    
        Stack() 
        {
            top = NULL;  // Initialize the stack
        }
    
        // Function to push a value onto the stack
        void push(int value) 
        {
            node* a = createNode(value);
            if (top == NULL) 
                top = a;  // If stack is empty
            else 
            {
                a->next = top;
                top = a;  // Insert the new node at the top
            }
            //Display();  // Display the stack after pushing
        }
    
        // Function to pop the top value off the stack
        void pop() 
        {
            if (top == NULL) 
                cout << "Stack rong.\n";  // Stack is empty
            else 
            {
                node* tmp = top;
                top = top->next;  // Move top to the next node
                delete tmp;  // Delete the old top node
            }
        }
    
        // Function to check if the stack is empty
        bool isEmpty() 
        {
            return top == NULL;  // Return true if the stack is empty
        }
    
        // Function to check if the stack is full (never full in linked list implementation)
        bool isFull() 
        {
            return false;  // For linked list implementation, the stack is never full
        }
    
        // Function to display the contents of the stack
        void Display() 
        {
            if (isEmpty()) 
                return;  // Exit the function if the stack is empty
            
            node* tmp = top;  // Start from the top of the stack
            while (tmp != NULL) 
            {
                cout << tmp->value << " ";  // Print each value
                tmp = tmp->next;  // Move to the next node
            }
           // cout << tmp->value << " "; 
            cout << endl;  // Print a new line at the end
        }
    };

// Function to check if a bracket sequence is valid
bool isValidBracketSequence(string s) 
    {
        Stack stack;
        for (char c : s) 
        {
            if (c == '(' || c == '[' || c == '{') 
                stack.push(c);  // Push opening brackets
            else if (c == ')' || c == ']' || c == '"') 
            {
                if (stack.isEmpty()) return false;  // Stack is empty but a closing bracket is found
                char top = stack.top->value;  // Get the top value without popping it
                // Check if the closing bracket matches the top of the stack
                if ((c == ')' && top == '(') || (c == ']' && top == '[') || (c == '{' && top == '}')) 
                    stack.pop();  // Pop if a valid match is found
                else 
                    return false;  // Invalid bracket sequence
            }
        }
        return stack.isEmpty();  // Ensure no unmatched opening brackets remain
    }

// Function to reverse words in a string
string reverseWords(string str) 
    {
        Stack stack;
        string result = "", word = "";
        for (char c : str) 
        {
            if (c == ' ') 
            {
                // Pop all characters of the word from the stack and add to result
                while (!stack.isEmpty()) 
                {
                    result += stack.top->value;  // Get the top value
                    stack.pop();  // Pop the top value
                }
                result += ' ';  // Add the space after the word
            } 
            else 
                stack.push(c);  // Push characters of the word onto the stack
        }
        // Pop the last word
        while (!stack.isEmpty()) 
        {
            result += stack.top->value;
            stack.pop();
        }
        return result;
    }

// Function to display the menu
void displayMenu() 
    {
        cout << "\nMenu:\n";
        cout << "1. Push several numbers onto the stack\n";  
        cout << "2. Check if the stack is empty\n";
        cout << "3. Check if the stack is full\n";
        cout << "4. Check if a bracket sequence is valid\n";
        cout << "5. Reverse words in a string\n";
        cout << "6. Exit\n";
        cout << "Choose an option: ";
    }

// Main function
int main() 
    {
        Stack A;
        int choice, a;
    
        do 
        {
            displayMenu();
            cin >> choice;  // Get the user's choice
    
            switch (choice) 
            {
                case 1: 
                {  // Push several numbers onto the stack
                    cout << "Enter several integers to push onto the stack (0 to stop): ";
                    while (true) 
                    {
                        cin >> a;  // Read the next integer
                        if (a == 0) break;  // Stop if sentinel value is entered
                        A.push(a);  // Push the value onto the stack
                    }
                    A.Display();
                    break;
                }
    
                case 2:  // Check if the stack is empty
                    if (A.isEmpty())
                        cout << "Stack rong.\n";
                    else
                        cout << "Stack is not empty.\n";
                    break;
    
                case 3:  // Check if the stack is full
                    if (A.isFull())
                        cout << "Stack is full.\n";
                    else
                        cout << "Stack is not full.\n";
                    break;
   
                case 4: 
                {  // Validate a bracket sequence
                    cout << "Enter a bracket sequence: ";
                    string bracketSequence;
                    cin >> bracketSequence;  // Input the bracket sequence
                    if (isValidBracketSequence(bracketSequence)) 
                        cout << "The bracket sequence is valid.\n";
                    else 
                        cout << "The bracket sequence is invalid.\n";
                    break;
                }
    
                case 5: 
                {  // Reverse words in a string
                    cin.ignore();  // Clear the buffer before getting the next line
                    cout << "Enter a string to reverse words: ";
                    string inputString;
                    getline(cin, inputString);  // Get a full line of input
                    cout <<reverseWords(inputString) << endl;
                    break;
                }
    
                case 6:  // Exit the program
                    cout << "Exiting the program.\n";
                    break;
    
                default:  // Invalid choice
                    cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 6);
    
        return 0;
    }