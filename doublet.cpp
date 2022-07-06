#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<list>
#include<iterator>
#include <queue>
#include <set>
#include <map>
#include "MinHeap.h"
#include <map>

using namespace std;

/* struct for Node that is used later in the Heap. Stores
   the current string variable that is being compared as well as the
   number of steps
*/
struct Node{
    std::string current;
    int numOfSteps;
    int numCharacters;
};

void makeUpper(string& in);
int heuristic(std::string currWord, std::string endWord);
void aStar(MinHeap<Node>& heap, map<string, vector<std::string> >& adj_list, std::string endWord, set<std::string>& seenWords);

/* aStar is a path search algo, in this case used to find the shortest transformation between
   the start and end words
*/
void aStar(MinHeap<Node>& heap, map<string, vector<std::string> >& adj_list, std::string endWord, set<std::string>& seenWords){
    
    while(!heap.isEmpty()) {

       const Node topNode =  heap.peek();
       heap.remove();
       
       if(topNode.current == endWord){
           cout << topNode.numOfSteps << endl;
           
           cout << seenWords.size() << endl;
           return;
       }
       seenWords.insert(topNode.current);
       int currSteps = topNode.numOfSteps;
       string currString = topNode.current;
       
       for(int i = 0 ; i < adj_list[currString].size(); i ++){
           string wordAdj = adj_list[currString][i];
           if(seenWords.find(wordAdj) == seenWords.end()){

               int f = heuristic(wordAdj, endWord) + (currSteps + 1);
               Node newNode;
               newNode.current = wordAdj;
               newNode.numOfSteps = currSteps +1;
               heap.add(newNode, f);
           }
       }
    }
    cout << "No transformation" << endl;
    cout << seenWords.size()  << endl;

}

/* Main function that reads in the start and end words as well as the text file that contains
   the word bank. Other core functionality as the creation of the adjacency list, heap object
   conversion to uppercase is executed in this function
*/
int main(int argc, char *argv[]){

    string start = argv[1];
    string end = argv[2];
    string fileName = argv[3];
    if(start == end){
        
        return 0;
    } else if( start.size() != end.size()){
        return 0 ;
    }

int numWords;
work

if (!infile)
{
    cout << "Cannot open " << fileName << "!" << endl;
    return 1;
}

infile >> numWords;

map<string, set<string> >adj_word_list;
vector<string> vec;
set <std::string> setOfWords;

map<string, vector<std::string> > adj_list;

for (int i = 0; i < numWords; i++){
    string uppercase;
    infile >> uppercase;
    if(uppercase.size() < start.size()){
        continue;
    }
    makeUpper(uppercase);

    setOfWords.insert(uppercase);
    vec.push_back(uppercase);
}
makeUpper(start);
makeUpper(end);
setOfWords.insert(start);
vec.push_back(start);
setOfWords.insert(end);
vec.push_back(end);


Node StartNode;
StartNode.current = start;
StartNode.numOfSteps = 0;
StartNode.numCharacters = 0;
int h = heuristic(start, end);


set<std::string> seenWords;
 
a
MinHeap<Node> heap(2);
heap.add(StartNode,h);



for(int i = 0; i < (int)vec.size(); i ++ ){
    std::string tempWord = vec[i];

    for (int j = 0; j < (int)tempWord.size(); j++){
        for(char k = 'A'; k <= 'Z'; k+=1){
            tempWord[j] = k;
            if(setOfWords.find(tempWord) != setOfWords.end()){
                adj_list[vec[i]].push_back(tempWord);
            }
        }
        tempWord = vec[i];
    }
}

aStar(heap, adj_list, end, seenWords);
return 0;
}


/* Converts all the strings in the input file to uppercase to avoid
   issues with comparisons
*/
void makeUpper(string& in){
    for (int i = 0; i < in.length(); i++){
        in[i] = toupper(in[i]);
    }
}

/* calculates the h value of a current word in relation to the end word
*/
int heuristic(std::string currWord, std::string endWord){
    int count = 0 ;
    for(int i = 0; i < currWord.size();i++){
        if(currWord[i] != endWord[i]){
            count++;
        }
    }
    return count;
}
