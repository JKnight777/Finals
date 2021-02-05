/*
  Made by: Justice Pankey-Thompson
  ID: 2529360
  Algorithm: Works like the previous final part, but this time, it has functions called alphabatize, Processing Student, selectStudent, and printing student tables. Alphabatize uses bubble swaps to change the elements of the vector in alphabetical order by using their string vals. Processing student calculates each student's GPA and course credits. Printing Student Tables formats and sends out the table of students both alphabatized, and nonalphabatized. selectStudent prompts the user to enter a student name, and then uses that name to find the student in the list. If it is in the list, it gives specific information on it, but if not, it tells the user that it failed. By adding and using these new functions, I was able to complete the added ojectives my program needed to accomplish.
*/

#include <string> 
#include <iostream> 
#include <fstream>
#include <iomanip>
#include <vector>

#define CAP 20

using namespace std; 

struct Student { 
  string studentname = "null";
  string studentID = "null";

  int numcourses = -1;
  int totcredits = 0;
  int compcredits = 0;

  double erncredits = 0.0;
  double gpa = -1;

  vector<string> classes;
  vector<int> credits; 
  vector<char> grades;
};


bool openFile(ifstream &inFS) {
  if (inFS.is_open()) {
    return true;
  }
  return false;
}

void Print_info_one(Student student) {
  cout << fixed << left << setw(24) << "Name :" << right << student.studentname << endl;

  cout << fixed << left << setw(24) << "Id Number :" << right << student.studentID << endl;

  cout << endl;

  cout << fixed << left << setw(24) << "Course Name" << setw(10)<< "Grade" << setw(10) << "units" << endl;

  for (int i = 0; i < student.numcourses; ++i) {
    cout << fixed << left << setw(25) << student.classes.at(i)<< setw(10) << student.grades.at(i) << setw(10) << student.credits.at(i) << endl;
  }

  cout << endl;

  cout << fixed << left << setw(24) << "Units Completed:" << right << static_cast<int>(student.compcredits) << endl;

  cout << fixed << left << setw(24) << "Units Taken:" << right << student.totcredits << endl;

  cout << fixed << left << setw(24) << "GPA:" << right << setprecision(2) << student.gpa << endl;
} 

void Read_info(Student &student, ifstream &inFS) {
  getline(inFS, student.studentname);

  getline(inFS, student.studentID);

  inFS >> student.numcourses;
  inFS.ignore(1000, '\n');

  
  vector<string> cls(student.numcourses);
  vector<int> cred(student.numcourses);
  vector<char> grd(student.numcourses);

  for (int i = 0; i < student.numcourses; ++i) {
    getline(inFS, cls.at(i));
    inFS >> grd.at(i);
    inFS >> cred.at(i);
    inFS.ignore(1000, '\n');
  }
  student.classes = cls;
  student.credits = cred;
  student.grades = grd;
} 
float Find_points(char curr) {

  if (curr == 'A' || curr == 'a') {
    return 4;
  }
  if (curr == 'B' || curr == 'b') {
    return 3;
  }
  if (curr == 'C' || curr == 'c') {
    return 2;
  }
  if (curr == 'D' || curr == 'd') {
    return 1;
  }
  return 0;
} // given a letter grade returns points associated to it
// include any additional functions you like.
void Process_Stu(Student &student) {
  for (int i = 0; i < student.numcourses; ++i) {

    student.totcredits += student.credits.at(i);

    if (Find_points(student.grades.at(i)) > 1){

      student.compcredits += student.credits.at(i);

    }

    student.erncredits += (student.credits.at(i) * Find_points(student.grades.at(i)));
  }

  student.gpa = student.erncredits / student.totcredits;
}

void printStudentTable(Student student) {
  cout << fixed << left << setw(25) << student.studentname << setw(20) << student.compcredits << setprecision(3) << student.gpa << endl;
}

void alphabatize(vector<Student> &stuList){
  cout << endl;
  int size = stuList.size();
  Student  temp;
  bool b;
  do{
    b = false;
    size--;
    for(int i = 0; i < size; i++) {
      if(stuList[i].studentname > stuList[i+1].studentname){
        temp = stuList[i];
        stuList[i] = stuList[i+1];
        stuList[i+1] = temp;
        b = true;
        
      }
    }
  }while(b);  
}

void selectStudent(vector<Student> &stuList){
  string target;

  getline(cin, target);

  int test = -1;

  for (int i = 0; i < stuList.size(); i++){
    if (stuList.at(i).studentname.compare(target) == 0) {
      test = i;
    }
  }

  if (test == -1) {
    cout << target << " is not on the list." << endl;
  }

  else {
    Print_info_one(stuList.at(test)); 
    cout << endl;
  }
}
int main() 
{ 

  string filename;

  int i = 1;

  vector<Student> stuList(CAP);

  cin >> filename;
  ifstream inFS;

  inFS.open(filename);

  if (!openFile(inFS)) {
    cout << "Bad file." << endl;
    return -1;
  }

  if (inFS.peek() == EOF){
    cout << "No data to process." << endl;
    return -1;
  }
  
  while (inFS.peek() != EOF) {
    Read_info(stuList.at(i - 1), inFS);
    Process_Stu(stuList.at(i -1));

    i++;
  }

  cout << fixed << setw(25) << left << "Name" << right << "Units Completed     GPA" << endl;

  for (int j = 0; j < i - 1; j++) {
    printStudentTable(stuList.at(j));
  }

  cout << endl;

  cin.ignore(1000, '\n');

  selectStudent(stuList);

  selectStudent(stuList);

  alphabatize(stuList);

  cout << fixed << setw(25) << left << "Name" << right << "Units Completed     GPA" << endl;

  for (int j = 0; j < i - 1; j++) {
    printStudentTable(stuList.at(j));
  }
  return 0;
}