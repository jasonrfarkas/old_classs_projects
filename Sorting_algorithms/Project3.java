/*
This code is written by Jason Farkas for the third assignment in Data Stuctures, spring 2015
There are 3 files that are part of this project: Project3.java, inSet.java and RandomNumbers.java
The first create sets of 5 sets of integers ( via inSet, and random integers generater via random numbers), 
and performs 5 differnt sorting methods to each set and prints to a file the amount of work done, along with some other information. 

selectionSort();
insertion sort
startQuickSort();
heapSort();
startIterativeQuickSort();

Before a new sorting algorthm is run the set is reset to it's original random order. 

*/
import javax.swing.*;
import java.util. *;
import java.io.PrintWriter;
import java.io.File;
import java.io.IOException;
/*
	class created by jason farkas: contains method main.
*/ 
public class Project3{
	/*
		public method main tries to write information to a file, and will print an error if it can't, 
		5 sets of random numbers, of various set sizes are created, and each of thier sort methods are called, 
		after each call information regarding the sorting is printed to a file, and then the set is reset.  
	*/
	public static void main(String[] args){

	try {
		File file = new File("Jason_Farkas_SortingMetrics.txt");  // open a file
		file.createNewFile();
      	PrintWriter out = new PrintWriter(file , "UTF-8"); // make a way to print to that file

      	//create sets of random numbers
		IntSet first = new IntSet(50);
		IntSet second = new IntSet(250);
		IntSet third = new IntSet(1000);
		IntSet fourth = new IntSet(2500);
		IntSet fifth = new IntSet(5000);

		//print first ten of random numbers generated - -
		out.println("The first ten numbers generated are: "+ first.getFirstTenUnsortedSetString()); 
		//print out all 50 of the first set in original order
		out.println("Random Numbers generated in first set are: " + first.getUnsortedSetString());
		// print out last 5 of each set in original order
		out.println("The last five of the first set are: " + first.getLastFiveUnsortedSetString());
		out.println("The last five of the second set are: " + second.getLastFiveUnsortedSetString());
		out.println("The last five of the third set are: " + third.getLastFiveUnsortedSetString());
		out.println("The last five of the fourth set are: " + fourth.getLastFiveUnsortedSetString());
		out.println("The last five of the fifth set are: " + fifth.getLastFiveUnsortedSetString());
		// perform sort on each set
		first.startIterativeQuickSort();
		second.startIterativeQuickSort();
		third.startIterativeQuickSort();
		fourth.startIterativeQuickSort();
		fifth.startIterativeQuickSort();
		//Print out the 50 integers from the first set after the algorithm sorts the integers of that set.
		out.println("Sorted first set is: " + first.getSortedSetString());
		// Print out the last 5 integers from each set after sorted
		out.println("The last five of the first set are: " + first.getLastFiveSortedSetString());
		out.println("The last five of the second set are: " + second.getLastFiveSortedSetString());
		out.println("The last five of the third set are: " + third.getLastFiveSortedSetString());
		out.println("The last five of the fourth set are: " + fourth.getLastFiveSortedSetString());
		out.println("The last five of the fifth set are: " + fifth.getLastFiveSortedSetString());
		// For each set of randomly generated integers, print out the amount of work the algorithm 
		out.println(first.getSortDetails());
		out.println(second.getSortDetails());
		out.println(third.getSortDetails());
		out.println(fourth.getSortDetails());
		out.println(fifth.getSortDetails());
		// Reset each set
		first.reSet();  
		second.reSet();
		third.reSet();
		fourth.reSet();
		fifth.reSet();

	// For the Selection Sort
		out.println("\n\n Sorting \n\n");
		
		first.selectionSort();
		second.selectionSort();
		third.selectionSort();
		fourth.selectionSort();
		fifth.selectionSort();
		//Print out the 50 integers from the first set after the algorithm sorts the integers of that set.
		out.println("Sorted first set is: " + first.getSortedSetString());
		// Print out the last 5 integers from each set after sorted
		out.println("The last five of the first set are: " + first.getLastFiveSortedSetString());
		out.println("The last five of the second set are: " + second.getLastFiveSortedSetString());
		out.println("The last five of the third set are: " + third.getLastFiveSortedSetString());
		out.println("The last five of the fourth set are: " + fourth.getLastFiveSortedSetString());
		out.println("The last five of the fifth set are: " + fifth.getLastFiveSortedSetString());
		// For each set of randomly generated integers, print out the amount of work the algorithm 
		out.println(first.getSortDetails());
		out.println(second.getSortDetails());
		out.println(third.getSortDetails());
		out.println(fourth.getSortDetails());
		out.println(fifth.getSortDetails());

		first.reSet();  // Reset each set
		second.reSet();
		third.reSet();
		fourth.reSet();
		fifth.reSet();

// For the insertions Sort
		out.println("\n\n Sorting \n\n");
		first.insertionSort();
		second.insertionSort();
		third.insertionSort();
		fourth.insertionSort();
		fifth.insertionSort();
		//Print out the 50 integers from the first set after the algorithm sorts the integers of that set.
		out.println("Sorted first set is: " + first.getSortedSetString());
		// Print out the last 5 integers from each set after sorted
		out.println("The last five of the first set are: " + first.getLastFiveSortedSetString());
		out.println("The last five of the second set are: " + second.getLastFiveSortedSetString());
		out.println("The last five of the third set are: " + third.getLastFiveSortedSetString());
		out.println("The last five of the fourth set are: " + fourth.getLastFiveSortedSetString());
		out.println("The last five of the fifth set are: " + fifth.getLastFiveSortedSetString());
		// For each set of randomly generated integers, print out the amount of work the algorithm 
		out.println(first.getSortDetails());
		out.println(second.getSortDetails());
		out.println(third.getSortDetails());
		out.println(fourth.getSortDetails());
		out.println(fifth.getSortDetails());

		first.reSet();  // Reset each set
		second.reSet();
		third.reSet();
		fourth.reSet();
		fifth.reSet();

		// For the Quick Sort
		out.println("\n\n Sorting \n\n");
		first.startQuickSort();
		second.startQuickSort();
		third.startQuickSort();
		fourth.startQuickSort();
		fifth.startQuickSort();
		//Print out the 50 integers from the first set after the algorithm sorts the integers of that set.
		out.println("Sorted first set is: " + first.getSortedSetString());
		// Print out the last 5 integers from each set after sorted
		out.println("The last five of the first set are: " + first.getLastFiveSortedSetString());
		out.println("The last five of the second set are: " + second.getLastFiveSortedSetString());
		out.println("The last five of the third set are: " + third.getLastFiveSortedSetString());
		out.println("The last five of the fourth set are: " + fourth.getLastFiveSortedSetString());
		out.println("The last five of the fifth set are: " + fifth.getLastFiveSortedSetString());
		// For each set of randomly generated integers, print out the amount of work the algorithm 
		out.println(first.getSortDetails());
		out.println(second.getSortDetails());
		out.println(third.getSortDetails());
		out.println(fourth.getSortDetails());
		out.println(fifth.getSortDetails());

		first.reSet();  // Reset each set
		second.reSet();
		third.reSet();
		fourth.reSet();
		fifth.reSet();

	// For the heap Sort
		out.println("\n\n Sorting \n\n");
		first.heapSort();
		second.heapSort();
		third.heapSort();
		fourth.heapSort();
		fifth.heapSort();
		//Print out the 50 integers from the first set after the algorithm sorts the integers of that set.
		out.println("Sorted first set is: " + first.getSortedSetString());
		// Print out the last 5 integers from each set after sorted
		out.println("The last five of the first set are: " + first.getLastFiveSortedSetString());
		out.println("The last five of the second set are: " + second.getLastFiveSortedSetString());
		out.println("The last five of the third set are: " + third.getLastFiveSortedSetString());
		out.println("The last five of the fourth set are: " + fourth.getLastFiveSortedSetString());
		out.println("The last five of the fifth set are: " + fifth.getLastFiveSortedSetString());
		// For each set of randomly generated integers, print out the amount of work the algorithm 
		out.println(first.getSortDetails());
		out.println(second.getSortDetails());
		out.println(third.getSortDetails());
		out.println(fourth.getSortDetails());
		out.println(fifth.getSortDetails());

		first.reSet();  // Reset each set
		second.reSet();
		third.reSet();
		fourth.reSet();
		fifth.reSet();

		out.println("\n\n");
		out.close();
		System.out.println("Printed Sorting Matrics to file");

		}// end try
	 catch (Exception ex)  
	    {
	    	System.out.println(ex);
	    	System.out.println("Could not print to file: ");
	    }

	} // end main
}// end project 3


