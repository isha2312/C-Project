// C project- SUDOKU GAME

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// declaring global array for storing t
int easy[9][9]={
    {0,2,0,4,5,6,7,8,9},
    {4,5,7,0,8,0,2,3,6},
    {6,8,9,2,3,7,0,4,0},
    {0,0,5,3,6,2,9,7,4},
    {2,7,4,0,9,0,6,5,3},
    {3,9,6,5,7,4,8,0,0},
    {0,4,0,6,1,8,3,9,7},
    {7,6,1,0,4,0,5,2,8},
    {9,3,8,7,2,5,0,6,0}
 };
 
int medium[9][9]={
    {1,4,2,0,9,0,0,0,5},
    {7,0,0,4,0,0,0,8,9},
    {8,0,5,0,0,0,0,2,4},
    {2,0,0,0,0,4,8,0,0},
    {0,3,0,0,0,1,2,6,0},
    {0,8,0,0,7,2,9,4,1},
    {0,5,0,2,0,6,0,0,0},
    {0,2,8,0,0,9,4,1,0},
    {0,7,9,1,0,8,5,3,0}
};


int hard[9][9]={
    {1,0,0,0,7,0,0,3,0},
    {8,3,0,6,0,0,0,0,0},
    {0,0,2,9,0,0,6,0,8},
    {6,0,0,0,0,4,9,0,7},
    {0,9,0,0,0,0,0,5,0},
    {3,0,7,5,0,0,0,0,4},
    {2,0,3,0,0,9,1,0,0},
    {0,0,0,0,0,2,0,4,3},
    {0,4,0,0,8,0,0,0,9}
};
 
 int arr[9][9];
 int fixed_index[9][9];
 
 
// for printing the sudoku 
void print()
{
    int i,j;
    printf("-------------------------------------\n");
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            printf("%d   ",arr[i][j]);
             
        
        }
        printf("\n");
        printf("-------------------------------------");
        printf("\n");
        
    }
}



// add a number to sudoku
void add()
{
    int row,column,number;
    printf("\nEnter the row and column where u want to add: ");
    scanf("%d %d",&row,&column);
    
    printf("\nEnter the number to be added: ");
    scanf("%d",&number);
    
    
    //before adding it checks that index is fixed or a gap to be filled
    if(fixed_index[row-1][column-1]==0)
    arr[row-1][column-1]=number;
    else
    printf("You can't change this number\n");  // if user tries changes the fixed indexes
}


// delete a number to sudoku
void delete()
{
    int row,column,number;
    printf("\nEnter the row and column where u want to delete: ");
    scanf("%d %d",&row,&column);
    
    if(fixed_index[row-1][column-1]==0)
    arr[row-1][column-1]=0;
    else
    printf("You can't change this number\n"); // if user tries changes the fixed indexes
}


// reset to original sudoku of the same level
void reset(char level)
{
 
  if(level=='E')
        {
            for (int i = 0; i < 9; i++)
                for (int j = 0; j < 9; j++)
                    arr[i][j] = easy[i][j];
        }
        else if(level=='M')
        {
           for (int i = 0; i < 9; i++)
                for (int j = 0; j < 9; j++)
                    arr[i][j] = medium[i][j];
        }
        else if(level=='H')
        {
            for (int i = 0; i < 9; i++)
                for (int j = 0; j < 9; j++)
                    arr[i][j] = hard[i][j];
        }
  
}

