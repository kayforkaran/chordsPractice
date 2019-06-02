#include<bits/stdc++.h>
using namespace std;
string chordType[] = {"Major", "Minor"};
string chordVariation[] = {"Flat", "Sharp"};
string chordInversion[] = {"First", "Second"};
string includePrompt = "Do you want to include ";
string choicePrompt = "?(y/n)";
void getChoice(string, bool);
bool isIncluded(char choice, string choiceFor, bool &choiceStore){
	if(choice == 'y' || choice == 'Y')
		return true;
	else if(choice == 'n' || choice == 'N')
		return false;
	cout<<"Please enter valid character."<<endl;
	getChoice(choiceFor, choiceStore);
}
void getChoice(string choiceFor, bool &choiceStore){
	char choice;
	cout<<includePrompt<<choiceFor<<choicePrompt<<endl;
	cin>>choice;
	isIncluded(choice, choiceFor, choiceStore);
}
void generate(bool typeIncluded, bool variationIncluded, bool inversionIncluded){
	char chord = 'A' + (rand() % 7);
	string typeString = "", variationString = "", inversionString = "";
	if(typeIncluded)
		typeString = " " + chordType[rand()%2];
	if(variationIncluded)
		variationString = " " + chordVariation[rand()%2];
	if(inversionIncluded)
		inversionString = chordInversion[rand()%2] + " inversion of";
	cout<<"Play "<<inversionString<<chord<<variationString<<typeString<<" chord."<<endl;
	getchar();
}
int main(){
	bool typeIncluded, variationIncluded, inversionIncluded;
	getChoice("black keys", variationIncluded);
	getChoice("Major/Minor Variations", typeIncluded);
	getChoice("inversions", inversionIncluded);
	while(1)
		generate(typeIncluded, variationIncluded, inversionIncluded);
	return 0;
}