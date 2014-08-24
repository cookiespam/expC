#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <stddef.h>
#include <time.h>

int menu_switch(void);
int reverse_num(void);
int calc_age(void);
int feetInches_to_CM(void);
int f_to_c(void);
int sum_of_int(void);
int displayLastNum(void);

static int choice = 0;

/*--------------------------------------------------------------------------------------------------------------------*/
int GetInt(const char *prompt, int *i) {
    int Invalid = 0;
    int EndIndex;
    char buffer[BUFSIZ];
    do {
        if (Invalid)
            fputs("\nInvalid input, try again.\n\n", stdout);
            Invalid = 1;
            fputs(prompt, stdout);
            fflush(stdout);
        if (NULL == fgets(buffer, BUFSIZ, stdin))
            return 1;
            errno = 0;
    }
    while ((1 != sscanf(buffer, "%d %n", i, &EndIndex)) || buffer[EndIndex] || errno);
    return 0;
}
/*--------------------------------------------------------------------------------------------------------------------*/
int GetDouble(const char *prompt, double *i) {
    int Invalid = 0;
    int EndIndex;
    char buffer[BUFSIZ];
    do {
        if (Invalid)
            fputs("\nInvalid input, try again.\n\n", stdout);
            Invalid = 1;
            fputs(prompt, stdout);
            fflush(stdout);
        if (NULL == fgets(buffer, BUFSIZ, stdin))
            return 1;
            errno = 0;
    }
    while ((1 != sscanf(buffer, "%lf %n", i, &EndIndex)) || buffer[EndIndex] || errno);
    return 0;
}
/*--------------------------------------------------------------------------------------------------------------------*/
int menu ( void )
{
    int option = 0;
    printf ( "Please choose from the options below:\n" );
    printf ( "[1] Rounds off numbers to two decimal places\n" );
    printf ( "[2] Reverse Numbers\n" );
    printf ( "[3] Calculate your age\n" );
    printf ( "[4] Convert Feet and Inches into Centimeters\n" );
    printf ( "[5] Convert Fahrenheit into Celsius\n" );
    printf ( "[6] Calculate sum of integers\n" );
    printf ( "[7] Keep reading positive numbers until a zero value entered and then outputs last positive number entered\n" );
    printf ( "[8] About\n" );
    printf ( "[9] Exit\n\n" );

    GetInt ( "Choice: ", &option );
    printf ( "\n" );

    return option;
}
/*--------------------------------------------------------------------------------------------------------------------*/
int display_num(void)
{
    /* declare variables and assign string value*/
    double num = 0;

    GetDouble("Insert a num: ",&num);

    printf("\n%.2f\n\n",num);
    
	printf("Press 1 to repeat, or Press 2 to return to menu or Press 3 to exit");
	GetInt("Choice: ",&choice);
	switch (choice) {
		case 1 :
			return display_num();
		case 2:
			return menu_switch();
		case 3:
			return 0;
		default:
			return 0;
	}
    
}
/*--------------------------------------------------------------------------------------------------------------------*/

int reverse_num()
{
    int num = 0;
    int reverse = 0;

    /*input*/
    GetInt("Enter a number to reverse : ",&num);

    /*process*/
    while(num > 0)
    {
        reverse = reverse*10;
        reverse = reverse + num%10;
        num = num/10;
        continue;
    }

    /*output*/
    printf("The reverse of entered number is : %d\n", reverse);
	
	printf("Press 1 to repeat, or Press 2 to return to menu or Press 3 to exit");
	GetInt("Choice: ",&choice);
	switch (choice) {
		case 1 :
			return reverse_num();
		case 2:
			return menu_switch();
		case 3:
			return 0;
		default:
			return 0;
	}
}
/*--------------------------------------------------------------------------------------------------------------------*/
int calc_age()
{
    int age=0;
    int choice1=0;
    int birth_year;
    int year1;
    GetInt("Enter your Birthyear: ",&birth_year);
    printf("Would you like to enter your own year? Y or N: ");
    choice1 = getchar();
    
    if(choice1 == 'Y' || choice1 == 'y'){
    	while ( getchar() != '\n' ); //flush buffer
    	GetInt("Enter the year: ",&year1);
    	age = year1 - birth_year;
	}
	
	else{
    	char            fmt[64], buf[64];
    	struct timeval  tv;
    	struct tm       *tm;
		int year2 = 0;
    	gettimeofday(&tv, NULL);
    	if((tm = localtime(&tv.tv_sec)) != NULL)
    	{
            strftime(fmt, sizeof fmt, "%Y", tm);
            snprintf(buf, sizeof buf, fmt, tv.tv_usec);
        	year2 = atoi (buf);
			age = year2 - birth_year;     
    	}
   }
    
    printf("Your age is %d this year \n",age);
       
	printf("Press 1 to repeat, or Press 2 to return to menu or Press 3 to exit");
	GetInt("Choice: ",&choice);
	switch (choice) {
		case 1 :
			return calc_age();
		case 2:
			return menu_switch();
		case 3:
			return 0;
		default:
			return 0;
	}
}
/*--------------------------------------------------------------------------------------------------------------------*/
int feetInches_to_CM()
{
    /* declare variables and assign string value*/
    double centimeters = 0;
	double feet = 0;
	double inches = 0;	
    /* enter input items */
    GetDouble("Enter length in feet: ",&feet);
    GetDouble("Enter length in inches: ",&inches);

    /* feet and inches in cm */
    centimeters =  (feet *30.48) + (inches * 2.54);

      /*display output item */
    if(centimeters<0){ //if centimeters is a negative which cant exist in real life
        printf("The length in centimeters is a negative value,here it is anyway: %.2f \n", centimeters); //print for fun
    }
    else {
        printf("The length in centimeters is %.2f \n", centimeters);
    }

	printf("Press 1 to repeat, or Press 2 to return to menu or Press 3 to exit");
	GetInt("Choice: ",&choice);
	switch (choice) {
		case 1 :
			return feetInches_to_CM();
		case 2:
			return menu_switch();
		case 3:
			return 0;
		default:
			return 0;
	}
}

