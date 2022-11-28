//header file for Sentence class
#ifndef SENTENCE_H
#define SENTENCE_H
#include <algorithm>
#include <string>
#include <string.h>



class Sentence
{

    public:
        void run();

    private:

        std::string numbers[10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
        int sentence_num = 0;
        int sentence_len;
        std::string curr_letter;
        std::string curr_sentence;
        int curr_index;
        int found = 1;
        int letter_check;

        std::string sentenceMaterial(std::string);
        int count(std::string, std::string);
        bool fileCheck(std::string);
};

#endif
