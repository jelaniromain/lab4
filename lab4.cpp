//============================================================================
// Name        : lab5.cpp
// Author      : jelani romain

//============================================================================
#include <iostream>
using namespace std;

float* UserInput(int&);
void ClearScreen();
void Average(float*,int);
void FindMinMax(float*,int);


int main(){

 int countVal=0;
 float* p =NULL;
 string confirm;


  do{
 p=UserInput(countVal);
 ClearScreen();

 cout<<"To Confirm Data Set Press the [ENTER] Key to Continue"<<endl;
 cout<<"To Re-Enter Data Type 'N' followed by the [ENTER] Key"<<endl;

 getline(cin,confirm);


	}

  while(confirm=="N");

Average(p,countVal);
FindMinMax(p,countVal);


}


float* UserInput(int &countVal){

  string input;
  float *p=NULL;
  float *tempPointer=NULL;
  float userInput=0.0;
  float sum=0.0;
  float average= 0.0;
  p= new float [countVal];


   	do
   	{
   	  cout << "Enter a float number: (enter Q to quit)" << endl;
         	getline(cin, input);

         	if (input!= "Q")
         	{
         	  userInput= stof(input);
         	  p[countVal]=userInput;
         	        countVal++;

         	  tempPointer= new float [(countVal)];

         	    for(int x=0; x<countVal; x++){
         	    	tempPointer[x]=p[x];
         	    }

         	  p=tempPointer;
   	   }

   	   	}
while (input != "Q");

  ClearScreen();
    cout << endl << "\t\t\t\tYou Have Entered " << countVal << " Data Values." << endl;

  for (int x=0; x<countVal;x++){
   cout<<"The ELEMENT "<<x+1<<" is "<<"["<<p[x]<<"]"<<endl;
  }
 return p;
}


void ClearScreen(){
  for (int x=0; x<5; x++){
	cout<<"\n"<<endl;
  }
}

void Average(float *p,int countVal){

float sum,average;

   	for (int x = 0; x < countVal; x++)
   	{
         	sum += p[x];

   	}

  average=  sum / countVal;

   	cout << "Your average value is: " <<average << endl;
}

void FindMinMax(float *p,int countVal){
float max,min;
max=min=p[0];


   	for (int x = 0; x < countVal; x++) {
                	if (min > p[x]) {
                      	min = p[x];
                	}
                	if (max < p[x]) {
                      	max = p[x];
                	}
   	}

cout<<"The maximum float value collected is "<<max<<endl;
cout<<"The minimum float value collected is "<<min<<endl;
}


