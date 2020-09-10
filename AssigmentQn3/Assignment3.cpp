#include<iostream>
#include <string>
#include <vector>
#include <sstream> //istringstream
#include <fstream> // ifstream
using namespace std;
int main(){
	fstream fin1; 
	fstream fin2; 
	fstream fin3; 
	int flag=0;
    fin1.open("experts.csv", ios::in); 
   // fin2.open("slots.csv", ios::in);
//    fin3.open("caretakers.csv", ios::in);
    vector<string> row1; 
    vector<string> row2; 
    vector<string> row3; 
    string line1, word1, temp1;
	string line2, word2, temp2;
	string line3, word3, temp3;
	string careTakerID;
    while(fin1){
    //	cout<<fin1<<endl;
    	flag=0;
    	row1.clear(); 
    	if(!getline(fin1, line1)){
    		cout<<"error"<<endl;
		}
        getline(fin1, line1); 
       // cout<<"Line1 is: "<<line1<<endl;
        stringstream s1(line1); 
        while (getline(s1, word1, ',')) { 
            //cout<<word1<<endl;
            row1.push_back(word1); 
        } 
        fin2.open("slots.csv", ios::in);
        while(fin2 >> temp2){
        
    	row2.clear(); 
    	if(!getline(fin2, line2)){
    		cout<<"error"<<endl;
		}
        getline(fin2, line2); 
        stringstream s2(line2); 
        while (getline(s2, word2, ',')) { 
            row2.push_back(word2); 
        } 
       
        if(row1[0]==row2[1] && row2[6]=="active" && row2[8]=="TRUE"){
        	careTakerID=row2[10];
        	fin3.open("caretakers.csv", ios::in);
        	 while(fin3 >> temp3){
    	       row3.clear(); 
               getline(fin3, line3); 
               stringstream s3(line3); 
               while (getline(s3, word3, ',')) { 
                   row3.push_back(word3); 
               } 
               if(row3[0]==careTakerID){
               	cout<<row3[1]<<endl;
               	flag=1;
               	break;
			   }
	    	}
	    	if(flag==1){
	    	break;
			}
    	}
    	else if(row1[0]==row2[1]&& row2[6]=="deleted"){
    	//	cout<<row1[0]<<endl;
    		cout<<"no active slots"<<endl;
    		break;
		}
        else if(row1[0]==row2[1]&&row2[8]=="FALSE"){
        	cout<<"no bookings"<<endl;
        	break;
		}
		
	}
	
}
}
