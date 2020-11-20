/**
 * Run-length encoding a form of lossless data compression 
 * in which runs of data (sequences in which the same data value occurs in 
 * many consecutive data elements) are stored as a single data value and count, 
 * rather than as the original run. 
 * 
 * For example, 
 * WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWBWWWWWWWWWWWWWW
   With a run-length encoding (RLE) data compression algorithm applied to the above hypothetical scan line, 
   it can be rendered as follows:
      9W3W1B9W3W3B9W9W6W1B9W5W

    Given a string, return the RLE of the string.
 **/

#include<bits/stdc++.h>
using namespace std;
//Approach: O(n) time & space
string runLengthEncoding(string str) {
  string res = "";
	int i = 0, count = 1;
	while(i < str.length()-1){
		if(count == 9){
			res += "9";
			res.push_back(str[i]);
			count = 1;
			i++;
			continue;
		}
		if(str[i] == str[i+1]){
			count++;
		}
		else{
			res += to_string(count);
			res.push_back(str[i]);
			count = 1;
		}
		i++;
	}
	res += to_string(count);
	res.push_back(str[str.length() - 1]);
	return res;
}
int main(){
  string str;
  cin>> str;
  string result = runLengthEncoding(str);
  cout<<result<<"\n";
}