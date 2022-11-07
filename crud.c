//CRUD APPLICATION IN C
#include<stdio.h>
#include<string.h>
void addStudent();
void editStudent();
void deleteStudent();
void searchStudent();
void displayStudent();
void displayListOfStudents();
int rollNumber[100];
char name[100][21];
int numberOfStudentsAdded;

int main()
{
    int ch;
    numberOfStudentsAdded=0;  
    while(1)
    {  
      printf("1.Add Student\n");
      printf("2.Edit Student\n");
      printf("3.Delete Student\n");
      printf("4.Search Student\n");
      printf("5.Display List of Students\n");
      printf("6.Exit\n");
      printf("Enter your choice(1-6):");
      scanf("%d",&ch);
      fflush(stdin);
      if(ch<1 || ch>6)
      {
        printf("Invalid Input, enter a valid choice.\n");
        continue;
        //continue se control vapas loop ke start mei jata h
      }
      if(ch==1 && numberOfStudentsAdded==100)
      {
        printf("You cannot add more than 100 students,\n");
        continue;
      }
      if(ch>=2 && ch<=5 && numberOfStudentsAdded==0)
      {
        printf("You have not added a single student.\n");
        continue;

      }
      if(ch==1) addStudent();
      if(ch==2) editStudent();
      if(ch==3) deleteStudent();
      if(ch==4) searchStudent();
      if(ch==5) displayListOfStudents();
      if(ch==6) break;
    }
    return 0;
}
void addStudent()
{
    int vRollNumber;
    char vName[22];
    char m,e;
    printf("Student(Add Module)\n");
    printf("Enter a roll number: ");
    scanf("%d",&vRollNumber);
    fflush(stdin);
    if(vRollNumber<=0)
    {
        printf("Invalid roll number.\n");
        return;
    }    
    e=0;
    while(e<numberOfStudentsAdded)
    {
        if(vRollNumber==rollNumber[e])
        {
            printf("That roll number is already alloted to %s.\n",name[e]);
            return;
        }
        e++;
    }
    printf("Enter name: ");
    fgets(vName,22,stdin);
    fflush(stdin);
    vName[strlen(vName)-1]='\0';
    printf("Save(Y/N): ");
    m=getchar();
    fflush(stdin);
    if(m!='y' && m!='Y')
    {
        printf("Student not added.\n");
        return;
    }
    rollNumber[numberOfStudentsAdded]=vRollNumber;
    strcpy(name[numberOfStudentsAdded],vName);
    numberOfStudentsAdded++;
    printf("Student added, press enter to continue.....");
    getchar();
    //getchar application ko rukwa dega
    fflush(stdin);
    numberOfStudentsAdded++;
}
void editStudent()
{
    int vRollNumber,found;
    char vName[22];
    char m;
    int e;
    printf("Student(Edit Module)\n");
    printf("Enter roll number of the student to edit: ");
    scanf("%d",&vRollNumber);
    fflush(stdin);
    if(vRollNumber<=0)
    {
        printf("Invalid Roll Number!\n");
        return;
    }
    found=0;
    e=0;
    while(e<numberOfStudentsAdded)
    {
        if(vRollNumber==rollNumber[e])
        {
            found=1;
            break;
        }
        e++;
    }
    if(found==0)
    {
        printf("Invalid roll number!\n");
        return;
    }
    printf("Name : %s\n",name[e]);
    printf("Edit(Y/N): ");
    m=getchar();
    fflush(stdin);
    if(m!='y' && m!='Y')
    {
        printf("Student not edited.\n");
        return;
    }
    printf("Enter new name : ");
    fgets(vName,22,stdin);
    fflush(stdin);
    vName[strlen(vName)-1]='\0';
    printf("Update(Y/N): ");
    m=getchar();
    fflush(stdin);
    if(m!='y'&&m!='Y')
    {
        printf("Student not updated.\n");
        return;
    }
    strcpy(name[e],vName);
    printf("Student updated, press enter to continue...");
    getchar();
    fflush(stdin);

}
void deleteStudent()
{
    int vRollNumber;
    int e,found;
    char m;
    int ep;
    printf("Student (Delete Module)\n");
    printf("Enter roll number to be deleted: ");
    scanf("%d",&vRollNumber);
    fflush(stdin);
    if(vRollNumber<=0)
    {
        printf("Invalid roll number !\n");
        return;
    }
    found=0;
    e=0;
    while(e<numberOfStudentsAdded)
    {
        if(vRollNumber==rollNumber[e])
        {
            found=1;
            break;
        }
        e++;
    }
    if(found==0)
    {
        printf("Invalid roll number!\n");
        return;
    }
    printf("Name : %s\n",name[e]);
    printf("Delete(Y/N): \n");
    m=getchar();
    fflush(stdin);
    if(m!='y' && m!='Y')
    {
        printf("Student not deleted.\n");
        return;

    }
    ep=numberOfStudentsAdded-2;
    while(e<=ep)
    {
        rollNumber[e]=rollNumber[e+1];
        strcpy(name[e],name[e+1]);
        e++;
    }
    numberOfStudentsAdded--;
    printf("Student deleted, press enter to continue.....");
    getchar();
    fflush(stdin);
        
}
void searchStudent()
{
    printf("Student(Search Module)\n");
    int e,vRollNumber,found;
    printf("Enter roll number of the student to be searched: ");
    scanf("%d",&vRollNumber);
    fflush(stdin);
    if(vRollNumber<=0)
    {
        printf("Invali Roll Number!\n");
        return;
    }
    e=0;
    found=0;
    while(e<numberOfStudentsAdded)
    {
        if(vRollNumber==rollNumber[e])
        {
            found=1;
            break;
        }
        e++;
    }
    if(found==0)
    {
        printf("Invalid roll number.\n");
        return;
    }
    printf("Name : %s\n",name[e]);
    printf("Press enter to continue......");
    getchar();
    fflush(stdin);
    
}
void displayListOfStudents()
{
    int f;
    printf("Student(List Module)\n");
    f=0;
    while(f<numberOfStudentsAdded)
    {
        printf("Roll number : %d, Name : %s\n",rollNumber[f],name[f]);
        f++;
    }
    printf("Press enter to continue.....");
    getchar();
    fflush(stdin);
}

