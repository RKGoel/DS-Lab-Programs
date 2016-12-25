import java.io.*;
import java.util.*;

public class QuickSort
{

	static int count = 0;
	 public static void main(String args[]) throws IOException
	  {
		  int i, size, choice, lower, upper;
		  
		  InputStreamReader read = new InputStreamReader(System.in);
		  BufferedReader in = new BufferedReader(read);
		  
		  
		  System.out.println("Enter no. of elements: ");
		  size= Integer.parseInt(in.readLine());
		  
		  int array[] = new int[size];
		  
		  System.out.println("1. Manual Entry\n2. Auto Entry\n0. Exit\nEnter your choice: ");
		  choice = Integer.parseInt(in.readLine());
		  
		  switch(choice)
		  {
		  case 1: System.out.println("Enter the array: ");
		  for(i=0; i<size; i++)
		  {
			  array[i] = Integer.parseInt(in.readLine());
		  }
		  break;

		  case 2: System.out.println("Enter range of numbers to be taken(lower and upper bounds): ");
			lower = Integer.parseInt(in.readLine());
			upper = Integer.parseInt(in.readLine());
			Random rand = new Random();
			for(i=0; i<size; i++){
				array[i] = lower + rand.nextInt(upper-lower+1);
			}
			break;
			
			case 0: System.exit(0);
			
			}
			
		  System.out.println("Values Before the sort:\n");
		  for(i = 0; i < size; i++)
		  System.out.print( array[i]+"  ");
		  System.out.println();
		  
		  if(size>0)
		  quick_srt(array,0,size-1);
		  
		  System.out.print("Values after the sort:\n");
		  for(i = 0; i < size; i++)
		  System.out.print(array[i]+"  ");
		  System.out.println("\nNo. of Comparisons= " +count);
	  }

	  public static void quick_srt(int array[],int beg, int end){
	  int lo = beg;
	  int hi = end;
	  if (lo >= hi) {
		  return;
	  }
	  do{
		  
		  while (lo<hi && array[lo] <= array[hi]) {
			  hi--;
			  count++;
		  }
			  if(lo<hi)
			  {
				  int T = array[lo];
				  array[lo] = array[hi];
				  array[hi] = T;
			  };
			  while(lo<hi && array[hi] >= array[lo]){
				  lo++;
				  count++;
			  }
			  if(lo<hi)
			  {
				  int T = array[lo];
				  array[lo] = array[hi];
				  array[hi] = T;
			  }
	  }while (lo < hi && array[lo] != array[hi]) ;
	  quick_srt(array, beg, lo-1);
	  quick_srt(array, lo+1 , end);
	  
	  
	  }
}
