#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

const int alphabetSize = 26;
unsigned int frequencies[alphabetSize];
char letters[alphabetSize];
ifstream userFile;

void getFileName(){
    string fileName;

    cout << "Please provide the name of a text file with the .txt extension: ";
    cin >> fileName;
    userFile.open(fileName);

    //Check if the file exists
    while(!userFile.is_open()){
        cout << "That is not an existing file. Please enter another file name with the .txt extension included: ";
        cin >> fileName;
        userFile.open(fileName);
    }
}

void countFreq(){
    //Count frequencies of English letters and ignore all other characters
    char letter;
    while(userFile.get(letter)){
        if(isalpha(letter)){
            letter = toupper(letter);
            frequencies[letter - 'A']++;
        }
    }
    userFile.close();

    //Display the letter frequencies in alphabetical order
    for(int i = 0; i < alphabetSize; i++){
        letters[i] = 'A' + i;
    }
    for(int j = 0; j < alphabetSize; j++){
        if(frequencies[j] > 0){
            cout << letters[j] << ": " << frequencies[j] << endl;
        }
    }
}

void sortAscending(){
    cout << "Sorting the letter frequencies in ascending order..." << endl;

    //sort the letters in ascending order of their frequencies using bubble sort
    for(int i = 0; i < alphabetSize - 1; i++){
        for(int j = 0; j < alphabetSize - i - 1; j++){
            if(frequencies[j + 1] < frequencies[j]){
                swap(frequencies[j], frequencies[j + 1]);
                swap(letters[j], letters[j + 1]);
            }
        }
    }

    //Display the sorted letters
    for(int k = 0; k < alphabetSize; k++){
        if(frequencies[k] > 0){
            cout << letters[k] << ": " << frequencies[k] << endl;
        }
    }
}

int main(){
    getFileName();
    countFreq();
    sortAscending();
    return 0;
}
