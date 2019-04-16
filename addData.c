#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "addData.h"
void addbook(int count,FILE *fp){
    /*FILE *fp;

    int n=0;
    while(!feof(fp)){
        n++;
    }*/
    int num=0;
   // printf("%d",count);
    fseek(fp,0,2);
    printf("what number books do you want to store:\n");
	scanf("%d",&num);
    printf("Input data:\n");
    for(int i=0; i<num; i++){
        struct book temp1;
      //  temp1.numberB=count;

        sprintf(temp1.numberB, "%d", count);
        scanf("%s %s", temp1.nameB, temp1.writer);
        fprintf(fp,"%s %s %s\n", temp1.numberB, temp1.nameB, temp1.writer);
        printf("%s%s%s\n",temp1.numberB,temp1.nameB,temp1.writer);
        count++;
    }
   // fclose(fp);
    return;
}
