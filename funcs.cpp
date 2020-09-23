/*
Author: Tommy Liang
Course: CSCI 135
Instuctor: Mike Zamansky
Assignment: Lab 04

funcs.cpp contains the code for each function call
*/
#include <iostream>

#include "funcs.h"

std::string box(int width, int height)
{
  std::string result = "";
  for(int row = 0; row < height; row++)
  {
    for(int col = 0; col < width; col++)
      result += "*";
    result += "\n";
  }
  return result + "\n";
}

std::string checkerboard(int width, int height)
{
  std::string result = "";
  for(int row = 0; row < height; row++)
  {
    for(int col = 0; col < width/2; col++)
    {
      if(row%2 == 0)
      //Every even row starts with a "*" while every odd row starts with a " "
        result += "* ";
      else
        result += " *";
    }
    if(row%2 == 0)
      result += "*";
    result += "\n";
  }
  return result + "\n";
}

std::string cross(int size)
{
  std::string result = "";
  for(int row = 0; row < size; row++)
  {
    for(int col = 0; col < size; col++)
    {
      if(row == col || row+col+1 == size)
      //constructs the diagonal from top left to bottom right and top right to bottom left
        result += "*";
      else
        result += " ";
    }
    result += "\n";
  }
  return result + "\n";
}

std::string lower(int length)
{
  std::string result = "";
  for(int row = 0; row < length; row++)
  {
    for(int col = 0; col < length; col++)
      if(col < row+1)
      //everything below and including the top left to bottom right diagonal
       result += "*";
    result += "\n";
  }
  return result;
}

std::string upper(int length)
{
  std::string result = "";
  for(int row = 0; row < length; row++)
  {
    for(int col = 0; col < length; col++)
      if(col > row-1)
      //everything above and including the top left to bottom right diagonal
        result += "*";
      else
        result += " ";
    result += "\n";
  }
  return result;
}

std::string trapezoid(int width, int height)
{
  std::string result = "";
  /*
    A trapezoid can't be made if the width is greater than half the height.
    As the height increases by 1, the width decreases by 2, one star per side
  */
  if(height > width/2)
  {
    result = "Impossible shape!\n";
    return result;
  }
  for(int row = 0; row < height; row++)
  {
    for(int col = 0; col < width; col++)
    {
      if(col >= row && col <= width-1-row)
      //takes away "row" number of stars from each side as row increases
        result += "*";
      else
        result += " ";
    }
    result += "\n";
  }
  return result;
}

std::string checkerboard3x3(int width, int height)
{
  std::string result = "";
  std::string inputr = "*";
  std::string inputc = "*";
  for(int row = 0; row < height; row++)
  {
    //Toggles the input every 3 rows
    if(row%3 == 0 && row != 0)
    {
      if(inputr == "*")
        inputr = " ";
      else
        inputr = "*";
    }
    for(int col = 0; col < width; col++)
    {
      //We set the inputc to inputr every time we start on a new row
      if(col == 0)
        inputc = inputr;
      else
      {
        //Toggles the input every 3 columns
        if(col%3 == 0)
        {
          if(inputc == "*")
            inputc = " ";
          else
            inputc = "*";
        }
      }
      result += inputc;
    }
    result += "\n";
  }
  return result;
}
