#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "Sentence.h"

using namespace std;

// checks the file exits
bool Sentence::fileCheck(string name)
{
    ifstream file;
    file.open(name.c_str());

    if (!file)
        return true;
    else
        return false;

    file.close();
}

/* this function takes a sentence and counts how many
    times a letter is displayed in the sentence */
int Sentence::count(string sentence, string letter)
{
     int letter_count = 0;

     for (int a=0; a < sentence.length(); a++)
     {
         string letterOn(1, sentence[a]);
         if (strcasecmp(letterOn.c_str(), letter.c_str()) == 0)
             letter_count = letter_count + 1;
     }

     return letter_count;
}

/* this function takes a file then counts a letter and
   displays the corresponding number in a sentence*/
string Sentence::sentenceMaterial(string name)
{
    ifstream file;
    file.open(name.c_str());

    int tuple_len, letter_len;
    file >> tuple_len;
    /* this will loop through the two tuples to get the letters wanted
       to search and the sentence that will appear*/
    for (int i=0; i < tuple_len; i++)
    {
        cout << "Sentece" << " " << i+1 <<":\n";
        string curr_sentence;
        sentence_num = sentence_num + 1;

        // next two loops will make a list of letters and a list of words
        file >> letter_len;
        string letters[letter_len];
        for (int i=0; i < letter_len; i++)
        {
             file >> letters[i];
        }

        file >> sentence_len;
        string words[sentence_len];
        for (int i=0; i < sentence_len; i++)
        {
            file >> words[i];
        }

        /* these loops will put together the senetence
           and check if it is the correct statement. If no
           true statment found it will display an Error */
        for (int i=0; i < letter_len; i++)
        {
            letter_check = letter_check + 1;
            for (int j=0; j<10; j++)
            {

                for (int k=0; k <sentence_len; k++)
                {
                    if (words[k] == "?")
                    {
                        curr_sentence = curr_sentence + letters[i] + " ";
                    }
                    else if (words[k] == "#")
                        curr_sentence = curr_sentence + numbers[j] + " ";
                    else
                        curr_sentence = curr_sentence + words[k] + " ";


                     if ((k+1) == sentence_len)
                     {
                         if (count(curr_sentence, letters[i]) == (j+1))
                         {
                             cout << curr_sentence << "\n";
                             found = 1;
                         }
                         else if (letter_check >= 9 && found != 0)
                         {
                             cout << "ERROR: no match for " << letters[i] << "\n";
                             letter_check = 0;
                         }

                         curr_sentence.clear();
                     }
                }
            }

        }





    }

    return "0";
}

/*will take file and create a sentence displaying a letter
  and how many times that letter is displayed in that sentence*/
void Sentence::run()
{
    string fileName;
    cout << "Name of sentence file to read in: ";
    cin >> fileName;
    if (fileCheck(fileName))
        exit(0);
    else
    {
        cout << "File successfully read in!\n";
        sentenceMaterial(fileName);
    }
}

