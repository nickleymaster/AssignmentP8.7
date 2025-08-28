#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    char alphabet[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

    int n = sizeof(alphabet) / sizeof(alphabet[0]);

    cout << "Full alphabet: ";
    for (int i = 0; i < n; i++) 
    {
        cout << alphabet[i] << " ";
    }
    cout << endl;

    ifstream input_file("input.txt");
    if (!input_file.is_open()) 
    {
        cerr << "Error: Could not open input.txt" << endl;
        return 1;
    }

    string word;
    input_file >> word;
    cout << "Word read from file: " << word << endl;

    // remove duplicates
    unordered_set<char> seen_chars;
    string result_s;
    for (char c : word) 
    {
        if (seen_chars.find(c) == seen_chars.end()) {
            result_s += c;
            seen_chars.insert(c);
        }
    }

    cout << "Unique characters (order preserved): " << result_s << endl;

    // remove keyword chars from alphabet
    unordered_set<char> remove_set(result_s.begin(), result_s.end());
    string remaining;
    for (int i = 0; i < n; i++) 
    {
        if (remove_set.find(alphabet[i]) == remove_set.end()) {
            remaining.push_back(alphabet[i]);
        }
    }

    // build final vector = result_s + reversed remaining
    vector<char> final;

    // add keyword characters first
    for (char c : result_s) 
    {
        final.push_back(c);
    }

    // then add remaining in reverse order
    for (int i = remaining.size() - 1; i >= 0; i--) 
    {
        final.push_back(remaining[i]);
    }

    // print stored value
    cout << "Final vector: ";
    for (char c : final) 
    {
        cout << c << " ";
    }
    cout << endl;

    input_file.close();
    
    return 0;
}
