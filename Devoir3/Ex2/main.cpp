#include <iostream>
#include "heap.h"
using namespace std;

int main()
{
    Heap<Vrajitor> heap(100);
    Vrajitor Cedric ("Diggory", "Cedric", 2000, "");
    Vrajitor Harry ("Potter", "Harry", 10000, "");
    Vrajitor Hermione ("Granger", "Hermione", 17000, "");
    Vrajitor Luna ("Lovegood", "Luna", 31000, "");
    Vrajitor Draco ("Malfoy", "Draco", 60000, "");
    Vrajitor Severus ("Snape", "Severus", 150000, "");

    heap.insertElement(Cedric);
    heap.insertElement(Harry);
    heap.insertElement(Hermione);
    heap.insertElement(Luna);
    heap.insertElement(Draco);
    heap.insertElement(Severus);

    heap.homes();
    return 0;
}
