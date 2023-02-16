#include <stdio.h>
#include "STD_TYPES.h"
#include <stdlib.h>
#include <string.h>

u16 slots[5]={0,0,0,0,0};

//constructing a linked list for the program
struct patient {
	u8 name[25];
	u8 gender[10];
	u16 id;
	u16 age;
	struct patient *next;
};
struct patient * head=NULL;
struct patient * current=NULL;


struct reserve {
	
	u16 id;
	u8 slot[15];
	struct reserve *next2;
};
struct reserve * head2=NULL;
struct reserve * current2=NULL;

//Adding new patient

void addpatientatlast(u16 p,u16 x,u8 y[25] ,u8 z[10]){
	struct patient * link = (struct patient *) malloc (sizeof(struct patient));
	link->id = p;
	link->age = x;
	strcpy (link ->name , y);
	strcpy (link ->gender,z);
	
	link -> next =NULL;
	if (head==NULL){
		head=link;
		return;
	}
	current=head;
	while (current->next!=NULL){
		current=current->next;
		
	}
	current->next=link;
}
//ADD new reservation
void addreservationatlast(u16 a,u8 b[15]){
	struct reserve * link2 = (struct reserve *) malloc (sizeof(struct reserve));
	link2->id = a;
	
	strcpy (link2 ->slot , b);
	
	link2 -> next2 =NULL;
	if (head2==NULL){
		head2=link2;
		return;
	}
	current2=head2;
	while (current2->next2!=NULL){
		current2=current2->next2;
		
	}
	current2->next2=link2;
}


//editing the patient 
void editpatient (u16 oldid ,u16 newid,u16 newage,u8 newname[25],u8 newgendre[10] ){
	
	if(head==NULL){
		printf("the list is empty");
		return;
	}
	current=head;
	while(current!=NULL){
		if(current->id==oldid){
			current->id = newid;
			current->age = newage;
			strcpy (current ->name , newname);
	        strcpy (current ->gender,newgendre);
			return;
		}
		current=current->next;
		
	}
	

}
//remove reservation
void deletereservation (u16 x){
			struct reserve *ptr1 =NULL;
			struct reserve *ptr2 =NULL;
			u16 position=0;
			u8 check[15];
			
	if(head2==NULL){
		printf("the list is empty");
		return;
	}
	current2=head2;
	ptr1=head2;
	ptr2=head2;
	
	
	while(current2!=NULL){
		if(current2->id==x) {
			
			strcpy(check,current2->slot);
			
			if (strcmp(check,"2to2:30pm")==0){slots[0]=0;}
			else if (strcmp(check,"2:30to3pm")==0){slots[1]=0;}
			else if (strcmp(check,"3to3:30pm")==0){slots[2]=0;}
			else if(strcmp(check,"4to4:30pm")==0){slots[3]=0;}
			else if(strcmp(check,"4:30to5pm")==0){slots[4]=0;}
			
            ptr1->next2=current2->next2;
			
			free(ptr2);
			return;
		}
		current2=current2->next2;
		ptr2=ptr2->next2;
		if (position !=0){
		ptr1=ptr1->next2;
		}
		position++;
		
	}
	printf("ID is not found"); 
}
//getting patient record
void findrecord (u16 k){
	u16 pos=0;
	if(head==NULL){
		printf("the list is empty");
		return;
	}
	current=head;
	while(current!=NULL){
		if(current->id==k){
			printf("patient name is : %s\n",current->name);
			printf("patient gender is : %s\n",current->gender);
			printf("patient age is : %d\n",current->age);
			
			return;
		}
		current=current->next;
		pos++;
	}
	printf("ID is not found");
}
//the following two print functions i used for debugging
void printpatient (void){
	struct patient *ptr =head;
	while (ptr!=NULL){
		printf("%d=>\n",ptr->id);
		printf("%s=>\n",ptr->name);
		printf("%s=>\n",ptr->gender);
		printf("%d=>\n",ptr->age);
		
		ptr=ptr->next;
	}
}
//printing the reservations for today
void printreservation (void){
	struct reserve *ptr =head2;
	while (ptr!=NULL){
		printf("ID is :%d\n",ptr->id);
		printf("Slot is :%s\n",ptr->slot);
		printf("\t ****** \t \n ");
		
		ptr=ptr->next2;
	}
}

