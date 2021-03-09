///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

#include "program.h"  //includes libraries
#include "aux.h"      //includes auxiliary functions

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  


int main(){
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    

//Creation of the "output" and "extra" directories. About their rights: user (file owner) and group have read, write and execute permission, and others have read and execute permission.

  mkdir("./output", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  mkdir("./extra", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  
 



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Create ./cards/rows_card_1.dat file

system("cd cards/ ;bash rows_card_maker.bash; cd ..");

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
  

//Set rows as an array (vector) with the data from ./cards/rows_card_1.dat. (rows_card_1.dat has 11 rows and 2 columns. For first 10 rows -> 1st column: #rows for each simulation card -> 2nd column: #rows for each experimental card; 11th row: -> 1st column: #rows incard-> 2nd column: #columns incard )

printf("\n\nExtracting number of rows in cards...\n");
  double *rows;
  rows=(double *) malloc(sizeof(double)*11*2);
  read(rows,1,11,2,3);



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//All the simulation and experimental cards have 2 columns

  int col=2;

//Allocation of memory blocks for simulation cards according their numbers of rows and columns
   
  int row_s_1=rows[2*0 + 0];
  double *sim_1;
  sim_1=(double *) malloc(sizeof(double)*row_s_1*col);
  
  int row_s_2=rows[2*1 + 0];
  double *sim_2;
  sim_2=(double *) malloc(sizeof(double)*row_s_2*col);
  
  int row_s_3=rows[2*2 + 0];
  double *sim_3;
  sim_3=(double *) malloc(sizeof(double)*row_s_3*col);
  
  int row_s_4=rows[2*3 + 0];
  double *sim_4;
  sim_4=(double *) malloc(sizeof(double)*row_s_4*col);
  
  int row_s_5=rows[2*4 + 0];
  double *sim_5;
  sim_5=(double *) malloc(sizeof(double)*row_s_5*col);


//Allocation of memory blocks for experimental cards according their numbers of rows and columns
  
  int row_e_1=rows[2*0 + 1];
  double *exp_1;
  exp_1=(double *) malloc(sizeof(double)*row_e_1*col);
  
  int row_e_2=rows[2*1 + 1];
  double *exp_2;
  exp_2=(double *) malloc(sizeof(double)*row_e_2*col);
  
  int row_e_3=rows[2*2 + 1];
  double *exp_3;
  exp_3=(double *) malloc(sizeof(double)*row_e_3*col);
  
  int row_e_4=rows[2*3 + 1];
  double *exp_4;
  exp_4=(double *) malloc(sizeof(double)*row_e_4*col);
  
  int row_e_5=rows[2*4 + 1];
  double *exp_5;
  exp_5=(double *) malloc(sizeof(double)*row_e_5*col);

  int row_e_6=rows[2*5 + 1];
  double *exp_6;
  exp_6=(double *) malloc(sizeof(double)*row_e_6*col);
  
  int row_e_7=rows[2*6 + 1];
  double *exp_7;
  exp_7=(double *) malloc(sizeof(double)*row_e_7*col);

  int row_e_8=rows[2*7 + 1];
  double *exp_8;
  exp_8=(double *) malloc(sizeof(double)*row_e_8*col);

  int row_e_9=rows[2*8 + 1];
  double *exp_9;
  exp_9=(double *) malloc(sizeof(double)*row_e_9*col);

  int row_e_10=rows[2*9 + 1];
  double *exp_10;
  exp_10=(double *) malloc(sizeof(double)*row_e_10*col);


//Extract number of rows and columns in incard

  int in_row = rows[2*10 + 0];
  int in_col = rows[2*10 + 1];


//The #columns of incard must be 23. 

   if (in_col != 23) {
    printf("\nError: the number of columns of the input card must be 23\n\n");
    return 1;
  }


printf("\nThe incard has %d rows and %d columns\n\n", in_row, in_col);

//Allocation of memory blocks for in_card according their numbers of rows and columns
  
  double *in_card;
  in_card=(double *) malloc(sizeof(double)*in_row*in_col);
  
  double *widths;
  widths=(double *) malloc(sizeof(double)*in_row*13);

  double *totalwidth;
  totalwidth=(double *) malloc(sizeof(double)*in_row*1); 

  double *mass;
  mass=(double *) malloc(sizeof(double)*in_row*1); //There are in_row masses in total

  double *BR;
  BR=(double *) malloc(sizeof(double)*in_row*10);

  double *xsBRsim;
  xsBRsim=(double *) malloc(sizeof(double)*in_row*11);

  double *xsBRexp;
  xsBRexp=(double *) malloc(sizeof(double)*in_row*11);

  double *strength;
  strength=(double *) malloc(sizeof(double)*in_row*35);

//  char *headers;
//  headers=(char *) malloc(sizeof(char)*31);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
 
//Take data from the simulation cards and put it in the corresponding variable

printf("\n\nReading simulation cards...\n");

  read(sim_1,1,row_s_1,2,1);
  read(sim_2,2,row_s_2,2,1);
  read(sim_3,3,row_s_3,2,1);
  read(sim_4,4,row_s_4,2,1);
  read(sim_5,5,row_s_5,2,1);

//printf("\nComplete!\n");

//Take data from the experimental cards and put it in the corresponding variable

printf("\n\nReading experimental cards...\n");

  read(exp_1,1,row_e_1,2,2);
  read(exp_2,2,row_e_2,2,2);
  read(exp_3,3,row_e_3,2,2);
  read(exp_4,4,row_e_4,2,2);
  read(exp_5,5,row_e_5,2,2);
  read(exp_6,6,row_e_6,2,2);
  read(exp_7,7,row_e_7,2,2);
  read(exp_8,8,row_e_8,2,2);
  read(exp_9,9,row_e_9,2,2);
  read(exp_10,10,row_e_10,2,2);

//printf("\nComplete!\n");

//Take data from incard and put it in the corresponding variable

  printf("\nReading incard...\n");
  read(in_card,1,in_row,in_col,4);



  
  int t=0;
  printf("\n\nCalculating decay widths to fermions and extracting decay widths to bosons...");
  for(t=0 ; t<in_row ; t++){

//Take mass for each row in incard (1st column of 23)
      mass[t]=in_card[23*t+0];




//Calculate widths for each final state


      widths[13*t + 0]=gamma_jj(in_card,t,1,in_col);//uu
      widths[13*t + 1]=gamma_jj(in_card,t,2,in_col);//dd
      widths[13*t + 2]=gamma_jj(in_card,t,3,in_col);//cc
      widths[13*t + 3]=gamma_jj(in_card,t,4,in_col);//ss
      widths[13*t + 4]=gamma_jj(in_card,t,5,in_col);//bb

      widths[13*t + 5]=gamma_tt(in_card,t,in_col);//tt

      widths[13*t + 6]=gamma_ll(in_card,t,1,in_col);//ee
      widths[13*t + 7]=gamma_ll(in_card,t,2,in_col);//mumu
      widths[13*t + 8]=gamma_ll(in_card,t,3,in_col);//tautau


//Take widths from in_card for the case of invisible, WW, HW, XX


      widths[13*t + 9]=in_card[23*t+19];//invisible
      widths[13*t + 10]=in_card[23*t+20];//WW
      widths[13*t + 11]=in_card[23*t+21];//ZH
      widths[13*t + 12]=in_card[23*t+22];//XX


//Calculate total width


     totalwidth[t]=widths[13*t + 0]+widths[13*t + 1]+widths[13*t + 2]+widths[13*t + 3]+widths[13*t + 4]+widths[13*t + 5]+widths[13*t + 6]+widths[13*t + 7]+widths[13*t + 8]+widths[13*t + 9]+widths[13*t + 10]+widths[13*t + 11]+widths[13*t + 12];


  }

//Total: 13 decay widths. Save them in ./extra/2.dat


char  headersw[13][22] = { "    Γuu     ", "   Γdd   ", "    Γcc     ", "   Γss   ", "   Γbb   ", "   Γtt   ", "   Γee   ", "   Γμμ   ", "   Γττ   ", "   Γinv   ", "   ΓWW   ", "   ΓZH   ", "   ΓXX   "
                    };

  
savew(widths,headersw,2,2,in_row,13);




//Calculation of 10 BR.

int t2=0;
  printf("\nCalculating branching ratios...");
  for(t2=0 ; t2<in_row ; t2++){
      BR[10*t2 + 0]=BR_jj(widths,t2,13);//uu+dd+cc+ss (jj)
      BR[10*t2 + 1]=BR_bb(widths,t2,13);//bb 	
      BR[10*t2 + 2]=BR_tt(widths,t2,13);//tt
      BR[10*t2 + 3]=BR_ee(widths,t2,13);//ee 
      BR[10*t2 + 4]=BR_mumu(widths,t2,13);//mumu 
      BR[10*t2 + 5]=BR_tautau(widths,t2,13);//tautau 
      BR[10*t2 + 6]=BR_inv(widths,t2,13);//invisible
      BR[10*t2 + 7]=BR_ww(widths,t2,13);//WW
      BR[10*t2 + 8]=BR_zh(widths,t2,13);//ZH
      BR[10*t2 + 9]=BR_xx(widths,t2,13);//XX   
  }


//Total: 10 branching ratios. Save them in ./extra/3.dat  
  
char  headersbr[10][22] = {  "   BRjj   ", "   BRbb   ", "   BRtt   ", "   BRee   ", "   BRμμ   ", "   BRττ   ", "   BRinv   ", "   BRWW   ", "   BRZH   ", "   BRXX   "
                    };



savebr(BR,headersbr,3,2,in_row,10);
  



//For each mass in the in_card (in_row in total), find the index of the closest mass within the simulation cards (rows_s_1 in total, that is the number of rows in sim_card_1.dat, but they have all the same number of lines)


double resta[row_s_1], k[in_row];

int q=0;
int p=0;

for(q=0 ; q<in_row ; q++){
  for(p=0 ; p<row_s_1 ; p++){
	resta[p]= fabs( mass[q] - sim_1[2*p] );
	}
	k[q]=indexofSmallestElement(resta,row_s_1);
}




//Save the index for each más in ./extra/6.dat
//save(k,6,2,in_row,1);




//save(resta,7,2,row_s_1,1); // Save in ./extra/7.dat


//Calculation of the total cross section at fixed mass as sum of all simulated cross sections (at closest mass) for each parton in the proton that couples to Z' (u, d, c, s, b) adjusted by the sum of the squared couplings in the incard



double sigmasim[in_row];

int t3=0;
  for(t3=0 ; t3<in_row ; t3++){
      sigmasim[t3]=sigmatot(in_card,t3,in_col,sim_1,k[t3],2,sim_2,k[t3],2,sim_3,k[t3],2,sim_4,k[t3],2,sim_5,k[t3],2);
     
 
  }

//save(sigmasim,8,2,in_row,1); //Save in ./extra/8.dat


//Product between total simulated cross-section and branching ratios

int r=0;
  printf("\nCalculating cross-section to each channel...");
  for(r=0 ; r<in_row ; r++){
      xsBRsim[11*r + 0]=mass[r];
      xsBRsim[11*r + 1]=sigmasim[r]*BR[10*r+0];//uu+dd+cc+ss (jj)
      xsBRsim[11*r + 2]=sigmasim[r]*BR[10*r+1];//bb
      xsBRsim[11*r + 3]=sigmasim[r]*BR[10*r+2];//tt
      xsBRsim[11*r + 4]=sigmasim[r]*BR[10*r+3];//ee
      xsBRsim[11*r + 5]=sigmasim[r]*BR[10*r+4];//mumu
      xsBRsim[11*r + 6]=sigmasim[r]*BR[10*r+5];//tautau
      xsBRsim[11*r + 7]=sigmasim[r]*BR[10*r+6];//inv
      xsBRsim[11*r + 8]=sigmasim[r]*BR[10*r+7];//WW
      xsBRsim[11*r + 9]=sigmasim[r]*BR[10*r+8];//ZH
      xsBRsim[11*r + 10]=sigmasim[r]*BR[10*r+9];//XX
    
 
  }
  

char  headerssigpred[11][22] = { "     M     ", "   σpred_jj   ", "   σpred_bb   ", "   σpred_tt   ", "   σpred_ee   ", "   σpred_μμ   ", "   σpred_ττ   ", "   σpred_inv   ", "   σpred_WW   ", "   σpred_ZH   ", "   σpred_XX   "
                    };


savex(xsBRsim,headerssigpred,4,2,in_row,11); // Save in ./extra/4.dat


double restae1[row_e_1], ke1[in_row], restae2[row_e_2], ke2[in_row], restae3[row_e_3], ke3[in_row], restae4[row_e_4], ke4[in_row], restae5[row_e_5], ke5[in_row], restae6[row_e_6], ke6[in_row], restae7[row_e_7], ke7[in_row], restae8[row_e_8], ke8[in_row], restae9[row_e_9], ke9[in_row], restae10[row_e_10], ke10[in_row];
int q1=0;
int p1=0;
int p2=0;
int p3=0;
int p4=0;
int p5=0;
int p6=0;
int p7=0;
int p8=0;
int p9=0;
int p10=0;

//For each mass in the in_card (in_row in total), find the index of the closest mass within each on of the experimental cards. 


for(q1=0 ; q1<in_row ; q1++){

  for(p1=0 ; p1<row_e_1 ; p1++){
	restae1[p1]= fabs( mass[q1] - exp_1[2*p1+0]); //uu+dd+cc+ss (jj)
	}
	ke1[q1]=indexofSmallestElement(restae1,row_e_1);

  for(p2=0 ; p2<row_e_2 ; p2++){
	restae2[p2]= fabs( mass[q1] - exp_2[2*p2+0] ); //bb
	}
	ke2[q1]=indexofSmallestElement(restae2,row_e_2);

  for(p3=0 ; p3<row_e_3 ; p3++){
	restae3[p3]= fabs( mass[q1] - exp_3[2*p3+0] ); //tt
	}
	ke3[q1]=indexofSmallestElement(restae3,row_e_3);

  for(p4=0 ; p4<row_e_4 ; p4++){
	restae4[p4]= fabs( mass[q1] - exp_4[2*p4+0] ); //ee
	}
	ke4[q1]=indexofSmallestElement(restae4,row_e_4);


  for(p5=0 ; p5<row_e_5 ; p5++){
	restae5[p5]= fabs( mass[q1] - exp_5[2*p5+0] ); //mumu
	}
	ke5[q1]=indexofSmallestElement(restae5,row_e_5);

  for(p6=0 ; p6<row_e_6 ; p6++){
	restae6[p6]= fabs( mass[q1] - exp_6[2*p6+0] ); //tautau
	}
	ke6[q1]=indexofSmallestElement(restae6,row_e_6);

  for(p7=0 ; p7<row_e_7 ; p7++){
	restae7[p7]= fabs( mass[q1] - exp_7[2*p7+0] ); //inv
	}
	ke7[q1]=indexofSmallestElement(restae7,row_e_7);

  for(p8=0 ; p8<row_e_8 ; p8++){
	restae8[p8]= fabs( mass[q1] - exp_8[2*p8+0] ); //WW
	}
	ke8[q1]=indexofSmallestElement(restae8,row_e_8);

  for(p9=0 ; p9<row_e_9 ; p9++){
	restae9[p9]= fabs( mass[q1] - exp_9[2*p9+0] ); //ZH
	}
	ke9[q1]=indexofSmallestElement(restae9,row_e_9);

  for(p10=0 ; p10<row_e_10 ; p10++){
	restae10[p10]= fabs( mass[q1] - exp_10[2*p10+0] ); //XX
	}
	ke10[q1]=indexofSmallestElement(restae10,row_e_10);



}


//save(ke1,6,2,in_row,1);




//Take for each mass in the incard the experimental limits in the cross-section for each channel (at closest mass).

double outlier=1e9;

int s=0;
  printf("\nExtracting cross-section limits from experimental cards...");
  for(s=0 ; s<in_row ; s++){
      xsBRexp[11*s + 0]=mass[s];

      if(int(ke1[s])==(row_e_1-1) || int(ke1[s])==0){
      xsBRexp[11*s + 1]=outlier;//uu+dd+cc+ss (jj)
      }else{
      xsBRexp[11*s + 1]=exp_1[2*(int) ke1[s]+1];//uu+dd+cc+ss (jj)
      }

      if(int(ke2[s])==(row_e_2-1) || int(ke2[s])==0){
      xsBRexp[11*s + 2]=outlier;//bb
      }else{
      xsBRexp[11*s + 2]=exp_2[2*(int) ke2[s]+1];//bb
      }

      if(int(ke3[s])==(row_e_3-1) || int(ke3[s])==0){
      xsBRexp[11*s + 3]=outlier;//tt
      }else{
      xsBRexp[11*s + 3]=exp_3[2*(int) ke3[s]+1];//tt
      }   

      if(int(ke4[s])==(row_e_4-1) || int(ke4[s])==0){
      xsBRexp[11*s + 4]=outlier;//ee
      }else{
      xsBRexp[11*s + 4]=exp_4[2*(int) ke4[s]+1];//ee
      }   


      if(int(ke5[s])==(row_e_5-1) || int(ke5[s])==0){
      xsBRexp[11*s + 5]=outlier;//mumu
      }else{
      xsBRexp[11*s + 5]=exp_5[2*(int) ke5[s]+1];//mumu
      }
      
      if(int(ke6[s])==(row_e_6-1) || int(ke6[s])==0){
      xsBRexp[11*s + 6]=outlier;//tautau
      }else{
      xsBRexp[11*s + 6]=exp_6[2*(int) ke6[s]+1];//tautau
      }

      if(int(ke7[s])==(row_e_7-1) || int(ke7[s])==0){
      xsBRexp[11*s + 7]=outlier;//inv
      }else{
      xsBRexp[11*s + 7]=exp_7[2*(int) ke7[s]+1];//inv
      }

      if(int(ke8[s])==(row_e_8-1) || int(ke8[s])==0){
      xsBRexp[11*s + 8]=outlier;//WW
      }else{
      xsBRexp[11*s + 8]=exp_8[2*(int) ke8[s]+1];//WW
      }

      if(int(ke9[s])==(row_e_9-1) || int(ke9[s])==0){
      xsBRexp[11*s + 9]=outlier;//ZH
      }else{
      xsBRexp[11*s + 9]=exp_9[2*(int) ke9[s]+1];//ZH
      }

      if(int(ke10[s])==(row_e_10-1) || int(ke10[s])==0){
      xsBRexp[11*s + 10]=outlier;//XX
      }else{
      xsBRexp[11*s + 10]=exp_10[2*(int) ke10[s]+1];//XX
      }      
     
  }




char  headerssiglim[11][22] = { "     M     ", "   σlim_jj   ", "   σlim_bb   ", "   σlim_tt   ", "   σlim_ee   ", "   σlim_μμ   ", "   σlim_ττ   ", "   σlim_inv   ", "   σlim_WW   ", "   σlim_ZH   ", "   σlim_XX   "
                    };

  
savex(xsBRexp,headerssiglim,5,2,in_row,11); //Save in ./extra/5.dat




//Calculation of the strength of each channel and mass.




char  headers[35][22] = {"    M     ", "   guuL   ", "   guuR   ", "   gddL   ", "   gddR   ", "   gccL   ", "   gccR   ", "   gssL   ", "   gssR   ", "   gbbL   ", "   gbbR   ", "   gttL   ", "   gttR   ", "   geeL   ", "   geeR   ", "   gμμL   ", "   gμμR   ", "   gττL   ", "   gττR   ",  "    Γinv     ",  "    ΓWW     ", "    ΓZH     ",  "    ΓXX     ", "   Sjj   ", "   Sbb   ", "   Stt   ", "   See   ", "   Sμμ   ", "   Sττ   ", "   Sinv   ", "   SWW   ", "   SZH   ", "   SXX   ", "   ΓZ'   ", "WARNING:ΓZ'>5%"
                    };



int u=0;
  printf("\nCalculating strength of each channel...\n\n");
  for(u=0 ; u<in_row ; u++){

      strength[35*u + 0]=mass[u];
      strength[35*u + 1]=in_card[23*u+1];
      strength[35*u + 2]=in_card[23*u+2];
      strength[35*u + 3]=in_card[23*u+3];
      strength[35*u + 4]=in_card[23*u+4];
      strength[35*u + 5]=in_card[23*u+5];
      strength[35*u + 6]=in_card[23*u+6];
      strength[35*u + 7]=in_card[23*u+7];
      strength[35*u + 8]=in_card[23*u+8];
      strength[35*u + 9]=in_card[23*u+9];
      strength[35*u + 10]=in_card[23*u+10];
      strength[35*u + 11]=in_card[23*u+11];
      strength[35*u + 12]=in_card[23*u+12];
      strength[35*u + 13]=in_card[23*u+13];
      strength[35*u + 14]=in_card[23*u+14];
      strength[35*u + 15]=in_card[23*u+15];
      strength[35*u + 16]=in_card[23*u+16];
      strength[35*u + 17]=in_card[23*u+17];
      strength[35*u + 18]=in_card[23*u+18];
      strength[35*u + 19]=in_card[23*u+19];
      strength[35*u + 20]=in_card[23*u+20];
      strength[35*u + 21]=in_card[23*u+21];
      strength[35*u + 22]=in_card[23*u+22];


      strength[35*u + 23]=xsBRsim[11*u+1]/xsBRexp[11*u+1];//uu+dd+cc+ss (jj)
      strength[35*u + 24]=xsBRsim[11*u+2]/xsBRexp[11*u+2];//bb
      strength[35*u + 25]=xsBRsim[11*u+3]/xsBRexp[11*u+3];//tt
      strength[35*u + 26]=xsBRsim[11*u+4]/xsBRexp[11*u+4];//ee
      strength[35*u + 27]=xsBRsim[11*u+5]/xsBRexp[11*u+5];//mumu
      strength[35*u + 28]=xsBRsim[11*u+6]/xsBRexp[11*u+6];//tautau
      strength[35*u + 29]=xsBRsim[11*u+7]/xsBRexp[11*u+7];//inv
      strength[35*u + 30]=xsBRsim[11*u+8]/xsBRexp[11*u+8];//WW
      strength[35*u + 31]=xsBRsim[11*u+9]/xsBRexp[11*u+9];//ZH
      strength[35*u + 32]=xsBRsim[11*u+10]/xsBRexp[11*u+10];//XX

      strength[35*u + 33]=totalwidth[u];//Total width
      

//Warning about narrow width approximation not satisfied

      if( (totalwidth[u]/mass[u])>0.05){
      strength[35*u + 34]=1;//Warning! Total width above 5%
printf("\nWarning, point with width above 5%, check corresponding column in /output/1.dat");
      }else{
      strength[35*u + 34]=0;//No warning. Total width bellow 5%
      }      
   

}

// Save all the masses (total:in_row) in the incard and the strength for each mass in each channel (total:10), with the total width and the narrow width approximation warning in ./output/1.dat
  printf("\n\nComplete!");


  saveo(strength,headers,1,1,in_row,35);




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

//free deallocates memory blocks previously allocated by the call to malloc, making them available again for further allocations.
  free(rows);
  free(sim_1);
  free(sim_2);     
  free(sim_3);     
  free(sim_4);     
  free(sim_5);
  free(exp_1);
  free(exp_2);
  free(exp_3);     
  free(exp_4);     
  free(exp_5);
  free(exp_6);     
  free(exp_7);
  free(exp_8);
  free(exp_9);
  free(exp_10);
  free(in_card);
  free(widths);
  free(BR);

  printf("\nOutput has been written to: ./output/1.dat \n\n");
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
