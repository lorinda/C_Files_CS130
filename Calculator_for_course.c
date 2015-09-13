//Lorinda Peoples
//CECS 130 Section 2
//Lab 4: Calculator Functions
//Due Date: 9/22/11

//Program Assignment:  Re-write Lab 3 to create a calculator using functions.

#include <stdio.h>

//Function Prototypes
float Addition(float , float); 
float Subtraction(float, float); 
float Multiply(float, float);
float Divide(float, float);
int Modulus(int, int);
int Power(int, int);
void Prime(int);
int Power(int, int);
int Factorial(int);
void Fibonacci(int);

main()
{//Start main function
      //Declare and Initialize all variables used in main() function
      int iSelection=0;  //Menu choice
      
      float fInput1=0; //first number input. Cases 1-4
      float fInput2=0;  //second number input. Cases 1-4
      
      int iInput1=0; //first number input. Cases 5-9
      int iInput2=0; //second number input. Case 5
      
      int iPower=0; //exponent. Case 8 Only
      
  while(iSelection != 10) //Program exit when Menu item 10 is selected
  {  //Start while function   
      //Calculator Menu and Selection
      printf("\n\nCALCULATOR MENU:\n\n(1)  Addition\n(2)  Subtraction\n(3)  Multiplication\n(4)  Division\n");
      printf("(5)  Modulus (Integers Only)\n(6)  Test if Prime (Integers only)\n");
      printf("(7)  Factorial\n(8)  Power\n(9)  Fibonacci (Integers only)\n(10) Exit\n\n");
      printf("Make your selection (number only):  ");
      scanf("%d", &iSelection);
      
      switch(iSelection)
      { //Start switch function      
             case 1: //Addition
                   printf("\nYou selected Addition\n");
                   printf("\nEnter the first number:  ");
                   scanf("%f", &fInput1);
                   printf("\nEnter the second number:  ");
                   scanf("%f", &fInput2);
                   printf("\n\n*********************************");
                   // Function Call:  Addition().  Display Sum
                   printf("\n\nThe sum is:  %.2f", Addition(fInput1, fInput2)); 
                   printf("\n%.2f + %.2f = %.2f\n\n", fInput1, fInput2, Addition(fInput1, fInput2));
                   printf("\n*********************************\n\n\n");
                   continue; //Display Menu
           
           case 2: //Subtraction
                  printf("\nYou selected Subtraction\n");
                  printf("\nSubtraction will be in the form:");
                  printf("\n     The First Number - The Second Number\n");
                  printf("\nEnter the first number:  ");
                  scanf("%f", &fInput1);
                  printf("\nEnter the second number:  ");
                  scanf("%f", &fInput2);
                  printf("\n\n*********************************");
                  //Function Call: Subtraction(). Display Difference
                  printf("\n\nThe difference is:  %.2f", Subtraction(fInput1, fInput2));
                  printf("\n%.2f - %.2f = %.2f\n\n", fInput1, fInput2, Subtraction(fInput1, fInput2));  
                  printf("\n*********************************\n\n\n");
                  continue; //Display Menu
                  
           case 3:  //Multiplication
                  printf("\nYou selected Multiplication\n");
                  printf("\nEnter your first number:  ");
                  scanf("%f", &fInput1);
                  printf("\nEnter your second number:  ");
                  scanf("%f", &fInput2);
                  printf("\n\n*********************************");
                  //Function Call: Multiply(). Display Product
                  printf("\n\nThe product is:  %.2f", Multiply(fInput1,fInput2)); 
                  printf("\n%.2f * %.2f = %.2f\n\n", fInput1, fInput2, Multiply(fInput1,fInput2)); 
                  printf("\n*********************************\n\n\n");
                  continue;  //Display Menu

           case 4:  //Division
                  printf("\nYou selected Division\n");
                  printf("\nDivision will be in the form:");
                  printf("\n     The First Number / The Second Number\n\n");
                  printf("\nEnter the first number:  ");
                  scanf("%f", &fInput1);
                  printf("\nEnter the second number:  ");
                  scanf("%f", &fInput2);
                  printf("\n\n*********************************");
                  //Function Call: Divide(). Display Quotient
                  printf("\n\nThe quotient is: %.2f", Divide(fInput1,fInput2)); 
                  printf("\n%.2f / %.2f = %.2f\n\n", fInput1, fInput2, Divide(fInput1,fInput2)); 
                  printf("\n*********************************\n\n\n");
                  continue;  //Display Menu      

           case 5: //Modulus
                  printf("\nYou selected Modulus (Intergers Only)\n");
                  printf("\nModulus will return the remainder of division\nwhich is of the form:\n");
                  printf("\n     The First Number / The Second Number\n\n");     
                  printf("\nEnter the first number:  ");
                  scanf("%d", &iInput1);
                  printf("\nEnter the second number:  ");
                  scanf("%d", &iInput2);
                  printf("\n\n*********************************");
                  //Function Call: Modulus(). Display Remainder
                  printf("\n\nThe modulus is: %d", Modulus(iInput1, iInput2)); 
                  printf("\n %d / %d = %d remainder %d\n\n", iInput1, iInput2, iInput1/iInput2, Modulus(iInput1,iInput2));
                  printf("\n*********************************\n\n\n");
                  continue; //Display Menu
                  
           case 6: //Prime
                  printf("\nYou selected Test if Prime (Integers only)\n");
                  printf("\nEnter the number:  ");
                  scanf("%d", &iInput1);
                  printf("\n\n*********************************");
                  //Function Call: Prime(). See Function Definition for Output
                  Prime(iInput1);
                  printf("\n*********************************\n\n\n");
                  continue; //Display Menu
           
           case 7:  //Factorial
                  printf("\nYou selected Factorial (Integers only)\n");
                  printf("\nEnter the number:  ");
                  scanf("%d", &iInput1);
                  printf("\n\n*********************************\n");
                  //Function Call: Factorial(). Display. See Function Definition for factor display.
                  printf("\n\n%d! = %d \n\n", iInput1, Factorial(iInput1));
                  printf("\n*********************************\n\n\n");
                  continue; // Display Menu
                
           case 8: //Power
                  printf("\nYou selected Power (Integers only)\n");
                  printf("\nEnter the main number:  ");
                  scanf("%d", &iInput1);
                  printf("Enter the power number (exponent):  ");
                  scanf("%d", &iPower);
                  printf("\n\n*********************************");
                  //Function Call: Power(). Display.
                  printf("\n\n%d^%d = %d\n\n", iInput1, iPower, Power(iInput1, iPower));
                  printf("\n*********************************\n\n\n");
                  continue;  // Display Menu
           
           
           case 9: //Fibonacci
                  printf("\nYou selected Fibonacci (Integers only)\n");
                  printf("\nEnter the desired number of elements in the sequence:  ");
                  scanf("%d", &iInput1);        
                  printf("\n\n****************************************");
                  //Function Call: Fibonacci(). See Function Definition for Output & array
                  Fibonacci(iInput1);
                  printf("\nScroll UP to see the entire sequence.\n\n****************************************\n");
                  continue; // Display Menu
           
           default: //1-10 not entered at Menu Choice
                  printf("\n*********************\nInvalid Category!!!\n*********************\n");
                        
      } //End switch function
  } //End while function                              
} //End main function

