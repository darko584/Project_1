#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

struct file_0{
  char Name[10];
  int roll_no;
  struct subject_marks{
    float Subject_marks[6];
  } g;
}d[3],*ptr;

struct SUBJECT{
  char a[10][6];
}g,*gptr;

struct file_1{
  char Name[10],Grade[5];
  int roll_no;
  float Total,Percentage;
  struct subject_marks_1{
    float Subject_marks_0[6];
  }u;
}i_1[3],*iptr,temp;

int i,j,k;

void red()
{
  printf("\033[1;31m");
}
void magenta()
{
  printf("\033[1;35m");
}
void green()
{
  printf("\033[1;32m");
}
void blue()
{
  printf("\033[0;34m");
}
char *Tolower(char str[100])
{
  char c;
  while(1)
  {
    c=str[i];
    putchar(tolower(c));
    i++;
  }
  return str;
}

void door_1();//

struct SUBJECT SUBJECT_NAME(struct SUBJECT h);//

void processResult();//

void Search_Method();//

void Search_by_Name();

void Search_by_Roll();

void Search_by_T();

void Ascending_Name();

void Descending_Total_marks();

void Descending_Roll_no();

void Highest_marks_sorting();

int main()//*********************************main()******************************
{
  int o;
  iptr=i_1;
  gptr=&g;
  SUBJECT_NAME(g);//correction

  ptr=d;//pointer defintion for main structure
  door_1();//function call (2)
  processResult();
  Search_Method();
  scanf("%d",&o);
  switch(o)
  {
    case 1:
    Search_by_Name();
    break;
    case 2:
    Search_by_Roll();
    break;
    case 3:
    Search_by_T();
    break;
    case 4:
    Ascending_Name();
    break;
    case 5:
    Descending_Total_marks();
    break;
    case 6:
    Descending_Roll_no();
    break;
    case 7:
    Highest_marks_sorting();
    break;
    default:
    red();
    printf("\n--------------------------!!-ERROR-!!-------------------------------\n");
    break;
  }
  return 0;
}
struct SUBJECT SUBJECT_NAME(struct SUBJECT h)
{
  for(i=1;i<7;i++)
  {
    green();
    printf("###################################----------ENTER SUBJECT %d NAME\n",i);
    scanf("%s",gptr->a[i]);
  }
  return h;
}

void Search_Method()
{
  red();
  printf("________________Type 1 for search by 'Name'\n________________Type 2 for search by 'Roll number'\n\
________________Type 3 for search by 'Highest Total Marks'\n________________Type 4 for search by 'Ascending \
order by name'\n________________Type 5 for search by'Descending order by Total marks'\n\
________________Type 6 for search by 'Descending Roll no'\n=====>");
}

