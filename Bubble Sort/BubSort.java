/**
 * Program to analyse Bubble Sort algorithm by plotting a graph
 */
import java.io.*;
import java.util.*;
import java.lang.*;
/**
 * @author Rajat
 *
 */
public class BubSort {

	public static void main(String[] args) throws IOException{
		
		int num, finalcomp, i, choice, lower, upper;
		
		InputStreamReader read = new InputStreamReader(System.in);
		BufferedReader in = new BufferedReader(read);
		
		System.out.println("Enter no. of numbers in the list");
		num = Integer.parseInt(in.readLine());
		int list[] = new int[num];
		
		System.out.println("1. Enter numbers manually\n2. Enter numbers automatically\nEnter your choice: ");
		choice = Integer.parseInt(in.readLine());
		
		switch(choice){
			case 1: System.out.println("Enter "+num+" numbers: ");
			for(i=0; i<num; i++){
				list[i] = Integer.parseInt(in.readLine());
			}
			finalcomp = Bubble(list, num);
			System.out.println("Total number of comparisons= "+finalcomp);
			break;
			
			case 2: System.out.println("Enter range of numbers to be taken(lower and upper bounds): ");
			lower = Integer.parseInt(in.readLine());
			upper = Integer.parseInt(in.readLine());
			Random rand = new Random();
			for(i=0; i<num; i++){
				list[i] = lower + rand.nextInt(upper-lower+1);
			}
			finalcomp = Bubble(list, num);
			System.out.println("Total number of comparisons= "+finalcomp);
			break;
			
			default: System.out.println("Incorrect choice!!");
		}
		

	}
	
	public static int Bubble(int[] arr, int size){
		int temp, i=1, comparison=0;
		do{
			for(int j=0; j<size-i; j++, comparison++){
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
			}
			if(size<=100){
				printarr(arr, size);
				System.out.println("No. of cumulative comparisons: "+comparison);
				System.out.println("");
			}
			i++;
				
		}while(i<size);
		
		return(comparison);
	}
	
	public static void printarr(int[] arr, int size){
		int i;
		for(i=0; i<size-1; i++){
			System.out.print(arr[i]+", ");
		}
		System.out.print(arr[i]);
		System.out.println("");
	}

}
