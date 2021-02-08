#include <iostream>
#include <stack>
using namespace std;

/*
Use a stack to evaluate the following expression in postfix notation.
5247*+7-

*/

int main() {
  stack<int> post_fix;
  string expression = "524*+7-";
  int operand1, operand2;

  //iterates through string
  for(int i = 0; i < expression.length(); i++){
    //isdigit() takes a char and checks if it is a digit
    if(isdigit(expression[i])){
      //if it is a digit pushes unto stack using string to int
      //stoi() and pushes the substring to stack.
      post_fix.push(stoi(expression.substr(i,1)));
    }else{
      //if it is not a digit it takes the last digits pushed into
      //the stack assigns it to two operand variables and pops them
      //from the stack.
      operand1 = post_fix.top();
      post_fix.pop();
      operand2 = post_fix.top();
      post_fix.pop();
      switch(expression[i]){
        //the uses the switch statement to complete operation
        // depending on the operand.
        case '+':
          post_fix.push(operand1 + operand2);
          break;
        case '-':
          post_fix.push(operand2 - operand1);
          break;
        case '*':
          post_fix.push(operand1 * operand2);
          break;
        case '/':
          post_fix.push(operand2 / operand1);
          break;
        
      }
    }
  }
  cout << "The answer to " << expression << endl;
  cout << " is " << post_fix.top() << endl;
}