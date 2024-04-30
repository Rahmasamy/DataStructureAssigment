#include <iostream>
#include <cstdlib>
#include<string>
//////////////////////////problem 3//////////////////////////////////////////
using namespace std;
/* name of groups rahma samy mohamed 20198035
doha khaled 20198126
mahmoud samy razek 20198075*/
template < class T>
class Stack{

	   T *arr ;
	   int top;
       int size;


public:
	Stack(){
	  size=0;
	  top=-1;
	}

	Stack(int realsize){
	    size=realsize;
        arr = new T[realsize];
        top = -1;

	   }
    void sets( T*arr2){
       for (int i=0;i<size;i++)
            arr[i]=arr2[i];
    }
    T gets(){
        return *arr;
    }


	~Stack(){
	   delete[]arr;

	}
	void push(T value ){
	/*  if (isfull())
    {
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    } */

    cout << "Inserting " << value << endl;
    arr[++top] = value;
	}
	T& pop(){
		/*if (isempty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    } */
        cout << "Removing " << topvalue() << endl;
         return arr[top--];
    }
	T& topvalue(){
    if (!isempty()) {
        return arr[top];
    }
    else {
        exit(EXIT_FAILURE);
    }

    }

	int sizestack(){
	  return top + 1; //if there is one element so the top will be 0 and the size will be one

	}
	bool isempty(){
	  return top == -1;  //if top==-1 return true else return false
	}
	bool isfull(){   return top == size - 1; }  //if top==size-1 return true else return false
    T& findtop(){ return top;}
};
void balanceparentheses()
{
    Stack<char> st;
    string s;
    cout << "Enter string parentheses:";
    cin >> s;

    int notice = 0;

    for (int i = 0; i < s.length(); i++)
    //length of the string calculated by number of letters
    {
    if (s[i] == '{' || s[i] == '[' || s[i] == '('||s[i]=='/*') {
            //push function to enter terms in a stack
            st.push(s[i]);
            notice = 1;
        }
    if (!st.isempty()) {
      if (s[i] == '}') {
        if (st.topvalue() == '{')
                // top of the stack
                {
                    st.pop();
                    //pop function to delete terms from the top of array
                    continue;
                }
                else
                    break;
            }
       if (s[i] == ']') {
         if (st.topvalue() == '[') {
            st.pop();
              continue;
            }
        else
           break;
        }
        if (s[i] == ')') {
           if (st.topvalue() == '(') {
                st.pop();
                continue;
            }
            else
                break;
            }

         if (s[i] == '*/') {
           if (st.topvalue() == '/*') {
                 st.pop();
                 continue;
            }
            else
                break;
            }
        }
        else {
            break;
        }
    }

    if ((st.isempty()) && (notice == 1))
        cout << "----------------valid--------------------------" << endl;
    else
        cout << "----------------NOn valid---------------------- " << endl;
}

int main()
{

    Stack<int> s(3);

    s.push(1);
    s.push(2);

    s.pop();
    s.pop();

    s.push(3);

    cout << "The top element is " << s.topvalue() << endl;
     cout << "The top value is " << s.findtop() << endl;
    cout << "The stack size is " << s.sizestack() << endl;

    s.pop();

    if (s.isempty()) {
        cout << "The stack is empty\n";
    }
    else {
        cout << "The stack is not empty\n";
    }

   cout << "-------------------------------------------------"<<endl;
////////////////////////////////////////problem 4///////////////////////////////
//Code to test the function Are Paranthese Balanced
    int counter;
    cout << "Enter number of test cases:";
    cin >> counter;

    for (int i = 0; i < counter; i++) {
        //calling of function for checking of brackets
        balanceparentheses();
    }



    return 0;
}
