#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
class Matrix {
    public:
    static int *readFileFromMatrix(char* fileName, int &size) {
        vector< vector<int> > v;
        ifstream ifs(fileName);
        string tempstr;
        int tempint;
        char delimiter;

        while (getline(ifs, tempstr)) {
            istringstream iss(tempstr);
            vector<int> tempv;
            while (iss >> tempint) {
                tempv.push_back(tempint);
                iss >> delimiter;
            }
            v.push_back(tempv);
        }
        int *resutl = new int[v.size()];
        size = v.size();
        int i = 0;
        for (auto row : v) {
            for (auto el : row) {
                resutl[i] = el;
            }
        }
        return resutl;
    }
};