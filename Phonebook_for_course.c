//Lorinda Peoples
//CECS 130 Section 2
//Lab 8: Phone Book
//Due Date: 10/27/11

/*Program Assignment:   To lab 7, add ability to store and retrieve
                        phone records into a file specified by the user. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> //Used for pause to display error for memory not allocated.


//Define new Data Type. Alias named entry.
typedef struct bookentry
{
   char FirstName[20];
   char LastName[20];
   char PhoneArea[4];
   char PhoneNext3[4];
   char PhoneLast4[5];
}entry;

//Function Prototypes and //Definition Line
int printMenu(void);
void addEntry(int *, entry *); //Line 143
void deleteEntry(int *, entry *); //Line 159
void printEntries(int *, entry *); //Line 217
void alphSort(int *, entry *); //Line 243
void findNumber(int *, entry *); //Line 315
void randomFriend(int *, entry *); //Line 344
void deleteALL(int *, entry *); //Line 357
void saveALL(int *, entry *); //Line 390
entry * openALL(int *, entry *); //Line 409

int main()
{
   int iCounter = 0; //Counter for records
   int iChoice = 0; //Menu choice
   int iCurrentTime = 0;  //To pause after unsuccessful allocation
   int iElapsedTime = 0;  //    and display message "Out of Memory"
   
   entry *phoneBook; //Instance of entry
   entry *temp; //Instance of entry for addEntry() function
   phoneBook = (entry *)calloc(1,sizeof(entry)); //Allocate memory
   if (phoneBook == NULL) //Could not allocate memory
   {
      printf("\n\nOut of Memory!!\n\n"); //Display Out of Memory
      iCurrentTime = time(NULL);         //for 2 seconds
      do
      {
         iElapsedTime = time(NULL);
      } while((iElapsedTime - iCurrentTime)< 2); //Pause before program
                                                 //closes.
      return 1;
   }
   else //Do if memory allocated
   { //Show menu. 10=Exit
       while (iChoice !=10)
       {
          iChoice = printMenu();
             switch(iChoice) //#'s 1-7
             {
                //Begin Function calls
                case 1: //Add Record
                   iCounter++; //increment counter
                   //Reallocate memory for each entry:
                   temp = realloc(phoneBook, sizeof(entry) * iCounter); 
                   if (temp == NULL) //Could not allocate memory
                   {
                      printf("\n\nOut of Memory!!\n\n");
                   }
                   else //Do if memory allocated
                   {
                      phoneBook = temp;
                      //Add Record. Definition Line 143
                      addEntry(&iCounter, phoneBook); //Function call
                   } 
                   break;
                   
                case 2: //Delete Record. Definition Line 159
                   deleteEntry(&iCounter, phoneBook); //Function call
                   break;
                   
                case 3: //Show phonebook. Definition Line 217
                   printEntries(&iCounter, phoneBook);
                   break;
                
                case 4: //alphabetically sort. Definition Line 243
                   alphSort(&iCounter, phoneBook);
                   break;
                
                case 5:  //findNumber. Definition Line 315
                   findNumber(&iCounter, phoneBook);
                   break;
                
                case 6:  //random friend. Definition Line 344
                   randomFriend(&iCounter, phoneBook); 
                   break;  
                
                case 7: //delete All. Definition Line 357
                   deleteALL(&iCounter, phoneBook);
                   iCounter = 0; //Reset counter to 0
                   break;
                
                case 8: //Save phonebook. Definition Line 390
                   saveALL(&iCounter, phoneBook);
                   break;
                   
                case 9:  //Open phonebook. Definition Line 409
                   deleteALL(&iCounter, phoneBook);
                   phoneBook = openALL(&iCounter, phoneBook);
                   break;
                
                case 10: //Program close
                   printf("\n\nProgram Exit");
                   break;
                   
                default:
                   printf("\n\nERROR:  Please enter 1-10.\n\n");               
                   break;
             } //End switch statement
       }//End while loop
   free(phoneBook); //Free allocated memory
  // free(temp);
   return 0; //Successful program run
   }//End else statement
}//End main()
      
//Function Definitions
int printMenu(void) //Show Menu
{
   int iChoice = 0;
   printf("\nPhone Book Menu\n");
   printf("(1) Add Record\n(2) Delete Record\n(3) Show PhoneBook\n");
   printf("(4) Sort Alphabetically\n(5) Find Number\n(6) Random Friend\n");
   printf("(7) Delete All\n(8) Save PhoneBook\n(9) Open PhoneBook\n(10) Exit\n\n");
   printf("Enter number choice:  ");
   scanf("%d", &iChoice);
   return iChoice; //For switch statement in main()
} //End printMenu function
   
void addEntry(int *ctr, entry *phoneBook) //Get name and phone number
{ // *ctr-1 because index begins with 0.
   printf("\nFirst name: ");
   scanf("%s", phoneBook[*ctr-1].FirstName);
   printf("Last name: ");
   scanf("%s", phoneBook[*ctr-1].LastName);
   printf("Phone number separated by dashes\n");
   printf("xxx-xxx-xxxx: ");
   scanf("%3s-%3s-%4s", phoneBook[*ctr-1].PhoneArea, 
         phoneBook[*ctr-1].PhoneNext3, phoneBook[*ctr-1].PhoneLast4);
   //scanf("%s", phoneBook[*ctr-1].PhoneNumber);
   printf("\n\n*****************************************");
   printf("\n\nRecord added to the phone book.\n\n");
   printf("*****************************************\n\n");
} //End addEntry function  

void deleteEntry (int *ctr, entry *phoneBook) //Delete record.
{
     char searchFirst[20];
     char searchLast[20];
     char nullString[20] = {0}; //String to delete names
     int x = 0; //Index for Name search
     int index = *ctr; //Index for Name match
     int counter = *ctr; //Holding variable for *ctr
     printf("\nFirst name: "); //User enters First Name
     scanf("%s", &searchFirst);
     printf("Last name: ");  //User enters Last Name
     scanf("%s", &searchLast); 
     printf("\n\n*****************************************");
     for (x = 0; x < *ctr; x++) //Search Name records
     {   
        if (strcmp(searchFirst, phoneBook[x].FirstName) == 0 
            && strcmp(searchLast, phoneBook[x].LastName) == 0)
        { //If a name match is found:
           strcpy(phoneBook[x].FirstName, nullString); //Delete First Name
           strcpy(phoneBook[x].LastName, nullString); //Delete Last Name
           strcpy(phoneBook[x].PhoneArea, nullString); //Delete Phone Number
           strcpy(phoneBook[x].PhoneNext3, nullString); //Delete Phone Number
           strcpy(phoneBook[x].PhoneLast4, nullString); //Delete Phone Number
           printf("\n\nRecord Deleted.\n\n");
           index = x; //Deletion point
           *ctr = *ctr-1; //Re-assign variable for *ctr decrease
           break;
        }//Close if  name matches loop
        else
        {
           if (strcmp(searchFirst, phoneBook[x].FirstName) != 0
           && x == (*ctr-1)) //If No match is found & counter reaches limit
           {
              printf("\n\nERROR: Name not found!!\n\n");
           }//End if Statement
        } //End else statement
     }//Close for Name match loop
     printf("*****************************************\n\n");
     for (x = index; x < *ctr; x++) /* Start at Deleted record. If NO
     deleted record, index = *ctr and for loop will not run.  Decrement records 
     by one index if index != *ctr  on each loop*/
     { 
         strcpy(phoneBook[x].FirstName, phoneBook[x+1].FirstName);
         strcpy(phoneBook[x].LastName, phoneBook[x+1].LastName);
         strcpy(phoneBook[x].PhoneArea, phoneBook[x+1].PhoneArea); 
         strcpy(phoneBook[x].PhoneNext3, phoneBook[x+1].PhoneNext3);
         strcpy(phoneBook[x].PhoneLast4, phoneBook[x+1].PhoneLast4);
         if (x == *ctr - 1)
         { //Free allocated memory for deleted index
            free(phoneBook[x].FirstName);
            free(phoneBook[x].LastName);
            free(phoneBook[x].PhoneArea);
            free(phoneBook[x].PhoneNext3);
            free(phoneBook[x].PhoneLast4);
         }  // End if statement  
     }  // End for statement
} //End deleteEntry function

