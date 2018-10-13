#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int p, gol, t1, t2, i=0, v[100], pontos=0, contE=0, tam=0, teste, j, aux, maior, cont0=0, cont=0;
    
    scanf ("%d%d", &p, &gol);
    while (p--)
    {
      scanf ("%d%d", &t1, &t2);
      if (t1>t2) pontos +=3;
      else if (t1==t2) contE++;
      else if (t1<t2) 
      {
          v[i] = t2-t1;
          tam++;
          i++;
      }
    }
    
    

    teste = contE-gol;
    //Colocar os gols comprados nos empates
    if (teste>=0)
    {
       pontos += gol*3; 
       pontos += teste;
    }
    else
   {
       //Acrescentando os pontos do empate
    pontos += contE*3;
    teste *= -1;
     //Ordenando o vetor da diferen?as de gols
    
       for (i=0; i<tam-1; i++)
       {
          maior = i; 
           for (j=i+1; j<tam;j++)
           {
              if (v[maior]>v[j]) maior=j; 
           }
           aux = v[maior];
           v[maior] = v[i];
           v[i] = aux;
           
          
       }
    /*   
       for (i=0; i<tam; i++)
       {
           printf ("%d\n", v[i] );
       }
       */
       //Descontando a direfen?a das derrotas com os gols
       for (i=0; i<tam; i++)
       {
           while (teste--)
           {
             v[i]--;  
             if (v[i]==-1) break;
           }
           if (v[i]==0) cont0++;
           if (teste==0) i=tam;
       }
        for (i=0; v[i]==-1; i++ )
        {
            if (v[i]==-1) cont++;
        }
   }
    pontos += cont0;
    pontos += cont*3;
 
    printf ("%d\n", pontos);
    
    
	return 0;
}