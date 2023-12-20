
    int choice = 0;
    bool isContinue = true;
    while(isContinue) {
        cout << "1. Insert node at the beginning" << endl;
        cout << "2. Insert node at the end" << endl;
        cout << "3. Insert node at the specific position" << endl;
        cout << "4. Delete node from the beginning" << endl;
        cout << "5. Delete node from the end" << endl;
        cout << "6. Delete node from the specific position" << endl;
        cout << "7. Sort the list" << endl;
        cout << "8. Reverse the list" << endl;
        cout << "9. Print the list" << endl;
        cout << "10. Exit program" << endl;
        
        cout << endl << "Enter one choice: ";
        cin >> choice;
        
        int value, pos;

        switch(choice) {
            case 1:
                LL.insertAtBeginning();
                cout << "Data inserted successfully!" << endl << endl;
                break;
            case 2:
                LL.insertAtEnd();
                cout << "Data inserted successfully!" << endl << endl;
                break;
            case 3:
                LL.insertAtPos();
                break;
            case 4:
                LL.deleteFromBeginning();
                cout << "Data deleted successfully!" << endl << endl;
                break;
            case 5:
                LL.deleteFromEnd();
                cout << "Data deleted successfully!" << endl << endl;
                break;
            case 6:
                LL.deleteFromPos();
                cout << "Data deleted successfully!" << endl << endl;
                break;
            case 7:
                LL.sortList();
                cout << "Data sorted successfully!" << endl << endl;
                break;
            case 8:
                LL.reverseList();
                cout << "List reversed successfully!" << endl << endl;
                break;
            case 9:
                LL.printList();
                break;
            case 10:
                isContinue = false;
                break;
            default:
                cout << "Invalid choice, select again!" << endl << endl;
        }
    }
    return 0;
}