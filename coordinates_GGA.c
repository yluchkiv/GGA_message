#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

struct nmea_rmc
{
    char Latitude[20];
    char Longitude[20];
};


char scanned_message[BUFFER_SIZE];
char latitude [BUFFER_SIZE];
char longitude [BUFFER_SIZE];


void receiveGGA();
void selectGGA(char imput_message[]);
void comma_counter(char in_message[]);
void print_La(char lat[]);
void print_Lo(char lo[]);
struct nmea_rmc selectRMC(const char input_message[], unsigned int length);

int main(int argc, const char* argv[])
{
// the main function
    receiveGGA();

    if (argc > 1) {
        struct nmea_rmc rmc = selectRMC(argv[1], strlen(argv[1]));
        printf("RMC: Lat=%s\t Lon=%s\n", rmc.Latitude, rmc.Longitude);
    }

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

struct nmea_rmc selectRMC(const char input_message[], unsigned int length)
{
    struct nmea_rmc rmc = {
        .Latitude = { '\0', },
        .Longitude = { '\0', }
    };

    int comma_counter = 0;
    int lat_pos = 0;
    int lon_pos = 0;

    for (unsigned int i = 0; i < length; i++) {
        if (input_message[i] == '$' && input_message[i+3] == 'R') {
            comma_counter = 0;
        }
        if (input_message[i] == ',') {
            comma_counter++;
            continue;
        }
        if (comma_counter == 3) {
            rmc.Latitude[lat_pos++] = input_message[i];
        }
        if (comma_counter == 5) {
            rmc.Longitude[lon_pos++] = input_message[i];
        }
        if (comma_counter == 6) {
            break;
        }
    }

    return rmc;
}
