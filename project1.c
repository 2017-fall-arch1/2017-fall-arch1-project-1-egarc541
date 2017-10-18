
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PAGE_SIZE 1024
#define MAX_NAME_LEN 255

void addName(FILE *file);
void removeName();
void readName(FILE *file);

/**********************Binary Search Tree***********************/
struct node{
  char *value;
  struct node *left, *right;
}node;

struct node *create(char *item){
  struct node *temp= (struct node *)malloc(sizeof(struct node));
  temp->value = (char *) malloc(strlen(item) +1);
  strcpy(temp->value, item);
  temp->left = temp-> right = NULL;
  return temp;
}

void inorder(struct node *root){
  if(root!= NULL){
    inorder(root->left);
    printf("%s \n",root->value);
    inorder(root->right);
  }
}


struct node *insert(struct node * node, char * name){
  int count;
  if(node== NULL)
    return create(name);
  if(count= strcmp(node->value,name)>0)
    node->left = insert(node->left,name);
  else if(count =strcmp(node->value,name)<0)
    node->right = insert(node->right, name);
  return node;
}



int main(int argc, char *argv[]){
  FILE *file;
  int cmd =0;
  struct node *root= NULL;
  char name[255];

  /*********************** USER INTERFACE **********************/
  while(1){
    printf("\n Welcome to ACME Solutions\n");
    printf("1- Add a new employee Name\n");
    printf("2- Remove employee from list\n");
    printf("3- Read List of Employee\n");
    printf("4- Insert and Print Employees names into BST\n");
    printf("5- Exit Interface\n");
    printf("What command would you like to complete?\n");
    scanf("%d",&cmd);
    switch(cmd){
    case 0:
    case 1:
      addName(file);
      break;
    case 2:
      removeName();
      break;
    case 3:
      readName(file);
      break;
    case 4:
      if((file= fopen("file.txt","r"))== NULL){
	printf("Unable to open file");
      }
      else{
	while(!feof(file)){
	  fgets(name,255,file);
	  root= insert(root,name);
	}
	inorder(root);
	fclose(file);
      }
      printf("BST with Names/n");
      break;

    case 5:
      printf("\nYou have exit the interface\n");
      printf("\nAdios\n");
      exit(0);
      break;

    default:
      printf("Invalid Number!!!! Please Try Again\n");
      break;

    }
  }

  if(file== NULL){
    printf("ERROR!!!");
    exit(1);
  }
  return 0;
}

void addName(FILE *testFile){
  char name[255];
  testFile= fopen("file.txt","w+");
  printf("Add Name to file:\n");
  
  //scanf("%s\n", name);
  //puts(name,testFile);
  //puts("\n",testFile);
   fputs("Kiara\n",testFile);
  fputs("Tania\n", testFile);
  fputs("Garcia\n",testFile);
  fputs("Eulalio\n", testFile);
  printf("\nNew Names Added!!\n");
  fclose(testFile);
  
}


void removeName(){
  FILE *test1, *test2;
  int line_del, tmp=1;
  char filename[40] ="file.txt";
  char name;
  test1 = fopen("file.txt","r");
  name= getc(test1);
   while(name != EOF){
   printf("%c",name);
   name= getc(test1);
   }
  
  rewind(test1);
  printf("Please enter the line of the name to be deleted:\n");
  scanf("%d", line_del);
  test2= fopen("file2.txt","w");
  name= getc(test1);
  while(name !=EOF){
    name= getc(test1);
    if(name=='\n');
    tmp++;
    if(tmp!=line_del){
      putc(name,test2);
    }
  }
  
  fclose(test1);
  fclose(test2);
  remove(filename);
  rename("file2.txt",filename);
  
}


void readName(FILE *testFile){
  testFile = fopen("file.txt","r");
  printf("Names on list:\n");

  /*************** FEOF is End-of-File for an external file*****/
  while(!feof(testFile)){
    char name[255];
    fgets(name, 255, testFile);
    printf("%s/",name);
  }
  fclose(testFile);
}