void printEntries(int *ctr, entry *phoneBook) //Show phone book
{
   int i = 0; //Index for loop
   char nullString[20] = {0}; //For empty records
   printf("\n\n*****************************************");
   printf("\n\n   PHONE BOOK RECORDS\n");
   for (i = 0; i < *ctr; i++) //Passes through records
   {
      if (strcmp(phoneBook[i].FirstName, nullString) != 0)//ctr > 0)
      { //Print records when First Name is not NULL
         printf("\n%d) %s %s....(%s) %s-%s\n",(i+1), phoneBook[i].FirstName, 
         phoneBook[i].LastName, phoneBook[i].PhoneArea, phoneBook[i].PhoneNext3,
         phoneBook[i].PhoneLast4); 
         
      }
      else
      {   
      }
   }
   printf("*****************************************\n\n");
   printf("Press any key to see Phone Book Menu:  ");
   while(!getch());
   printf("\n\n");
} //End printEntries function

//alphabetically sort
void alphSort(int *ctr, entry *phoneBook)
{
     entry *temp; //Used to store moving records
     temp = (entry *)calloc(*ctr, sizeof(entry)); //Allocate memory
     if (temp == NULL)
     {
        printf("Out of Memory");
     }
     else
     {
        int x = 0;
        int i = 0;
        if (strcmp(phoneBook[1].FirstName,"") == 0)
        { //Print Error if less than 2 records are entered
           printf("\n\n*****************************************"); 
           printf("\n\nERROR: Please add 2 or more records!\n\n");
           printf("*****************************************\n\n"); 
     
        }
        else
        {//If 2 or more records are stored
           printf("\n\n*****************************************");
           printf("\nORDERED BY LAST NAME (FIRST NAME IF EQUAL)\n\n");
           do
           {
              for (i = 0; i < *ctr-1; i++) //Search Name records
              {  
                 if (strcmp(phoneBook[i].LastName, phoneBook[i+1].LastName) > 0)
                 {//if i > i+1, switch records i and i+1
                    temp[i] = phoneBook[i];
                    phoneBook[i] = phoneBook[i+1];
                    phoneBook[i+1] = temp[i];
                 } //End if strcmp loop
                 for (x = 0; x < *ctr-1; x++) //Search Name records
                 {
                    if (strcmp(phoneBook[x].LastName, phoneBook[x+1].LastName) > 0)
                    { //if x > x+1, switch records x and x+1
                       temp[x] = phoneBook[x];
                       phoneBook[x] = phoneBook[x+1];
                       phoneBook[x+1] = temp[x];
                    } //End if strcmp loop
                    else if (strcmp(phoneBook[x].LastName, phoneBook[x+1].LastName) == 0)
                    { //if last names are the same
                       if (strcmp(phoneBook[x].FirstName, phoneBook[x+1].FirstName) > 0)
                       { //Compare first names and switch if [x] > [x+1]
                          temp[x] = phoneBook[x];
                          phoneBook[x] = phoneBook[x+1];
                          phoneBook[x+1] = temp[x];
                       } //End if strcmp first name loop
                    }//End else if strcmp last name loop
                 }//End for x loop
              } //End for i loop
           } while(strcmp(phoneBook[0].LastName, phoneBook[1].LastName) > 0);
           /* Continue While the 1st last name should be switched with the 
           2nd last name */
         
           
           for (i = 0; i < *ctr; i++)
           { //Print alphabetized list
              printf("\n%d) %s %s....(%s) %s-%s\n",(i+1), phoneBook[i].FirstName, 
              phoneBook[i].LastName, phoneBook[i].PhoneArea, phoneBook[i].PhoneNext3,
              phoneBook[i].PhoneLast4);
           }
           printf("*****************************************\n\n"); 
           printf("Press any key to see Phone Book Menu:  ");
           while(!getch());
           printf("\n\n");
        } //End else{} if 2 or more records are stored
     }//End else() if temp allocated
     free(temp); //Free allocated memory
} //End alphSort() function 
           
