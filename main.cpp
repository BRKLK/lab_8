#include<iostream>
#include<cctype>
#include"functions.hpp"

using namespace std;
using namespace LabFuncs;


int main()
{
    string text, longest_alphabet_words[2000];
    int n;
    Reading(text, n);
    GettingWords(text, longest_alphabet_words, n);
}