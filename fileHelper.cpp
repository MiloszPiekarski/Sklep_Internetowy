using namespace std;

#include <vector>
#include <sstream>
#include "fstream"

fstream OpenFile(string path)
{
    string fullPath = "..\\dane\\" + path;
    fstream file;
    file.open(fullPath);
    return file;
}
vector<string> split(const string &s, char delim) {
    vector<std::string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}