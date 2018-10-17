#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int iTam, jTam, i, j, iMaior=0, jMaior=0, aux;
    
    scanf ("%d%d", &iTam, &jTam );
    int m[iTam][jTam];
    
    for (i=0; i<iTam; i++)
    {
        aux=0;
        for (j=0; j<jTam; j++)
        {
            scanf ("%d", &m[i][j]);
            aux += m[i][j]; 
        }
        if (iMaior<aux) iMaior= aux;
    }
    
    for (j=0; j<jTam; j++)
    {
        aux=0;
        for (i=0; i<iTam; i++)
        {
            aux += m[i][j]; 
        }
        if (jMaior<aux) jMaior= aux;
    }
    
    
    if (jMaior>iMaior) printf ("%d\n", jMaior);
    else
    {
        printf ("%d\n", iMaior);
    }
    
    
   /* for (i=0; i<iTam; i++)
    {
        for (j=0; j<jTam; j++)
        {
            printf ("%d ", m[i][j]);
        }
        printf("\n");
    }
    */
    
	return 0;
}