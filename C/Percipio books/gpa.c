#include <stdio.h>

void addGPA(float[], float);
void calculateAverage(float[], int);

void main(){
    int i = 0;
    float GPA = 0.0;
    float gpaArray[30];
    int gpaCount = 0;
    int choice = 0;

    for(i=0; i<30; i++)
        gpaArray[i]=0.0;

    system("clear");
    printf("You can enter upto 30 GPAs.\n");

    do{
        
        if(GPA == 0){
            printf("\n\t1. Enter a GPA: ");
            scanf("%f", &GPA);
            addGPA(gpaArray, GPA);
            gpaCount++;

        } else {
            printf("\n\nYou have %d's GPA's left to enter\n", (30-gpaCount));
            printf("\nChoose from the following:\n");
            printf("\t1. Enter a GPA\n");
            printf("\t2. Calculate average\n");
            scanf("%d", &choice);
            switch(choice){
                case 1:
                    printf("\nEnter a GPA: ");
                    scanf("%f", &GPA);
                    addGPA(gpaArray, GPA);
                    gpaCount++;
                    break;
                case 2:
                    calculateAverage(gpaArray, gpaCount);
                    break;
            }
        }
        
    }while(GPA != 1);
}

void addGPA(float gpaArray[], float gpa){
    for(int i = 0; i < 30; i++){
        if(gpaArray[i] == 0){
            gpaArray[i]=gpa;
            break;
        }
    }

}

void calculateAverage(float gpaArray[], int gpaCount){
    float average = 0;

    for(int i = 0; i < 30; i++){
        if(gpaArray[i] != 0){
            average += gpaArray[i];
        }  
    }

    printf("\n\nGPA average: %.2f", average/gpaCount);

}