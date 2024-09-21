#include<stdio.h>
#include<stdlib.h>
void add();
void list();
void search();
struct CustomerDetails
{
char roomnumber[10];
char name[20];
char address[25];
char phonenumber[15];
char nationality[15];
char email[20];
char period[10];
char arrivaldate[10];
}s;
int main()
{
int i=0;
char customername;
char choice;
system("cls");
while (1)
{
for(i=0;i<80;i++)
printf("-");
printf("\n");
printf("****************************** |MAIN MENU|***************************** \n");
for(i=0;i<80;i++)
printf("-");
printf("\n");
printf("\t\t *Please enter your choice for menu*:");
printf("\n\n");
printf(" \n Enter 1 -> Book a room");
printf("\n------------------------");

printf(" \n Enter 2 -> View Customer Record");
printf("\n----------------------------------");

printf(" \n Enter 3 -> Search Customer Record");
printf("\n-----------------------------------");
printf(" \n Enter 4 -> Exit");
printf("\n-----------------");
printf("\n");
for(i=0;i<80;i++)
printf("-");
choice=getche();
choice=toupper(choice);
switch(choice)
{
case '1':
add();break;
case '2':
list();break;
case '3':
search();break;
case '4':
system("cls");

printf("\n\n\t *****THANK YOU*****");
exit(0);
break;
default:
system("cls");
printf("Incorrect Input");

printf("\n Press any key to continue");
getch();
}
}
}
void add()
{
FILE *f;
char test;
f=fopen("add.txt","a+");
if(f==0)
{ f=fopen("add.txt","w+");
system("cls");

printf("Please hold on while we set our database in your computer!!");

printf("\n Process completed press any key to continue!! ");
getch();
}
while(1)
{
system("cls");
printf("\n Enter Customer Details:");
printf("\n**************************");
printf("\n Enter Room number:\n");
scanf("\n%s",s.roomnumber);
fflush(stdin);
printf("Enter Name:\n");
scanf("%s",s.name);
printf("Enter Address:\n");
scanf("%s",s.address);
printf("Enter Phone Number:\n");
scanf("%s",s.phonenumber);
printf("Enter Nationality:\n");
scanf("%s",s.nationality);
printf("Enter Email:\n");
scanf(" %s",s.email);
printf("Enter Period (\'x\'days):\n");
scanf("%s",&s.period);
printf("Enter Arrival date(dd\\mm\\yyyy):\n");
scanf("%s",&s.arrivaldate);
fwrite(&s,sizeof(s),1,f);
fflush(stdin);

printf("\n\n1 Room is successfull booked!!");

printf("\n Press esc key to exit, any other key to add another customer detail:");
test=getche();
if(test==27)
break;
}
fclose(f);
}
void list()
{
FILE *f;
int i;
if((f=fopen("add.txt","r"))==NULL)
exit(0);
system("cls");
printf("ROOM ");
printf("NAME\t ");
printf("\tADDRESS ");
printf("\tPHONENUMBER ");
printf("\tNATIONALITY ");
printf("\tEMAIL ");
printf("\t\t PERIOD ");
printf("\t ARRIVALDATE \n");
for(i=0;i<118;i++)
printf("-");
while(fread(&s,sizeof(s),1,f)==1)
{
printf("\n%s \t%s \t\t%s \t\t%s \t%s \t%s \t %s \t %s",s.roomnumber, s.name , s.address , s.phonenumber ,s.nationality,s.email,s.period, s.arrivaldate);
}
printf("\n");
for(i=0;i<118;i++)
printf("-");
fclose(f);
getch();
}
void search()
{
system("cls");
FILE *f;
char roomnumber[20];
int flag=1;
f=fopen("add.txt","r+");
if(f==0)
exit(0);
fflush(stdin);

printf("Enter Room number of the customer to search its details: \n");
scanf("%s", roomnumber);
while(fread(&s,sizeof(s),1,f)==1)
{
if(strcmp(s.roomnumber,roomnumber)==0){
flag=0;
printf("\n\tRecord Found\n ");

printf("\nRoom Number:\t%s",s.roomnumber);
printf("\nName:\t%s",s.name);
printf("\nAddress:\t%s",s.address);

printf("\nPhone number:\t%s",s.phonenumber);
printf("\nNationality:\t%s",s.nationality); 
printf("\nEmail:\t%s",s.email);
printf("\nPeriod:\t%s",s.period);
printf("\nArrival date:\t%s",s.arrivaldate);
flag=0;
break;
}
}
if(flag==1){

                printf("\n\tRequested Customer could not be found!");
            }
getch();
fclose(f);
}
