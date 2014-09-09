//
//  main.cpp
//  NimGame
//
//  Created by Kunjal Davawala on 9/6/14.
//  Copyright (c) 2014 Kunjal Davawala. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;
// Global variables

const int NUM_HEAPS[] = {3,5,7};
const int HEAP_SIZE[] = {9,11,13};
const string PLAYER[] = {"human","computer"};
int heap_index,num_heap,subheap_index,subheap_size;
int *heap;

string firstPlayer;
int randFunction(int size);


//Display wining player message
void winner(string firstPlayer)
{
    cout << "Player "<< firstPlayer << " has won.";
}
// Checks the game status if it is over or not
bool gameStatus(int *heap)
{
    for (int i = 1; i <= NUM_HEAPS[heap_index]; i++)
    {
        if(heap[i] !=0){ return false;}
    }
    return true;
}
// Displays the content of heap
void display_heap(int heap[])	// calls the function display heap
{
    cout << endl;
    for (int i = 1; i <= NUM_HEAPS[heap_index]; i++)
    {
        cout << " Heap " << i << ":" << heap[i];
    }
    cout << endl;
}
// checks if the sum of heap is even or odd
bool ifsum_even()
{
    int total=0;
    for(int i=1;i<=num_heap;i++)
    {
        total = total + heap[i];
    }
    //cout << total << " TOTAL ";
    if(total%2 == 0)
    {
        return true;
    }else{
        return false;
    }
    
}
// Computer sends the current number of sticks and gets the number it should remove.
int remove_sticks(int x)
{
    int y=1;
    if(x != 0)
    {
        if(ifsum_even())
        {
            for(int i=x;i>0;i--)
            {
                //cout << " EVEN " << endl;
                if(i%2==0)
                {
                    //cout <<i << " i";
                    y =1;
                    break;
                }
            }
            return y;
            
        }else
        {
            for(int i=x;i>0;i--)
            {
                //cout << " ODD " << endl;
                if(i%3==0)
                {
                    //cout <<i << " i";
                    y = i;
                    break;
                }
            }
            return y;
        }
        
    }else
    {
        remove_sticks(x);
        return y;
    }
}
//Computer Move for the game
void computerMove()
{
    int curr_heap = randFunction(num_heap+1);
    int remove_stick = 0;
    
    while(heap[curr_heap] == 0 || curr_heap == 0)
    {
         curr_heap = randFunction(num_heap);
    }
    if(heap[curr_heap] != 0)
    {
        remove_stick = remove_sticks(heap[curr_heap]);
        heap[curr_heap] -= remove_stick;
    }

    //cout << heap[curr_heap] << " heap value after remove ";
    cout << "\n" << "Player computer took "<< remove_stick << " objects from heap " << curr_heap << "\n";
    display_heap(heap);
    if(gameStatus(heap) == true)
    {
        winner(firstPlayer);
    }
    firstPlayer = "human";
}
// Human move for the game
void humanMove()
{
    int x,y;
    cout << "\n" << "Player human enter the number of objects (Y) to take from what heap (X)- in order: Y X" << "\n";
    cin >> y >> x;
    if(NUM_HEAPS[heap_index] >= x > 0 && heap[x]>=y && x!=0 && y!=0)
    {
        heap[x] -= y;
        //check for game over
        display_heap(heap);
    }else
    {
        cout << "Player human that is an invalid move, try again" << "\n";
        humanMove();
    }
    if(gameStatus(heap) == true)
    {
        winner(firstPlayer);
    }
    firstPlayer = "computer";
}
// Functions which calculates the random numbers
int randFunction(int size)
{
    int RandIndex = 0;
    if(size != 0)
    {
        //cout << size << " randome function size " << endl;
        RandIndex = rand() % size;
    }
    //cout << "RandIndex " << RandIndex << endl;
    return RandIndex;
}
// main
int main()
{
    srand((unsigned)time(NULL));
    heap_index = randFunction(3);
    num_heap = NUM_HEAPS[heap_index];
    cout << "Created " << num_heap << " heaps of size";
    heap = new int[num_heap];
    for(int i=1;i<=num_heap;i++)
    {
        subheap_index = randFunction(3);
        subheap_size = HEAP_SIZE[subheap_index];
        heap[i] = subheap_size;
        cout << " " << heap[i];
    }
    firstPlayer = PLAYER[randFunction(2)];
    while(gameStatus(heap) != 1)
    {
        if(firstPlayer == "computer")
        {
            //cout << "here again in main compu";
            computerMove();
        }else if(firstPlayer=="human")
        {
            humanMove();
        }
    }
    
    return 0;
}


