#include<iostream>
#include<iomanip>

#include"FileManager.h"
using namespace std;




void management();
void DisplayCommands();
void displayFileManagerWord();
void displayTerminalWord();
void loading(int n);
int main()
{
    loading(30);
    displayTerminalWord();
    DisplayCommands();
    management();
    return 0;
}

void management()
{
    string command;
    FileManager run;
    while (true)
    {
       // DisplayCommands();
        cout << "\nCurrent Directory: " << run.getBuffer() << "\n";
        cout << "$";
        getline(cin, command);

        if (command == "ls")
        {
            run.listDirectoryContents();
        }
        else if (command.substr(0, 3) == "cat")
        {
            string filename = command.substr(4);
            run.viewFileContents(filename);
        }
        else if (command.substr(0, 5) == "tough")
        {
            string filename = command.substr(6);
            run.createFile(filename);
        }
        else if (command.substr(0, 5) == "mkdir")
        {
            string dirname = command.substr(6);
            run.createDirector(dirname);
        }
        else if (command.substr(0, 2) == "cp")
        {
            string source = command.substr(3, command.find(' ', 3) - 3);
            string destination = command.substr(command.find(' ', 3) + 1);
            run.copyFile(source, destination);
        }
        else if (command.substr(0, 2) == "mv")
        {
            string source = command.substr(3, command.find(' ', 3) - 3);
            string destination = command.substr(command.find(' ', 3) + 1);
            run.moveFile(source, destination);
        }
        else if (command.substr(0, 3) == "rmf")
        {
            string fileName = command.substr(4);
            run.removeFile(fileName);
        }
        else if (command.substr(0, 3) == "rmd")
        {
            string directoryName = command.substr(4);
            run.removeDirectory(directoryName);
        }
        else if (command.substr(0, 2) == "cd")
        {
            string dirname = command.substr(3);
            run.changeDirectory(dirname);
        }
        else if (command == "back")
        {
            run.BackToPrevoiusDirectory();
        }
        else if (command == "clear" || command == "cls") {
            system("cls");
            displayTerminalWord();
            DisplayCommands();
        }
        else if (command == "exit")
        {
            break;
        }
        else
        {
            std::cerr << "Invalid command.\n";
        }
    }
}

void DisplayCommands()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   // SetConsoleTextAttribute(hConsole, 10); // Set text color to Green (10)
                                          cout << "                                Commands:\n";
    SetConsoleTextAttribute(hConsole, 10);cout << "                                        ls ";SetConsoleTextAttribute(hConsole, 7);cout<<" - List directory contents\n";
    SetConsoleTextAttribute(hConsole, 10);cout << "                                        cat <filename>";SetConsoleTextAttribute(hConsole, 7);cout << " - View file contents\n";
    SetConsoleTextAttribute(hConsole, 10);cout << "                                        tough <filename>";SetConsoleTextAttribute(hConsole, 7);cout << " - Create file \n";
    SetConsoleTextAttribute(hConsole, 10);cout << "                                        mkdir <dirname> ";SetConsoleTextAttribute(hConsole, 7);cout << "- Create directory\n";
    SetConsoleTextAttribute(hConsole, 10);cout << "                                        cp <source> <destination> ";SetConsoleTextAttribute(hConsole, 7);cout << "- Copy file\n";
    SetConsoleTextAttribute(hConsole, 10);cout << "                                        mv <source> <destination> ";SetConsoleTextAttribute(hConsole, 7);cout << "- Move file\n";
    SetConsoleTextAttribute(hConsole, 10);cout << "                                        rmf <filename>";SetConsoleTextAttribute(hConsole, 7);cout << " - Remove file \n";
    SetConsoleTextAttribute(hConsole, 10);cout << "                                        rmd <filename>";SetConsoleTextAttribute(hConsole, 7);cout << " - Remove Directory \n";
    SetConsoleTextAttribute(hConsole, 10);cout << "                                        cd <dirname> ";SetConsoleTextAttribute(hConsole, 7);cout << "- Change directory\n";
    SetConsoleTextAttribute(hConsole, 10);cout << "                                        back ";SetConsoleTextAttribute(hConsole, 7);cout << "- Return to previous directory\n";
    SetConsoleTextAttribute(hConsole, 10);cout << "                                        cls ";SetConsoleTextAttribute(hConsole, 7);cout << " - Clear console \n";
    SetConsoleTextAttribute(hConsole, 10);cout << "                                        exit ";SetConsoleTextAttribute(hConsole, 7);cout << "- Exit file manager\n\n";

    SetConsoleTextAttribute(hConsole, 7); // Reset text color to default (7)

}

