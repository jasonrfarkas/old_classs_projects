/*
Class created by Jason Farkas

This class has a random number generator which is uses to generate numbers in the set
It keeps track of the original set in an array, and provides the ability to sort the set by keeping a version of the set for sorting
It keeps track if the set isSort via boolean, 
and it keeps track of the number of comparisons and exchanges, and the overal size and type of sort performed. 
There is also an int N for referance in the heap sort

There are two constructors, one that takes a size for the set, one that defaults it at 5000, 
There is a getsize method, and a isSorted method

There are also a number of fuctions to return strings that are helpful for printing out infomation regarding the ints in the set, or sorting details.
getSortDetails(), getSortedSetString(),getUnsortedSetString(),getFirstTenUnsortedSetString(),getLastFiveUnsortedSetString(),getLastFiveSortedSetString()

There is a reSet function which sets the sortedSet array values to the order of the original array values and reset sorting details,  - thus the set is randomized again


There is then a selectiom, insert, heap, quick recurisive, and quick iterative sort. Some have helping functions.



*/


public class IntSet {

  private RandomNumbers rndGen;
  private static int DEFAULTCAPACITY= 5000;
  private int[] originalSet;
  private int[] sortedSet;
  private boolean isSorted;
  private int comparisonCount;
  private int exchangesCount;
  private int size;
  private String sortType;
  private int N;

//constructors
  public IntSet(int c)
  {
    rndGen = new RandomNumbers(); // create a random number generation
    originalSet = new int[c]; // create a set of the indicated size
    sortedSet = new int[c]; 
    for(int i=0; i< c; i++){ //generate random numbers and store them in the arrays
      originalSet[i]=rndGen.getNextRandomNumber();
      sortedSet[i]=originalSet[i];
    }
    size = c;
    isSorted= false;
    comparisonCount=0;
    exchangesCount =0;
    sortType = "";

  }

  // default constructor
  public IntSet(){
    this(DEFAULTCAPACITY);
  }

// get/set methods
  public int getSize()
  {
    return size;
  }
  public boolean isSorted(){
    return isSorted;
  }

  //print methods
  public String getSortDetails(){
    String sa = "";
    if(isSorted){
      sa+= "Set of size" + size +  " Sorted via " + sortType + ". " + comparisonCount + " comparisons counted, and " + exchangesCount + " exchanges counted. Work total calculated at " + (comparisonCount+exchangesCount*3) + "." ; 
    }
    else{
      sa= "Array is not sorted";
    }
    return sa;
  }

  public String getSortedSetString(){
    String sa = "";
    if(isSorted){
      for(int i=0; i<size; i++){
        sa += sortedSet[i] + ", ";
      }
    }
    else{
      sa= "Array is not sorted";
    }
    return sa;
  }

  public String getUnsortedSetString(){
    String sa = "";
    for(int i=0; i<size; i++){
       sa += originalSet[i] + ", " ; 
    }
    return sa;
  }

   public String getFirstTenUnsortedSetString(){
    String sa = "";
    for(int i=0; i<10; i++){
       sa += originalSet[i] + ", " ; 
    }
    return sa;
  }

  public String getLastFiveUnsortedSetString(){
     String sa = "";
    for(int i=size-5; i<size; i++){
       sa += originalSet[i] + ", " ; 
    }
    return sa;
  }

  public String getLastFiveSortedSetString(){
    String sa = "";
    if(isSorted){
      for(int i=size-5; i<size; i++){
        sa += sortedSet[i] + ", ";
      }
    }
    else{
      sa= "Array is not sorted";
    }
    return sa;
  }

//reset method
  public void reSet(){
    for(int i=0; i< size; i++){
      sortedSet[i]=originalSet[i];
    }
    isSorted= false;
    comparisonCount=0;
    exchangesCount =0;
    sortType = "";
  }

// Sorter Methods
  //helper swap method
  public void swap(int arr[], int i, int j)
  {
      int tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp; 
      exchangesCount++; 
  } 
  //slection sort
  public void selectionSort() { 
   int i, j, maxIndex, tmp;
          for (i = size-1; i >= 1; i--) {
                maxIndex = i;
                for (j = i - 1; j >= 0; j--){
                      if (sortedSet[j] > sortedSet[maxIndex])
                            maxIndex = j;
                      comparisonCount++;
                      //System.out.println(" i: " + i+  " j: "+ j+  " max: " + maxIndex);
                }
                if (maxIndex != i) {      
                      swap(sortedSet, i, maxIndex);
                      //tmp = sortedSet[i];
                      //sortedSet[i] = sortedSet[maxIndex];
                     // sortedSet[maxIndex] = tmp;
                      //exchangesCount++;
                } comparisonCount++;
          }
          isSorted= true;
          sortType = "Selection Sort";
  }

