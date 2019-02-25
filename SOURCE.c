#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>

struct file{
  char Name[10];
  int roll_no;
  struct subject_marks{
    int Subject_marks[6];
  } g;
}d[35],*ptr;

struct SUBJECT{
  char a[10][6];
}g,*gptr;

void door_1();//   1*****

struct SUBJECT SUBJECT_NAME(struct SUBJECT h);//    2*****

void FILE_1();//         3******

int main()
{
  gptr=&g;
  SUBJECT_NAME(g);//correction

  ptr=d;//pointer defintion for main structure
  door_1();//function call (2)
  return 0;
}
struct SUBJECT SUBJECT_NAME(struct SUBJECT h)
{
  int i;
  for(i=1;i<7;i++)
  {
    printf("#######ENTER SUBJECT %d NAME\n",i);
    scanf("%s",gptr->a[i]);
  }
  return h;
}

void door_1()//    1******
{
  int i,j;
  for(i=0;i<3;i++)
  {
  printf("********Enter the students name*********\n");
    scanf(" %[^\n]s",ptr->Name);//a sapce before % fixes the issue of it skipping user input
  printf("********Enter %s roll no*******\n",ptr->Name);
    scanf("%d",&ptr->roll_no);
  srand(time(NULL));//difference in random genaration
  for(j=1;j<7;j++)
    {
      printf("********Entering %s's Subject_marks For %s *********\n",ptr->Name,gptr->a[j]);//open in a loop
      ptr->g.Subject_marks[j]=rand()%100;//random genration of numbers
    }
    FILE_1();//function call ******  3
  ptr++;
  }
  //FILE();//function call ******  3
}

void FILE_1()     //  3***********
{
  FILE *fp=fopen("/Users/mac/documents/Project_10.txt","a");
  int j;char j;
  fprintf(fp,"%s\n%d\n",ptr->Name,ptr,ptr->roll_no);
  for(j=0;j<6;j++)
  fprintf(fp,"%d\n",ptr->g.Subject_marks[j]);
  fclose(fp);

}