void displayFileManagerWord()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 14); // Set text color to yellow (14)

    std::cout << " /$$$$$$$$ /$$ /$$                 /$$      /$$                                                             " << std::endl;
    std::cout << "| $$_____/|__/| $$                | $$$    /$$$                                                             " << std::endl;
    std::cout << "| $$       /$$| $$  /$$$$$$       | $$$$  /$$$$  /$$$$$$  /$$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$ " << std::endl;
    std::cout << "| $$$$$   | $$| $$ /$$__  $$      | $$ $$/$$ $$ |____  $$| $$__  $$ |____  $$ /$$__  $$ /$$__  $$ /$$__  $$" << std::endl;
    std::cout << "| $$__/   | $$| $$| $$$$$$$$      | $$  $$$| $$  /$$$$$$$| $$  \\ $$  /$$$$$$$| $$  \\ $$| $$$$$$$$| $$  \\__/" << std::endl;
    std::cout << "| $$      | $$| $$| $$_____/      | $$\\  $ | $$ /$$__  $$| $$  | $$ /$$__  $$| $$  | $$| $$_____/| $$      " << std::endl;
    std::cout << "| $$      | $$| $$|  $$$$$$$      | $$ \\/  | $$|  $$$$$$$| $$  | $$|  $$$$$$$|  $$$$$$$|  $$$$$$$| $$      " << std::endl;
    std::cout << "|__/      |__/|__/ \\_______/      |__/     |__/ \\_______/|__/  |__/ \\_______/ \\____  $$ \\_______/|__/      " << std::endl;
    std::cout << "                                                                              /$$  \\ $$                    " << std::endl;
    std::cout << "                                                                             |  $$$$$$/                    " << std::endl;
    std::cout << "                                                                              \\______/                     " << std::endl;

    SetConsoleTextAttribute(hConsole, 7); // Reset text color to default (7)
}

void displayTerminalWord()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10); // Set text color to yellow (14)

    std::cout << "                       _                      _             _           \n";
    std::cout << "/\\_/\\___  _   _ _ __  | |_ ___ _ __ _ __ ___ (_)_ __   __ _| |          \n";
    std::cout << "\\_ _/ _ \\| | | | '__| | __/ _ \\ '__| '_ ` _ \\| | '_ \\ / _` | |          \n";
    std::cout << " / \\ (_) | |_| | |    | ||  __/ |  | | | | | | | | | | (_| | |  _ _ _ _ \n";
    std::cout << " \\_/\\___/ \\__,_|_|     \\__\\___|_|  |_| |_| |_|_|_| |_|\\__,_|_| (_|_|_|_)\n";
    std::cout << "                                                                       \n";
    std::cout << "                                                                       \n";
    SetConsoleTextAttribute(hConsole, 7); // Reset text color to default (7)

}

void loading(int n)
{
    for (int i = 0; i <= n; i++)
    {
        displayFileManagerWord();

        cout << "\n\n\n\n\n\n\n\n\n\n\n\n" << setw(65) << "PLEASE WAIT FEW SECOND ";
        for (int j = 0; j < i; j++)
        {
            cout << ".";
        }
        cout << endl;
        Sleep(100); // delay for 100 milliseconds
        system("cls"); // clear the console
    }
}

































/*// Basic File Manager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include<string>
#include <Windows.h>
#include <sys/stat.h>
#include <sstream> // For stringstream
using namespace std;
int main()
{
    string input;
    while (input != "exite")
    {
        cout << "$->";getline(cin, input);
        // clear /creat files/ view files / copy or move files/  / navigate directions
       //cout << input.substr(0, 6);
        if (input.substr(0, 5) == "touch")
        {
            fstream file;

            cout << "first done\n";
            file.open(input.substr(input.find(' ') + 1, input.length() - 1), ios::app);
            if (file.is_open())
                cout << "File creted successfully\n";
        }
        else if (input == "ls")
        {
            WIN32_FIND_DATAW findFileData;
            HANDLE hFind = FindFirstFileW(L"*.*", &findFileData);
            int fileNumber = 1;

            if (hFind != INVALID_HANDLE_VALUE) {
                do {
                    // Set console text color to yellow (14)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

                    // Output file number
                    std::wcout << fileNumber++ << "-> ";

                    // Output file name
                    std::wcout << findFileData.cFileName << std::endl;

                    // Restore default console text color
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

                } while (FindNextFileW(hFind, &findFileData) != 0);
                FindClose(hFind);
            }
        }
        else if (input == "clear" || input == "cls")
            system("cls");
        else if (input.substr(0, 5) == "mkdir")
        {
            string folderName = input.substr(input.find(' ') + 1, input.length());
            // Construct the system command to create the directory
            std::string command = "mkdir \"" + folderName + "\"";

            // Execute the system command
            int result = system(command.c_str());

            // Check if the command executed successfully
            if (result == 0) {
                std::cout << "Folder created successfully." << std::endl;
            }
            else {
                std::cerr << "Failed to create folder." << std::endl;
                //return 1;
            }


        }
    }




return 0;

}
*/



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
