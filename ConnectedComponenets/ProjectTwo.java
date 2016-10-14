/*

Write a program that takes as input a fully parenthesized, arithmetic expression and converts it to
a binary expression tree, as shown in section 8.2 of the course textbook. Your program should
display the tree in some way and also print the value associated with the root. For an additional
challenge, allow the leaves to store variables of the form x1, x2, x3, and so on, which are initially
0 and which can be updated interactively by your program, with the corresponding update in the
printed value of the root of the expression tree.


You must implement the Tree data structure as given in the course textbook as well as any other
data structures you may use in your program, such as: linked lists, stacks, queues, deques, lists,
and positional lists, instead of the built in version of these data structures in the Java Collections
Framework.



/*
 * @author JasonFarkas
 *
 * This is a project for data structures class, assignment #2
 * The overal project requires 15 classes/interfaces in seperate files - Some contain nested classes: 
 *	1]	ArithmeticExpression
 *	2]	BTExtendedArithmeticExpression extends ArithmeticExpression
 * 15]	interface Queue<E> 
 *	3]	ArrayQueue<E> implements Queue<E> 
 *	4]	interface List<E> extends Iterable<E> 
 *	5]	ArrayList<E> implements List<E>
 * 14]	ArrayIterator.java
 *	6]	interface Tree<E> extends Iterable<E>
 *	7]	interface BinaryTree<E> extends Tree<E>
 *	8]	AbstractTree<E> implements Tree<E>
 *	9]	AbstractBinaryTree<E> extends AbstractTree<E> implements BinaryTree<E>
 * 10]	LinkedBinaryTree<E> extends AbstractBinaryTree<E>
 * 11]	ArithmeticLinkedBinaryTree extends LinkedBinaryTree<BTExtendedArithmeticExpression>
 * 12]	ProjectTwo
 * 13] 	interface Position<E>
 *	
 *	Within the class of project two an ArithmeticLinkedBinaryTree is created based on the first argument passed
 * 	Note that the The Arithmetic expression can contain both positive and negative ints- this is instead of computing the value of an expression with variables (although the program will create a binary tree for variables)
 *	The program then attempts to open a file and write to the file the original fully parenthasized expression, the computed value, and a binary tree representation
 *	If it can't it will print all that to system output. 
 */

import javax.swing.*;
import java.util. *;
import java.io.PrintWriter;
import java.io.File;
import java.io.IOException;

public class ProjectTwo{

	public static void main(String[] args){
		String testAE = args[0] ;
		ArithmeticLinkedBinaryTree albert= new ArithmeticLinkedBinaryTree(testAE);
		try {
			File file = new File("Jason_Farkas_Tree.txt");  // open a file
			file.createNewFile();
	      	PrintWriter out = new PrintWriter(file , "UTF-8"); // make a way to print to that file
	       	out.println("Original Expression: " +  testAE);
			out.println("Print In Order: ");
			for (Position<BTExtendedArithmeticExpression> p : albert.positions() ){  // Iterate through the tree 
				out.print(p.getElement().getCoreData() );  // print the main part of each arithmetic expression
			}
			out.print(" = " + albert.getValue() );	// print the overal value of the expression
			out.println("\nTesting Tree Print: ");
			albert.layout(albert, albert.root(), 0, 0); // give each BTExtendedArithmeticExpression in the tree an X,Y value to represent it graphically
			int currentLevel = 0;
			int currentx = 0; 
			for (Position<BTExtendedArithmeticExpression> p : albert.breadthfirst() ){  // Iterate through the tree from left to right one level at a tme
				if(p.getElement().getY() > currentLevel){  // Check what level we are at, if we are further down the tree start printing on a new line
					out.println("");
					currentLevel= p.getElement().getY();	// Reset the current Y level
					currentx = 0; 							// Reset the current x to start at the beging of the line
				}
				for(int i=0; i< p.getElement().getX()-currentx; i++ ){ // calculate the difference between the Element's X and the previous x
					out.print("    ");						// print a "   "  for each x position in between the previous node and this one
				}
				out.print(p.getElement().getCoreData() );	// print the expression's core data
				currentx = p.getElement().getX();			// reset the current X to be the x of the BTExtendedArithmeticExpression we just printed
			}
			out.println("\n\n");
			out.close();
			System.out.println("Info Printed to file" );
		}
	    catch (Exception ex)  
	    {
	    	System.out.println(ex);
	    	System.out.println("Could not print to file: ");
	        System.out.println("Print In Order: ");
			for (Position<BTExtendedArithmeticExpression> p : albert.positions() ){
				 System.out.print(p.getElement().getCoreData() );
			}
			// Print Like a tree
			 System.out.println("\nTesting Tree Print: ");
			albert.layout(albert, albert.root(), 0, 0);
			int currentLevel = 0;
			int currentx = 0; 
			for (Position<BTExtendedArithmeticExpression> p : albert.breadthfirst() ){
				if(p.getElement().getY() > currentLevel){
					//System.out.println("");
					 System.out.println("");
					currentLevel= p.getElement().getY();
					currentx = 0; 
				}
				for(int i=0; i< p.getElement().getX()-currentx; i++ ){
					 System.out.print("    ");
				}
				 System.out.print(p.getElement().getCoreData() );
				currentx = p.getElement().getX();
			}
			System.out.println("\n\n");
			System.out.close();
	    }
	}
}

