#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 1000
#define NUM 500
int main(){
	char arr1[MAX];
	int suma1[NUM-1],suma2[NUM-1],resta[NUM-1],arr2[NUM],s_arr1[NUM],s_arr2[NUM];
	int i,j=0,k,n=0,tam,cont=0,cont2=0;
	int *p1,*p2,*p3;
	FILE *entrada;
	FILE *salida;
	entrada=fopen("entrada.ent","r+b");
	if(entrada==NULL){
		printf("error al abrir el archivo");
	}
	else{
		for(i=0;i<NUM;i++){
			suma1[i]=0;
			suma2[i]=0;
			resta[i]=0;
			arr2[i]=0;
		}	
		for(i=0;i<MAX;i++){
			arr1[i]=fgetc(entrada);
			if((arr1[i]==48)||(arr1[i]==49)||(arr1[i]==50)||(arr1[i]==51)||(arr1[i]==52)||(arr1[i]==53)||(arr1[i]==54)||(arr1[i]==55)||(arr1[i]==56)||(arr1[i]==57)){
				cont++;
			}	
			else{
				if(cont>=2){
					salida2:
					arr2[j]=arr2[j]+(arr1[i-cont]-48)*pow(10,cont-1);
					cont--;
					cont2++;
					if(cont>=1) goto salida2;
					if((cont2>=3)&&(cont2%2==1)){
						arr2[j]=arr2[j]+1;
					}
					j++;
					cont=0;
					cont2=0;
				}
				else{
					if((arr1[i-1]==48)||(arr1[i-1]==49)||(arr1[i-1]==50)||(arr1[i-1]==51)||(arr1[i-1]==52)||(arr1[i-1]==53)||(arr1[i-1]==54)||(arr1[i-1]==55)||(arr1[i-1]==56)||(arr1[i-1]==57)){
						arr2[j]=arr1[i-cont]-48;
						j++;
						cont=0;
					}
				}
			}
		}
		tam=arr2[0]+1;
		fclose(entrada);
		p1=&arr2[1];
		salida1:
		n++;
		k=0;
		for(i=0;i<tam-1;i++){
			if(i<n){
				s_arr1[i]=*(p1+i);
				s_arr2[i]=0;
			}	
			else{
				s_arr2[i]=*(p1+i);
				s_arr1[i]=0;
			}	
			p2=&s_arr1[0];
			p3=&s_arr2[0];	
			suma1[n-1]=suma1[n-1]+*(p2+k);
			suma2[n-1]=suma2[n-1]+*(p3+k);
			k++;		
		}
		p2=&suma1[0];
		p3=&suma2[0];
		resta[n-1]=abs(*(p2+n-1)-*(p3+n-1));
		if(n!=tam) goto salida1;
		for(i=1;i<tam-1;i++){
			if(resta[i]<=resta[i+1]){
				resta[i+1]=resta[i];
			}
			else{
				resta[i]=resta[i+1];
			}
		}
		salida=fopen("salida.sal","w+b");
		if(salida==NULL){
			printf("el fichero no existe");
		}
		else{
			fprintf(salida,"%d",resta[tam-1]);
			fclose(salida);
		}
	}
	return 0;
}		