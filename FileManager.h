#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include<direct.h>
#include<stack>
using namespace std;
class FileManager
{
private:
    string input;
    char buffer[MAX_PATH];
    stack<string> directoryHistory;

public:
    string getBuffer();
    FileManager();
    void setInput(string input);
    void createFile(string fname);
    void createDirector(string FolderName);
    void viewFileContents(string fname);
    void listDirectoryContents();
    void copyFile(const string& source, const string& destination);
    void moveFile(const string& source, const string& destination);
    void changeDirectory(const string& dirname);
    void BackToPrevoiusDirectory();
    bool removeFile(const std::string& filename);
    bool removeDirectory(const std::string& dirname);

    virtual ~FileManager();

protected:

};

#endif // FILEMANAGER_H
