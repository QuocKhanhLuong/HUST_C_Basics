#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

const char *articles[] = {"the", "a", "one", "some", "any"};
const char *nouns[] = {"boy", "girl", "dog", "town", "car"};
const char *verbs[] = {"drove", "jumped", "ran", "walked", "skipped"};
const char *prepositions[] = {"to", "from", "over", "under", "on"};

void capitalize(char *string)
{
    string[0] = toupper(string[0]);
}

void generateSentences(char *sentences)
{
    sprintf(sentences, "%s %s %s %s %s %s.",
        articles[rand() % 5],
        nouns[rand() % 5],
        verbs[rand() % 5],
        prepositions[rand() % 5],
        articles[rand() % 5],
        nouns[rand() % 5]);
    capitalize(sentences);
}

int main()
{
    srand(time(NULL));
    char sentence[100];

    for(int i = 0; i < 20; i++)
    {
        generateSentences(sentence);
        printf("%s\n", sentence);
    }
    return 0;
}