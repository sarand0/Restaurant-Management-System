#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Program written by Saran Duncan, 2019-2020. 
//this program manages a restaurant named Sonia's Home-style Kitchen. Each authorized employee at the restaurant has the access code and username, 
//the program allows them to enter their username and password in order to gain access; allows employees to create reservations for customers,  
//create deliveries for customers, view the deliveries and reservations stored in the system and calculate customer's totals as well as 
//print their receipts.


#define            SERVICECHRG  .15
#define            DELIVERYFEE  500
#define            USERCODE     "Team10user"
#define            UNAME        "Admin"

FILE *fp1, *fp2;

typedef struct
{
  char resFname[15], resLname[15], resEmail[15], resTime[10],resDate[10], resPhn[10];
        int resNumppl, resNum;
        char resCurrent;
}Resrecord;

typedef struct
{
        char delFname[15], delLname[15], delEmail[15], delAddy[30], delDate[15], delTime[15], delPhn[10];        
        char delCurrent,delOrder[30];
        int  delNum;
}Delrecord;

int Login();
int showmenu();
int makereservation(int count1);
int makedelivery(int count2);
char Foodmenu();
int showschedule();
int bill();


int main()
{
    int choice,check;
    int count1 = 0;
    int count2 = 0;
    
    printf("__________Welcome to Sonia's Home Style Kitchen__________\n");
    system ("PAUSE");

    check = Login();
    if (check != 1)
    {
    	exit(1);
	}
	else
	{
		do
    	{
    		choice = showmenu();
    		switch(choice)
    		{
    			case 1 : count1 = makereservation(count1);
    					break;
    			case 2:  count2 = makedelivery(count2);
    		     		break;
    			case 3:  showschedule();
    			    	break;
    			case 4: bill();
    			    	break;
    			case 5: printf("\nProgram ending...");
    					exit(1); 
    					break;
    			default:printf("\n Invalid choice\n");
    					break;
    		
			}
		}while (choice != 5);
	}


return 0;
}
	

int Login() // username and password are accepted in order to access program
{
	int i,valid = 0;
	char passw[15], usern[15];
	
		printf("\n Username: ");
		scanf(" %s", usern);
		printf("\n Password: ");
		scanf(" %s", passw);
		if((strcmp(UNAME,usern) == 0) && (strcmp(USERCODE,passw) == 0))
		{
			valid++; //acts as a flag to determine when the correct input has been entered
			printf("\n Welcome,");
			system("PAUSE");
		}
		else
		{
			printf("\n Invalid, you will only be able to try once more.\n");
			system("PAUSE");
			printf("\n Username: ");
			scanf(" %s", usern);
			printf("\n Password: ");
			scanf(" %s", passw);
			if((strcmp(UNAME,usern) == 0) && (strcmp(USERCODE,passw) == 0))
			{
				valid++; //acts as a flag to determine when the correct input has been entered
				printf("\n Welcome,");
				system("PAUSE");
			}
			else
			{
				printf("\n Invalid username or password.\n");
			}
			
		}
return (valid);
}

int showmenu()  //displays the main menu; accepts and returns the user's choice to the calling function
{
	int option;
	
	puts("\n************************************************************");
	puts("\n**                                                    **");
	puts("\n** 1		-		Make a reservation        **");
	puts("\n** 2		-		Make a delivery           **");
	puts("\n** 3		-		View Schedule             **");
	puts("\n** 4		-		Calculate total and print receipt **");
	puts("\n** 5		-		End program              **");
	puts("\n**                                                   **");
	puts("\n**********************************************************\n");
	system("PAUSE");
	puts("\n Please select one option: ");
	scanf(" %d", &option);
    return option;  //option entered is accepted
	
}

int makereservation(int count1) //allows the user to input necessary information for a reservation and stores it in records which are then stored to a Reservations file
{
	FILE *fp1;
	Resrecord resrec;
	//resrec.resNum = 0;
	
	
	if ((fp1 = fopen ("Reservations.txt", "a"))== NULL)
	{
		printf("\nFile does not exist");
		system ("PAUSE");
		exit (1);
	}
	else 
	{
		
	//	count++;
		resrec.resNum++; //updates each customer's reservation number as a means of identification
		count1 = resrec.resNum; // keeps track of the previous Reservation number in order to increment it successfully each time
		fprintf(fp1, "%d", resrec.resNum);
		
		printf("\n Enter customer's first name: ");
		scanf(" %s", resrec.resFname);
		fprintf(fp1, " %s", resrec.resFname);
	
		printf("\n Enter customer's last name: ");
		scanf(" %s", resrec.resLname);
		fprintf(fp1, "%s", resrec.resLname);
	
		printf("\n Enter customer's email: ");
		scanf(" %s", resrec.resEmail);
		fprintf(fp1, "%s", resrec.resEmail);
	
		printf("\n Enter the customer's phone number: ");
		scanf(" %s", resrec.resPhn);
		fprintf(fp1, "%s", resrec.resPhn);
	
		printf("\n Enter the date for reservation(dd/mm/yyyy): ");
		scanf(" %s", resrec.resDate);
		fprintf(fp1, "%s", resrec.resDate);
	
		printf("\n Enter the time for the reservation (7:00pm): ");
		scanf(" %s", resrec.resTime);
		fprintf(fp1, "%s", resrec.resTime);
	
		printf("\n Enter the number of people for the reservation: ");
		scanf(" %d", &resrec.resNumppl);
		fprintf(fp1, "%d", resrec.resNumppl);
		
		resrec.resCurrent = 'Y'; //set to 'Y' for yes to indicate that this is an ongoing/current reservation
		fprintf(fp1, "%c", resrec.resCurrent);
		
	}
	fclose(fp1);
	printf("\nReservation created successfully!\nReservation number: %d \n", resrec.resNum);
	system("PAUSE");

	return count1;
}



