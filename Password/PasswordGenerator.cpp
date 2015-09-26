
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // looks for samll word in string


//1. Passwords must be at least 9 characters long and less than L5 characters.
//2. Passwords must have at least 2 numbers in them.
//3. Passwords must have at least 2 uppercase letters and 2 lowercase letters in them.
//4. Passwords must have at least 1 symbol in them (eg ?, S, f, %). you may define a set of
//acceptable symbols to use


void mainss()
{
	//play with ranges wehn generating pasword to achive all the rquirements

char myFileName[15+1]; 
char passwordTemp[15+1];
char strAlpha[] = {"0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWYZ!#$%&'*+,-./"};  // 26 +26 + 10 +12 = 73 SO 72 Starts at 0
char digits[] =  {"0123456789"};
char lowerCase[] ={"abcdefghijklmnopqrstuvwxyz"}; //26 so 25 because starts at 0
char uperCase[] = {"ABCDEFGHIJKLMNOPQRSTUVWYZ"};
char special[] = {"!#$%&'*+,-./\|@^();:?"};
char myString [14+1];
int myNumber=0;
int iPos;
int alphaPosition;
int digitsInPasword = 0;
int lowerCaseInPasword = 0;
int upperCaseInPasword = 0;
int specialCahr = 0;
int temporary, randomNum, last; // Shufle variables
FILE *fptr;
int passGood ;
// num range  0-9
// lower abc  10- 35
// uper abc   36 -60
// special char 61 -72

int passwordLen, tempNum, counter;

while(myNumber!=9)
{
printf("\nEnter a number 9 to exit 1 to gen pass, enter 2 to check pass: ");
scanf("%d", &myNumber);

	if(myNumber==1)
	{//If loop start
	int a = rand() % 10;
	int b = rand() % 10;
	int c = rand() % 26;
	int d = rand() % 26;
	int e = rand() % 26;
	int f = rand() % 26;
	int g = rand() % 21;
	int h = rand() % 73;
	int i = rand() % 73;

	tempNum = rand() % 6;
	printf("%d", tempNum);
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


	myFileName[passwordLen] ='\0';  // = to 0 so it wount prin out crap at the end

	// Shufles the chars in password
	for (last = passwordLen; last > 1; last--)
    {
	randomNum = rand( ) % last;
    temporary = myFileName[randomNum];
	myFileName[randomNum] = myFileName[last - 1];
    myFileName[last - 1] = temporary;
    }
	//Shufles the chars in password
	


	//printf("\n %d %d %d %d %d %d %d %d %d %d",a,b,c,d,e,f,g,h,i);
	//printf("\nMy string: %c%c%c%c%c%c%c%c%c%c  ",myFileName[0],myFileName[1] ,myFileName[2] ,myFileName[3],myFileName[4],myFileName[5] ,myFileName[6] ,myFileName[7] ,myFileName[8] );
	
	printf("\n %s",myFileName);
	printf("\n %d",passwordLen);

	fptr = fopen("GeneratedPasswords.txt","a+");

	if (fptr == NULL)
	{
		printf("There is no file");
	}
	else
	{
		while(fscanf(fptr,"%s",passwordTemp) ==1 )
		{
			if(strcmp(myFileName,passwordTemp)==0)
			{
				
				printf("Password Used");
			}
			else 
			{
				printf("Password Ok");
				fprintf(fptr,"%s \n",myFileName);
			}
		}
	}
	fprintf(fptr,"%s \n",myFileName);
	fclose(fptr);
	

	for(iPos = 0; iPos < passwordLen; iPos++)
	{// Main For loop start
		myFileName[iPos];
		
		// Loop counts digits in Password
		for( alphaPosition = 0;  alphaPosition < 10;  alphaPosition++)
		{// DigitvFor loop start

			if(myFileName[iPos]==digits[alphaPosition])
			{//If loop start 
				digitsInPasword++;
			}// If loop end
		
		 

		}// Digit For loop end

	    //Loop counts lowercase in password
		for( alphaPosition = 0;  alphaPosition < 26;  alphaPosition++)
		{//  lowercase For loop start

			if(myFileName[iPos]==lowerCase[alphaPosition])
			{//If loop start 
				lowerCaseInPasword++;
			}// If loop end
		
		 

		}//  lowercase For loop end

		//Loop upper case in password
		for( alphaPosition = 0;  alphaPosition < 26;  alphaPosition++)
		{//  Upper case For loop start

			if(myFileName[iPos]==uperCase[alphaPosition])
			{//If loop start 
				upperCaseInPasword++;
			}// If loop end
		
		 

		}//  Upper case For loop end

		// Loop for special characters
		for( alphaPosition = 0;  alphaPosition < 21;  alphaPosition++)
		{//  Special char For loop start

			if(myFileName[iPos]==special[alphaPosition])
			{//If loop start 
				specialCahr++;
			}// If loop end
		
		 

		}//Special char For loop end


	}// Main For loop end
	printf("\nDigits: %d ",digitsInPasword);
	printf("\nLower Case: %d ",lowerCaseInPasword);
	printf("\nUpper Case: %d ",upperCaseInPasword);
	printf("\nSpecial Caharcter: %d ",specialCahr);
	

	upperCaseInPasword = 0;
	digitsInPasword = 0;
	lowerCaseInPasword = 0;
	specialCahr = 0;

	}//If loop end

	else if(myNumber==2)
	{//If statment  2 starts
		printf("\nEnter your password:");
		scanf("%s", &myString);
		printf("\n %s",myString);



		for(iPos = 0; iPos < 15; iPos++)
	{// Main For loop start
		myString[iPos];
		
		// Loop counts digits in Password
		for( alphaPosition = 0;  alphaPosition < 10;  alphaPosition++)
		{// DigitvFor loop start

			if(myString[iPos]==digits[alphaPosition])
			{//If loop start 
				digitsInPasword++;
			}// If loop end
		
		 

		}// Digit For loop end

	    //Loop counts lowercase in password
		for( alphaPosition = 0;  alphaPosition < 26;  alphaPosition++)
		{//  lowercase For loop start

			if(myString[iPos]==lowerCase[alphaPosition])
			{//If loop start 
				lowerCaseInPasword++;
			}// If loop end
		
		 

		}//  lowercase For loop end

		//Loop upper case in password
		for( alphaPosition = 0;  alphaPosition < 26;  alphaPosition++)
		{//  Upper case For loop start

			if(myString[iPos]==uperCase[alphaPosition])
			{//If loop start 
				upperCaseInPasword++;
			}// If loop end
		
		 

		}//  Upper case For loop end

		// Loop for special characters
		for( alphaPosition = 0;  alphaPosition < 21;  alphaPosition++)
		{//  Special char For loop start

			if(myString[iPos]==special[alphaPosition])
			{//If loop start 
				specialCahr++;
			}// If loop end
		
		 

		}//Special char For loop end


	}// Main For loop end

	printf("\nDigits: %d ",digitsInPasword);
	printf("\nLower Case: %d ",lowerCaseInPasword);
	printf("\nUpper Case: %d ",upperCaseInPasword-1);
	printf("\nSpecial Caharcter: %d ",specialCahr-1);
	

	upperCaseInPasword = 0;
	digitsInPasword = 0;
	lowerCaseInPasword = 0;
	specialCahr = 0;

	char myString []= {"               "};
	}// If statment 2 ends
	
}


//printf("\nEnter a number 9 to exit 1 to gen pass, enter 2 to check pass: ");
//scanf("%d", &myNumber);


printf("\n\n");
system("pause");

} // end main

















	//printf("");
	//printf("");

	//printf("\nCharacter  Code\n"

	//"\t===============\n");

	//for (c=32; c<127; c++)

	//printf("\t  %c     %4d\n", c, c);


	
