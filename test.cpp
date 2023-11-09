#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void read_record()
{
    // File pointer
    ifstream fin;

    // បើកហ្វាល់ដែលបានបង្កើតហើយ
    fin.open("reportcard.csv");

    // យកលេខរៀង
    int rollnum;
    cout << "Enter the roll number of the student to display details: ";
    cin >> rollnum;

    // អានដែលតាដែលចេញពីហ្វាល់
    // as String Vector
    vector<string> row;
    string line, word;

    while (getline(fin, line))
    {
        row.clear();

        // ប្រើសម្រាប់បំបែកពាក្យ(ដកឃ្លា​ ចន្លោះ)
        stringstream s(line);

        // ​អានគ្រប់ជួរនៃលេខរៀងដែលទទួលបានហើយទុកវាក្នុង string variable ដែលជា word
        while (getline(s, word, ','))
        {
            //បន្ថែមជួរតាមដែលតានីមួយៗតាមទៅកាន់vector
            row.push_back(word);
        }

        // convert string to integer សម្រាប់ប្រៀបធៀប
        int roll2 = stoi(row[0]);

        // ប្រៀបធៀបលេខរៀងនិងជួរ
        if (roll2 == rollnum)
        {
            // Print ព័ត៌មានដែលទទួលបាន
            cout << "Details of Roll " << row[0] << ":\n";
            cout << "Name: " << row[1] << "\n";
            cout << "Maths: " << row[2] << "\n";
            cout << "Physics: " << row[3] << "\n";
            cout << "Chemistry: " << row[4] << "\n";
            cout << "Biology: " << row[5] << "\n";
            return;
        }
    }

    cout << "Record not found\n";
}

void create()
{
    // file pointer
    ofstream fout;

    //បើកហ្វាល់​​ cvs ដែលមានហើយឫបង្កើតថ្មីប្រសិនបើគ្មាន
    fout.open("reportcard.csv");

    cout << "Enter the details of 5 students: (roll name maths phy chem bio)" << endl;

    int roll, phy, chem, math, bio;
    string name;

    // Read the input
    for (int i = 0; i < 5; i++)
    {
        cin >> roll >> name >> math >> phy >> chem >> bio;

        // បញ្ចូលដែលតាទៅកាន់ហ្វាល់
        fout << roll << "," << name << "," << math << "," << phy << "," << chem << "," << bio << "\n";
    }

    fout.close();
}

int main()
{
    create();
    read_record();
    return 0;
}