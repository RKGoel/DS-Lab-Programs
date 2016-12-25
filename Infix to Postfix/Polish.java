import java.io.*;
import java.util.*;

class Stack{

	private char arr[] = new char[100];
	private int top;
	
	Stack(){
		top = -1;
	}
	
	public void Push(char a){
	if (top == 100){
	System.out.println("Overflow");
	return;
	}
	
	top = top+1;
	arr[top] = a;
	//System.out.println("Pushed: "+arr[top]);
	}
	
	public char Pop(){
	if(top == -1){
	System.out.println("Underflow");
	return(' ');
	}
	else{
	//System.out.println("Poped: "+arr[top]);
	return(arr[top--]);
	}
	}
	
	}
	
public class Polish{

	public static void main(String args[]) throws IOException{
	
		InputStreamReader read = new InputStreamReader(System.in);
		BufferedReader in = new BufferedReader(read);
		Scanner sc = new Scanner(System.in);
		
		char exp[] = new char[100];
		char temp = ' ';
		int j=0;
		Stack stk = new Stack();
		
		
		System.out.println("Enter the expression: ");
		char[] ex = sc.next().toCharArray();
		for( j=0; j<ex.length; j++)
		exp[j] = ex[j];
		exp[j] = ')';
		j++;
		//System.out.print(j);
	
		stk.Push('(');
		
		for(int i=0; i< j; i++){
			//System.out.print("Hi");
			if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^'){
				if(exp[i] == '+' || exp[i] == '-'){
					temp = stk.Pop();
					while(temp!='('){
					System.out.print(temp);
					temp = stk.Pop();
					}
					}
				else if(exp[i] == '*' || exp[i] == '/'){
					temp = stk.Pop();
					while(temp!='(' && (temp == '^' || temp == '*' || temp == '/')){
					System.out.print(temp);
					temp = stk.Pop();
					}
					if(temp!='(' && (temp=='+' || temp=='-'))
						stk.Push(temp);
					}
				else{
					temp = stk.Pop();
					while(temp!='(' && temp =='^'){
					System.out.print(temp);
					temp = stk.Pop();
					}
					if(temp!='(' && temp!='^')
					stk.Push(temp);
					}
			if(temp == '(')
			stk.Push(temp);
			//System.out.println(exp[i]);
			stk.Push(exp[i]);
			
			}
		
		else if(exp[i] == '(')
		stk.Push(exp[i]);
		
		else if(exp[i] == ')'){
			temp = stk.Pop();
			while(temp!='('){
			System.out.print(temp);
			temp = stk.Pop();
			}
			}
		else
		System.out.print(exp[i]);
		}
	}
}