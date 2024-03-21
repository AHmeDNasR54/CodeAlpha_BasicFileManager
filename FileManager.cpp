#include "FileManager.h"

FileManager::FileManager()
{
    _getcwd(buffer, sizeof(buffer));
}

FileManager::~FileManager()
{
    //dtor
}
void FileManager::setInput(string input)
{
    this->input = input;

}
string FileManager::getBuffer()
{
    return buffer;
}

void FileManager::createFile(string fname)
{
    fstream file;

    file.open(fname, ios::app);
    if (file.is_open())
        cout << "FILE """ << fname << """CREATED SUCCESSFULLY\n";
    else cout << "FAILD TO CREATE FILE\n";
}
void FileManager::createDirector(string FolderName)
{
    //string folderName = input.substr(input.find(' ') + 1, input.length());
    // Construct the system command to create the directory
    string command = "mkdir \"" + FolderName + "\"";

    // Execute the system command
    int result = system(command.c_str());

    // Check if the command executed successfully
    if (result == 0)
    {
        cout << "FOLDER """ << FolderName << """CREATED SUCCESSFULLY.\n";
    }
    else
    {
        cerr << "FAILD TO CREATE FOLDER." << endl;
        //return 1;
    }

}
void FileManager::viewFileContents(string fname)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // SetConsoleTextAttribute(hConsole, 10); // Set text color to Green (10)

    ifstream file(fname);
    if (file.is_open())
    {
        string line;
        SetConsoleTextAttribute(hConsole, 13);
        while (file.good())
        {
            getline(file, line);
            cout << line << endl;
        }
    }
    else cout << "UNABLE TO OPEN THE FILE\n";
    SetConsoleTextAttribute(hConsole, 7);

}

void FileManager::listDirectoryContents()
{
    WIN32_FIND_DATAW findFileData;
    HANDLE hFind = FindFirstFileW(L"*.*", &findFileData);
    int fileNumber = 1;

    if (hFind != INVALID_HANDLE_VALUE)
    {
        do
        {
            // Set console text color to yellow (14)
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

            // Output file number
            std::wcout << fileNumber++ << "-> ";

            // Output file name
            std::wcout << findFileData.cFileName << " ";

            // Output kind (file or directory)
            if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
                std::wcout << " [Directory] ";
            }
            else
            {
                std::wcout << " [File] ";
            }

            // Output file size
            std::wcout << " ,Size: " << findFileData.nFileSizeLow << " bytes" << std::endl;

            // Restore default console text color
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

        } while (FindNextFileW(hFind, &findFileData) != 0);
        FindClose(hFind);
    }
}

void FileManager::copyFile(const string& source, const string& destination)
{
    // string source = command.substr(3, command.find(' ', 3) - 3);
        //std::string destination = command.substr(command.find(' ', 3) + 1);
        // copyFile(source, destination);
    if (CopyFileA(source.c_str(), destination.c_str(), FALSE))
    {
        cout << "File copied successfully.\n";
    }
    else
    {
        cerr << "Error: Failed to copy file.\n";
    }
}
void FileManager::moveFile(const string& source, const string& destination)
{
    if (rename(source.c_str(), destination.c_str()) == 0)
    {
        std::cout << "Moved successfully.\n";
    }
    else
    {
        std::cerr << "Error: Failed to move.\n";
    }

}
void FileManager::changeDirectory(const std::string& dirname)
{
    if (_chdir(dirname.c_str()) == 0) {
        // Check if the specified directory is different from the current one
        if (dirname != buffer) {
            directoryHistory.push(buffer); // Push current directory to history stack
        }
        // Update buffer with the new directory
        _getcwd(buffer, MAX_PATH);


    }
    else {
        std::cerr << "Error: Directory does not exist.\n";
    }

}
void FileManager::BackToPrevoiusDirectory()
{
    if (!directoryHistory.empty()) {
        std::string prevDirectory = directoryHistory.top(); // Get the last directory from the history stack
        directoryHistory.pop(); // Remove the last directory from the history stack
        if (_chdir(prevDirectory.c_str()) == 0) {
            // Update buffer with the previous directory
            _getcwd(buffer, MAX_PATH);
        }
        else {
            std::cerr << "Error: Failed to navigate back to the previous directory.\n";
        }
    }
    else {
        std::cerr << "Error: No previous directory.\n";
    }
}
bool FileManager::removeFile(const std::string& filename) {
    if (DeleteFileA(filename.c_str())) {
        std::cout << "File removed successfully.\n";
        return true;
    }
    else {
        std::cerr << "Error: Failed to remove file.\n";
        return false;
    }
}

bool FileManager::removeDirectory(const std::string& dirname) {
    if (RemoveDirectoryA(dirname.c_str())) {
        std::cout << "Directory removed successfully.\n";
        return true;
    }
    else {
        std::cerr << "Error: Failed to remove directory.\n";
        return false;
    }
}

