// TODO: remove this comment header

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include "strlib.h"
#include "stack.h"

using namespace std;


int main() {
    cout << "Welcome to Word Ladder." << endl;
    runWordLadder();
    

    cout << "Have a nice day." << endl;
    return 0;
}

// Runs Word Ladder program
void runWordLadder() {
    cout << "Please give me two English words, and I will change the first into the second by changing one letter at a time." << endl;
    Lexicon dictionary = openDictionary(); // Initializes a new lexicon containing words from a dictionary txt file
    while (true) {
        string word1 = getWordOne(dictionary);
        if (word1 == "") { // If empty string is entered, quits program.
            return;
        }
        string word2 = getWordTwo(word1, dictionary); 
        if (word2 == "") { // If empty string is entered, quits program.
            return;
        }

        findShortestWordLadder(word1, word2, dictionary);
    }
}

Lexicon openDictionary() {
    string filename = getLine("Dictionary file name? ");
    Lexicon lex(filename); // reads in the contents from the data file. Must be text file containing 1 word per line. Or a space-efficient precompiled binary format.
    return lex;
}

// Asks user to input the first word. Returns string in lower case.
// TO DO: Combine with getWordTwo
string getWordOne(Lexicon &dic) {
    string w1;
    while (true) {
        w1 = getLine("Word #1 (or Enter to quit): ");
        if (dic.contains(w1)) {
            break;
        }
        cout << "I can't find that word in the dictionary. Try another word." << endl;
    }
    return toLowerCase(w1);
}

/* Asks user to input second word. Loops until the user inputs a second word of same length as word one */
string getWordTwo(string w1, Lexicon &dic) {
    string w2;
    while (true)  {
        w2 = getline("word #2 (or enter to quit): ");
        if (wordIsValid(w1, w2, dic)) {
            break;
        }
    }  
    return toLowerCase(w2);
}

// Returns true if w2 is of the same length as w1
bool wordIsValid(string w1, string w2, Lexicon &dic) {
    if (w1.length != w2.length) {
        cout << "The second word needs to be the same length of the first. Try again." << endl;
        return false;
    } 
    if (!dic.contains(w2)) {
        cout << "I can't find that word in the dictionary. Try another word." << endl;
        return false;
    }
    return true;
}

// Find the shortest word ladder between strings w1 and w2
void findShortestWordLadder(string w1, string w2, Lexicon &dic) {

    Queue<Stack<string> > wordLadders; // Create an empty queue of stacks

    Stack<string> start; // Create and add a stack containing w1 to the queue
    start.push(w1); 
    wordLadders.enqueue(start);
    
    while (!wordLadders.isEmpty()) {
        Set<string> usedWords; // Initialize a set to hold all words that we have addded to a partial-ladder stack
        Stack<string> partialLadder = wordLadders.dequeue(); // Dequeue the partial-ladder stack from the front of the queue
        string topWord = partialLadder.peek(); // Retrieve the word on top of the stack
        
        Set<string> neighbors = findNeighborWords(topWord, dic);
        for (int i = 0; i < set.size(); i++) {
            if (!usedWords.contains(set[i]) {
                if (set[i] == w2) {
                    partialLadder.push(set[i]);
                    printWordLadder(partialLadder); // Prints out the word ladder
                    return;
                }
                
                partialLadder.push(set[i]);
                usedWords.add(set[i]);
            }
        }

    }
}
