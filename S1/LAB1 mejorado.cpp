#include<iostream>
using namespace std;

//Ver las buenas prácticas al codificar
//Ver si estoy comentando bien
//Aplicar TDA con los desplazamientos a la derecha,izquierda y mostrar vectores

int A[10],B[10],C[20];
int j=0,k=0;//acumuladores?(verificar nombre)
			//j: indica cantidad de valores actuales en vectores A y B
			//k: indica cantidad de valores actuales en vector C
int menu();
void extraer();
void visualizar();
void insertar();
void liberar();//desplaza 1 espacio a la izquierda a vectores A y B

int main(){
	int op;
	do	{
		op = menu();
		switch (op){
			case 1:insertar();break;
			case 2:extraer();break;
			case 3:visualizar();break;
			case 4:break;
		}
	}while (op!=4); //consistencia de opcion de menu
	return 0;
}

void extraer(){
	if (j==0) //consistencia por vectores A y B vacios
		cout<<"Vectores A y B vacios, elegir opcion 1";
	else{
		int suma=A[0]+B[0];
		j--;	//Reducir acumulador de A y B
		k++;	//Aumentar acumulador de C
		if (k!=1){	//desplazamiento de valores de C a la derecha
			for(int i=k;i>0;i--)
				C[i]=C[i-1];
		}
		C[0]=suma; //Asignación de nuevo valor al inicio de C[]
		liberar(); //Quitar sumandos de A y B
		visualizar();	
	}
}

void liberar(){
	for(int i=0;i<j;i++){	//Desplazamiento a la izquierda de valores de A y B
		A[i]=A[i+1];
		B[i]=B[i+1];
	}
}

void visualizar(){
	cout<<"Vector A: ";
	for(int i=0;i<j;i++)
		cout<<A[i]<<"\t";
	cout<<endl;
	cout<<"Vector B: ";
	for(int i=0;i<j;i++)
		cout<<B[i]<<"\t";
	cout<<endl;
	cout<<"Vector C: ";
	for(int i=0;i<k;i++)
		cout<<C[i]<<"\t";
}

void insertar(){
	if(j==10)	//Consistencia, sin espacio en A y B
		cout<<"Vectores A y B llenos, elegir opcion 2";
	else{
		int numP,numN;
		j++;
		do	{cout<<"Inserte 1 numero positivo (distinto de 0): ";
			cin>>numP;
		}while(numP<=0);	//Consistencia, solo números positivos
		if (j!=1){	//Caso solo si hay más de un valor en A[]
			for(int i=j;i>0;i--)	//Desplazamiento a la derecha para dejar [0] libre
				A[i]=A[i-1];
		}
		A[0]=numP;
		do	{cout<<"Inserte 1 numero negativo (distinto de 0): ";
			cin>>numN;
		}while(numN>=0); 	//Consistencia, solo números negativos
		if (j!=1){	//Caso solo si hay más de un valor en B[]
			for(int i=j;i>0;i--)	//Desplazamiento a la derecha para dejar [0] libre
				B[i]=B[i-1];
		}
		B[0]=numN;
	}
}

int menu(){//Hacerlo con puntero???
	int op;
	cout<<endl;
	cout<<">>>> MENU <<<<"<<endl;
	cout<<"1) Insertar"<<endl;
	cout<<"2) Extraer"<<endl;
	cout<<"3) Visualizar"<<endl;
	cout<<"4) Salir"<<endl;
	do	{
		cout<<"Opcion -> ";
		cin>>op;
	}while(op<0 || op>4);
	
	cout<<endl;
	return op;
}
