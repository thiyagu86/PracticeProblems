#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gradingStudents' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY grades as parameter.
 */

vector<int> gradingStudents(vector<int> grades) {
    int nSize = grades.size();
    //cout << "Printing nSize" << nSize << endl;
    vector<int> resVect;
    int nRes;   
    for(int n = 0;n< nSize;n++)
    {
        if(grades.at(n) < 38)
        {
            nRes = grades.at(n);
            cout << "Printing nRes at condition: 1 less than 38" << nRes << endl;
        }
        else if(grades.at(n) >= 38 )
        {
            if((grades.at(n)%5) > 2)
            {
                nRes = grades.at(n) + 5-(grades.at(n)%5);
            }
            else
            {
                nRes = grades.at(n);
            }
            //cout << "input: grades.at("<< n << ") is: " << grades.at(n) << endl;
            //cout << "Values: " << grades.at(n)%5 << endl;
            //cout << "Printing nRes at condition:2 Greater than 38 and needs rounding off" << nRes << endl;
            //resVect.push_back(grades.at(0) + 5-(grades.at(0)%5));
        }
        resVect.push_back(nRes);
    }
    //cout << "Inside func value of vec is: " << resVect.size() << endl;
    //for(auto i: resVect)
        //cout << i << endl;
    return resVect;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string grades_count_temp;
    getline(cin, grades_count_temp);

    int grades_count = stoi(ltrim(rtrim(grades_count_temp)));

    vector<int> grades(grades_count);

    for (int i = 0; i < grades_count; i++) {
        string grades_item_temp;
        getline(cin, grades_item_temp);

        int grades_item = stoi(ltrim(rtrim(grades_item_temp)));

        grades[i] = grades_item;
    }

    vector<int> result = gradingStudents(grades);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