// to check the sudoku
bool validate()
{
  
  int flag=0;
  
  
  // validating row 
  for (int r = 0; r < 9; r++)
  {
      int sum=0;
      for (int c = 0; c< 9; c++) 
      {
          // if any empty field
         if(arr[r][c]==0)
         {
           printf("\nAll the empty fileds are to be filled before validation\n");
            return false;
         }
           
         else
           {
             sum+=arr[r][c]; // calculating sum of each row
           }
      }
      
       // if sum is not 45 so must be a repeating value somewhere
      if(sum!=45)
      {
          for(int i=0;i<9;i++)
            {
                for(int j=i+1;j<9;j++)
                {
                    if(arr[r][i]==arr[r][j])
                    {
                        printf("\nOops!! two numbers at %d and %d position in row %d are same! pls check.\n",i+1,j+1,r+1);
                        return false;
                    }
                }
            }
     }
     
      
  }
      
    //validating column
    
    for(int c=0;c<9;c++)
    { 
         
        int sum=0;
        for(int r=0;r<9;r++)
        {
            sum+=arr[r][c];
        }
        if(sum!=45)
        {
            for(int j=0;j<9;j++)
            {
                for(int i=j+1;i<9;i++)
                {
                    if(arr[i][c]==arr[j][c])
                    {
                        printf("\nOops!! two numbers at %d and %d position in column %d are same! pls check.\n",i+1,j+1,c+1);
                        return false; 
                    }
                }
            }
        }
    }
    
    //validating each(3*3)box
    
    // putting every (3*3)box values from arr in each row of box_arr 
    // i.e. putting numbers in every box to the rows of the box_arr 
    int box_arr[9][9];
    box_arr[0][0]=arr[0][0];box_arr[0][1]=arr[0][1];box_arr[0][2]=arr[0][2];box_arr[0][3]=arr[1][0];box_arr[0][4]=arr[1][1];box_arr[0][5]=arr[1][2];box_arr[0][6]=arr[2][0];box_arr[0][7]=arr[2][1];box_arr[0][8]=arr[2][2];
    box_arr[1][0]=arr[0][3];box_arr[1][1]=arr[0][4];box_arr[1][2]=arr[0][5];box_arr[1][3]=arr[1][3];box_arr[1][4]=arr[1][4];box_arr[1][5]=arr[1][5];box_arr[1][6]=arr[2][3];box_arr[1][7]=arr[2][4];box_arr[1][8]=arr[2][5];
    box_arr[2][0]=arr[0][6];box_arr[2][1]=arr[0][7];box_arr[2][2]=arr[0][8];box_arr[2][3]=arr[1][6];box_arr[2][4]=arr[1][7];box_arr[2][5]=arr[1][8];box_arr[2][6]=arr[2][6];box_arr[2][7]=arr[2][7];box_arr[2][8]=arr[2][8];
    box_arr[3][0]=arr[3][0];box_arr[3][1]=arr[3][1];box_arr[3][2]=arr[3][2];box_arr[3][3]=arr[4][0];box_arr[3][4]=arr[4][1];box_arr[3][5]=arr[4][2];box_arr[3][6]=arr[5][0];box_arr[3][7]=arr[5][1];box_arr[3][8]=arr[5][2];
    box_arr[4][0]=arr[3][3];box_arr[4][1]=arr[3][4];box_arr[4][2]=arr[3][5];box_arr[4][3]=arr[4][3];box_arr[4][4]=arr[4][4];box_arr[4][5]=arr[4][5];box_arr[4][6]=arr[5][3];box_arr[4][7]=arr[5][4];box_arr[4][8]=arr[5][5];
    box_arr[5][0]=arr[3][6];box_arr[5][1]=arr[3][7];box_arr[5][2]=arr[3][8];box_arr[5][3]=arr[4][6];box_arr[5][4]=arr[4][7];box_arr[5][5]=arr[4][8];box_arr[5][6]=arr[5][6];box_arr[5][7]=arr[5][7];box_arr[5][8]=arr[5][8];
    box_arr[6][0]=arr[6][0];box_arr[6][1]=arr[6][1];box_arr[6][2]=arr[6][2];box_arr[6][3]=arr[7][0];box_arr[6][4]=arr[7][1];box_arr[6][5]=arr[7][2];box_arr[6][6]=arr[8][0];box_arr[6][7]=arr[8][1];box_arr[6][8]=arr[8][2];
    box_arr[7][0]=arr[6][3];box_arr[7][1]=arr[6][4];box_arr[7][2]=arr[6][5];box_arr[7][3]=arr[7][3];box_arr[7][4]=arr[7][4];box_arr[7][5]=arr[7][5];box_arr[7][6]=arr[8][3];box_arr[7][7]=arr[8][4];box_arr[7][8]=arr[8][5];
    box_arr[8][0]=arr[6][6];box_arr[8][1]=arr[6][7];box_arr[8][2]=arr[6][8];box_arr[8][3]=arr[7][6];box_arr[8][4]=arr[7][7];box_arr[8][5]=arr[7][8];box_arr[8][6]=arr[8][6];box_arr[8][7]=arr[8][7];box_arr[8][8]=arr[8][8];
    
   
   // checking the sum for it 
  for (int r = 0; r < 9; r++)
  {
      int sum=0;
      for (int c = 0; c< 9; c++) 
      {
         
         
             sum+=arr[r][c];
           
      }
      if(sum!=45)
      {
          for(int i=0;i<9;i++)
            {
                for(int j=i+1;j<9;j++)
                {
                    if(box_arr[r][i]==box_arr[r][j])
                    {
                        printf("\nOops!! two numbers at %d and %d position in box %d are same! pls check.\n",i+1,j+1,r+1);
                        return false;
                    }
                }
            }
     }
     
      
  }
  
 
  return true;
 
    
}





int main()
{
    printf("            SUDOKU\n");
    
        char level;
        
        //user selects level
        printf("\n1. Press E for easy level");
        printf("\n2. Press M for Medium level");
        printf("\n3. Press H for Hard level");
        printf("\nEnter your dificulty level:");
        scanf("%c",&level);
        
        if(level=='E')
        {
            for (int i = 0; i < 9; i++)
                for (int j = 0; j < 9; j++)
                    arr[i][j] = easy[i][j];
        }
        else if(level=='M')
        {
           for (int i = 0; i < 9; i++)
                for (int j = 0; j < 9; j++)
                    arr[i][j] = medium[i][j];
        }
        else if(level=='H')
        {
            for (int i = 0; i < 9; i++)
                for (int j = 0; j < 9; j++)
                    arr[i][j] = hard[i][j];
        }
        
        
        // storing the fixed numbers indexes in an fixed_index array so that user doesn't changes fixed numbers
        for (int i = 0; i < 9; i++)
        {
                for (int j = 0; j < 9; j++)
                {
                 if(arr[i][j]!=0)
                 {
                     fixed_index[i][j]=1; // 1 means indexing are fixed
                 }
                 else
                 {
                    fixed_index[i][j]=0; // 0 means gaps to fill
                 }
                }
        }
        
        
        
    print();
    
    char choice='u';
    
        
      // user selects choice  
     do
    {
     
        printf("\n1. Press A to add a number");
        printf("\n2. Press D to delete a number");
        printf("\n3. Press V to validate Sudoku");
        printf("\n4. Press R to Reset");
        printf("\n5. Press Q to exit game");
        printf("\nEnter your Choice:");
        scanf(" %c",&choice);
        
        bool ans;
        switch(choice)
        {
            case 'A':
                add();
                break;
            case 'D':
                delete();
                break;
            case 'V':
                ans=validate();
                if(ans==true)
                {
                    printf("\nWohhoo!!!! You Won\n");
                }
                break;
            case 'R':
                reset(level);
                break;
            case 'Q':
                return 0;
                break;
            default:
                printf("\nEnter valid choice\n");
                break;
            
        }
        
        print(); // printing sudoku after every choice
    }while(choice!='Q');
    
    
    return 0;
}
