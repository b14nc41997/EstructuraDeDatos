#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int nodeCount=1;

struct node{
	int weight;
	int code;
	struct node *next;
};

typedef struct node *List;

List createNode(){
	List newNode = NULL;
	int w;
	newNode = new(struct node);
	cout<<endl<<">Ingrese peso de paquete: ";
	cin>>w;
	newNode->weight=w;
	newNode->code=nodeCount++;
	newNode->next=NULL;
	return newNode;
}

void insertEnd(List &list){
	List node=createNode();
	cout<<endl<<">Nuevo paquete registrado: "<<node->code<<", "<<node->weight<<endl<<endl;
	if(list==NULL){
		list=node;
		return;
	}
	List temp=list;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=node;
}

int nodeCounter(List list){
	if (list==NULL){
		cout<<">Cantidad de paquetes: 0"<<endl<<endl;
		return 0;
	}
	int counter=0;
	while(list!= NULL){
		list=list->next;
		counter++;
	}
	cout<<">Cantidad de paquetes: "<<counter<<endl<<endl;
	return counter;
}

void nodeSum(List list,int counter){
	if (list==NULL){
		cout<<">Peso promedio de paquetes: 0"<<endl<<endl;
		return;
	}
	float sum=list->weight, average;
	while(list->next != NULL){
		list=list->next;
		sum=sum+list->weight;
	}
	average=sum/counter;
	cout<<">Peso promedio de paquetes: "<<average<<endl<<endl;	
}

void sortingByExchangeMethod(List list, int size){
	if (list==NULL){
		cout<<endl<<"ERROR: Lista vacia.. no permite esta opcion"<<endl<<endl;
		system("pause");
		return;
	}
	int w,c;
	List temp=NULL;
	bool flag=true;
	for (int i=1;(i<size && flag==true);i++){
		temp=list;
		flag=false;
		while(temp->next != NULL){
			temp=temp->next;
			if(list->weight > temp->weight){
				w=temp->weight;
				temp->weight=list->weight;
				list->weight=w;
				
				c=temp->code;
				temp->code=list->code;
				list->code=c;
				flag=true;
			}
		}
		list=list->next;
	}
}

void seeList(List list){
	if (list==NULL){
		cout<<">LISTA VACIA..."<<endl<<endl;
		return;
	}
	cout<<">LISTA: ";
	while(list!=NULL){
		cout<<list->code<<", "<<list->weight<<"      ";
		list=list->next;
	}
	cout<<endl<<endl;
}

int menu(){
	int option;
	do	{
		system("CLS");
		cout<<"\n\tLABORATORIO\n\n";
		cout<<"1.- Registrar paquetes"<<endl;//mostrar cant y peso prom, lista
		cout<<"2.- Ordenar paquetes"<<endl;//mostrar lista anterior???
		cout<<"0.- Salir"<<endl<<endl;
		cout<<"Ingresar Opcion---> ";
		cin>>option;
	}while(option<0 || option>2);
	return option;
}

int main() {
	List list=NULL;
	int option=0,count=0;
	do{
		option = menu();
		switch(option){
			case 1:{
				insertEnd(list);
				count=nodeCounter(list);
				nodeSum(list,count);
				seeList(list);
				system("pause");
				break;
			}
			case 2:{
				if (list==NULL){
					cout<<endl<<"ERROR: Lista vacia.. no permite esta opcion"<<endl<<endl;
					system("pause");
					break;
				}
				sortingByExchangeMethod(list,count);
				seeList(list);
				system("pause");
				break;
			}
		}
	}while(option !=0);
	return 0;
}
