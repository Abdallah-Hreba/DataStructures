#include <bits/stdc++.h>
using namespace std;
void generateBinaryNumbers(int n) {
    queue<string> q;
    q.push("1");

    while (n--) {
        string binary = q.front();
        q.pop();

        cout << binary << " ";

        q.push(binary + "0");
        q.push(binary + "1");
    }
}
//sorting queue using insertion sort without using any extra space
int minIndex(queue<int> &q, int sortedIndex)
{
    int min_index = -1;
    int min_val = INT_MAX;
    int n = q.size();
    for (int i=0; i<n; i++)
    {
        int curr = q.front();
        q.pop();
        if (curr <= min_val && i <= sortedIndex)
        {
            min_index = i;
            min_val = curr;
        }
        q.push(curr);
    }
    return min_index;
}


void insertMinToRear(queue<int> &q, int min_index)
{
    int min_val;
    int n = q.size();
    for (int i = 0; i < n; i++)
    {
        int curr = q.front();
        q.pop();
        if (i != min_index)
            q.push(curr);
        else
            min_val = curr;
    }
    q.push(min_val);
}

void sortQueue(queue<int> &q)
{
    for (int i = 1; i <= q.size(); i++)
    {
        int min_index = minIndex(q, q.size() - i);
        insertMinToRear(q, min_index);
    }
}
int main() {
    int n = 3;
    cout << "Binary numbers from 1 to " << n << ": ";
    generateBinaryNumbers(n);
    cout << endl;
    queue<int> q;
    q.push(5);
    q.push(3);
    q.push(8);
    q.push(1);
    q.push(2);

    cout << "Original Queue: ";
    queue<int> qCopy = q; // Create a copy of the original queue for printing
    while (!qCopy.empty()) {
        cout << qCopy.front() << " ";
        qCopy.pop();
    }
    cout << endl; 
    sortQueue(q);

    cout << "Sorted Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
