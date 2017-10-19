#include <fstream>
#include <ctime>
#include <math.h>
#include <time.h>

#include "insultgenerator_14vb16.h"

const string InsultGenerator::insultsSourceFile = "./InsultsSource.txt";

void InsultGenerator::initialize()
{
    if (this->hasLoadedFile)
    {
        return;
    }

    // Seed for the random number generator.
    srand(static_cast<unsigned int>(time(nullptr)));

    ifstream sourceFile;
    sourceFile.open(InsultGenerator::insultsSourceFile);

    if (!sourceFile)
    {
        throw FileException();
    }

    string currentLine = "";
    while (getline(sourceFile, currentLine))
    {
        int i = 0;
        int columnIndex = 0;
        string currentInsult = "";

        while (i < currentLine.length())
        {
            if (currentLine[i] == '\t')
            {
                if (this->insultWords.size() == columnIndex)
                {
                    this->insultWords.push_back(vector<string>());
                }
                this->insultWords[columnIndex].push_back(currentInsult);
                columnIndex++;
                currentInsult = "";
            }
            else
            {
                currentInsult += currentLine[i];
            }
            i++;
        }

        if (this->insultWords.size() == columnIndex)
        {
            this->insultWords.push_back(vector<string>());
        }
        this->insultWords[columnIndex].push_back(currentInsult);
    }

    sourceFile.close();

    if (this->insultWords.size() > 0)
    {
        this->hasLoadedFile = true;
    }
    else
    {
        throw FileException();
    }
}

string InsultGenerator::talkToMe()
{
    if (!hasLoadedFile)
    {
        this->initialize();
    }

    vector<string> insultingWords;
    for (vector<string> &insultColumn : this->insultWords)
    {
        insultingWords.push_back(insultColumn[rand() % insultColumn.size()]);
    }

    return this->createInsult(insultingWords);
}

vector<string> InsultGenerator::generate(int numberOfInsultsToGenerate)
{
    double start = clock();
    if (!hasLoadedFile)
    {
        this->initialize();
    }

    if (numberOfInsultsToGenerate < InsultGenerator::minNumberOfInsults ||
            numberOfInsultsToGenerate > InsultGenerator::maxNumberOfInsults)
    {
        throw NumInsultsOutOfBounds();
    }

    double numberOfColumns = this->insultWords.size();
    int wordsPerColumn = static_cast<int>(pow(numberOfInsultsToGenerate, 1.0/numberOfColumns) + 1);

    cout << clock() - start << endl;

    // Randomly generates the first index of insults to generate per column.
    vector<int> startIndexes;
    for (vector<string> &insultColumn : this->insultWords)
    {
        int insultStartIndex = static_cast<int>(rand() % (insultColumn.size() - (wordsPerColumn - 1)));
        startIndexes.push_back(insultStartIndex);
    }

    cout << clock() - start << endl;

    vector<string> insults;
    vector<string> currentInsult;
    currentInsult.resize((unsigned long) numberOfColumns);
    this->createRandomUniqueInsults(insults, currentInsult, startIndexes, 0, wordsPerColumn, numberOfInsultsToGenerate);
    cout << clock() - start << endl;

    return insults;
}

void InsultGenerator::createRandomUniqueInsults(vector<string> &insults,
                                                vector<string> &currentInsult,
                                                vector<int> &startIndexes,
                                                int column,
                                                int wordsPerColumn,
                                                int numberOfInsultsToGenerate)
{
    int counter = 0;
    for (int i = startIndexes[0]; i < startIndexes[0] + 100; i++) {
        currentInsult[0] = this->insultWords[0][i];
        for (int j = startIndexes[1]; j < startIndexes[1] + 100; j++) {
            currentInsult[1] = this->insultWords[1][j];
            for (int k = startIndexes[2]; k < startIndexes[2] + 100; k++) {
                if (counter < numberOfInsultsToGenerate) {
                    counter++;
                } else {
                    cout << "# Iterations " << counter << "\n";
                    return;
                }
                insults.push_back("Thou " + currentInsult[0] + " " + currentInsult[1] + " " + currentInsult[2] + "!");
            }
        }
    }
}

void InsultGenerator::generateAndSave(string fileName,
                                      int numberOfInsultsToGenerate)
{
    vector<string> insults = this->generate(numberOfInsultsToGenerate);

    ofstream outputFile;
    outputFile.open(fileName);
    for (string &insult : insults)
    {
        outputFile << insult + "\n";
    }

    outputFile.close();
}

string InsultGenerator::createInsult(const vector<string> &insults)
{
    string insult = "Thou ";
    for (int i = 0; i < insults.size(); i++)
    {
        insult += insults[i];
        if (i != insults.size() - 1)
        {
            insult += " ";
        }
    }
    return insult + "!";
}
