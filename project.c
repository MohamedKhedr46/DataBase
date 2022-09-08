#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef struct Student
{
    char studentId[10];
    char studentYear[10];
    char course_1Id[10];
	char course_1Grade[10];
	char course_2Id[10];
	char course_2Grade[10];
	char course_3Id[10];
	char course_3Grade[10];
} Student;

void createAccount();
void displayInfo();
void updateInfo(); 
void deleteInfo();
void searchInfo();


int main()
{
    char option;

    while (option != '0')
    {
        system("cls");
        printf("\n\t\t\t Student Management Database System \n");
        printf("\n\t\t\t1. Create Student Account");
        printf("\n\t\t\t2. Display All Students Information");
        printf("\n\t\t\t3. Update Student Information");
        printf("\n\t\t\t4. Delete Student Information");
        printf("\n\t\t\t5. Search Student Information");
        printf("\n\t\t\t0. Exit");

        printf("\n\n\n\t\t\tEnter Your Option: ");
        scanf(" %c", &option);

        switch (option)
        {
        case '1':
            createAccount();
            break;
        case '2':
            displayInfo();
            break;
        case '3':
            updateInfo();
            break;
        case '4':
            deleteInfo();
            break;
       case '5':
            searchInfo();
            break;
        case '0':
            printf("\n\t\t\t\t Thank You ");
            break;
        default:
            printf("\n\t\t\tInvalid Option, Please Enter Right Option !\n");
        }
    }
    return 0;
}

void createAccount()
{
    FILE *fileOne = fopen("studentInfo.bin", "ab+");

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    Student stundentInformation;

    system("cls");

    printf("\t\t\t\t Create Student Account \n");

    printf("\n\t\t\tEnter Student's ID : ");
    getchar();
    gets(stundentInformation.studentId);
    printf("\t\t\tEnter Student's Year : ");
    gets(stundentInformation.studentYear);
    printf("\t\t\tEnter Course_1 ID : ");
    gets(stundentInformation.course_1Id);
	printf("\t\t\tEnter Course_1 Grade : ");
    gets(stundentInformation.course_1Grade);
	printf("\t\t\tEnter Course_2 ID : ");
    gets(stundentInformation.course_2Id);
	printf("\t\t\tEnter Course_2 Grade : ");
    gets(stundentInformation.course_2Grade);
	printf("\t\t\tEnter Course_3 ID : ");
    gets(stundentInformation.course_3Id);
	printf("\t\t\tEnter Course_3 Grade : ");
    gets(stundentInformation.course_3Grade);
	
	
    fwrite(&stundentInformation, sizeof(stundentInformation), 1, fileOne);

    printf("\n\n\t\t\tInformations have been stored sucessfully\n");
    printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();

    fclose(fileOne);
}

void displayInfo()
{
    FILE *fileOne = fopen("studentInfo.bin", "rb");

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    Student stundentInformation;

    system("cls");

    printf("\n\n\t\t\t\t\t\t\tAll Students Information \n");

    printf("\n\n\t\t %s \t\t%s \t\t%s \t\t%s \t\t%s \t\t%s \t\t%s \t\t%s\n", "ID", "year", "Course_1 ID", "Grade","Course_2 ID", "Grade", "Course_3 ID", "Grade");

    while (fread(&stundentInformation, sizeof(stundentInformation), 1, fileOne) == 1)
    {
        printf("\n\n\t\t%s \t\t%s \t \t%s \t\t\t%s \t\t%s \t\t\t%s \t  \t%s \t\t\t%s\n", stundentInformation.studentId, stundentInformation.studentYear, stundentInformation.course_1Id , stundentInformation.course_1Grade ,stundentInformation.course_2Id, stundentInformation.course_2Grade, stundentInformation.course_3Id, stundentInformation.course_3Grade);
    }

    printf("\n\n\t\tEnter any keys to continue.......");
    getch();

    fclose(fileOne);
}