/*--------------------------------------------------------------------------------------------------------------------*/
int f_to_c()
{
    /* declare variables and assign string value*/
    double celsius = 0;
	double fahrenheit = 0;
    /* enter input items */
    GetDouble("Enter temperature in Fahrenheit: ",&fahrenheit);

    /*output*/
    if (fahrenheit >= -459.67) {  //-459.67F is absolute zero

        /* feet and inches in cm */
        celsius = (fahrenheit-32)*5/9;

         /*display output item */
        printf("\nThe temperature in celsius is %.2f \n", celsius);
    }

    /*if fahrenheit is below -459.67*/
    else {
          printf("You are breaking the laws of physics or whatever it is nooooob lololololol swag!!!!! \n");
    }
        
	printf("Press 1 to repeat, or Press 2 to return to menu or Press 3 to exit");
	GetInt("Choice: ",&choice);
	switch (choice) {
		case 1 :
			return f_to_c();
		case 2:
			return menu_switch();
		case 3:
			return 0;
		default:
			return 0;
	}
}
/*--------------------------------------------------------------------------------------------------------------------*/
int sum_of_int()
{
	int n;
	int c;
    int sum = 0;
    int *array = malloc(n*sizeof(int));

    sum = 0; //set sum to 0 as not doing so would result in sum retaining values of the previous loop
   /* if while doing malloc oom appears, exit program */
    if(array == NULL)
    {
        fprintf(stderr, "Out of memory, exiting\n");
        exit(1);
    }

    GetInt("How many integers would you like to enter?: ", &n);
    printf("\n");

    for (c = 0; c < n; c++)
    {
        GetInt("Enter number: ",&array[c]);
        sum = sum + array[c];
    }
    free(array);
    array = NULL;
    printf("\nSum = %d\n",sum);
        
	printf("Press 1 to repeat, or Press 2 to return to menu or Press 3 to exit");
	GetInt("Choice: ",&choice);
	switch (choice) {
		case 1 :
			return sum_of_int();
		case 2:
			return menu_switch();
		case 3:
			return 0;
		default:
			return 0;
	}
}

/*--------------------------------------------------------------------------------------------------------------------*/
int displayLastNum()
{
    /*initialization*/
    int num = 0;
	int last_positive_num = 0;

	do { //loops forever when num > 0
    	GetInt("Enter a positive number: ",&num);

    	if (num > 0) {
       		printf("The Number you entered is %d\n", num);
        	last_positive_num = num;
        }

    	else if(num<0) {
        	continue;
        }

    } while (num !=0 );
    printf("The Last Positive Number is %d\n", last_positive_num);
        
	printf("Press 1 to repeat, or Press 2 to return to menu or Press 3 to exit");
	GetInt("Choice: ",&choice);
	switch (choice) {
		case 1 :
			return displayLastNum();
		case 2:
			return menu_switch();
		case 3:
			return 0;
		default:
			return 0;
	}
}
/*--------------------------------------------------------------------------------------------------------------------*/
int menu_switch()
{

    switch ( menu() ) {
    case 1:
        display_num();
        break;
    case 2:
        reverse_num();
        break;
    case 3:
        calc_age();
        break;
    case 4:
        feetInches_to_CM();
        break;
    case 5:
        f_to_c();
        break;
    case 6:
        sum_of_int();
        break;
    case 7:
        displayLastNum();
        break;
    case 8:
        printf ( "Have a nice day!\n" );
        break;
    case 9:
        printf ( "Have a nice day!\n" );
        break;
    default:
        printf ( "Invalid Choice, try again\n\n");
        return menu_switch();
    }
    return 0;
}

/*---------------------------------------------------------------------------------------------------------------------*/
int main (void)
{
    menu_switch();
    return 0;
}