void door_1()
{
  FILE *fp=fopen("/Users/mac/documents/Project_10.txt","w");
  for(i=0;i<3;i++)
  {
  printf("\n***************************Enter the students name*********\n");
    scanf(" %[^\n]s",ptr->Name);//a sapce before % fixes the issue of it skipping user input
  printf("****************************Enter %s's roll no*******\n",ptr->Name);
    scanf("%d",&ptr->roll_no);
  srand(time(NULL));//difference in random genaration
  for(j=1;j<7;j++)
    {
  printf("*****************************Entering %s's Subject_marks For %s *********\n\n",ptr->Name,gptr->a[j]);//open in a loop
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
  FILE *fp0;
  i=0;
  fp0=fopen("/Users/mac/documents/Project_10.txt","r");
  for(i=0;i<3;i++)
    {
     fscanf(fp0,"%s %d  %f %f %f %f %f %f",i_1[i].Name,&i_1[i].roll_no,&i_1[i].u.Subject_marks_0[0],&i_1[i].u.Subject_marks_0[1]\
      ,&i_1[i].u.Subject_marks_0[2],&i_1[i].u.Subject_marks_0[3],&i_1[i].u.Subject_marks_0[4],\
      &i_1[i].u.Subject_marks_0[5]);
    }
  fclose(fp0);
  FILE *fp1;
  fp1=fopen("/Users/mac/documents/Ledger.txt","w");
  for(i=0;i<3;i++)
    {
    i_1[i].Total=0;
    for(j=0;j<6;j++)
        iptr->Total+=iptr->u.Subject_marks_0[j];
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
  fprintf(fp1,"\n%s\t%d\t%f\t%f\t%s\n ",iptr->Name,iptr->roll_no,iptr->Total,iptr->Percentage,iptr->Grade);
    //for(i=0;i<6;i++)
  fprintf(fp1,"%f %f %f %f %f %f",iptr->u.Subject_marks_0[0],iptr->u.Subject_marks_0[1]\
  ,iptr->u.Subject_marks_0[2],iptr->u.Subject_marks_0[3],iptr->u.Subject_marks_0[4],\
  iptr->u.Subject_marks_0[5]);
    //FILE_2();
iptr++;
    }
    fclose(fp1);
}

void Search_by_Name()
{
  char s[10];
  magenta();
  printf("\n######################################-Username-################################\n======>");
  scanf(" %[^\n]s",s);
  for(i=0;i<3;i++)
      {
        if(strcmp(s,i_1[i].Name)==0)
        {
        magenta();
        printf("|Name:%s  |Roll no:%d\n",i_1[i].Name,i_1[i].roll_no);
        for(j=0;j<6;j++)
          printf("|%s = %f\t",g.a[j+1],i_1[i].u.Subject_marks_0[j]);
          printf("|Total = %f\t|Percentage = %f",i_1[i].Total,i_1[i].Percentage);
        printf("\n|Grade : %s",i_1[i].Grade);
        }
        else
        {
          red();
          printf("--------------------------!!-ERROR-!!-------------------------------\n");
        }
      }
}

void Search_by_Roll()
{
  int y;
  printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^User's Roll-no^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n====>");
  scanf("%d",&y);
  for(i=0;i<3;i++)
    {
      if(y==i_1[i].roll_no){
        green();
        printf("|Name:%s  |Roll no:%d\n",i_1[i].Name,i_1[i].roll_no);
        for(j=0;j<6;j++)
          printf("|%s = %f\t",g.a[j],i_1[i].u.Subject_marks_0[j]);
        printf("|Total = %f\t|Percentage = %f",i_1[i].Total,i_1[i].Percentage);
        printf("\n|Grade : %s\n",i_1[i].Grade);
        }
      else
      {
        red();
        printf("--------------------------!!-ERROR-!!-------------------------------\n");
      }
    }

}

void Search_by_T()
{
  int y;
  green();
  printf("****************************************Users Total marks********\n===>");
  scanf("%d",&y);
  for(i=0;i<3;i++)
    {
      if(y==i_1[i].Total){
       blue();
        printf("|Name:%s  |Roll no:%d\n",i_1[i].Name,i_1[i].roll_no);
        for(j=0;j<6;j++)
          printf("|%s = %f\t",g.a[j],i_1[i].u.Subject_marks_0[j]);
        printf("|Total = %f\t|Percentage = %f",i_1[i].Total,i_1[i].Percentage);
        printf("\n|Grade : %s\n",i_1[i].Grade);
        }
      else
      {
        red();
        printf("--------------------------!!-ERROR-!!-------------------------------\n");
      }
    }
}

void Ascending_Name()
{
  for(i=0;i<3;i++)
  {
    for(j=1+i;j<3;j++)
    {
      if(strcmp(i_1[i].Name,i_1[j].Name)>0)//Ascending order in terms of name
      {
        temp=i_1[i];
        i_1[i]=i_1[j];
        i_1[j]=temp;
      }

    }

  }
  for(i=0;i<3;i++)
    {
       blue();
       printf("|Name:%s  |Roll no:%d\n",i_1[i].Name,i_1[i].roll_no);
       for(j=0;j<6;j++)
          printf("|%s = %f\t",g.a[j],i_1[i].u.Subject_marks_0[j]);
       printf("|Total = %f\t|Percentage = %f",i_1[i].Total,i_1[i].Percentage);
       printf("\n|Grade : %s\n",i_1[i].Grade);
    }
}

void Descending_Total_marks()
{
  for(i=0;i<3;i++)
  {
    for(j=1+i;j<3;j++)
    {
      if(i_1[i].Total<i_1[j].Total)
      {
        temp=i_1[i];
        i_1[i]=i_1[j];
        i_1[j]=temp;
      }
    }

  }
  for(i=0;i<3;i++)
    {
      magenta();
      printf("|Name:%s  |Roll no:%d\n",i_1[i].Name,i_1[i].roll_no);
      for(j=0;j<6;j++)
         printf("|%s = %f\t",g.a[j],i_1[i].u.Subject_marks_0[j]);
      printf("|Total = %f\t|Percentage = %f",i_1[i].Total,i_1[i].Percentage);
      printf("\n|Grade : %s\n",i_1[i].Grade);
    }

}

void Descending_Roll_no()
{
  for(i=0;i<3;i++)
  {
    for(j=1+i;j<3;j++)
    {
      if(i_1[i].roll_no<i_1[j].roll_no)
      {
        temp=i_1[i];
        i_1[i]=i_1[j];
        i_1[j]=temp;
      }

    }

  }
  for(i=0;i<3;i++)
  {
    blue();
    printf("|Name:%s  |Roll no:%d\n",i_1[i].Name,i_1[i].roll_no);
    for(j=0;j<6;j++)
       printf("|%s = %f\t",g.a[j],i_1[i].u.Subject_marks_0[j]);
    printf("|Total = %f\t|Percentage = %f",i_1[i].Total,i_1[i].Percentage);
    printf("\n|Grade : %s\n",i_1[i].Grade);
  }

}

void Highest_marks_sorting()
{
  char t[10];
  green();
  printf("-------------------Choose a subject for structure sorting---------------------\n====>");
  scanf(" %[^\n]s",t);
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
          if(strcmp(t,i_1[i].u.Subject_marks_0[j])==0)
          {
            for(k=1+i;k<3;k++)
            {
              if(i_1[i].u.Subject_marks_0[j]<i_1[k].u.Subject_marks_0[j])
                {
                  temp=i_1[i];
                  i_1[i]=i_1[k];
                  i_1[k]=temp;
                }
            }
          }

        }

    }
   for(i=0;i<3;i++)
   {
     red();
     printf("|Name:%s  |Roll no:%d\n",i_1[i].Name,i_1[i].roll_no);
     for(j=0;j<6;j++)
        printf("|%s = %f\t",g.a[j],i_1[i].u.Subject_marks_0[j]);
     printf("|Total = %f\t|Percentage = %f",i_1[i].Total,i_1[i].Percentage);
     printf("\n|Grade : %s\n",i_1[i].Grade);
   }


}
