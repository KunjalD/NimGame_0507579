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
int randomPlayer();
void winner(string)
{
    cout << "Player "<< firstPlayer << " has won.";
}
bool gameStatus(int *heap)
{
    for (int i = 1; i <= NUM_HEAPS[heap_index]; i++)
    {
        if(heap[i] !=0){ return false;}
    }
    return true;
}
void display_heap(int heap[])	// calls the function display heap
{
    cout << endl;
    for (int i = 1; i <= NUM_HEAPS[heap_index]; i++)
    {
        cout << " Heap " << i << ":" << heap[i];
    }
    cout << endl;
}
/*int remove_sticks(int x)
{
    int y;
    cout << " inside odd y ";
    //y = 3 * rand() % x;
    cout << " odd y " << y;
    return y;
}*/
void computerMove()
{
    int curr_heap = randFunction(num_heap);
    //int curr_sticks =heap[curr_heap];
    int remove_stick = 0;
    //cout << curr_heap << " curr_heap " << endl;
    //cout << curr_sticks << " curr_sticks " << endl;
    //cout << heap[curr_heap] << " heap curr_heap " << endl;
    if(heap[curr_heap] != 0)
    {
        cout << "NOT ZERO" << endl;
        remove_stick = randFunction(heap[curr_heap]);
        heap[curr_heap] -= remove_stick;
    }else
    {
        cout << "ZERO " << endl;
        computerMove();
    }

   // cout << curr_sticks << " curr_sticks ";
    cout << heap[curr_heap] << " heap value after remoev ";
    cout << "\n" << "Player computer took "<< remove_stick << " objects from heap " << curr_heap << "\n";
    display_heap(heap);
    if(gameStatus(heap) == true)
    {
        winner(firstPlayer);
    }
    firstPlayer = "human";
}
void humanMove()
{
    int x,y;
    cout << "\n" << "Player human enter the number of objects (Y) to take from what heap (X)- in order: Y X" << "\n";
    cin >> y >> x;
    if(NUM_HEAPS[heap_index] >= x > 0 && heap[x]>=y)
    {
        cout << "possible" << "\n";
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

int randFunction(int size)
{
    int RandIndex =0;
    if(size != 0)
    {
        cout << size << " randome function size " << endl;
        RandIndex = rand() % size;
    }
    return RandIndex;
}

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
        cout << " here again " << heap[i] ;
    }
    firstPlayer = PLAYER[randFunction(2)];
    cout << "\n" << "Player " << firstPlayer << " goes first";
    while(gameStatus(heap) != 1)
    {
        if(firstPlayer == "computer")
        {
            computerMove();
        }else if(firstPlayer=="human")
        {
            humanMove();
        }
    }
    
    return 0;
}


