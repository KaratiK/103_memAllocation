// 103_DynamicMemory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
using std::string;


char* heapAddress() {
    char name[10];               //Create array size 10 in stack
    int size = 0;                //Create int size initialized to 0 on stack
    std::cout << "Enter Subject name\n";
    std::cin >> name;        //Receive input for name

    //If input in name at index i is something, increment size
    for (int i = 0; i < 10; i++) {
        if (name[i] != NULL)
            size++;
    }

    //Create pointer variable on stack to address in newly allocated location on heap
    char* namePtr = (char*)malloc(size);

    //Add index i of name array to index i of on the heap
    for (int i = 0; i < size; i++) {
        *(namePtr + i) = name[i];
    }
    return namePtr;
}



int main()
{
    int size;

    std::cout << "How many subjects do you wish to add?\n";
    std::cin >> size;


    char** addressCollection = (char**)malloc(size * sizeof(char*));

    for (int i = 0; i < size; i++) {
        *(addressCollection + i) = heapAddress();
    }

    for (int i = 0; i < size; i++) {
        std::cout << *(addressCollection + i) << "\t";
    }
}
    //i = (int*)malloc(size * sizeof(int));

    //for (int val = 0; val < size; val++) {
    //    std::cin >> *(i + val);
    //}
    //for (int val = 0; val < size; val++) {
    //    std::cout << *(i + val) << "\t";
    //}





    //free(name);

    /*float* f_data;
    f_data = (float*)calloc(5, sizeof(float));

    int* v;
    int* v = new int[25];*/
    
}