char Foodmenu() //displays the menu of food and drinks for the user to select from; accepts and returns the users choice to the calling function
{
	char delOrder;
	
	
	puts("\n*****************************************************");
	puts("\n**                                                 **");
	puts("\n** A		-		Chicken soup           **");
	puts("\n** B		-		Peas soup              **");
	puts("\n** C		-		Baked Chicken          **");
	puts("\n** D		-		Fried Chicken          **");
	puts("\n** E		-		Stew pork and beans    **");
	puts("\n** F		-		Soda                   **");
	puts("\n** G		-		Water                  **");
	puts("\n** X		-		Exit                   **");
	puts("\n**                                                 **");
	puts("\n*****************************************************\n");
	puts(" \n All items are served with rice and peas and steamed veg.");
	puts("\n*****************************************************\n");
	printf("\n Select order option, exit menu when order is complete.\n");
	scanf(" %c", &delOrder);
	
	return(delOrder);	
}

int makedelivery(int count2) //allows the user to input necessary information for a delivery and stores it in records which are then stored to a Delivery file
{
	FILE *fp1;
	Delrecord delrec;
	char delOrder;
	int count = 0; // creates number of slots in the order array based on how many items are created
	
	
		(fp1 = fopen("Deliveries.txt", "a"));

		delrec.delNum++; //updates the delivery number for each customer as a means of identification
		count2 = delrec.delNum; // keeps track of the previous Delivery number in order to increment it successfully each time
		fprintf(fp1, " %d", delrec.delNum);
		
		printf("\nEnter customer's First name: ");
		scanf(" %s", delrec.delFname);
		fprintf(fp1, " %s", delrec.delFname);
		
		printf("\nEnter customer's last name: ");
		scanf(" %s", delrec.delLname);
		fprintf(fp1, " %s", delrec.delLname);
		
		do
		{
			delrec.delOrder[count] = Foodmenu(); 
			if ((delrec.delOrder[count] != 'x') || (delrec.delOrder[count] != 'X'))
			{
				fprintf(fp1, " %c", delrec.delOrder[count]);
				count++;	
			}
			
		} while ((delrec.delOrder[count - 1] != 'x') && (delrec.delOrder[count - 1] !='X'));
		
		printf("\nEnter customer's email: ");
		scanf(" %s", delrec.delEmail);
		fprintf(fp1," %s", delrec.delEmail);
		
		printf("\nEnter the customer's phone number: ");
		scanf(" %s", delrec.delPhn);
		fprintf(fp1," %s", delrec.delPhn);
		
		printf("\nEnter the customer's address: ");
		scanf(" %s", delrec.delAddy);
		fprintf(fp1," %s", delrec.delAddy);
		
		printf("\n Enter the date for delivery(dd/mm/yyyy): ");
		scanf(" %s", delrec.delDate);
		fprintf(fp1, " %s", delrec.delDate);
		
		printf("\n Enter the time for the delivery (7:00pm): ");
		scanf(" %s", delrec.delTime);
		fprintf(fp1, "%s", delrec.delTime);
		
		delrec.delCurrent = 'Y'; //set to 'Y' for yes to indicate that this is an ongoing/current delivery
		fprintf(fp1, " %c", delrec.delCurrent);
		
	system("PAUSE");
	fclose(fp1);
	printf("\nDelivery was successfully created\nDelivery number: %d\n", delrec.delNum);
	system("PAUSE");
	return count2;
	
}


int showschedule() //allows the user to see details for all reservations or deliveries stored in the system
{
	
	char  article[21], filename[12];

      printf("\nType the name of the file: "); // prompt the user for the file name
      scanf("%s", filename);                               
     
      if ((fp2 = fopen( filename, "r")) == NULL) //open the file as input file or NULL is placed in the pointer if the file does not exist
      {
            puts("\nFile does not exist");
            system("PAUSE");
            exit(1);
      }
      else       
      {
            printf("\nThis is what is in the file:\n");
            do
            {
				  fscanf(fp2, "	%[^\n]s	", article);         //reads 1 entire line from file
                  printf("	%s \t			\n", article);
            } while(!feof(fp2));
      }

      fclose(fp2);
      system("PAUSE");
      showmenu();
      return(0);
}

int bill() //calculates the customer's sub-total and prints it.
{
	float total,DSubtotal,RSubtotal;
	char choice;
	
	printf("\n Would you like to calculate the total for a Delivery or Reservation? (D/R) \n");
	scanf(" %c", &choice);
	if ((choice == 'd') || (choice == 'D'))
	{
		printf("\n Enter total cost: ");
		scanf(" %f", &total);
		DSubtotal = total +(total * SERVICECHRG)+ DELIVERYFEE;
		printf("\n The subtotal is $ %.2f\n",DSubtotal);
	}
	else
	{
		if ((choice == 'r') || (choice == 'R'))
		{
			printf("\n Enter total cost: ");
			scanf(" %f", &total);
			RSubtotal = total + (total * SERVICECHRG);
			printf("\n The subtotal is $ %.2f\n", RSubtotal);
		}
		else
		{
			printf("Invalid choice\n");
		}	
	} 
	system("PAUSE");
	return(0);
}


