#include <iostream>
const int N=9;
int grid[N][N] = {
   {1, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 7, 9, 0, 5},
   {0, 8, 0, 9, 0, 3, 4, 2, 0},
   {0, 0, 2, 0, 4, 0, 8, 0, 0},
   {8, 1, 0, 0, 2, 0, 0, 0, 0},
   {0, 0, 7, 0, 0, 0, 0, 5, 6},
   {6, 5, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 3, 0, 0, 0, 0, 9, 0},
   {0, 0, 0, 0, 0, 0, 7, 0, 4}
};
void print_grid()
{
  for(int i=0; i<9; i++)
  {
    for(int j=0; j<9; j++){
      std::cout<<grid[i][j]<<"  ";
    }
    std::cout<<std::endl;
  }
}
bool is_empty(int& row,int& col){
  for(row=0; row<9; row++)
  {
    for(col=0; col<9; col++)
    {
     if(grid[row][col]==0){
     return true;
  }
    }
  }
  return false;
}

bool is_in_row(int row, int num)
{
  for (int i=0; i<9; i++)
  {
    if(grid[row][i]==num){
      return true;
    }
  }
  return false;
}

bool is_in_col(int col, int num){
  for(int i=0; i<9; i++)
  {
    if(grid[i][col]==num)
    {
      return true;
    }
  }
  return false;
}
bool is_in_box(int row, int col, int num)
{ 
  
  for(int i = 0; i<3; i++ )
  {
    for(int j=0; j<3; j++)
    {
      if(grid[row+i][col+j]==num){
        return true;
      }
    }
  }
  return false;
}

bool is_valid_place(int row, int col, int num){
   return !is_in_row(row, num) && !is_in_col(col, num) && !is_in_box(row-row%3, col-col%3,num);
}

bool solve_sudoku(){
   int row, col;
   if (!is_empty(row, col))
      return true; 

 for (int num = 1; num <= 9; num++){ 
      if (is_valid_place(row, col, num)){ 
         grid[row][col] = num;
         if (solve_sudoku()) 
            return true;
         grid[row][col] = 0; 
      }
   }
   return false;
}


int main() {
  if(solve_sudoku())
  {
    print_grid();
  }
  else
  {
    std::cout<<"There isn't any solution";
    
  }
