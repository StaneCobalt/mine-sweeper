#ifndef __SPLIT_H
#define __SPLIT_H
#include <vector>
#include <string>
using std::vector;
using std::string;

const std::string delimiters = " \n\t~!@#%^&*()_+={}|\\{};:,.<>,?\"";

// split returns a vector of the "words" in s
// words are separated by delimiters 
vector<string> split(const string & s, const string& delim = delimiters){
	vector<string> v;
	string::size_type pos1, pos2=0;
	string::size_type n;
	string word;
	pos1=s.find_first_not_of(delim,pos2); //find first item not a delimiter starting at position 0
	while(pos1!=string::npos){ //npos = string size or end of string
		if((pos2=s.find_first_of(delim,pos1))==string::npos){ //if pos2 is at end of string
			word=s.substr(pos1); //last word is added in
			pos1=pos2; //pos1 goes to end of string
		}
		else{
			word=s.substr(pos1,pos2-pos1); //gets word from start of pos1, between pos1 and pos2
			pos1=s.find_first_not_of(delim,pos2); //pos1 finds the beginning of the next word
		}
		v.push_back(word); //the word is pushed into the vector
	}
	return v;
}

#endif