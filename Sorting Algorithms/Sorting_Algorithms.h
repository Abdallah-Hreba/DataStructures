#include<bits/stdc++.h>
#include "Stopwatch.h"
#include <Windows.h>
using std::cout;
using win32::Stopwatch;
using namespace std;

int comparisons=0,gpacomparisons=0,mc=0,m2c=0;
class Student {
public:
    string name;
    int id;
    double gpa;

    Student(string name, int id, double gpa)
            : name(name), id(id), gpa(gpa) {}

    Student(){};//default constructor
    void displayInfo()const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "GPA: " << gpa << endl;
        cout << "------------------------" << endl;
    }
    bool operator<(const Student& other) const {
        return name < other.name;
    }


};
void runtime(const string& filename,double z = 0)
{
    ofstream file(filename, ios::app);

    if (!file) {
        cerr << "Error opening file!" << endl;
    }
    else
    {
        file <<"Runtime: "<<z<<"   ms"<<endl;
    }
    // Close the file
    file.close();
}

void appendtofile(const string& filename,const vector<Student>& students,int comparisons){

    ofstream file(filename, ios::app);

    if (!file) {
        cerr << "Error opening file!" << endl;
    }
    else
    {
        file <<"Number of comparisons : "<<comparisons<<endl;
        for (size_t i = 0; i < students.size(); i++)
        {
            file <<students[i].name<<"\n"<<students[i].id<<"\n"<<students[i].gpa<<"\n------------------------------------------\n";
        }
    }
    // Close the file
    file.close();
}
void infofile(const string& filename,string x)
{
    ofstream file(filename, ios::app);

    if (!file) {
        cerr << "Error opening file!" << endl;
    }
    else
    {
        file << x <<"\n";
    }
    // Close the file
    file.close();
};
template<class t>
void bubblebyname(vector <t> students){
    Stopwatch sw;
    sw.Start();
    int n = students.size(),comparisons=0;
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (students[j+1] < students[j]){
                swap(students[j],students[j+1]);
            }
        }
        ++comparisons;

    }
    sw.Stop();

    infofile("SortedByName.txt","algorithm used : Bubble Sort\n");
    runtime("SortedByName.txt",sw.ElapsedMilliseconds());
    appendtofile("SortedByName.txt",students,comparisons);
}
template<class t>
void bubblebygpa(vector <t> students){
    Stopwatch sw;

    sw.Start();
    int n = students.size(),comparisons=0;
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (students[j+1].gpa>students[j].gpa){
                swap(students[j],students[j+1]);
            }
        }
        comparisons++;
    }

    sw.Stop();

    infofile("SortedByGpa.txt","algorithm used : Bubble Sort\n");
    runtime("SortedByGpa.txt",sw.ElapsedMilliseconds());
    appendtofile("SortedByGpa.txt",students,comparisons);
}
template <typename T>
void insertionSort(vector<T> students) {
    Stopwatch sw;
    sw.Start();
    int comparisons = 0;
    int n = students.size();
    for (int i = 1; i < n; ++i) {
        T key = students[i];
        int j = i - 1;

        while (j >= 0 && ++comparisons && key < students[j]) {
            students[j + 1] = students[j];
            j--;
        }

        students[j + 1] = key;
    }
    sw.Stop();
    infofile("SortedByName.txt","algorithm used : Insertion Sort\n");
    runtime("SortedByName.txt",sw.ElapsedMilliseconds());
    appendtofile("SortedByName.txt",students,comparisons);
}

template <typename g>
void insertionbygpa(vector<g> arr) {
    Stopwatch sw;
    sw.Start();

    int n = arr.size(),insertioncomparisons=0;

    for (int i = 1; i < n; ++i) {
        g key = arr[i];
        int j = i - 1;

        while (j >= 0 && key.gpa > arr[j].gpa) {
            arr[j + 1]= arr[j];
            j--;
            insertioncomparisons++;
        }
        insertioncomparisons++;
        arr[j + 1] = key;
    }
    sw.Stop();
    infofile("SortedByGpa.txt","algorithm used : Insertion Sort\n");
    runtime("SortedByGpa.txt",sw.ElapsedMilliseconds());
    appendtofile("SortedByGpa.txt",arr,insertioncomparisons);
}
template<class f>
void selectionbyname(vector <f> arr) {
    Stopwatch sw;
    sw.Start();

    int n = arr.size(),comparison=0;
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        comparison++;
        for (int j = i + 1; j < n; j++) {
            comparison++;
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }

        }
        swap(arr[i], arr[min_index]);
    }
    sw.Stop();

    infofile("SortedByName.txt","algorithm used : Selection Sort\n");
    runtime("SortedByName.txt",sw.ElapsedMilliseconds());
    appendtofile("SortedByName.txt",arr,comparison);
}

