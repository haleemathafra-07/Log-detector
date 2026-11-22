#include <stdio.h>
#include <string.h>

//FUNCTION DECLARATIONS
void readLog(int* info,int*warning,int* error);
void filterError();
void filterWarning();
void filterInfo();
void searchLog(char* searchWord);
void saveReport(int* info,int*warning,int* error);

int main()
{
    int info=0,warning=0,error=0;
    char searchWord[100];

     readLog( &info, &warning,&error);
    //log report display
    printf("=================================\n\n");
    printf("\n\n========== LOG REPORT ==========\n\n");
    printf("TOTAL LOG ENTRIES: %d\n",info+warning+error);
    printf("INFO: %d\n",info);
    printf("WARNING: %d\n",warning);
    printf("ERROR: %d\n",error);
    printf("=================================\n\n");
    
    
    filterError();
    filterInfo();
    filterWarning();
    searchLog(searchWord);
    saveReport(&info,&warning,&error);

    return 0;
}

void readLog(int* info,int*warning,int* error)
{
    FILE* fptr;
    fptr = fopen("logs/sample.log", "r");

    char content[1000];

    if (fptr != NULL)
    {
        while (fgets(content, sizeof(content), fptr))
        {
            printf("%s", content);
            if(strstr(content,"ERROR"))
            {
                (*error)++;
            }

            if(strstr(content,"WARNING"))
            {
                (*warning)++;
            }

            if(strstr(content,"INFO"))
            {
                (*info)++;
            }
        }

        fclose(fptr);
    }
    else
    {
        printf("FILE OPEN UNSUCCESSFUL!");
    }

}

void filterError()
{
    FILE* fptr;
    fptr = fopen("logs/sample.log", "r");

    char content[1000];

    if (fptr != NULL)
    {
         printf("\n\n=================== ERROR LOGS ===============\n\n");
         while (fgets(content, sizeof(content), fptr))
         {
            if(strstr(content,"ERROR"))
            {
               printf("%s", content);
            }
         }
        fclose(fptr);
    }
    else
    {
        printf("FILE OPEN UNSUCCESSFUL!");
    }

}

void filterInfo()
{
    FILE* fptr;
    fptr = fopen("logs/sample.log", "r");

    char content[1000];

    if (fptr != NULL)
    {
         printf("\n\n=================== INFO LOGS ===============\n\n");
         while (fgets(content, sizeof(content), fptr))
         {
            if(strstr(content,"INFO"))
            {
               printf("%s", content);
            }
         }
        fclose(fptr);
    }
    else
    {
        printf("FILE OPEN UNSUCCESSFUL!");
    }

}

void filterWarning()
{
    FILE* fptr;
    fptr = fopen("logs/sample.log", "r");

    char content[1000];

    if (fptr != NULL)
    {
        printf("\n\n=================== WARNING LOGS ===============\n\n");
         while (fgets(content, sizeof(content), fptr))
         {
            if(strstr(content,"WARNING"))
            {
               printf("%s", content);
            }
         }
        fclose(fptr);
    }
    else
    {
        printf("FILE OPEN UNSUCCESSFUL!");
    }

}

void searchLog(char* searchWord)
{
    printf("\nENTER THE WORD TO SEARCH: ");
    fgets(searchWord,100,stdin);

     //strcspn() finds the newline, and we replace it with the string terminator.
     searchWord[strcspn(searchWord, "\n")] = '\0';

    FILE* fptr;
    fptr = fopen("logs/sample.log", "r");

    char content[1000];

    if (fptr != NULL)
    {
        
         while (fgets(content, sizeof(content), fptr))
         {
            if(strstr(content,searchWord))
            {
                
                 printf("%s", content);
            }
         }
        fclose(fptr);
    }
    else
    {
        printf("FILE OPEN UNSUCCESSFUL!");
    }

}



void saveReport(int* info, int* warning, int* error)
{
    FILE* fptr, *fptr_2;

    fptr_2 = fopen("reports/analysis_report.txt", "w");
    fptr = fopen("logs/sample.log", "r");

    if(fptr != NULL)
    {
        if(fptr_2 != NULL)
        {
            fputs("=====LOG ANALYSIS REPORT ======\n\n", fptr_2);

            fprintf(fptr_2, "TOTAL LOG ENTRIES : %d\n", *error + *info + *warning);
            fprintf(fptr_2, "INFO: %d\n", *info);
            fprintf(fptr_2, "WARNING: %d\n", *warning);
            fprintf(fptr_2, "ERROR: %d\n", *error);

            char content[1000];
            char errors[10][250];
            int errorCounts[10] = {0};
            int uniqueCount = 0;

            while(fgets(content, sizeof(content), fptr))
            {
                char* message = strstr(content, "ERROR: ");

                if(message != NULL)
                {
                    message += 7;
                    int found = 0;

                    message[strcspn(message, "\n")] = '\0';

                    for(int p = 0; p < uniqueCount; p++)
                    {
                        if(strcmp(message, errors[p]) == 0)
                        {
                            errorCounts[p]++;
                            found = 1;
                            break;
                        }
                    }

                    if(found == 0 && uniqueCount < 10)
                    {
                        strcpy(errors[uniqueCount], message);
                        errorCounts[uniqueCount] = 1;
                        uniqueCount++;
                    }
                }
            }

            fprintf(fptr_2, "\n\n============== ERROR SUMMARY ==============\n\n");

            for(int p = 0; p < uniqueCount; p++)
            {
                fprintf(fptr_2, "%s : %d\n", errors[p], errorCounts[p]);
            }

            fclose(fptr);
            fclose(fptr_2);
        }
        else
        {
            printf("\nREPORT FILE OPEN UNSUCCESSFUL\n");
            fclose(fptr);
        }
    }
    else
    {
        printf("\nLOG FILE OPEN UNSUCCESSFUL\n");

        if(fptr_2 != NULL)
        {
            fclose(fptr_2);
        }
    }
}
