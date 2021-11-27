#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100


char scanned_message[BUFFER_SIZE];
char latitude [BUFFER_SIZE];
char longitude [BUFFER_SIZE];


void receiveGGA();
void selectGGA(char imput_message[]);
void comma_counter(char in_message[]);
void print_La(char lat[]);
void print_Lo(char lo[]);

int main()
{
// the main function
    receiveGGA();

    return 0;

}

void receiveGGA()
{
    printf("Insert your GGA massage:\n");
    //copy your GGA message 
    
    for (int i = 0; i< BUFFER_SIZE; i++)
    {
        
        scanf("%c", &scanned_message[i]);
        
    }
   
    selectGGA(scanned_message);

}

void selectGGA(char imput_message[])
{
    for (int i = 0; i <BUFFER_SIZE; i++)
    {
        if(imput_message[i]=='$'&& imput_message[i+3]=='G' && imput_message[i+4]=='G' && imput_message[i+5]=='A')
        {
           comma_counter(imput_message);
        }
        else
        {
            printf("Wrong message type!\n");
            break;

        }

    }
    
}

void comma_counter(char in_message[])
{
    for(int i = 0; i<BUFFER_SIZE; i++)
    {
        if(in_message[i]==',')
        {
            for(int j =i+1; j < BUFFER_SIZE;j++)
            {      
                if(in_message[j]==',')
                {
                    for(int k = j+1, a = 0; a <BUFFER_SIZE && k < BUFFER_SIZE;k++,a++)
                    {
                        if(in_message[k]!=',')
                        {
                            latitude[a]= in_message[k];
                        }
                        else 
                        {
                            latitude[a]=in_message[k+1];
                            print_La(latitude);

                            for(int l = k+3,b = 0;b<BUFFER_SIZE && l< BUFFER_SIZE;b++, l++)
                            {
                                if(in_message[l]!=',')
                                {
                                    longitude[b] = in_message[l];
                                }
                                else
                                {
                                    longitude[b] = in_message[l+1];
                                    print_Lo(longitude);
                                    
                                    break;

                                }
                                
                            }
                            break;
                        }
                    }   

                    break;
                }
            }

            break;      
        }
    }
}

void print_La(char lat[])
{
   
   printf ("Latitude: ");
   for (unsigned int i=0; i<=strlen(lat);i++) 
   {
        printf ("%c",lat[i]);
   }
    printf ("\n");
}

void print_Lo(char lo[])
{
   
   printf ("Longitude: ");
   for (unsigned int i = 0; i<=strlen(lo);i++) 
   {
        printf ("%c",lo[i]);
   }
    printf ("\n");

}


struct nmea_rmc
{
    char speed[20];
    char date[20];
};

struct nmea_rmc selectRMC(char input_message[], unsigned int length)
{
    struct nmea_rmc rmc;

    rmc.speed[0] = input_message[0];
    rmc.speed[1] = (char)length;
    rmc.speed[2] = '\0' ;

    return rmc;
}
