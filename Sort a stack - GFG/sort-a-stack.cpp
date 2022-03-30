// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

void position(stack<int> &st, int num){
    if( st.size() == 0 || st.top() <= num){
        st.push(num);
    }
    else{
        int temp_top = st.top();
        st.pop();
        position(st, num);
        st.push(temp_top);
    }
}

void recur(stack<int> &st){
    if(st.size() == 0){
        return;
    }
    int top = st.top();
    st.pop();
    recur(st);
    position(st, top);
    // if(st.size() > 0){
    // }
    // return;
}

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
   //Your code here
   recur(s);
}