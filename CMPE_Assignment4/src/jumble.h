/*
 * Author: Viraj Bangari
 *
 * Class that handles the creation of the jumble puzzle.
 */
#ifndef JUMBLE_h
#define JUMBLE_h value

#include <string>
#include <exception>
#include <cstdlib>

typedef int Difficulty;

class JumblePuzzle {
 public:
    JumblePuzzle(std::string hiddenWord, std::string difficulty);

    /*
     * Big 3.
     */
    JumblePuzzle(JumblePuzzle&);
    JumblePuzzle& operator=(JumblePuzzle&);
    ~JumblePuzzle();

    /*
     * Get methods
     */
    char** getJumble() { return puzzle; }
    const std::string& getHiddenWord() { return hiddenWord; }
    int getSize() { return puzzleSize; }
    int getRowPos() { return rowPos; }
    int getColPos() { return colPos; }
    char getDirection() { return direction; }

 private:
    /*
     * Private constants
     */
    static const Difficulty EASY = 2;
    static const Difficulty MEDIUM = 3;
    static const Difficulty HARD = 4;

    /*
     * Initializes the difficulty based on the constructor args.
     */
    static Difficulty initDifficulty(std::string&);

    /*
     * Initializes the hidden word based on the constructor args.
     */
    static const std::string initHiddenWord(std::string);

    /*
     * Private helper method for generating a puzzle
     */
    static char** generatePuzzle(int puzzleSize, 
                                 char direction, 
                                 int rowPos, 
                                 int colPos, 
                                 const std::string& hiddenWord);

    /*
     * Modifies an array of chars to have the valid directions.
     * Returns the number of valid valid directions.
     */
    static int getValidDirections(int rowPos,
                                  int colPos,
                                  int puzzleSize,
                                  const std::string& hiddenWord,
                                  char* outDirections);

    Difficulty difficulty;
    std::string hiddenWord;
    char** puzzle;
    int puzzleSize;
    char direction;
    int rowPos;
    int colPos;
};

class BadJumbleException : public std::exception {
 public:
     BadJumbleException(const char* message_) : message(message_) {};
     const char* what() const throw () { return message; }
 private:
     const char* message;
};


#endif /* ifndef JUMBLE_h */
