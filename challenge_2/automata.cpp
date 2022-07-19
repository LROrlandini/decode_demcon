#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void getInstruction(vector<string>& inst);
bool defineRules(string type, vector<vector<bool>>& rules);
void buildCellGrid(vector<string> inst, vector<bool>& myGen);
void findStartingPostions(vector<string>& inst, vector<int>& pos);
void computeNewGeneration(vector<bool>& myGen, const vector<vector<bool>> rules);
void printGeneration(vector<bool> const aGeneration);

int main()
{
    vector<string> instruction;
    vector<bool> myGeneration;
    vector<vector<bool>> rules;

    getInstruction(instruction);
    string type = instruction[0];
    int iterations = stoi(instruction[2]);
   
    if (!defineRules(type, rules))
    {
        throw invalid_argument("Invalid instruction type.");
    }

    buildCellGrid(instruction, myGeneration);

    for (auto i = 0; i < iterations; i++)
    {
        printGeneration(myGeneration);
        computeNewGeneration(myGeneration, rules);
    }

    return 0;
}

void getInstruction(vector<string>& inst)
{
    string input, tempInstruction;

    cout << "Enter instruction: " << endl;
    cout << "e.g A 61 20 init_start 20 30 init_end: " << endl;
    getline(cin, input);
    stringstream i(input);
  
    while (getline(i, tempInstruction, ' '))
    {
        inst.push_back(tempInstruction);
    }
}

bool defineRules(string type, vector<vector<bool>>& rules)
{
    vector<vector<bool>> a
    {
        {0, 0, 0, 0}, {0, 0, 1, 1}, {0, 1, 0, 0}, {0, 1, 1, 1},
        {1, 0, 0, 1}, {1, 0, 1, 1}, {1, 1, 0, 0}, {1, 1, 1, 0}
    };
    vector<vector<bool>> b
    {
        {0, 0, 0, 0}, {0, 0, 1, 1}, {0, 1, 0, 1}, {0, 1, 1, 0},
        {1, 0, 0, 1}, {1, 0, 1, 0}, {1, 1, 0, 1}, {1, 1, 1, 0}
    };
    vector<vector<bool>> u
    {
        {0, 0, 0, 1}, {0, 0, 1, 0}, {0, 1, 0, 0}, {0, 1, 1, 0},
        {1, 0, 0, 0}, {1, 0, 1, 0}, {1, 1, 0, 0}, {1, 1, 1, 1}
    };

    if (toupper(type[0]) == 'A') rules = a;
    else if (toupper(type[0]) == 'B') rules = b;
    else if (toupper(type[0]) == 'U') rules = u;
    else return false;

    return true;
}

void buildCellGrid(vector<string> inst, vector<bool>& myGen)
{
    vector<int> startPositions;
    findStartingPostions(inst, startPositions);
    myGen.push_back(0);
    for (auto i = 1; i <= stoi(inst[1]); i++)
    {
        auto it = find(startPositions.begin(), startPositions.end(), i);
        if (it != startPositions.end()) myGen.push_back(1);
        else myGen.push_back(0);
    }
    myGen.push_back(0);
}

void findStartingPostions(vector<string>& inst, vector<int>& pos)
{
    auto range_min = find_if(inst.begin(), inst.end(), [](string s)
    {
        if (s == "init_start") return true;
        return false;
    });
    auto range_max = find_if(inst.begin(), inst.end(), [](string e)
    {
        if (e == "init_end") return true;
        return false;
    });
    auto arguments = range_max - range_min - 1;
    for (auto i = 4; i < 4 + arguments; i++)
    {
        pos.push_back(stoi(inst[i]));
    }
}

void computeNewGeneration(vector<bool>& myGen, const vector<vector<bool>> rules)
{
    vector<bool> temp;
    temp.push_back(0);
    bool l, m, r;
    for (auto i = 1; i < myGen.size() - 1; i++)
    {
        if (i != myGen.size() - 1)
        {
            l = myGen[i - 1];
            m = myGen[i];
            r = myGen[i + 1];
        }
        for_each(rules.begin(), rules.end(),
            [&l, &m, &r, &temp](vector<bool> rlz)
            {
                 if (rlz[0] == l && rlz[1] == m && rlz[2] == r)
                {
                    temp.push_back(rlz[3]);
                }
            });
    }
    temp.push_back(0);
    myGen.assign(temp.begin(), temp.end());
}

void printGeneration(vector<bool> const aGeneration)
{
    for (bool i : aGeneration)
    {
        if (i) cout << '*';
        else cout << ' ';
    }
    cout << endl;
}

