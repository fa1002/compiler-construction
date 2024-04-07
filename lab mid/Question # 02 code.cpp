#include <iostream>
#include <stdlib.h>
using namespace std;


int count = 0; 
string expr;  


void S();      
void X();      
void Xp();   
void Y();     
void Yp();     
void Z();      

int main() {
  
  cin >> expr;
  
  expr += "$";

  
  S();

  
  if (expr.length() == count) {
    cout << "Accepted" << endl;
  } else {
    cout << "Rejected" << endl;
  }

  cin.get(); 
}


void S() {
  cout << "S->X$" << endl;
  X();
  if (expr[count] == '$') {
    count++;
  } else {
    cout << "Rejected" << endl;
    exit(0);
  }
}


void X() {
  cout << "X->YX'" << endl;
  Y();
  Xp();
}


void Xp() {
  if (expr[count] == '%') {
    count++;
    cout << "X'->%YX'" << endl;
    Y();
    Xp();
  } else {
    cout << "X'->e" << endl;
  }
}


void Y() {
  cout << "Y->ZY'" << endl;
  Z();
  Yp();
}


void Yp() {
  if (expr[count] == '&') {
    count++;
    cout << "Y'->&ZY'" << endl;
    Z();
    Yp();
  } else {
    cout << "Y'->e" << endl;
  }
}


void Z() {
  if (expr[count] == 'k') {
    count++;
    cout << "Z->kXk" << endl;
    X();
    if (expr[count] == 'k') {
      count++;
    } else {
      cout << "Rejected" << endl;
      exit(0);
    }
  } else if (expr[count] == 'g') {
    count++;
    cout << "Z->g" << endl;
    return;
  } 
}
