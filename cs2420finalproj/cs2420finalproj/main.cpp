#include <fstream>				//Used for file input/output
#include <iostream>				//Used to display information to the consol window
#include <string>				//For strings
#include <sstream>				//Used to parse user input
using namespace std;

struct term{
	string word;
	term *next;
	int fileParent;
};

void initiate(struct term *root, string word){
	root->word = word;
	root->next = NULL;
}

void addWord(struct term *root, string word, int a){
	term *newTerm = new term;
	newTerm -> word = word;
	newTerm -> fileParent = a;
	newTerm->next = NULL;
	
	term *cur = root;
	while (cur){
		if(cur->next == NULL){
			cur->next = newTerm;
			return;
		}
		cur = cur->next;
	}
}

void searchNode(struct term *head, string word) {
	term *cur = head;
	while(cur) {
		if(cur->word == word){cout<<"Found in: "<< cur->fileParent<<" ";};
		cur = cur->next;
	}
	cout << "No Node " << word << " in list.\n";
}

void display(struct term *head){
	term *list = head;
	while(list) {
		cout << list->word << " ";
		list = list->next;
	}
	cout << endl;
	cout << endl;
}

int main(){
	const int docsNum=50;			//Number of documents to search through at the beginning
	string fileNames[docsNum];		//Array of strings to hold the filenames
	string masterFiles[docsNum];	//Array of strings to hold the master filenames
	string stopwords[55];			//Array of words we will not be using to search the files for.
	string data;					//The string we read in
	bool okWord = true;				//Boolean that determines if the word is not a stop word
	string searchQuery;				//Input from user for the search.
	
	ifstream myFile("stopwords.txt");																		//This opens up the stopwords file and stores the words we are avoiding into an array.
	for (int i=0; i<55;i++){
		string stopWord;
		getline(myFile,stopWord);
		stopwords[i]=stopWord;
							}
myFile.close();
term *root;


//for(int i=0;i<50;i++){																	//For loop that opens the input file ignores any lines starting with '<' and outputs the data
	//if(i<9){fileNames[i] = "cranfield000" + to_string(i+1) + ".txt";}
	//else{fileNames[i] = "cranfield00" + to_string(i+1) + ".txt";	}
//	masterFiles[i] = "masterFile" + to_string(i+1) + ".txt";
//		
//	ofstream masterFile(masterFiles[i],ios::app);
//	ifstream myFile;
//	myFile.open(fileNames[i]);
//	while(!myFile.eof()){
		//okWord = true;
		//myFile>>data;
		//if(data[0]!='<'){
		//	if (data.length()<5){
		//		int j=0;
		//		while(j<54){
		//			if(data == stopwords[j]){j=54; okWord=false;}
		//			j++;
		//					}								//Ends while loop for checking all the stop words
		//						}							//Ends if data string is less than 5 characters
		//		if(data.length()>5){okWord=true;}
		//		if(okWord == true){masterFile<<data<<" ";}
		//	}												//Ends if first characters is not '<' 
		//					

		//}													//ends while loop for not at end of file
		//myFile.close();
//		masterFile.close();
//		//cout<<"Parsing file: "<<i+1<<" of "<<docsNum<<endl;
//	}														//Ends for loop for parsing all files into new files

for (int i=0;i<50;i++){
	if(i<9){fileNames[i] = "cranfield000" + to_string(i+1) + ".txt";}
	else{fileNames[i] = "cranfield00" + to_string(i+1) + ".txt";	}

	ifstream myFile;
	myFile.open(fileNames[i]);
	while(!myFile.eof()){
		okWord = true;
		myFile>>data;
		if(data[0]!='<'){
		if (data.length()<5){
			int j=0;
			while(j<54){
				if(data == stopwords[j]){j=54; okWord=false;}
					j++;
							}								//Ends while loop for checking all the stop words
								}							//Ends if data string is less than 5 characters
				if(data.length()>5){okWord=true;}
				if(okWord == true){addWord(root,data,i);				}
			}												//Ends if first characters is not '<' 
							

		}													//ends while loop for not at end of file
		myFile.close();


}


//cout<<"Please enter your search query. Incorrect queries will return an error message."<<endl;
//cin>>searchQuery;

display(root);
  return 0;

}