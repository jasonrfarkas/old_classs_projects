import javax.swing.*;
import java.util. *;
import java.util. *;

/*
 * This Class holds a string and breaks it down into groups based on opening and closing parentheses characters. 
 * It numbers the groups based on the opening ( 's 
 * When the object is created a help function goes through an arraylist corrisponding to the input string and markes off positions that have ( by numbering which group they start
 * The function then goes from the end of the input list looking for the start of a group, once it finds a start of a group it looks for the next ) that isn't already ending a different group and marks that position with the number of the group it is ending
 * Therefore the arraylist should have two numbers for each group one to mark the start one to mark the end. 
 * ex.  h ( i(jk)l (mn) o ) q    // would be:
 *		0 1  2  2  3  3   1 0    // where every unmarked position is -1
 * Then to get a particular group there is a function to find the first and second time that int appears in the arraylist which corrispond to the start and end of the group, the resulting substring is returned
 */
public class NestedGroup{
	private String expression;  // Holds the original expression
	private ArrayList<Integer> groupNumberArray; 

// Constructers:
	public NestedGroup(){ this("");  /* Calls the constructor that takes a string parameter */ }
	public NestedGroup(NestedGroup e){  this(e.expression); /* Calls the constructor that takes a string parameter */ }
	/** Constructor that accepts a string */ 
	public NestedGroup(String e){
		try{
			//expression= e.replaceAll("\\s+",""); 	// Remove all white space from string 
			expression= " " + e + " ";
			setGroupNumberArray();
		}
		catch(Exception m){
			System.out.println("Error in create NestedGroup: " + m);
			System.out.println("Replacing InValidExpression with 'IVE' " ); // This way the program can still run.
			expression= "IVE";						// The rest of the functions will treat the expression as a nonMultipartExpression that contains a VARIABLE
		}
	}

// Accessor functions :
// Get functions:
	public int getNumberOfGroups(){ return numbOfGroups;	}
	public String printGroupNumbArray(){
		String h = "";
		for (int i=0; i<groupNumberArray.size(); i++){
			h+=groupNumberArray.get(i);
		}
		return h;
	}
// Method to get a particular group based on an int argument that specifies the number of the group
	public String getGroup(int x){
		String groupEx = "";
		if(x <= numbOfGroups){
			boolean inGroup = false;
			for (int i=0; i<groupNumberArray.size(); i++){
				if(groupNumberArray.get(i) == x){
					inGroup = !inGroup;
					if(!inGroup){ groupEx += expression.charAt(i); }
				}
				if(inGroup){
					groupEx += expression.charAt(i);
				}
			}
		}
		return groupEx;
	}
	
// Real Set Functions:    // aka they take arguments
	public void	 setExpression(String newE){
		expression = newE.replaceAll("\\s+","");
	}

//Help functions
	private ArrayList<Integer> setGroupNumberArray(){
		String e = expression;
		groupNumberArray = new ArrayList(e.length());
		//System.out.println("Group Length" + e.length() );
		int groupNum= 0;
		if (e.length()  > 0){
			groupNumberArray.add(groupNum);
			for(int i=1; i <= e.length()-2; i++){
				//System.out.println("accessing index " + i );
				if(e.charAt(i)== '(' && i!=0){ 
						groupNumberArray.add(++groupNum);
				}
				else{
					groupNumberArray.add(-1);
				}
			}
			groupNumberArray.add(0);

			int currentGroup = -1;
			for(int i=e.length()-2; i >=0; i--){
				if(groupNumberArray.get(i) != -1){
					currentGroup = groupNumberArray.get(i);
					for(int j=i; j <= e.length()-2; j++){
						//System.out.println("third loop accessing index " + j );
						// This will cause a problem as it will overright the previous group numbers
						if(e.charAt(j)== ')' && groupNumberArray.get(j) == -1 ){
							groupNumberArray.set(j, currentGroup);
							break;
						}
					}
				}
			}
		}
		numbOfGroups=groupNum;
		return groupNumberArray;
	}
}






