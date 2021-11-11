/************************************************************//*
  Filename   : sort.cc
  Author     : Dominic J. DuRant
  Course     : CSCI 362-01
  Assignment : 3
  Description: An overview and comparison of various sorting algorithms.
*/

/************************************************************/
// System includes

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <random>
#include <bits/stdc++.h>

/************************************************************/
// Local includes

/************************************************************/
// Using declarations

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::minstd_rand;

/************************************************************/
// Function prototypes/global vars/typedefs

// Perform an optimized bubble sort on 'v'
// Return the number of comparisons and swaps
//   using the reference parameters
void
bubbleSort (vector<int>& v, size_t& numCompares, size_t& numSwaps);

// Perform an insertion sort on 'v'
// Return the number of comparisons performed
size_t
insertionSort (vector<int>& v);

// Perform a selection sort on 'v'
// Return the number of comparisons and swaps
//   using the reference parameters
void
selectionSort (vector<int>& v, size_t& numCompares, size_t& numSwaps);


/************************************************************/

int
main (int argc, char* argv[])
{
  size_t n;
  string algorithm;
  char type;
  int seed; 
  vector<int> order;
  size_t numCompares; 
  size_t numSwaps; 

  cout << "N         ==> ";
  cin >> n;
  cout << "Algorithm ==> ";
  cin >> algorithm;
  cout << "Type      ==> ";
  cin >> type;
  cout << endl;

  if (type == 'r')
  {
    cout << "Seed      ==> ";
    cin >> seed;
    cout << endl;

    minstd_rand gen (seed);

    for (size_t i = 1; i <= n; ++i)
    {
      //adding values to the vector between 0 and 999 inclusive
      order.push_back(gen () % 1000);
    }
  }

  if (type == 'a')
  {
    for (size_t i = 1; i <= n; ++i)
    {
      order.push_back(i);
    }
  }
  else if (type == 'd')
  {
    for (size_t i = n; i >= 1; --i)
    {
      order.push_back(i);
    }
  }

  if (algorithm == "insertion")
  {
    insertionSort (order);
  }
  else if (algorithm == "bubble")
  {
    bubbleSort (order, numCompares, numSwaps);
  }
  else if (algorithm == "selection")
  {
    selectionSort (order, numCompares, numSwaps);
  }

  return EXIT_SUCCESS;
}

/************************************************************/

void
bubbleSort (vector<int>& v, size_t& numCompares, size_t& numSwaps)
{
  vector<int> Acopy (v);
  std::sort (Acopy.begin (), Acopy.begin () + Acopy.size ());
  numCompares = 0;
  numSwaps = 0;

  for (size_t i = v.size () - 1; i >= 1; --i) 
  {
    bool didSwap = false;
    for (size_t j = 0; j < i; ++j)
    {
      ++numCompares;
      if (v[j] > v[j + 1]) 
      {
        std::swap (v[j], v[j + 1]);
        didSwap = true;
        ++numSwaps;
      }
    }
    if (!didSwap)
    {
      break;
    } 
  }

  cout << "# Compares: " << numCompares << endl;
  cout << "# Swaps   : " << numSwaps << endl;
  if (v == Acopy){
    cout << "Sort ok?    yes\n";
  }
  else
  {
    cout << "Sort ok?    no\n";
  }
}

/************************************************************/

size_t
insertionSort (vector<int>& v)
{
  vector<int> Acopy (v);
  std::sort (Acopy.begin (), Acopy.begin () + Acopy.size ());
  size_t numCompares = 0;
  size_t numSwaps = 0;

  for (size_t i = 1; i < v.size (); ++i)
  {
    int a = v[i];
    int b = i;
    while (b >= 1 && a < v[b - 1])
    {
      v[b] = v[b - 1];
      --b;
      ++numCompares;  
    }
    v[b] = a;
    if (b != 0 && b >= v[b - 1])
    {
      ++numCompares;
    }
  }
  
  cout << "# Compares: " << numCompares << endl;
  cout << "# Swaps   : " << numSwaps << endl;
  if (v == Acopy){
    cout << "Sort ok?    yes\n";
  }else{
    cout << "Sort ok?    no\n";
  }

  return numCompares;

}
/************************************************************/

void
selectionSort (vector<int>& v, size_t& numCompares, size_t& numSwaps)
{
  vector<int> Acopy (v);
  std::sort (Acopy.begin (), Acopy.end ());
  
  numCompares = 0;
  numSwaps = 0;

  for (size_t i = 0; i < v.size () - 1; ++i)
  {
    size_t min = i;
    for (size_t j = i + 1; j < v.size (); ++j)
    {
      ++numCompares;
      if (v[j] < v[min])
      {
        min = j;
      }
    
     std::swap (v[i], v[min]);
    
     if (i != min)
     {
       ++numSwaps;;
     }
    }
    
  } 

  cout << "# Compares: " << numCompares << endl;
  cout << "# Swaps   : " << numSwaps << endl;
  if (v == Acopy){
    cout << "Sort ok?    yes\n";
  }else{
    cout << "Sort ok?    no\n";
  }
}
/************************************************************/
/************************************************************/