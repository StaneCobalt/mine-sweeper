#include "split.h"
#include <vector>
#include <string>
using std::vector;
using std::string;

vector<string> split(const string & s,const string & delim){
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

vector<string> csplit(const string & s,const string & accept){
	vector<string> v;
	string::size_type pos1, pos2=0;
	string::size_type n;
	string word;
	pos1=s.find_first_of(accept,pos2); //find first item that's acceptable starting at position 0
	while(pos1!=string::npos){
		if((pos2=s.find_first_not_of(accept,pos1))==string::npos){
			word=s.substr(pos1);
			pos1=pos2;
		}
		else{
			word=s.substr(pos1,pos2-pos1);
			pos1=s.find_first_of(accept,pos2);
		}
		v.push_back(word);
	}
	return v;
}