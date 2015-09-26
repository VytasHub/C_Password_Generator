#include <ctype.h> // make copy of a string
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // looks for samll word in string


//1. Passwords must be at least 9 characters long and less than L5 characters.
//2. Passwords must have at least 2 numbers in them.
//3. Passwords must have at least 2 uppercase letters and 2 lowercase letters in them.
//4. Passwords must have at least 1 symbol in them (eg ?, S, f, %). you may define a set of
//acceptable symbols to use


void main()
{
	//play with ranges wehn generating pasword to achive all the rquirements

char myFileName[15+1];
char myFileNamCopy[15+1];
char passwordTemp[15+1];
char strAlpha[] = {"0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWYZ!#$%&'*+,-./"};  // 26 +26 + 10 +12 = 73 SO 72 Starts at 0
char digits[] =  {"0123456789"};
char lowerCase[] ={"abcdefghijklmnopqrstuvwxyz"}; //26 so 25 because starts at 0
char uperCase[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
char special[] = {"!#$%&@?"};
char myString [15+1];
char myStringCopy[15+1];
char comonWord[5+1];
int myNumber=0;
int iPos;
int alphaPosition;
int digitsInPasword = 0;
int lowerCaseInPasword = 0;
int upperCaseInPasword = 0;
int specialCahr = 0;
int temporary, randomNum, last; // Shufle variables
FILE *fptr;
FILE *comWord;
int passGood ;
int passwordFlag = 1;
int totalChars =0;
int ok;
int userPassFlag;
int userCommonWordsFlag;


// num range  0-9
// lower abc  10- 35
// uper abc   36 -60
// special char 61 -72

int passwordLen, tempNum, counter;

while(myNumber!=3)
{
//fflush(stdin);


//myFileName[16] = '\0';
printf("\n");
printf("\n1.Generate Password \n2.Check Password\n3.To EXIT\n\nEnter your option:");
scanf("%d", &myNumber);



	if(myNumber==1)
	{//If loop start
	
	int a = rand() % 10;
	int b = rand() % 10;
	int c = rand() % 26;
	int d = rand() % 26;
	int e = rand() % 26;
	int f = rand() % 26;
	int g = rand() % 7;
	int h = rand() % 73;
	int i = rand() % 73;

	tempNum = rand() % 6;
	//printf("%d", tempNum);
	passwordLen  = 9 + tempNum;

	myFileName[0] = digits[a];
	myFileName[1] = digits[b];
	myFileName[2] = lowerCase[c];
	myFileName[3] = lowerCase[d];
	myFileName[4] = uperCase[e];
	myFileName[5] = uperCase[f];
	myFileName[6] = special[g];
	myFileName[7] = strAlpha[h];
	myFileName[8] = strAlpha[i];
	
	// Loop for all the extra chars
	
	for(counter = 9; counter < passwordLen; counter++)
	{
		myFileName[counter] = strAlpha[rand() % 72];
	}
	
	// Loop for all extra chars


	 // = to 0 so it wount print out crap at the end Terminates whe sees 0
	
	//////////////////////////////////////////////////////////////////////
	//Shufles the chars in password
	for (last = passwordLen; last > 1; last--)
	{
	randomNum = rand( ) % last;
	temporary = myFileName[randomNum];
	myFileName[randomNum] = myFileName[last - 1];
	myFileName[last - 1] = temporary;
	}
	//Shufles the chars in password
	myFileName[passwordLen] ='\0'; 
	myFileNamCopy[passwordLen] ='\0';
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	printf("\n ");
	printf("\n%s",myFileName); 	     //// Prints out password
	printf("\n ");
	strncpy(myFileNamCopy,myFileName, 15);    /// Makes a Copy of the char Array
	///////////////////////////////////////////
	
	
	for(iPos = 0; iPos <passwordLen ; iPos++)
	{
			myFileNamCopy[iPos] = tolower(myFileNamCopy[iPos]);   ////////// Converts to lowercase before checking for comon words
	} 
	
	printf("\n");  

	fflush(stdin);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	fptr = fopen("GeneratedPasswords.txt","a+"); // Opens and adds a file a+

	if (fptr == NULL)  //Creates a file if does not exist
	{
		printf("There is no file");
	}
	else
	{
		passwordFlag = 1;
		while(fscanf(fptr,"%s",  &passwordTemp) == 1 )  //Checks all previuos passwords
		{
			if(strcmp(myFileName,passwordTemp) == 0 )
			{
				passwordFlag = 0;
				printf("\nPassword allready been used"); //if password is used just sez that is not Unique and does not put it to txt file
				printf("\nNot Stored");  
			}
		
		}
	}
	fclose(fptr);// Close file
	/////////////////////////////////////////////////////////////////////////////////////////////////
	comWord = fopen("CommonWords.txt","r+"); // Reads the files r+	== reading	
	ok=1;
	while (fscanf(comWord, "%s", &comonWord) == 1)
	{
			if(strstr(myFileNamCopy, comonWord))
			{
				ok =0;
				printf("\nPassword contains: %s",comonWord);
				printf("\nNot Stored");                             //CHECKS FOR COMMON WORDS
			}
	}

	if(passwordFlag == 1 && ok ==1)//If no previuos password flag remains 0 and file is writen to GeneratedPasswords.txt
	{
		printf("\nPassword is unique has not been generated before");
		printf("\nAnd does not Contain common word");
		printf("\nIts been stored to GeneratedPasswords.txt ");
		
		fptr = fopen("GeneratedPasswords.txt","a+");
		fprintf(fptr,"%s \n", myFileName);    //If password is unique than puts it to file
		fflush(stdin);
	}
	fclose(fptr);
	fclose(comWord);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	for(iPos = 0; iPos < passwordLen; iPos++)
	{// Main For loop start
		myFileName[iPos];
		
		// Loop counts digits in Password
		for( alphaPosition = 0;  alphaPosition < 10;  alphaPosition++)///////
		{// DigitvFor loop start

			if(myFileName[iPos]==digits[alphaPosition])
			{//If loop start 
				digitsInPasword++;
			}// If loop end
		}// Digit For loop end///////////////////////////////////////////////

	    //Loop counts lowercase in password
		for( alphaPosition = 0;  alphaPosition < 26;  alphaPosition++)//////
		{//  lowercase For loop start

			if(myFileName[iPos]==lowerCase[alphaPosition])
			{//If loop start 
				lowerCaseInPasword++;		
			}// If loop end
		}//  lowercase For loop end/////////////////////////////////////////

		//Loop upper case in password
		for( alphaPosition = 0;  alphaPosition < 26;  alphaPosition++)/////
		{//  Upper case For loop start

			if(myFileName[iPos]==uperCase[alphaPosition])
			{//If loop start 
				upperCaseInPasword++;

			}// If loop end/////////////////////////////////////////////////

		}//  Upper case For loop end

		// Loop for special characters
		for( alphaPosition = 0;  alphaPosition < 7;  alphaPosition++)/////
		{//  Special char For loop start

			if(myFileName[iPos]==special[alphaPosition])
			{//If loop start 
				specialCahr++;
			}// If loop end///////////////////////////////////////////////

		}//Special char For loop end
		
	
	}// Main For loop end
	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	printf("\n");
	printf("\nDigits: %d ",digitsInPasword);
	printf("\nLower Case: %d ",lowerCaseInPasword);
	printf("\nUpper Case: %d ",upperCaseInPasword);
	printf("\nSpecial Caharcter: %d ",specialCahr);
	printf("\nPassword Lenght: %d",passwordLen);
	
	
	upperCaseInPasword = 0;
	digitsInPasword = 0;
	lowerCaseInPasword = 0;
	specialCahr = 0;
	totalChars = 0;

	printf("\n\n");

	myFileName[0] = NULL;
	}//If loop end

	else if(myNumber==2)
	{//If statment  2 starts
	upperCaseInPasword = 0;
	digitsInPasword = 0;
	lowerCaseInPasword = 0;
	specialCahr = 0;
	totalChars = 0;
	
	printf("\n");
	printf("\nMinimum Password Requiremnets");
	printf("\nDigits:2 ");
	printf("\nLower Case:2 ");
	printf("\nUpper Case:2 ");
	printf("\nSpecial Caharcter:1  List of Characters !#$%&@?");
	printf("\nPassword Lenght:9-15 ");
	printf("\n");


		printf("\nEnter your password:");
		scanf("%s", &myString);
		printf("\n %s",myString);  // Prints out entered Password
		//myStringCopy
		strncpy(myStringCopy,myString, 15);  // Makes a copy of char Array
		/////////////////////////////////////////////////////////////////////////
		
		//////////////////////////////////////////////////////////////////////////
		for(iPos = 0; iPos <15 ; iPos++)
		{
			myStringCopy[iPos] = tolower(myStringCopy[iPos]);   ////////// Converts to lowercase before checking for comon words
		} 
		/////////////////////////////////////////////////////////////////////////
		printf("\n");  
		///////////////////////////////////////////////////////////////////////////////////////////////
		for(iPos = 0; iPos < 15; iPos++)
		{// Main For loop start
		myString[iPos];
		
		// Loop counts digits in Password////////////////////////////////////
		for( alphaPosition = 0;  alphaPosition < 10;  alphaPosition++)
		{// DigitvFor loop start
			if(myString[iPos]==digits[alphaPosition])
			{//If loop start 
				digitsInPasword++;
			}// If loop end
		}// Digit For loop end///////////////////////////////////////////////

	    //Loop counts lowercase in password//////////////////////////////////
		for( alphaPosition = 0;  alphaPosition < 26;  alphaPosition++)
		{//  lowercase For loop start
			if(myString[iPos]==lowerCase[alphaPosition])
			{//If loop start 
				lowerCaseInPasword++;
			}// If loop end
		}//  lowercase For loop end//////////////////////////////////////////

		//Loop upper case in password////////////////////////////////////////
		for( alphaPosition = 0;  alphaPosition < 26;  alphaPosition++)
		{//  Upper case For loop start
			if(myString[iPos]==uperCase[alphaPosition])
			{//If loop start 
				upperCaseInPasword++;
			}// If loop end
		}//  Upper case For loop end/////////////////////////////////////////

		// Loop for special characters///////////////////////////////////////
		for( alphaPosition = 0;  alphaPosition < 7;  alphaPosition++)
		{//  Special char For loop start

			if(myString[iPos]==special[alphaPosition])
			{//If loop start 
				specialCahr++;
			}// If loop end
		}//Special char For loop end/////////////////////////////////////////


	}// Main For loop end/////////////////////////////////////////////////////////////////////////////////
	printf("\nYour Password contains");
	printf("       Minimum Password Requiremnets");
	printf("\n");
	printf("\nDigits: %d ",digitsInPasword);
	printf("                   Digits:2 ");
	printf("\nLower Case: %d ",lowerCaseInPasword);
	printf("               Lower Case:2 ");
	printf("\nUpper Case: %d ",upperCaseInPasword);
	printf("               Upper Case:2 ");
	printf("\nSpecial Caharcter: %d ",specialCahr);
	printf("        Special Caharcter:1  List of Characters !#$%&@?");
	//printf("\n                 And be not shorter tha 9 and not longer than 15 characters");
	totalChars = digitsInPasword+lowerCaseInPasword+(upperCaseInPasword)+(specialCahr);
	printf("\nPassword Lenght: %d ",totalChars);
	printf("          Password Lenght:9-15 ");

	
	// userPassFlag;
    // userCommonWordsFlag;

	printf("\n\n");
	if(digitsInPasword>1 && (lowerCaseInPasword)>1 && (upperCaseInPasword)>1 && (specialCahr)>0 && totalChars>8 && totalChars<16 )
	{//Check Entered Password does it meet all requierments
		printf("\nYour Password meets the Requiremnets   PASS");
		
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	fptr = fopen("GeneratedPasswords.txt","a+"); // Opens and adds a file a+

	if (fptr == NULL)  //Creates a file if does not exist
	{
		printf("There is no file");
	}
	else
	{
		userPassFlag = 1;
		while(fscanf(fptr,"%s",  &passwordTemp) == 1 )  //Checks all previuos passwords
		{
			if(strcmp(myString,passwordTemp) == 0 )
			{
				userPassFlag = 0;
				printf("\nPassword allready been used     FAIL"); //if password is used just sez that is not Unique and does not put it to txt file
				 
			}

			
		}
	}
	fclose(fptr);
	
	//fprintf(fptr,"%s \n",myFileName);
	
	
	//////////////////////////////////////////////////////
	//for(iPos = 0; iPos < passwordLen; iPos++)
	//{
	//	myFileName[iPos] = tolower(myFileName[iPos]);   ////////// Converts to lowercase before checking for comon words
	//}                                                   ////////// And whe writes to file writes in lower case
	/////////////////////////////////////////////////////////
	comWord = fopen("CommonWords.txt","r+"); // Reads the files r+	== reading	
	userCommonWordsFlag=1;
	while (fscanf(comWord, "%s", &comonWord) == 1)
	{
			if(strstr(myStringCopy, comonWord))
			{
				userCommonWordsFlag =0;
				printf("\nBut Password contains: %s FAIL",comonWord);
				                          //CHECKS FOR COMMON WORDS
			}
	}


	if( userPassFlag == 1 && userCommonWordsFlag ==1)//If no previuos password flag remains 0 and file is writen to GeneratedPasswords.txt
	{
		printf("\nPassword is unique has not been generated before");
		printf("\nAnd does not Contain common word");
		printf("\nIts been stored to GeneratedPasswords.txt ");

	

		fptr = fopen("GeneratedPasswords.txt","a+");
		fprintf(fptr,"%s \n", myString);    //If password is unique than puts it to file
		fflush(stdin);
	}
	fclose(fptr);
	fclose(comWord);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////	
	}
	else 
	{// else starts
		printf("\nYour Password dosnt meet the Requiremnets   FAIL");
		printf("\n");
	}// esle ends

	upperCaseInPasword = 0;
	digitsInPasword = 0;
	lowerCaseInPasword = 0;
	specialCahr = 0;
	totalChars = 0;
	

	}// If statment 2 ends


	else
	{// else starts
	printf("\nInavalid Oprion Press 1,2,3");
	printf("\n");
	}// else end

}// while loop end

printf("\n\n");
system("pause");

} // end main

















	


	
