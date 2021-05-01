#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void admin();
void addPatient();
void edit();

int main()
{


    printf("Welcome to clinic \n For Admin Mode press 1 \n For User Mode press 2\n");
    char mode;
    scanf("%c" , &mode);
    if(mode == '1'){
        admin();
    }

    return 0;
}
void edit(){
FILE *patients = fopen("Patients.txt","a");
FILE *patient = fopen("Patients.txt","r");
FILE *patient2 = fopen("Patients.txt","r");

FILE *temp = fopen("temporary.tmp","w");
char id[8];
char newID[8];
printf("\nID: ");
scanf("%s",id);
printf("\nNew ID: ");
scanf("%s",newID);
int c = 0;
char buffer[200];
while((fgets(buffer , 200 , patient))!= NULL){
printf("hi");
        c++;
    int i = 0;
    char tempID[10] = "";
    int tempIDIndex = -1;
    // save current ID in variable tempID
    while(buffer[i] != ','){
            tempID[++tempIDIndex] = buffer[i];
           // printf("hi");
            //printf("%c",buffer[i]);
       // strcat(tempID,buffer[i]);
        //printf("%s",tempID);
        printf("olddata");
        i++;
    }
    // put new data in temporary file
    if(strcmp(tempID,id) == 0){
            printf("%s",tempID);
        char buffer2[200];
        char *pat[30];
        char name2[30] = "";
        char id2[8] = "";
        char gender2[2] = "";
        char age2[3] = "";
        int x = 0;
        int q = 0;
        int index = -1;
        while((fgets(buffer2 , 200 , patient2))!= NULL){
           // printf("%d",c);
           printf("getout");
                x++;
            if(c == x){
                    int n = 0;

                for(n=0;n<strlen(buffer2)-1;n++){
                    if(buffer2[n] == ','){
                            q++;
                            index = -1;
                        continue;
                    }
                    else{
                       // strcat(pat[q],buffer[n]);
                       printf("newdata");
                       printf("%d",q);
                      // pat[q][++index] = buffer2[n];
                     // strncat(pat[q],&buffer2[n],1);
                      //printf("%s",pat[q]);
                      switch(q){
                      case 0 : {id2[++index] = buffer2[n];
                      } break;
                      case 1: {
                      name2[++index] = buffer2[n];
                      } break;
                      case 2: {
                      gender2[++index] = buffer2[n];
                      } break;
                      case 3: {
                      age2[++index] = buffer2[n];
                      } break;
                      }
                    }
                }
                char newData[80];
               // printf("%s,%s,%s,%s",pat[0],pat[1],pat[2],pat[3]);

                sprintf(newData,"%s,%s,%s,%s",newID,name2,gender2,age2);
               // printf("%s",newID);
                printf("%s,%s,%s,%s hi",id2,name2,gender2,age2);


                fprintf(temp , "%s\n",newData);
             // fputs(newData,temp);
            }
            else{
                    printf("%s",buffer2);
                fprintf(temp,"%s",buffer2);
              // fputs(buffer2,temp);
            }
        }
       break;
    }
}
fclose(patient2);
fclose(patient);
fclose(patients);
fclose(temp);
remove("Patients.txt");
rename("temporary.tmp","Patients.txt");


}
void addPatient(){
 FILE *patients = fopen("Patients.txt","a");
char name[30];
char gender[3];
char age[3];
char id[8];
char test[4];
printf("\nhi ");
gets(test);

printf("\nName: ");

gets(name);
printf("\nGender: ");
gets(gender);
printf("\nAge: ");
gets(age);
printf("\nID: ");
gets(id);


fprintf(patients,"%s,%s,%s,%s\n",id,name,gender,age);
}


void admin(){
char password[5] = "1234";
char userPassword[5];

    int f = 0;
    for(int i = 0 ; i<3 ; i++){
printf("Password : ");
scanf("%s",userPassword);

if(strcmp(password,userPassword) == 0){
  f = 1;
  break;
}
else{
    printf("Incorrect Password ");
}
}
if(f == 1){
    printf("Admin");
   // addPatient();
    edit();

}
else{
    exit(1);
}

}
