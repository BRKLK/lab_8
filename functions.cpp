#include<iostream>
#include<cmath>
#include<cctype>
#include"functions.hpp"

using namespace std;


void LabFuncs::Reading(string& text, int& n)
{
    cout << "Text: "; cin >> text;
    cout << "Number of words to find: "; cin >> n;
}

void SplitText(string text, string& words[2000], int& length)
{
    int l = text.length();
    string t = "";
    for(int i = 0, j = 0; i < l; i++)
    {
        char letter = text[i];
        if (letter != ' ' && letter != '.' && letter != ',') // if char is a letter
            t += text[i];
        else 
        {
            words[j] = t;
            t = "";
            j++;
            length++;
        }
    }
}


void SortWords(string allWords[2000], int length)
{
    for(int i = 0; i < length-1; i ++)
    {
        for(int j = i+1; j < length; j ++)
        {
            if (allWords[i].length() < allWords[j].length())
            {
                swap(allWords[i], allWords[j]);
            }
        }
    }
}

bool IsConsonantsAplphabet(string word)
{
    string t = "";
    //bcdfghjklmnpqrstvwxyz
    bool IsCharConsonant(char letter)
    {
        if((letter != 'a') && (letter != 'e') && (letter != 'i') && (letter != 'o') && (letter != 'u'))
            return true;
        else 
            return false;
    }

    //Filling t with all consonant chars
    for(int i = 0; i < word.length(); i++)
    {
        if(IsCharConsonant(tolower(word[i])))
            t += tolower(word[i])
    }

    if(t.length() == 0)
        return false;
    else if (t.length() == 1)
        return true;
    else
    {
        // If the order is not alphabetical return false
        for(int i = 0; i < t.length()-1; i++)
        {
            if ((int)t[i] > (int)t[i+1])
                return false;
        }
    }
    return true;
}

void ClearDuplicates(string words[2000], int l)
{
    for(int i = 0; i < l; )
}

void GettingWords(string text, string alphabetWords[2000], int n)
{
    string allWords[2000];
    int l = 0;
    SplitText(text, allWords, l);
    SortWords(allWords, l);

    for(int i = 0, j = 0; (i < l) && (j < n); i++)
    {
        if(IsConsonantsAplphabet(allWords[i]))
        {
            alphabetWords[j] = allWords[i];
            j++;
        }
    }
}
