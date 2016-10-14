/*

*/
import javax.swing.*;
import java.util. *;
import java.io.PrintWriter;
import java.io.File;
import java.io.IOException;
/*
	class created by jason farkas: contains method main.
*/ 
public class Main{
	/*
		public method main tries to write information to a file, and will print an error if it can't, 
		
	*/
	public static void main(String[] args){

	try {
		String inputFileName = args[0];

		File file = new File("Jason_Farkas_Project1Output.txt");  // open a file
		file.createNewFile();
      	PrintWriter out = new PrintWriter(file , "UTF-8"); // make a way to print to that file


		// Input File
		TextFileInput inputF = new TextFileInput(inputFileName);
		String line = inputF.readLine();
		while (line != null) { // read every line of the file
			NestedGroup groupOfLine = new NestedGroup(line);
			out.println("Inputed Text: " + line);
			//out.println("GNA =         " + groupOfLine.printGroupNumbArray() );
			int numbOfGroups = groupOfLine.getNumberOfGroups();
			for(int i=0;i<=numbOfGroups;i++){  // Print ever group of the line which is being read. 
				out.println("Group " + i + " = " + groupOfLine.getGroup(i) );
			}
			
			line = inputF.readLine();
		} // end while loop
		
		inputF.close();
		out.close();

		}// end try
	 catch (Exception ex)  
	    {
	    	System.out.println(ex);
	    	System.out.println("Could not print to file: ");
	    }

	} // end main
}// end project 3


