#include <iostream>
#include <string>

void basicMemAlloc();
void arrayMemAlloc();
void multiDimensionalArrayMemAlloc();
void objectMemAlloc();
void printArr(int **arr, int *row, int *col);
void deleteArr(int **arr);

// class for objectMemAlloc();
class Box
{
    public:
        //ctor for box, creates box object.
        Box()
        {
            std::cout << "Constructor called!" << std::endl;
        }
        //destructor for box.  Deletes the box object.
        ~Box()
        {
            std::cout << "Destructor called!" << std::endl;
        }
};

int main()
{
    std::cout << "Dynamic Memory Allocation examples: " << std::endl;
    basicMemAlloc();
    arrayMemAlloc();
    multiDimensionalArrayMemAlloc();
    objectMemAlloc();
    return 0;
}

void basicMemAlloc()
{

    double *value = NULL; // initialize value pointer
    value = new double;   // request memory for pointer variable

    *value = 65465.21; // assign value to memory address
    std::cout << "Value: " << *value << std::endl;

    delete value; // free up memory allocated pointer
    std::cout << std::endl;
}

void arrayMemAlloc()
{
    std::string *arr = NULL;
    arr = new std::string;

    *arr = "my dynamic array!";
    std::cout << *arr << std::endl;

    // delete the string array pointer using erase();
    arr->erase();
    std::cout << std::endl;
}

void multiDimensionalArrayMemAlloc()
{
    int **box = NULL;
    int row = 7, col = 8;

    //alloc memory for the 2D array
    box = new int *[row];
    for (int i = 0; i < row; i++)
    {
        box[i] = new int[col];
    }

    // put random values in the 2D array.
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            box[i][j] = rand() % 100;
        }
    }

    // box is already a pointer, can be passed as is
    printArr(box, &row, &col);
    //delete via function
    deleteArr(box);
}

void objectMemAlloc()
{
    std::cout << "myBox: " << std::endl;
    Box *myBox = new Box;
    delete myBox;
    std::cout << std::endl;

    std::cout << "myBoxArr, size 2: " << std::endl;
    Box *boxArr = new Box[2];
    delete [] boxArr;
    std::cout << std::endl;
}


void printArr(int **arr, int *row, int *col)
{

    std::cout << "Printing 2D array:" << std::endl;

    for (int i = 0; i < *row; ++i)
    {
        for (int j = 0; j < *col; ++j)
        {
            std::cout << "numbers[" << i << "][" << j << "]: " << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void deleteArr(int **arr)
{
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        delete[] arr[i];
    }

    delete[] arr;
}