void findNumber(int *ctr, entry *phoneBook)
{
     char searchFirst[20];
     char searchLast[20];
     int x = 0; //Index for Name search
     printf("\nFirst name: "); //User enters First Name
     scanf("%s", &searchFirst);
     printf("Last name: ");  //User enters Last Name
     scanf("%s", &searchLast); 
     printf("\n\n*****************************************");
     for (x = 0; x < *ctr; x++) //Search Name records
     {   
        if (strcmp(searchFirst, phoneBook[x].FirstName) == 0 
            && strcmp(searchLast, phoneBook[x].LastName) == 0)
        { //Print if a match is found
           printf("\n%s %s....(%s) %s-%s\n",phoneBook[x].FirstName, 
           phoneBook[x].LastName, phoneBook[x].PhoneArea, 
           phoneBook[x].PhoneNext3, phoneBook[x].PhoneLast4);
           break;
        } //Close if statement
        else
        {
           if (x == (*ctr-1)) //If No match is found & counter reaches limit
           printf("\n\nERROR: Name not found!!\n\n");
        } //End else statement
     } //Close for loop
     printf("*****************************************\n\n");
} //End findNumber() function

void randomFriend(int *ctr, entry *phoneBook)
{
     int RandIndex = 0;
     srand(time(NULL));
     RandIndex = (rand() % *ctr); //Random # 0 to one less than counter
     printf("\n\n*****************************************");
     printf("\n\nCall this friend:\n");
     printf("\n%s %s....(%s) %s-%s\n",phoneBook[RandIndex].FirstName, 
         phoneBook[RandIndex].LastName, phoneBook[RandIndex].PhoneArea, 
         phoneBook[RandIndex].PhoneNext3, phoneBook[RandIndex].PhoneLast4);
     printf("*****************************************\n\n");
} //End randomFriend() function