void main(void)
{
	u32 password=0;
	u16 mode=0;
	u16 i=0;
	u16 operation=0;
	u16 operation2=0;
	u16 ID=0;
	u16 Age=0;
	u8 Name[25];
	u8 Gender[10];
	u8 scan1=0;
	u16 IdCheck=0;
	u8 Slot1[15]="2to2:30pm";
	u8 Slot2[15]="2:30to3pm";
	u8 Slot3[15]="3to3:30pm";
	u8 Slot4[15]="4to4:30pm";
	u8 Slot5[15]="4:30to5pm";
	u16 ids[20];
	u16 count=0;
	
	u16 m;
	// Now we are going to choose which mode we are working on 
	//there are 2 modes : admin and user
	//each mode has its features
	printf("\t \t Welcome To Future Clinic \t \t \n");
	printf("\t \t Dr:Saied Mohamed Kamara \t \t \n");
	
	for (u16 f=0;;f++){
	printf("please enter the Mode you want to use\n");
	printf("Press \"1\" for admin mode \t press \"2\" for user mode\n");
	scanf("%d",&mode);
	

	if (mode==1)
		//after choosing admin we check for password 
	{ 
    printf("You have choosen admin mode\n");
	for (i;i<3;i++){
		printf("enter password for admin mode=");
		scanf("%d",&password);
		if (password==1234){
			printf("\t \t You are now working in admin mode\n");
			break;
		}
		printf("Wrong password \n");			
		}
		if (i==3){
				printf("system shall shut down now");
				return ;
				
			}
			//choosing operation
			for (u16 k=0;;k++){
			printf("\t \t ********************\n");
			printf("Future clinic Documentation \n");
			printf("1-Add new patient record\n");
			printf("2-Edit patient record\n");
			printf("3-Reserve a slot with the doctor\n");
			printf("4-Cancel reservation\n");
			printf("5-Print patient record \n");
			printf("6-print reservations for today\n \n \n");
			printf("Choose one of the above operations=");
			
			scanf("%d",&operation);
			//ADD patient
			if (operation == 1){
				for (u16 b=0;;b++){
					
					printf("please enter patient name :");
					scanf("%s",Name);
					
					
					printf("please enter patient age :");
					scanf("%d",&Age);
					
					printf("please enter patient gender :");
					scanf("%s",Gender);
					
					printf("please enter patient ID :");
                    scanf("%d",&ID);
					
					for (u16 j=0;j<=count;j++){
					if  (ID==ids[j]){
						printf("ID is already Used..Please enter another one:");
						scanf("%d",&ID);
					}
					}
					
					
					ids[count]=ID;
					count++;
					
					addpatientatlast(ID,Age,Name,Gender);
					
					printf("If you want to add another Patient Press \"1\" if you dont press \"2\" :");
					scanf("%d",&scan1);
					printf("\t \t************************\n");
					if(scan1==1){continue;}
					else if (scan1==2){break;}
				}
			}
			//Edit patient
			if (operation ==2){
				for (u16 n=0;;n++){
					
					printf("please enter the patient ID you want to edit :");
					scanf("%d",&IdCheck);
					
					
					printf("please enter new patient name :");
					scanf("%s",Name);
					
					printf("please enter new patient age :");
					scanf("%d",&Age);
					
					printf("please enter new patient gender :");
					scanf("%s",Gender);
					
					printf("please enter new patient ID :");
                    scanf("%d",&ID);
					
					editpatient(IdCheck,ID,Age,Name,Gender);
					printf("\n \n");
					
					printf("If you want to edit another Patient Press \"1\" if you dont press \"2\" :");
					scanf("%d",&scan1);
					
					if(scan1==1){continue;}
					else if (scan1==2){break;}
					
				}
			}
			
			
			//Reserving a slot from 5 slots : 2:2.5 ,2.5:3 , 3:3.5, 4:4.5, 4.5:5
			if (operation == 3 )
			{
				printf("the avilable slots for reservation is :\n");
				if (slots[0]==0){printf("1: 2 to 2:30 pm\n");}
				if (slots[1]==0){printf("2: 2:30 to 3 pm\n");}
				if (slots[2]==0){printf("3: 3 to 3:30 pm\n");}
				if (slots[3]==0){printf("4: 4 to 4:30 pm\n");}
				if (slots[4]==0){printf("5: 4:30 to 5 pm\n");}
				printf("Enter patient ID:");
				scanf("%d",&ID);
				printf("Enter the number of slot you want:");
				scanf("%d",&m);
				if(m==1){
					addreservationatlast(ID,Slot1);
					slots[0]=1;
				}
				else if(m==2){
					addreservationatlast(ID,Slot2);
					slots[1]=1;
				}
				else if(m==3){
					addreservationatlast(ID,Slot3);
					slots[2]=1;
				}
				else if(m==4){
					addreservationatlast(ID,Slot4);
					slots[3]=1;
				}
				else if(m==5){
					addreservationatlast(ID,Slot5);
					slots[4]=1;
				}
				printf("\n \n \t \t ***********************\n");
				
				printreservation();
				
				
			}
			//Removing a Reservation
			
			if (operation == 4){
				printf("enter the patient ID you want to remove its reservation :");
				scanf("%d",&ID);
				deletereservation(ID);
				printf("\t \t ****************\n \n ");
				
			}
			printf("If you want to do another opeation press \"1\" if you dont press \"2\" :");
					scanf("%d",&scan1);
					if(scan1==1){continue;}
					else if (scan1==2){break;}
					
				
			}
			
			//showing patient record
			if (operation ==5){
				for (u16 u=0;;u++){
			printf("Please enter patient ID:");
			scanf("%d",&ID);
			findrecord(ID);
			printf("\t \t ************************ \n \n \n");
			printf("If you want to check another Patient Press \"1\" if you dont press \"2\" \n:");
			scanf("%d",&scan1);
					if(scan1==1){continue;}
					else if (scan1==2){break;}
			
			
		}
				
			}
			//showing reservation record
		    if (operation ==6){
				printreservation();
			printf("\t\t ********************** \n \n \n");
				
			}
	}		
	
		//choosing user mode
	if (mode==2){
		printf("\t \t you are now working on user mode \n");
		printf("Choose on of you following features:\n");
		printf("1:View patient record\n");
		printf("2:view today's reservation\n");
		scanf("%d",&operation2);
		
		//showing patient record
		if (operation2 == 1){
			for (u16 u=0;;u++){
			printf("Please enter patient ID:");
			scanf("%d",&ID);
			findrecord(ID);
			printf("\t \t ************************ \n \n \n");
			printf("If you want to check another Patient Press \"1\" if you dont press \"2\" \n:");
			scanf("%d",&scan1);
					if(scan1==1){continue;}
					else if (scan1==2){break;}
			
			
		}
		}
		//showing today reservations
		else if (operation2 == 2){
			printreservation();
			printf("\t\t ********************** \n \n \n");
			
		}
	}	
		
	
	printf("If you want to change your mode or start again press \"1\" if you want to shut down \"2\" :");
					scanf("%d",&scan1);
					if(scan1==1){continue;}
					else if (scan1==2){break;}
	}
	}
		
	
