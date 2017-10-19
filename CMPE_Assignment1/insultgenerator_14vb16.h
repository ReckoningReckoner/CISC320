#ifndef INSULTGENERATOR_14VB16_H
#define INSULTGENERATOR_14VB16_H

#include<iostream>
#include <vector>
#include <exception>

using namespace std;

/*
 * Author: Viraj Bangari
 *
 * Reads a tab separated value file of insults, and generates them at random.
 * Can work with any number of columns. Each column specifies the order that a
 * word should be inserted.
 */
class InsultGenerator
{
    public:
        /* 
         * Loads the insults text file based on the insultsSourceFile
         * value. Then loads the insults into insultWords.
         */
        void initialize();

        /* Generates one insult at random */
        string talkToMe();

        /* Generates a specified number of unique insults, alphabetically sorted */
        vector<string> generate(int numberOfInsultsToGenerate);

        /* Generates a specified number of unique, sorted insults, and then saves them
         * to a text file. */
        void generateAndSave(string fileName, int numberOfInsultsToGenerate);

    private:
        static const string insultsSourceFile;

        /* Minimum and maximum number of insults */
        const static int minNumberOfInsults = 1;
        const static int maxNumberOfInsults = 10000;

        /* Keeps track of whether the file has been loaded. */
        bool hasLoadedFile = false;

        /* Where the insults themselves are stored. Each subvector corresponds
         * to a column of insults in insultsSourceFile */
        vector<vector<string> > insultWords;
        string createInsult(const vector<string> &insults);
        void createRandomUniqueInsults(vector<string> &insults,
                                       vector<string> &currentInsult,
                                       vector<int> &startIndexes,
                                       int column,
                                       int wordsPerColumn,
                                       int numberOfInsults);
};

class NumInsultsOutOfBounds : exception
{
    public:
        const char* what() const noexcept
        {
            return "Requested number of insults is out of bounds.";
        };
};

class FileException : exception
{
    public:
        const char* what() const noexcept
        {
            return "Insults text file does not exist and was not loaded.";
        };
};

#endif
