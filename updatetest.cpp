#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;


int main() {


// File read
fstream fin;

// Open an existing record
fin.open("reportcard.csv");

// Create a new file to store updated data
ofstream fout ("reportcardnew.csv"); // Added open mode
int rollnum, roll1, marks, count = 0, i;
char sub;
int index, new_marks;
string line, word;
vector<string> row;

// Get the roll number from the user
cout << "Enter the roll number of the record to be updated: ";
cin >> rollnum;

// Get the data to be updated
cout << "Enter the subject to be updated(M/P/C/B): ";
cin >> sub;

// Determine the index of the subject
if (sub == 'm' || sub == 'M')
index = 2;
else if (sub == 'p' || sub == 'P')
index = 3;
else if (sub == 'c' || sub == 'C')
index = 4;
else if (sub == 'b' || sub == 'B')
index = 5;
else {
cout << "Wrong choice.\n";
return 1; // Exit the program if the choice is wrong
}
// Get the new marks
cout << "Enter new marks: ";
cin >> new_marks;
// Traverse the file
while (getline(fin, line)) { // Use getline directly
row.clear();
stringstream s(line);
while (getline(s, word, ',')) { // Use ',' as the delimiter
row.push_back(word);
}
roll1 = stoi(row[0]);
int row_size = row.size();
if (roll1 == rollnum) {
count = 1;
row[index] = to_string(new_marks);
}
// Write the updated or existing data to the new file
for (i = 0; i < row_size - 1; i++) {
fout << row[i] << ", ";
}
fout << row[row_size - 1] << "\n";
}
if (count == 0)
cout << "Record not found\n";
fin.close();
fout.close();
// Rename the new file to the original file
remove("reportcard.csv");
rename("reportcardnew.csv", "reportcard.csv");
return 0; // Return 0 to indicate successful execution
}