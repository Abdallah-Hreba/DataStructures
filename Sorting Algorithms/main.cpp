#include <bits/stdc++.h>
#include "Sorting_Algorithms.h"
using namespace std;
int main() {
    ifstream inputFile("Data.txt");

    if (!inputFile) {
        cout << "Error opening the file!" << endl;
        return 1;
    }

    int numStudents;
    inputFile >> numStudents;

    vector<Student> students,QCS,qcs2,M,M2;

    for (int i = 0; i < numStudents; ++i) {
        string name;
        int id;
        double gpa;

        inputFile.ignore(); // Ignore the newline character after the previous number
        getline(inputFile, name);
        inputFile >> id >> gpa;

        Student student(name, id, gpa);
        students.push_back(student);
        QCS.push_back(student);
        qcs2.push_back(student);
        M.push_back(student);
        M2.push_back(student);
    }
    bubblebyname(students);//executing bubble sort by name ALGO
    insertionSort(students);//executing insertion sort by name ALGO
    bubblebygpa(students);//executing bubble sort by GPA ALGO
    insertionbygpa(students);//executing insertion sort by GPA ALGO
    selectionbyname(students);//executing selection sort by name ALGO
    selectionbygpa(students);//executing selection sort by GPA ALGO

    //executing quick sort by name ALGO and writing to the output file
    infofile("SortedByName.txt","algorithm used : quick Sort\n");
    Stopwatch q;
    q.Start();
    quickSort(QCS, 0, QCS.size()-1 );
    q.Stop();
    runtime("SortedByName.txt",q.ElapsedMilliseconds());
    appendtofile("SortedByName.txt",QCS,comparisons);
    //executing quick sort by GPA ALGO and writing to the output file
    infofile("SortedByGpa.txt","algorithm used : quick Sort\n");
    Stopwatch v;
    v.Start();
    quickSortbygpa(qcs2,0,qcs2.size()-1);
    v.Stop();
    runtime("SortedByGpa.txt",v.ElapsedMilliseconds());
    appendtofile("SortedByGpa.txt",qcs2,gpacomparisons);
    //executing merge sort by name ALGO and writing to the output file
    infofile("SortedByName.txt","algorithm used : merge Sort\n");
    Stopwatch s;
    s.Start();
    mergeSort(M,0,M.size()-1);
    s.Stop();
    runtime("SortedByName.txt",s.ElapsedMilliseconds());
    appendtofile("SortedByName.txt",M,mc);
    //executing merge sort by GPA ALGO and writing to the output file
    infofile("SortedByGpa.txt","algorithm used : merge Sort\n");
    Stopwatch sw;
    sw.Start();
    mergeSortbygpa(M2,0,M2.size()-1);
    sw.Stop();
    runtime("SortedByGpa.txt",sw.ElapsedMilliseconds());
    appendtofile("SortedByGpa.txt",M2,m2c);

    shellSort(students);//Executing shell sort by name
    shellSortbygpa(students);//Executing shell sort by GPA
    inputFile.close();
    return 0;
    /*NOTE: if u run the program multiple times the data in the output files will be repeated (not changed).*/
}