  // insertion sort 
  public void insertionSort()
  {
        int j;  // the number of items sorted so far
        int key;  // the item to be inserted
        int i;  
       for(j = 1; j < size; j++)    // Start with 1 (not 0)
      {
             key = sortedSet[j];
             for( i = j - 1; (i >= 0) && (sortedSet[i] > key); i--)   // Smaller values are moving up
            {
                if(sortedSet[i] > key){
                   sortedSet[i+1] = sortedSet[i];
                   exchangesCount++;
                   comparisonCount++;
                }
                else{
                  comparisonCount++;
                  break;
                }
            }
           sortedSet[i+1] = key;    // Put the key in its proper location
           exchangesCount++;
       }
       isSorted= true;
       sortType = "Insertion Sort";
  }

 

// heap sort
     public void heapSort()
    {       
        heapify(sortedSet);        //turn the array into a proper max heap, now most of the chilren are lower then the parents, it is semi sorted
        for (int i = N; i > 0; i--) // start from the last internal node and go to the rood backwords breathwize, we want to finish sorting it 
        {
            swap(sortedSet,0, i); // switch the parent at i with the top of the stack
            N = N-1; // dont deal with the end of the heap which is sorted already
            maxheap(sortedSet, 0); // downheap the top of the stack until it is the max of it's own stack
        }
         isSorted= true;
         sortType = "Heap Sort";
    }    

    // This goes through the first half of the array, treating them as parents of the heap, and making sure they are the max of their heap, 
    // if they are not, switch them with their children to make them the max of their heap, 
    public void heapify(int arr[])
    {
        N = arr.length-1;
        for (int i = N/2; i >= 0; i--)
            maxheap(arr, i);        
    }
    // This function looks at three values, representing the parent and two children and make sure the parent has the max value, 
    // It 'places' a value into the heap, at a location where it is the greatest of its subheap 
    public void maxheap(int arr[], int i)
    { 
        int left = 2*i ; // this assumes the position where the left node would be stored in the array representation of a binary tree
        int right = 2*i + 1;// this assumes the position where the right node would be stored in the array representation of a binary tree
        int max = i; 
        if (left <= N && arr[left] > arr[i]){ // if left is within the array, and the int in that position is greater than the int at the inital position
            max = left;  // then the max value of the three considered is the position at the assumed left location
        } comparisonCount++;
        if (right <= N && arr[right] > arr[max]){ // checks if the right child is greater than the left child and parent 
            max = right;
        } comparisonCount++;
        if (max != i) // if one of the children has the max value
        {
            swap(arr, i, max); // place the child in the parent position
            maxheap(arr, max); // make sure the initial position is at the top of it's heap, aka max of where its children would be 
        }
    }    


