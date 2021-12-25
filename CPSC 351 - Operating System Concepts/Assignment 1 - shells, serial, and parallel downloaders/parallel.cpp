#include <cstring>
#include <fstream>
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <vector>
using namespace std;

vector<string> url; // create a vector to hold all the urls

int counter = 0; // counter will keep track of the index in the urls vector

void load_url() // function will open the urls.txt file, while it is parsing
                // through the file and doesn't reach the end of the file, add
                // the content of the file to the string variable afterwards,
                // push the string variable to the vector
{
    string urlLine;
    ifstream urlFile("urls.txt");

    if (urlFile.is_open()) // if the file exists, POG CHAMPION
                           // WOOOOOOOOOOOOOOOOOO :)
    {
        cout << "Poggers" << endl;
    } else {
        cout << "Not pog" << endl; // otherwise, not pog :(
        exit(-1);
    }

    while (!urlFile.eof()) {
        urlFile >> urlLine;
        url.push_back(urlLine);
        counter++;
    }
    urlFile.close(); // close the file once completed
}

void createChild() // function will create a child node based off the value of
                   // the process ID
{
    pid_t pid;

    for (int i = 0; i < counter; i++) // iterate through counter for the urls
    {
        pid = fork();
        if (pid < 0) {
            cerr << "no fork" << endl;
            exit(1);
        }

        if (pid < 0) {
            cout << "this is not epic" << endl;
            exit(1);
        } else if (pid == 0) // evaluate the return value
        {
            if (!(execlp("wget", "wget", url.back().c_str(), NULL))) {
                perror("execlp");
                exit(1);
            }
        } else {
            url.pop_back();
        }
    }
}

int main() {
    vector<string> urls;

    load_url();
    createChild();

    while (counter > 0) // while there are urls, do the following
    {
        wait(NULL);
        counter--;
    }

    cout << endl;
    cout << "Complete :)" << endl;
    return 0;
}