template<class f>
void selectionbygpa(vector <f> arr) {
    Stopwatch sw;
    sw.Start();

    int n = arr.size(),comparison=0;
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        comparison++;
        for (int j = i + 1; j < n; j++) {
            comparison++;
            if (arr[j].gpa > arr[min_index].gpa) {
                min_index = j;
            }

        }
        swap(arr[i], arr[min_index]);
    }
    sw.Stop();
    infofile("SortedByGpa.txt","algorithm used : Selection Sort\n");
    runtime("SortedByGpa.txt",sw.ElapsedMilliseconds());
    appendtofile("SortedByGpa.txt",arr,comparison);
}
template<class q>
int partition(vector<q>& arr, int low, int high) {
    string pivot = arr[high].name; // Select the last element's name as the pivot
    int i = (low - 1); // Index of smaller element
    for (int j = low; j <= high - 1; j++) {
        // If current element's name is smaller than or equal to pivot's name
        if (arr[j].name <= pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
        comparisons++;
    }

    swap(arr[i + 1], arr[high]); 
    return (i + 1); 
}
template <class q>
void quickSort(vector<q>& arr, int low, int high) {
    if (low < high) {
        // Partition the array and get the partitioning index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the elements before and after the partition
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
        
    }
}
int partitionbygpa(vector<Student>& arr, int low, int high) {
    double pivot = arr[high].gpa; // Select the last element's GPA as the pivot
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        // If current element's GPA is greater than or equal to pivot's GPA
        if (arr[j].gpa >= pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
        gpacomparisons++;
    }
    swap(arr[i + 1], arr[high]); 
    return (i + 1); 
}

// Recursive function to perform QuickSort
void quickSortbygpa(vector<Student>& arr, int low, int high) {
    if (low < high) {
        // Partition the array and get the partitioning index
        int pivotIndex = partitionbygpa(arr, low, high);

        // Recursively sort the elements before and after the partition
        quickSortbygpa(arr, low, pivotIndex - 1);
        quickSortbygpa(arr, pivotIndex + 1, high);
    }
}
void merge(vector<Student>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of the left subarray
    int n2 = right - mid;    // Size of the right subarray
    vector<Student> L(n1);
    vector<Student> R(n2);
    // Copy data from arr to the temporary arrays
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0; 
    int j = 0; 
    int k = left; 

    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
        mc++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Recursive function to perform Merge Sort based on the student names
void mergeSort(vector<Student>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Find the middle index

        // Recursively sort the left and right subarrays
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        // Merge the sorted subarrays
        merge(arr, left, mid, right);
    }
}
void mergebygpa(vector<Student>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of the left subarray
    int n2 = right - mid;    // Size of the right subarray
    // Create temporary arrays to store the left and right subarrays
    vector<Student> L(n1);
    vector<Student> R(n2);
    // Copy data from arr to the temporary arrays
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    int i = 0; 
    int j = 0; 
    int k = left; 
    while (i < n1 && j < n2) {
        if (L[i].gpa > R[j].gpa) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
        m2c++;
    }
    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSortbygpa(vector<Student>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Find the middle index
        // Recursively sort the left and right subarrays
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        // Merge the sorted subarrays
        mergebygpa(arr, left, mid, right);
    }
    
}
void shellSort(vector<Student>& students) {
    int n = students.size(),comparison=0;
    Stopwatch sw;
    sw.Start();
    // Start with a large gap and reduce it
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            Student temp = students[i];
            
            // shift earlier gap-sorted elements up until the correct
            // location for students[i] is found
            int j;
            for (j = i; j >= gap && students[j - gap].name > temp.name; j -= gap) {
                students[j] = students[j - gap];
                comparison++;
            }
            
            // put temp (the original students[i]) in its correct location
            students[j] = temp;
        }
    }
    sw.Stop();
    infofile("SortedByName.txt","algorithm used : shell Sort\n");
    runtime("SortedByName.txt",sw.ElapsedMilliseconds());
    appendtofile("SortedByName.txt",students,comparison);
}

void shellSortbygpa(vector<Student>& students) {
    int n = students.size(),comparison=0;
    Stopwatch sw;
    sw.Start();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            
            Student temp = students[i];
            int j;
            for (j = i; j >= gap && students[j - gap].gpa < temp.gpa; j -= gap) {
                students[j] = students[j - gap];
                comparison++;
            }
            students[j] = temp;
        }
    }
    sw.Stop();
    infofile("SortedByGpa.txt","algorithm used : shell Sort\n");
    runtime("SortedByGpa.txt",sw.ElapsedMilliseconds());
    appendtofile("SortedByGpa.txt",students,comparison);
}