void deleteALL(int *ctr, entry *phoneBook)
{
     char nullString[20] = {0}; //String to delete names
     int x = 0; //Index to search names
     if (strcmp(phoneBook[0].FirstName,"") == 0)
        return;
     for (x = 0; x < *ctr; x++) //Search Name records
     {   
        printf("\n%s ", phoneBook[x].FirstName);
        strcpy(phoneBook[x].FirstName, nullString); //Delete First Name
        strcpy(phoneBook[x].LastName, nullString); //Delete Last Name
        strcpy(phoneBook[x].PhoneArea, nullString); //Delete Phone Number
        strcpy(phoneBook[x].PhoneNext3, nullString); //Delete Phone Number
        strcpy(phoneBook[x].PhoneLast4, nullString); //Delete Phone Number
        printf("Deleted.");
     } //End for loop
     for ( x = *ctr; x <= 0; x--)
     {
         free(phoneBook[x].FirstName);
         free(phoneBook[x].LastName);
         free(phoneBook[x].PhoneArea);
         free(phoneBook[x].PhoneNext3);
         free(phoneBook[x].PhoneLast4);
     }
     printf("\n");
     /* Allocate memory for 1 structure unit since program
     has not terminated: */
     phoneBook = (entry *)calloc(1,sizeof(entry));
     /* Malloc if NULL test is in addEntry function
        in the realloc if NULL test */
                   
} //End deleteAll() function

