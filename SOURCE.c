#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>

struct file_0{
  char Name[10];
  int roll_no;
  struct subject_marks{
    float Subject_marks[6];
  } g;
}d[35],*ptr;

struct SUBJECT{
  char a[10][6];
}g,*gptr;

struct file_1{
  char Name[10],Grade[5];
  int roll_no;
  float Total,Percentage;
  struct subject_marks_1{
    int Subject_marks_0[6];
  }u;
}i_1[35],*iptr;

int i,j,k;

void door_1();//   1*****

struct SUBJECT SUBJECT_NAME(struct SUBJECT h);//    2*****

void processResult();//      4****************

void FILE_2();//          5*************

int main()//*********************************main()******************************
{
  iptr=i_1;
  gptr=&g;
  SUBJECT_NAME(g);//correction

  ptr=d;//pointer defintion for main structure
  door_1();//function call (2)
  processResult();

  return 0;
}
struct SUBJECT SUBJECT_NAME(struct SUBJECT h)
{
  for(i=1;i<7;i++)
  {
    printf("#######ENTER SUBJECT %d NAME\n",i);
    scanf("%s",gptr->a[i]);
  }
  return h;
}

void door_1()//    1******
{
  FILE *fp=fopen("/Users/mac/documents/Project_10.txt","w");
  for(i=0;i<3;i++)
  {
  printf("\n********Enter the students name*********\n");
    scanf(" %[^\n]s",ptr->Name);//a sapce before % fixes the issue of it skipping user input
  printf("********Enter %s's roll no*******\n",ptr->Name);
    scanf("%d",&ptr->roll_no);
  srand(time(NULL));//difference in random genaration
  for(j=1;j<7;j++)
    {
      printf("********Entering %s's Subject_marks For %s *********\n",ptr->Name,gptr->a[j]);//open in a loop
      ptr->g.Subject_marks[j]=rand()%100;//random genration of numbers
    }
    fprintf(fp,"%s\n%d\n",ptr->Name,ptr->roll_no);
    for(k=0;k<6;k++)
    fprintf(fp,"%f\n",ptr->g.Subject_marks[k]);
  ptr++;
  }
  //FILE();//function call ******  3
  fclose(fp);
}

void processResult()
{
  FILE *fp0,*fp1;
  i=0;
  fp0=fopen("/Users/mac/documents/Project_10.txt","r");
  for(i=0;i<3;i++)
    fread(&i_1[i],sizeof(struct file_1),1,fp0);
  fclose(fp0);
  fp1=fopen("/Users/mac/documents/Ledger.txt","w");
  iptr->Total=0;
  for(i=0;i<3;i++)
    {
    for(j=0;j<6;j++)
      {
        iptr->Total+=iptr->u.Subject_marks_0[j];
      }
  iptr->Percentage=iptr->Total/5;
    if(iptr->Percentage>=95)
      strcpy(iptr->Grade,"A+");
    else if(iptr->Percentage>=90 && iptr->Percentage<95)
      strcpy(iptr->Grade,"A");
    else if(iptr->Percentage>=85 && iptr->Percentage<90)
      strcpy(iptr->Grade,"A-");
    else if(iptr->Percentage>=80 && iptr->Percentage<85)
      strcpy(iptr->Grade,"B+");
    else if(iptr->Percentage>=75 && iptr->Percentage<80)
      strcpy(iptr->Grade,"B");
    else if(iptr->Percentage>=70 && iptr->Percentage<75)
      strcpy(iptr->Grade,"B-");
    else if(iptr->Percentage>=65 && iptr->Percentage<70)
      strcpy(iptr->Grade,"C+");
    else if(iptr->Percentage>=60 && iptr->Percentage<65)
      strcpy(iptr->Grade,"C");
    else if(iptr->Percentage>=55 && iptr->Percentage<60)
      strcpy(iptr->Grade,"C-");
    else
      strcpy(iptr->Grade,"F");
  fprintf(fp1,"%s\n%d\n%f\n%f\n%s\n",iptr->Name,iptr->roll_no,iptr->Total,iptr->Percentage,iptr->Grade);
    for(i=0;i<6;i++)
  fprintf(fp1,"%d\t",iptr->u.Subject_marks_0[i]);
  fclose(fp1);
    //FILE_2();
    iptr++;
    }
  }

/*void FILE_2()
  {
      FILE *fp1=fopen("/Users/mac/documents/Ledger.txt","a");
        fprintf(fp1,"%s\n%d\n%f\n%f\n",iptr->Name,iptr->roll_no,iptr->Total,iptr->Percentage);
      for(i=0;i<6;i++)
        fprintf(fp1,"%d\t",iptr->u.Subject_marks_0[i]);
      fclose(fp1);
  }*/
