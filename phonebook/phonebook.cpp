#include <iomanip>
#include <iostream>
#include <string>

#define size 100

using namespace std;

struct contact {
  string f_name;
  string l_name;
  int phone = 0;
};

contact phonebook[size];

int menu() {
  int ch;

  system("clear");

  cout << "==========================\n";
  cout << "\t PHONEBOOK \t\n";
  cout << "==========================\n";
  cout << "1. Add new contact..." << endl;
  cout << "2. Search contact..." << endl;
  cout << "3. Display all contact..." << endl;
  cout << "4. Delete contact..." << endl;
  cout << "5. Edit contact..." << endl;
  cout << "6. Exit..." << endl;
  cout << "----------------------------\n";
  cout << "Your choice: ";

  cin >> ch;

  return ch;
}

int find(int ss = 0) {
  for (int i = 0; i < size; i++) {
    if (phonebook[i].phone == ss) {
      return i;
    }
  }

  return -1;
}

void Add(int n) {
  system("clear");

  cout << "==========================\n";
  cout << "\t Add new contact \t\n";
  cout << "==========================\n";

  cin.get();

  cout << "Please enter first name:";
  getline(cin, phonebook[n].f_name);

  cout << "Please enter last name:";
  getline(cin, phonebook[n].l_name);

  string phone;

  cout << "Please enter phone number:";
  cin >> phone;

  phonebook[n].phone = stoi(phone.substr(2));

  cout << "Done.......\n";
  cout << "Press Enter...";

  cin.get();
  cin.get();
}

void display() {
  system("clear");

  int count = 0;

  for (int i = 0; i < size; i++) {
    if (phonebook[i].phone != 0) {
      count++;
    }
  }

  cout << left << setw(10) << "index"
       << setw(20) << "first name"
       << setw(20) << "last name"
       << setw(20) << "phone" << endl;

  cout << "===============================================================\n";

  if (count == 0) {
    cout << "There is no phones saved yet.\n";
  } else {
    for (int i = 0; i < size; i++) {
      if (phonebook[i].phone != 0) {
        cout << left << setw(10) << i
             << setw(20) << phonebook[i].f_name
             << setw(20) << phonebook[i].l_name
             << "09" << phonebook[i].phone << endl;
      }
    }
  }

  cout << "Press enter to continue...";

  cin.get();
  cin.get();
}

void del() {
  system("clear");

  cout << left << setw(10) << "index"
       << setw(20) << "first name"
       << setw(20) << "last name"
       << setw(20) << "phone" << endl;

  cout << "==========================================================\n";

  for (int i = 0; i < size; i++) {
    if (phonebook[i].phone != 0) {
      cout << left << setw(10) << i
           << setw(20) << phonebook[i].f_name
           << setw(20) << phonebook[i].l_name
           << "09" << phonebook[i].phone << endl;
    }
  }

  int idx;

  cout << "select index to delete: " << endl;
  cin >> idx;

  if (idx < 0 || idx > size || phonebook[idx].phone == 0) {
    cout << "404, invalid index. \n";
  } else {
    phonebook[idx] = {"", "", 0};
    cout << "index " << idx << " deleted! \n";
  }

  cout << "Press enter to continue...";

  cin.get();
  cin.get();
}

void edit() {
  system("clear");

  cout << left << setw(10) << "idx"
       << setw(20) << "first name"
       << setw(20) << "last name"
       << setw(20) << "phone" << endl;

  cout << "=====================================================================\n";

  for (int i = 0; i < size; i++) {
    if (phonebook[i].phone != 0) {
      cout << left << setw(10) << i
           << setw(20) << phonebook[i].f_name
           << setw(20) << phonebook[i].l_name
           << "09" << phonebook[i].phone << endl;
    }
  }

  int idx;

  cout << "Enter index to edit: ";
  cin >> idx;
  cin.get();

  if (phonebook[idx].phone == 0) {
    cout << "That slot is empty.\n";
    cout << "Press Enter...";

    cin.get();

    return;
  }

  cout << "\nCurrent: "
       << phonebook[idx].f_name << " "
       << phonebook[idx].l_name << " "
       << phonebook[idx].phone << "\n\n";

  string input;

  cout << "New first name (Enter = keep): ";
  getline(cin, input);

  if (input != "") {
    phonebook[idx].f_name = input;
  }

  cout << "New last name (Enter = keep): ";
  getline(cin, input);

  if (input != "") {
    phonebook[idx].l_name = input;
  }

  cout << "New phone (Enter = keep): ";
  getline(cin, input);

  if (input != "") {
    phonebook[idx].phone = stoi(input.substr(2));
  }

  cout << "Edited\n";
  cout << "Press Enter...";

  cin.get();
}

int main() {
  int n, i;

  while (true) {
    n = menu();

    switch (n) {
    case 1:
      i = find();

      if (i == -1) {
        cout << "Memory is Full.........\n";
        cout << "Press Enter...";

        cin.get();
        cin.get();
      } else {
        Add(i);
      }

      break;

    case 3:
      display();
      break;

    case 4:
      del();
      break;

    case 5:
      edit();
      break;

    case 6:
      exit(0);
      break;

    default:
      cout << "Please try again....(1-6)\n";
      cout << "Press Enter...";

      cin.get();
      cin.get();

      break;
    }
  }

  return 0;
}