void saveALL(int *ctr, entry *phoneBook)
{
   char sFilename[100];
   int iChoice = 0;
   FILE *pWrite;
   int i = 0; //counter for records
   
   printf("\n\nHow do you want to save the file?\n");
   printf("\n1)Type file folder path and filename");
   printf("\n2)Store in Default location as 'phone.txt'\n");
   printf("\nYour choice:  ");
   scanf("%d", &iChoice);
   do
   {
      switch (iChoice)
      {
      default:
           printf("\n\nPlease choose 1 or 2.");
           scanf("%d", &iChoice);
           break;
      case 1:
           printf("\n\nEnter file destination and name.  Use 2 \\\\ for all \\");
           printf("\n(ex. C:\\\\Users\\\\LPeoples\\\\Desktop\\\\filename.txt)\n");
           printf("\n Save as? :   ");
           scanf("%s", sFilename);
           pWrite = fopen(sFilename, "w");
           iChoice = 100;
           break;
      case 2:
           pWrite = fopen("phone.txt", "w");
           iChoice = 100;
           break;
      }
   }while(iChoice != 100);
           
           
   if (pWrite == NULL)
      printf("\nFile cannot be saved.\n");
   else
   {
      for (i = 0; i < *ctr; i++)
      { //Print alphabetized list
         fprintf(pWrite, "%s %s %s %s %s\n", phoneBook[i].FirstName, 
            phoneBook[i].LastName, phoneBook[i].PhoneArea, phoneBook[i].PhoneNext3,
            phoneBook[i].PhoneLast4);
      }
      fclose(pWrite);
   printf("\nFile saved.\n");
   } 
}        

entry * openALL(int *ctr, entry *phoneBook)
{
   char sFilename[200] = {0};
   entry *temp2;
   FILE *pRead;
   int iChoice = 0;
   
   printf("\n\nHow do you want to open the file?\n");
   printf("\n1)Type file folder path and filename");
   printf("\n2)Open default file 'phone.txt'\n");
   printf("\nYour choice:  ");
   scanf("%d", &iChoice);
   
   do
   {
      switch (iChoice)
      {
      default:
           printf("\n\nPlease choose 1 or 2.");
           scanf("%d", &iChoice);
           break;
      case 1:
           printf("\n\nEnter file destination and name.  Use 2 \\\\ for all \\");
           printf("\n(ex. C:\\\\Users\\\\LPeoples\\\\Desktop\\\\filename.txt)\n");
           printf("\n Enter here :   ");
           scanf("%s", sFilename);
           pRead = fopen(sFilename, "r");
           iChoice = 200;
           break;
      case 2:
           pRead = fopen("phone.txt", "r");
           iChoice = 200;
           break;
      }
   }while(iChoice != 200);
   
   if (pRead == NULL)
      printf("File cannot be opened.\n\n");
   else
   {
      *ctr = 1;
      temp2 = (entry *)calloc(*ctr, sizeof(entry)); 
      if (temp2 == 0)
         printf("Memory cannot be allocated to open file's data.");
      else
      {
         phoneBook = temp2;      
      
                   
         fscanf(pRead, "%s%s%s%s%s", phoneBook[*ctr-1].FirstName, 
         phoneBook[*ctr-1].LastName, phoneBook[*ctr-1].PhoneArea, 
         phoneBook[*ctr-1].PhoneNext3, phoneBook[*ctr-1].PhoneLast4);
      
         while(!feof(pRead))
         {
            printf("\n%d) %s %s....(%s) %s-%s\n",(*ctr), phoneBook[*ctr-1].FirstName, 
            phoneBook[*ctr-1].LastName, phoneBook[*ctr-1].PhoneArea, 
            phoneBook[*ctr-1].PhoneNext3, phoneBook[*ctr-1].PhoneLast4);
         
            *ctr = *ctr + 1;
            temp2 = realloc(phoneBook, sizeof(entry) * *ctr); 
            if (temp2 == NULL) //Could not allocate memory
            {
               printf("\n\nOut of Memory!!\n\n");
            }
            else if (!feof(pRead))
            {
               phoneBook = temp2;
               fscanf(pRead, "%s%s%s%s%s", phoneBook[*ctr-1].FirstName, 
               phoneBook[*ctr-1].LastName, phoneBook[*ctr-1].PhoneArea, 
               phoneBook[*ctr-1].PhoneNext3, phoneBook[*ctr-1].PhoneLast4);
            }
         } //Close while
         *ctr = *ctr - 1;
      free(temp2);
      } //Close else if temp != NULL
   fclose(pRead);
   }  //Close else if pRead != NULL
   return phoneBook;
         
}  
  