void updateInfo()
{
    FILE *fileOne = fopen("studentInfo.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");

    Student studentInformation, tempInformation;

    int choice, flag = 0;

    if (fileOne == NULL || temp == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\n\n\t\t\t\t\t Update Students Information \n");

    printf("\n\t\t\tEnter Student's ID : ");
    getchar();
    gets(tempInformation.studentId);

    while (fread(&studentInformation, sizeof(studentInformation), 1, fileOne) == 1)
    {
        if (strcmp(studentInformation.studentId, tempInformation.studentId) == 0)
        {
            flag++;
            printf("\n\t\t\tChoose your option :\n\t\t\t1.Update Student ID\n\t\t\t2.Update Student Year.\n\t\t\t3.Update course_1 Id\n\t\t\t4.Update course_1 Grade\n\t\t\t5.Update course_2 Id\n\t\t\t6.Update course_2 Grade\n\t\t\t7.Update course_3 Id\n\t\t\t8.Update course_3 Grade");
            printf("\n\n\t\t\tEnter Your Option : ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("\n\t\t\tEnter Student's ID to Update: ");
                getchar();
                gets(tempInformation.studentId);
                strcpy(studentInformation.studentId, tempInformation.studentId);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 2)
            {
                printf("\n\t\t\tEnter Student's Year to Update: ");
                getchar();
                gets(tempInformation.studentYear);
                strcpy(studentInformation.studentYear, tempInformation.studentYear);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 3)
            {
                printf("\n\t\t\tEnter Course_1 ID to Update: ");
                getchar();
                gets(tempInformation.course_1Id);
                strcpy(studentInformation.course_1Id, tempInformation.course_1Id);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 4)
            {
                printf("\n\t\t\tEnter course_1 Grade to Update: ");
                getchar();
                gets(tempInformation.course_1Grade);
                strcpy(studentInformation.course_1Grade, tempInformation.course_1Grade);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 5)
            {
                printf("\n\t\t\tEnter Course_2 ID to Update: ");
                getchar();
                gets(tempInformation.course_2Id);
                strcpy(studentInformation.course_1Id, tempInformation.course_1Id);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 6)
            {
                printf("\n\t\t\tEnter course_2 Grade to Update: ");
                getchar();
                gets(tempInformation.course_2Grade);
                strcpy(studentInformation.course_2Grade, tempInformation.course_2Grade);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }			
			else if (choice == 7)
            {
                printf("\n\t\t\tEnter Course_3 ID to Update: ");
                getchar();
                gets(tempInformation.course_3Id);
                strcpy(studentInformation.course_3Id, tempInformation.course_3Id);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 8)
            {
                printf("\n\t\t\tEnter course_3 Grade to Update: ");
                getchar();
                gets(tempInformation.course_3Grade);
                strcpy(studentInformation.course_3Grade, tempInformation.course_3Grade);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
			
            else
            {
                printf("\n\t\t\tInvalid Option.");
                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
            }
        }
        else
        {
            fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
        }
    }

    fclose(fileOne);
    fclose(temp);

    remove("studentInfo.bin");
    rename("temp.bin", "studentInfo.bin");

    if (flag == 0)
    {
        printf("\n\t\t\tStudent Id is not found");
    }

    printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();
}

void deleteInfo()
{
    FILE *fileOne = fopen("studentInfo.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");

    Student studentInformation, tempInformation;

    int choice, flag = 0;

    if (fileOne == NULL || temp == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\n\n\t\t\t\t\t Delete Student Information \n");

    printf("\n\t\t\tEnter Student's ID : ");
    getchar();
    gets(tempInformation.studentId);

    while (fread(&studentInformation, sizeof(studentInformation), 1, fileOne) == 1)
    {
        if (strcmp(studentInformation.studentId, tempInformation.studentId) == 0)
        {
            flag++;
            printf("\n\t\t\tAre you sure to delete ??\n\t\t\t\t1.Yes\n\t\t\t\t2.Back\n\t\t\t\tEnter Your Option : ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("\n\n\t\t\tInformation has been deleted successfully!\n\n");
            }
            else if (choice == 2)
            {
                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
            }
            else
            {
                printf("\n\t\t\tInvalid Option");
                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
            }
        }
        else
        {
            fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
        }
    }

    fclose(fileOne);
    fclose(temp);

    remove("studentInfo.bin");
    rename("temp.bin", "studentInfo.bin");

    if (flag == 0)
    {
        printf("\n\t\t\tStudent Id is not found");
    }

    printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();
}

void searchInfo()
{
    FILE *fileOne = fopen("studentInfo.bin", "rb");

    Student studentInformation;

    int choice, flag = 0;
    char studentID[10];

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }


        system("cls");
        printf("\n\n\t\t\t\t\t Search Student Information \n");
        printf("\n\n\t\t\tEnter Student ID : ");
        getchar();
        gets(studentID);
        while (fread(&studentInformation, sizeof(studentInformation), 1, fileOne) == 1)
        {
            if (strcmp(studentInformation.studentId, studentID) == 0)
            {
                flag++;
                printf("\n\t\t\tStudent ID : %s\n\t\t\tStudent Year : %s\n\t\t\tcourse_1 Id : %s\n\t\t\tcourse_1 Grade : %s\n\t\t\tcourse_2 Id : %s\n\t\t\tcourse_2 Grade : %s\n\t\t\tcourse_3 Id  : %s\n\t\t\tcourse_3 Grade : %s\n", studentInformation.studentId, studentInformation.studentYear, studentInformation.course_1Id, studentInformation.course_1Grade, studentInformation.course_2Id, studentInformation.course_2Grade, studentInformation.course_3Id, studentInformation.course_3Grade);
            }
        }
        if (flag == 0)
        {
            printf("\n\t\t\tStudent Id is not found");
        }

    else
    {
        printf("\n\t\t\tInvalid Option");
    }

    fclose(fileOne);

    printf("\n\n\n\t\t\tEnter any keys to continue.......");
    getch();
}
