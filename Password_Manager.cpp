#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

void encryptDecrypt(char *input, char *output) {
    char key[] = {'K', 'C', 'Q'}; //Can be any chars, and any size array
    int keyLength = sizeof(key)/sizeof(*key);
    int i;

    for(i = 0; i < strlen(input); i++) {
        output[i] = input[i] ^ key[i % keyLength];
    }
}

int main() {

    string username, password, appPassword;
    char encrypted[100], decrypted[100];
    int choice;
    cout <<"******YOU ARE WELCOME TO OUR APPLICATION PASSWORD MANAGEMENT SITE. WE HELP TO STORE AND RETRIEVE STORED PASSWORDS*******"<<endl;
    cout <<" ";
    cout << "Please enter the application password: ";
    getline(cin, appPassword);
                   //Checking Password Condition
    if (appPassword != "0987654321") {
        cout << "Invalid application password. Program terminated.";
        return 0;
    }
                //Choosing the choice of yours
    while (true) {
        cout << "\n1. Store password\n2. Retrieve password\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
                // Implementing if else statement 
				//Storing Password
        if (choice == 1) {
            ofstream file("passwords.txt", ios::app);
            cout << "Enter the username: ";
            getline(cin, username);
            cout << "Enter the password: ";
            getline(cin, password);
            encryptDecrypt(&password[0], encrypted);
            file << username << " " << encrypted << endl;
            file.close();
            cout << "Password stored successfully.";
        }
              //Retrieveing Password
        else if (choice == 2) {
            ifstream file("passwords.txt");
            bool found = false;
            cout << "Enter the username: ";
            getline(cin, username);
            while (file >> username >> encrypted) {
                encryptDecrypt(encrypted, decrypted);
                if (username == username) {
                    found = true;
                    cout << "The password for " << username << " is " << decrypted << endl;
                }
            }
            file.close();
            if (!found) {
                cout << "Username not found.";
            }
        }
               //EXIT
        else if (choice == 3) {
            cout << "Program terminated"<<endl;
            cout << "Exiting Program...."<<endl;
}
            
        else{
        	cout <<"Invalid input of choice......" <<endl;
        	cout <<"Please Try Again....." <<endl;
}
		return 0;
	}
	}
	
	
	
	

