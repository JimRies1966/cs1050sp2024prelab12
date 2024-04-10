/*
 * CS1050
 * Spring 2023
 * Prelab 12
 * by Jim Ries
 */
#include <stdio.h>

// Symbolic Constants
#define FILENAME "DnDMonsterScores.csv"

// Main
int main(void)
{
    FILE * fp;
    char name[256];

    fp = fopen(FILENAME,"r");
    if (NULL!=fp)
    {
        // Throw away the blank line at the top
        fgets(name,255,fp);

        // Throw away the header line (but print it out to prove we read it)
        fgets(name,255,fp);
        name[255]='\0'; // Can't be too careful NULL-terminating things
        printf("Header line was: %s\n",name);

        // Variables for each field in the csv file
        int ac,hp,str,dex,con,intel,wis,cha;

        // Note that my code just reads the first data line in the CSV.  You will need to 
        // read all the lines, right?

        // fscanf() returns the number of fields it successfully read.  We asked for 9, so
        // if we didn't get 9, then something must be wrong.  Notice also that the first field is
        // "anything but a comma" because the names might have spaces in them.  Notice also
        // that I am reusing the name variable.
        if (9==fscanf(fp," %[^,],%d,%d,%d,%d,%d,%d,%d,%d,",name,&ac,&hp,&str,&dex,&con,&intel,&wis,&cha))
        {
            printf("\"%s\" : AC=%d,HP=%d\n",name,ac,hp);
        }
    }

    // Make your mama proud and clean up after yourself!
    fclose(fp);
}
