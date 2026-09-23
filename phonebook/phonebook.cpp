
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
  system("cls");
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
    if (phonebook[i].phone == ss)
      return i;
  }
  return -1;
}
void Add(int n) {
  system("cls");
  cout << "==========================\n";
  cout << "\t Add new contact \t\n";
  cout << "==========================\n";
  cin.get();
  cout << "Please enter first name:";
  getline(cin, phonebook[n].f_name);

  cout << "Please enter last name:";
  getline(cin, phonebook[n].l_name);

  cout << "Please enter phone number:";
  cin >> phonebook[n].phone;

  cout << "Done.......\n";
  system("pause");
}

void display() {
  system("cls");
  cout << left << setw(20) << "first name" << setw(20) << "last name"
       << setw(20) << "phone" << endl;
  cout << "==========================================================\n";

  for (int i = 0; i < size; i++) {
    if (phonebook[i].phone != 0)

      cout << left << setw(20) << phonebook[i].f_name << setw(20)
           << phonebook[i].l_name << setw(20) << phonebook[i].phone << endl;
  }
  system("pause");
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
        system("pause");
      } else
        Add(i);
      break;
    case 2:
      search();
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
      system("pause");
      break;
    }
  }

  return 0;
}
