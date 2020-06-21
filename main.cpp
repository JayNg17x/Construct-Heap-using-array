/* 
 * File:   main.cpp
 * Author: kienneymar
 *
 * Created on November 30, 2019, 8:14 PM
 */

#include<iostream>
#include <cstdlib>
#include<algorithm>
#include<cmath>
//#define MAX 200
using namespace std;


//void make_heap(, size_t);
//void reheapify_down(int, size_t);
//void heap_sort(int , size_t);
//void heap_sort_1(int, size_t);
//void delete_root(int, size_t&);
//void insert_node(int, size_t, int);

// member function to print tree structures
void non_rotated(int, size_t);
void rotated_90(int, size_t);
void h_tree_form(int, size_t);

//struct Heap
//{
//    Heap* _left, _right;
//    int value;
//};


void make_heap(int data[], size_t n)
{
    size_t i, k;
    for(i = 1; i < n; ++i)
    {
        k = i;
        while(data[k] != data[0] && data[k] > data[(k-1)/2])
        {
            swap(data[(k-1)/2], data[k]);
            k = (k - 1)/2;         
        }
    }
}
void reheapify_down(int data[], size_t n)
{
    size_t current;
    size_t big_child_index;
    bool heap_ok;
    
    current = 0;
    heap_ok = false;
    
    while((!heap_ok) && ((current * 2) + 1) < n && ((current * 2) + 2) < n)
    {
        if(data[current] < data[big_child_index])
        {
            swap(data[current], data[big_child_index]);
            big_child_index = current;          
        }
        else
            heap_ok = true;
    }
}

void heap_sort(int data[], size_t n)
{
    size_t unsort;
    
    make_heap(data, n);
    while(unsort > 1)
    {
        --unsort;
        swap(data[0], data[unsort]);
        reheapify_down(data, unsort);
    }
}
void delete_root(int data[], size_t& n)
{
    int last_element = data[n - 1];
    
    data[0] = data[n - 1];
    
    n = n - 1;
    
    reheapify_down(data, n);  
}
void insert_node(int data[], size_t n, int& key)
{
    n = n + 1;
    
    // insert element at the end of heap.
    data[n - 1] = key;
    
    reheapify_down(data, n);   
}
void print_heap(int data[], size_t n)
{
    make_heap(data, n);
    for(size_t i = 0; i < n; ++i)
    {
        cout << data[i] << " ";
    }
}


int main(int argc, char** argv) {

    size_t n  = 5;
    int data[n];
    char ch;
    int key;
      

    
     
    return 0;
}