//FUNCTION DEFINITIONS


//Case 1:  Addition() function definition
float Addition(float a, float b) 
{
    return a + b; //Return Sum
} //End Function Definition


//Case 2:  Subtraction() function definition
float Subtraction(float a, float b) 
{
     
    return a - b; //Return Difference
     
} //End Function Definition


//Case 3:  Multiply() function definition
float Multiply(float a, float b) 
{
      return a * b; //Return Product
} // End Function Definition


// Case 4:  Divide() function definition
float Divide(float a, float b)
{
      return a / b; //Return Quotient
} // End Function Definition


// Case 5:  Modulus() function defintion
int Modulus(int a, int b) 
{ // Modulus(iInput1, iInput2)
    return (a - (b * (a/b))); //Return Modulus
} // End Function Definition


// Case 6:  Prime() function definition                                    
void Prime(int a) 
{
     int iCount=0;
     int iModulusPrime=0;
     int iFactor1=0;
     int iFactor2=0;
     for(iCount = 2; iCount < a; iCount++)
     {  //Start for loop
          iModulusPrime = a - (iCount * (a/iCount)); //Find Modulus 
                     
          if(iModulusPrime == 0)
          {  //Start if statement for Not Prime
             iFactor1 = iCount;
             iFactor2 = a / iFactor1;
             //Display NOT Prime
             printf("\n\n%d is NOT a Prime Number.", a); 
             //Display first factors
             printf("\n%d x %d = %d\n\n", iFactor1, iFactor2, a);  
             break;                  
          }  //End if statement
          
          else if (iCount == a - 1)
          {  //Start else if statement for Prime
             printf("\n\n%d is a Prime Number.\n\n\n", a); //Display Prime
          }  //End else if statement
    }  //End loop
} //End Function Definition


// Case 7:  Factorial() function definition
int Factorial(int a) 
{
    int iCount = 0;
    int iFactorial = 1;
    for (iCount = 1; iCount <= a; iCount++)
    {  //For loop printing factors and calculating factorial 
        iFactorial *= iCount;
        printf("%d ", iCount);
        if (iCount != a)
          printf("* ");
    } //End for loop
    printf("= %d", iFactorial);                                
    return iFactorial; //Return Factorial
} //End Function Definition


// Case 8:  Power() function definition
int Power(int a, int b) 
{  // Power(iInput1,iPower)
     
     int iCount = 0;
     int iNewNumber = 1; //if exponent is 0, will return 1
     if (b < 0)
     { //if exponent is negative
           iNewNumber=0;
     } //end if statement
     for(iCount = 1; iCount <= b; iCount++)
        { //Start for to Calculate Power
           iNewNumber = iNewNumber * a; 
        } //End for loop
     return iNewNumber; //Return Power Calculation
} //End Function Definition


// Case 9:  Fibonacci() function definition
void Fibonacci(int a) 
{
     int iCount = 2; // Array Index
     int iFibArray[a]; // Initialize Array with requested number of elements
     iFibArray[0] = 0; // @ Sequnce No. 1, Fibonacci = 0
     iFibArray[1] = 1; // @ Sequnce No. 2, Fibonacci = 1
     printf("\n\nFibonacci Sequence:\n\n");
     printf("  Fibonacci No.\t\t   Sequence No.\n");
     printf("  -------------\t\t   -----------\n");
     // Print Sequence Noumbers 1 and 2:
     printf("\t%d\t\t\t1\n\t%d\t\t\t2\n", iFibArray[0], iFibArray[1]);
     while (iCount < a) 
     { // While Sequence # is less than input number
           // Step through array calculating Fibonacci numbers            
           iFibArray[iCount] = iFibArray[iCount - 1] + iFibArray[iCount-2];
           
           // Print Sequence Numbers 3 through (a - 1) with Fibonacci Number
           printf("\t%d\t\t\t%d\n", iFibArray[iCount], iCount+1);
           iCount++;
     
     }  //End while loop
} //End function definition
