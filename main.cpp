#include <iostream>
#include <string>
#include <fstream>
#include "DoublyLinkedList.h"

using namespace std;


int main(int argc, char *argv[]) {
    string listType;
    string listFile;
    ifstream listF;
    DoublyLinkedList<int> *list;
    DoublyLinkedList<float> *list2;
    DoublyLinkedList<string> *list3;
    int numInt;
    float numFloat;
    string numString;

    // Exits out of program if user does not follow "usage"
    // User must enter file with linked list data on the command line
    // User can not enter more than 2 argc
    if (argc == 2) {
        listFile = argv[1];
        listF.open(listFile, ios::in);
    } else {
        cerr << "Usage: main [listFile]" << endl;
        exit(1);
    }

    // Checks if list file exists with list data
    if (!listF) {
        cerr << "Error: cannot parse list information from file"<< endl;
        listF.close();
        exit(1);
    }

    cout << "Enter list type(i - int, f - float, s - std::string): ";
    cin >> listType;

    if (listType.compare("i") == 0) {
        list = new DoublyLinkedList<int>();
        while (listF >> numInt) {
            list->insertItem(numInt);
        }
    }
    if (listType.compare("f") == 0) {
        list2 = new DoublyLinkedList<float>();
        while (listF >> numFloat) {
            list2->insertItem(numFloat);
        }
    }
    if (listType.compare("s") == 0) {
        list3 = new DoublyLinkedList<string>();
        while (listF >> numString) {
            list3->insertItem(numString);
        }
    }

    listF.close();

    // while loop that user repeats after every given instruction
    bool quitL = false;
    char command;
    while (!quitL) {
        cout << "insert (i), delete (d), length (l), print (p), deleteSub (b), mode (m),printReverse(r), swapAtl(s), quit (q)" << endl;
        cout << "Enter a command: ";
        cin >> command;
        switch(command) {
        case 'i': {
            cout << "Item to insert: " ;
            if (listType.compare("i") == 0) {
                cin >> numInt;
                list->insertItem(numInt);
                list->print();
            }
            if (listType.compare("f") == 0) {
                cin >> numFloat;
                list2->insertItem(numFloat);
            }
            if (listType.compare("s") == 0) {
                cin >> numString;
                list3->insertItem(numString);
            }
        }
            break;
        case 'd': {
            cout << "Item to delete: " ;
            if (listType.compare("i") == 0) {
                cin >> numInt;
                list->deleteItem(numInt);
                list->print();
            }
            if (listType.compare("f") == 0) {
                cin >> numFloat;
                list2->deleteItem(numFloat);
                list2->print();
            }
            if (listType.compare("s") == 0) {
                cin >> numString;
                list3->deleteItem(numString);
                list3->print();
            }
        }
            break;
        case 'l': {
            cout << "The length is: ";
            if (listType.compare("i") == 0) {
                cout << list->lengthIs();
                cout << "" << endl;
            }
            if (listType.compare("f") == 0) {
                cout << list2->lengthIs();
                cout << "" << endl;
            }
            if (listType.compare("s") == 0) {
                cout << list3->lengthIs();
                cout << "" << endl;
            }
        }
            break;
        case 'p': {
            if (listType.compare("i") == 0) {
                list->print();
            }
            if (listType.compare("f") == 0) {
                list2->print();
            }
            if (listType.compare("s") == 0) {
                list3->print();
            }
        }
            break;
        case 'b': {
            if (listType.compare("i") == 0) {
                int range;
                int range2;
                cout << "Enter lower bound: ";
                cin >> range;
                cout << "Enter upper bound: ";
                cin >> range2;
                cout << "Original List: ";
                list->print();
                list->deleteSubsection(range, range2);
                cout << "Modified List: ";
                list->print();
            }
            if (listType.compare("f") == 0) {
                float rangef;
                float rangef2;
                cout << "Enter lower bound: ";
                cin >> rangef;
                cout << "Enter upper bound: ";
                cin >> rangef2;
                cout << "Original List: ";
                list2->print();
                list2->deleteSubsection(rangef, rangef2);
                cout << "Modified List: ";
                list2->print();
            }
            if (listType.compare("s") == 0) {
                string ranges;
                string ranges2;
                cout << "Enter lower bound: ";
                cin >> ranges;
                cout << "Enter upper bound: ";
                cin >> ranges2;
                cout << "Original List: ";
                list3->print();
                list3->deleteSubsection(ranges,ranges2);
                cout << "Modified List: ";
                list3->print();
            }
        }
            break;
        case 'm': {
            if (listType.compare("i") == 0) {
                list->print();
                cout << "Mode: " << list->mode() << endl;
            }
            if (listType.compare("f") == 0) {
                list->print();
                cout << "Mode: " << list2->mode() << endl;
            }
            if (listType.compare("s") == 0) {
                list->print();
                cout << "Mode: " << list3->mode() << endl;
            }
        }
            break;
        case 'r': {
            if (listType.compare("i") == 0) {
                list->printReverse();
            }
            if (listType.compare("f") == 0) {
                list2->printReverse();
            }
            if (listType.compare("s") == 0) {
                list3->printReverse();
            }
        }

            break;
        case 's':{
            if (listType.compare("i") == 0) {
                cout << "Original List: ";
                list->print();
                list->swapAlternate();
                cout << "Swapped List: ";
                list->print();
            }
            if (listType.compare("f") == 0) {
                cout << "Original List: ";
                list2->print();
                list2->swapAlternate();
                cout << "Swapped List: ";
                list2->print();
            }
            if (listType.compare("s") == 0) {
                cout << "Original List: ";
                list3->print();
                list3->swapAlternate();
                cout << "Swapped List: ";
                list3->print();
            }
        }
            break;
        case 'q': {
            cout << "Quitting program..." << endl;
            quitL = true;
        }
            break;
        default: {
            cout << "Command not found!" << endl;
        }
        }


    }


        return 0;
}
