#include <cstring>
#include <fstream>
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <vector>
using namespace std;

vector<string> url; // create a vector to hold all the urls

void load_url() // function will open the urls.txt file, while it is parsing
                // through the file and doesn't reach the end of the file, add
                // the content of the file to the string variable afterwards,
                // push the string variable to the vector
{
    string urlLine;
    ifstream urlFile("urls.txt");

    if (urlFile.is_open()) {
        cout << "Poggers" << endl;
    } else {
        cout << "Not pog" << endl;
        exit(-1);
    }

    while (!urlFile.eof()) {
        urlFile >> urlLine;
        url.push_back(urlLine);
    }
    urlFile.close();
}

void createChild() // function will create a child node based off the value of
                   // the process ID
{
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        cout << "this is not epic" << endl;
        exit(1);
    } else if (pid == 0) {
        if (!(execlp("wget", "wget", url.back().c_str(), NULL))) {
            perror("execlp");
            exit(1);
        }
    }
}

int main() {
    load_url();
    createChild();
    wait(NULL);
    url.pop_back();
    createChild();
    wait(NULL);
    cout << "Complete :)" << endl;
    return 0;
}