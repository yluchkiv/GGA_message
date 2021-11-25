#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 87

char scanned_message[BUFFER_SIZE];
char latitude [BUFFER_SIZE];
char longitude [BUFFER_SIZE];

void receiveGGA();
void selectGGA(char imput_message[]);
void print_La(char lat[]);
void print_Lo(char lo[]);

int main()
{
receiveGGA();
}

void receiveGGA()
{
    printf("Insert your GGA massage:\n");
    for (int i = 0; i< BUFFER_SIZE; i++)
    {
        
        scanf("%c", &scanned_message[i]);
        
    }
    printf("All Entered\n");
    selectGGA(scanned_message);

}

void selectGGA(char imput_message[])
{
    for (int i = 0; i <BUFFER_SIZE; i++)
    {
        if(imput_message[i]=='$')
        {
           for (int k = 0; k <= 14; k++)
           {
                latitude[k]=imput_message[i+16];
                i++;
           }
           print_La(latitude);
           for (int j = 0;j<=15;j++)
           {
                longitude[j]=imput_message[i+17];
                i++;
           }
           print_Lo(longitude);

        }
    }
    
}
void print_La(char lat[])
{
   
   printf ("Latitude: ");
   for (int i=0; i<=strlen(lat);i++) 
   {
        printf ("%c",lat[i]);
   }
    printf ("\n");
}
void print_Lo(char lo[])
{
   
   printf ("Longitude: ");
   for (int i=0; i<=strlen(lo);i++) 
   {
        printf ("%c",lo[i]);
   }
    printf ("\n");
}