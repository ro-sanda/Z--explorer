///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "aux.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void read(double *matrix,int number,int rows,int columns,int option){   
  
  
  
  
  int TAM_C=columns;
  int TAM_F=rows;
  
  
  FILE *archive;   // creation of the archive

  char name[22];
  char ext[12]=".dat";
  char path[22];



//The option determines the path inside de directory

  if(option==1){
  strncpy(path, "./cards/sim_card_", 22);
  }
  if(option==2){
  strncpy(path, "./cards/exp_card_", 22);    
  }
  if(option==3){
  strncpy(path, "./cards/rows_card_", 22);    
  }
  if(option==4){
  strncpy(path, "./incard/card_", 22);    
  }

//Print number inside name
  sprintf(name,"%d",number);



//Concatenate strings  
  strcat(name,ext); //Example: name=1.dat

  strcat(path,name); //Example: path=./cards/sim_card_1.dat

// At this stage we have defined the variable path as required by the the function call
  

  printf("%s\n",path); //It prints the path (optional)
  archive= fopen(path,"r"); // Open the required file in read access mode into the variable archive
  
  int f=0; 
  int c=0;
  int i=0;
  
  for(f=0 ; f<TAM_F ; f++){ //go through all the rows of matrix
    for(c=0 ; c<TAM_C ; c++){ //go through all the columns of matrix 
      i=fscanf(archive,"%lf",&matrix[TAM_C*f + c]); //Save a data from archive in the matrix       
     
    }
  }
  
  
  fclose(archive); //close archive
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void save(double *matrix,int num,int option,int rows,int columns){    


  int TAM_C=columns;
  int TAM_F=rows;
    
  FILE *archive;   // creation of the archive
  char name[12];
  char ext[12]=".dat";
  char path[22];

//The option determines the path inside de directory


  if(option==1){
  strncpy(path, "./output/", 22);
  }
  if(option==2){
  strncpy(path, "./extra/", 22);
  }
  if(option==3){
  strncpy(path, "./", 22);
  }


//Print number inside name  
  sprintf(name,"%d",num);

//Get name length
  int largo = strlen(name) ;


//Concatenate strings  
  strcat(name,ext);
  strcat(path,name);
  //printf("\n  el tam del string es =%i \n",largo);


//Create an empty file and open it for update 
  archive= fopen(path,"w+"); 
  int f=0; 
  int c=0;

  
  for(f=0 ; f<TAM_F ; f++){ //go through all the rows of matrix
    for(c=0 ; c<TAM_C ; c++){ //go through all the columns of matrix
      fprintf(archive,"%.15f	",matrix[TAM_C*f + c]); //Save a data from matrix to archive
    }
      fprintf(archive,"\n"); //space after each row
  }
  
  
  fclose(archive); //close archive
}
// The format to save data is [ row_i -empty space- row_i+1 -empty space- row_i+2 ..... ]   

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void savex(double *matrix,char headers[11][22], int num,int option,int rows,int columns){    
     

  int TAM_C=columns;
  int TAM_F=rows;
    
  FILE *archive;   // creation of the archive
  char name[12];
  char ext[12]=".dat";
  char path[22];

//The option determines the path inside de directory


  if(option==1){
  strncpy(path, "./output/", 22);
  }
  if(option==2){
  strncpy(path, "./extra/", 22);
  }
  if(option==3){
  strncpy(path, "./", 22);
  }


//Print number inside name  
  sprintf(name,"%d",num);

//Get name length
  int largo = strlen(name) ;


//Concatenate strings  
  strcat(name,ext);
  strcat(path,name);
  //printf("\n  el tam del string es =%i \n",largo);


//Create an empty file and open it for update 
  archive= fopen(path,"w+"); 
  int f=0; 
  int c=0;


for(c=0 ; c<TAM_C ; c++){ //go through all the columns of headers
      fprintf(archive,"%.20s	",headers[c] ); //Save a data from headers to archive
    }
      fprintf(archive,"\n"); //space after headers



  
  for(f=0 ; f<TAM_F ; f++){ //go through all the rows of matrix
    for(c=0 ; c<TAM_C ; c++){ //go through all the columns of matrix
      fprintf(archive,"%.12f	",matrix[TAM_C*f + c]); //Save a data from matrix to archive
    }
      fprintf(archive,"\n"); //space after each row
  }
  
  
  fclose(archive); //close archive
}
// The format to save data is [ row_i -empty space- row_i+1 -empty space- row_i+2 ..... ]   

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void saveo(double *matrix,char headers[11][22], int num,int option,int rows,int columns){    
     

  int TAM_C=columns;
  int TAM_F=rows;
    
  FILE *archive;   // creation of the archive
  char name[12];
  char ext[12]=".dat";
  char path[22];

//The option determines the path inside de directory


  if(option==1){
  strncpy(path, "./output/", 22);
  }
  if(option==2){
  strncpy(path, "./extra/", 22);
  }
  if(option==3){
  strncpy(path, "./", 22);
  }


//Print number inside name  
  sprintf(name,"%d",num);

//Get name length
  int largo = strlen(name) ;


//Concatenate strings  
  strcat(name,ext);
  strcat(path,name);
  //printf("\n  el tam del string es =%i \n",largo);


//Create an empty file and open it for update 
  archive= fopen(path,"w+"); 
  int f=0; 
  int c=0;


for(c=0 ; c<TAM_C ; c++){ //go through all the columns of headers
      fprintf(archive,"%.20s	",headers[c] ); //Save a data from headers to archive
    }
      fprintf(archive,"\n"); //space after headers



  
  for(f=0 ; f<TAM_F ; f++){ //go through all the rows of matrix
    for(c=0 ; c<TAM_C ; c++){ //go through all the columns of matrix
      fprintf(archive,"%.12f	",matrix[TAM_C*f + c]); //Save a data from matrix to archive
    }
      fprintf(archive,"\n"); //space after each row
  }
  
  
  fclose(archive); //close archive
}
// The format to save data is [ row_i -empty space- row_i+1 -empty space- row_i+2 ..... ]   


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int indexofSmallestElement(double array[], int size)
{
    int index = 0;

    for(int i = 1; i < size; i++)
    {
        if(array[i] < array[index])
            index = i;              
    }

    return index;
}