 // Quick sort recursive
  public void startQuickSort(){
    quickSortInPlace(sortedSet, 0, size-1);
    isSorted= true;
    sortType = "Recursive QuickSort";
  }
  // the following function calls itself multiple times and always provides itself with the range on which it works, leftside, rightside
  /*
    This functions sets a pivot at the right end, and scan on the left side until it finds a number >= the pivot, it then scans from the right side to find a number <= pivot
    it then flips the numbers so that the <= number is on the left, and the >= is on the right, it then repeats until the left marker is further to the right then the right marker
    this indicates that what the left marker points to will be >= the pivot(rightmost side),
    now we switch the comparison number we set asside with the number at this location, so that everything to the right of the location is greater then that number, and to the left is lower, 
    and we call the function again on the subarrays of the left and right sides, without the middle location. 
  */
  private void quickSortInPlace(int[] S, int a, int b) {
    if (a >= b){  // if the leftsize is to the right of the right side the range is invalid
      return;
    } // end if
    int left = a;
    int right = b-1;
    int pivot = S[b];// select the pivot to be the rightmost position in the array
    int temp;

    while (left <= right) {
      // subarray is trivially sorted
      // scan until reaching value equal or larger than pivot (or right marker)
      while (left <= right){ // I don't combine it with the if so that I can count the proper # of comparisons
        comparisonCount++; // for the following comparision
        if (S[left]< pivot){
          left++; 
        }
        else{
          break;
        }
      } // end inner while 1
      // scan until reaching value equal or smaller than pivot (or left marker)
      while (left <= right ){
        comparisonCount++; // for the following comparision
        if(S[right]> pivot ){
          right--;
        }
        else{
          break;
        }
      } // end innerwhile 2

    if (left <= right) { // indices did not strictly cross
      // so swap values and shrink range
      swap(S,left,right);
      left++;
      right--;
      } // end if
      comparisonCount++; // for the if statement
    } /// end outer while
    // put pivot into its final place (currently marked by left index)
    swap(S,left,b);
    // make recursive calls
    quickSortInPlace(S, a, left - 1);
    quickSortInPlace(S, left + 1, b);
  } // end method

//extra credit, iterative quick sort, 
  /*
    There is a starter method, a helper partion method, and a method that keeps track of what needs to be sorted

  */

public void startIterativeQuickSort(){
  quickSortIterative( sortedSet, 0, size- 1 );
  isSorted= true;
  sortType = "IterativeQuickSort ";
}

/*
  This type of parition works a bit different then the last version
  it keeps track of the leftside of the subarray where all numbers are lessthan the value of the value used for comparison called x, 
  so that when scanning from left to right and it finds a value less than x it will take that value and switch it with the next value, that is not itself, 
  that is > x as indicated by the fact that i points to it


  A[] --> Array to be sorted, l  --> Starting index, h  --> Ending index 
*/
private int partition (int arr[], int l, int h)
{
    int x = arr[h]; // set the value of the righthand position to be the value for comparision
    int i = (l - 1);
    // the loop goes along the array from right to left,
    for (int j = l; j <= h- 1; j++)
    {
        comparisonCount++;// for the following
        if (arr[j] <= x)  // if the current value is <= to the comparison value then switch it with something > the comparison value
        {
            i++; 
            if(i!=j){ // don't perform a swap on itself
              swap (arr, i, j); 
            }
        }
    }
    swap (arr, i + 1, h); //swich the comparison value with the first value from the left that is > than it.
    return (i + 1); // return the location which has been sorted
}
 
/* 
  A[] --> Array to be sorted, l  --> Starting index, h  --> Ending index 
  This function keeps track of which values were sorted through an array that works as a stack via a top pointer, 
  it calls the parition method with values from the array and propogates values to the stack based on the location of 
  the pivot recieved until the pivot values are at the ends of the original array
*/
private void quickSortIterative (int arr[], int l, int h)
{
    // Create an auxiliary stack
    int[] stack = new int[ h - l + 1 ];
    // initialize top of stack
    int top = -1;
    // push initial values of l and h to stack
    stack[ ++top ] = l;
    stack[ ++top ] = h;
    // Keep popping from stack while is not empty
    while ( top >= 0 )
    {
        // Pop h and l
        h = stack[ top-- ];
        l = stack[ top-- ];
        // Set pivot element at its correct position in sorted array
        int p = partition( arr, l, h );
        // If there are elements on left side of pivot, then push left
        // side to stack
        if ( p-1 > l )
        {
            stack[ ++top ] = l;
            stack[ ++top ] = p - 1;
        }
        // If there are elements on right side of pivot, then push right
        // side to stack
        if ( p+1 < h )
        {
            stack[ ++top ] = p + 1;
            stack[ ++top ] = h;
        }
    }
}

}// end class
