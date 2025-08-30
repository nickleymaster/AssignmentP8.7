/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
** Class: 	CSC 242
** Assignment: 	Lesson #4
** File: 	source.cpp
** Description: This program reads a word from a file, removes duplicate characters
** from the word while preserving their order, and then constructs a final vector
** by combining the unique characters with the remaining alphabet characters in reverse order.
**
** Author: 	Nick Leymaster and Marcell Njei
** Date: 	Create Date
** -------------------------------------------------------------------------*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
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

    
	// error checking for file open
    ifstream input_file("input.txt");
    if (!input_file.is_open()) 
    {
        cerr << "Error: Could not open input.txt" << endl;
        return 1;
    }


    // create string from file
    string word;
    input_file >> word;
    cout << "Word read from file: " << word << endl;

    input_file.close();

	// remove duplicates from word while preserving order
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
        if (remove_set.find(alphabet[i]) == remove_set.end()) 
        {
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

	// print the keyword and reversed remaining characters
    cout << "Final vector: ";
    for (char c : final) 
    {
        cout << c << " ";
    }
    cout << endl;

	// create vector p_word from string input
	// p_word will be the plaintext word to be encoded
    
    string input = "hello";
    vector<char> p_word;

	for (char c : input) // add each character to p_word
    {
        p_word.push_back(c);
    }

    cout << "Plaintext characters in p_word: ";
    for (char c : p_word)
    {
        cout << c << " ";
    }
    cout << endl;

    // build cipher map
    unordered_map<char, char> cipher_map;
    for (int i = 0; i < n; i++)
    {
        cipher_map[alphabet[i]] = final[i];
    }

    // encrypt p_word
    string encrypted;
    for (char c : p_word)
    {
        if (cipher_map.find(c) != cipher_map.end()) 
        {
            encrypted.push_back(cipher_map[c]);
        }
        else {
            encrypted.push_back(c); // non-alphabet chars unchanged
        }
    }

    cout << "Encrypted word: " << encrypted << endl;





    return 0;
}
