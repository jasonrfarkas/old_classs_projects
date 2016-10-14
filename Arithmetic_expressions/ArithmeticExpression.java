import javax.swing.*;
import java.util. *;
/*
 * @author
 * This class holds an Arithmetic Expression.
 * Truly it only accepts an string representing an expression and determines if that string can be broken into other mini expressions
 * It does this by looking at the '(' and ')' of the string, and noting what depth level each character is on. ex. 5 is on 0, (5) is on 1, ((5)) is on 2.
 * It then looks to see if the expression contains an opperator, if it does it looks for it at level 0, if there is none it attempts to remove extra surrounding '()' and try again
 * If there is no extra () it will print that the expression is invalid and eventually catagorize the opperator as "IVE" 
 * If it finds the opperator at level zero it can use that location to break down the expression into two smaller expressions
 * It will also catagorize the core element of the expression as the opperator
 * If the expression has no opperator it will set the core element of the expression to the entire expression, as it assumes the expression is a number or variable
 * The value of the expression can be computed assuming it contains only numbers that can be converted to floats, 
 * When the value of the expression is returned it will return the value of all subExpressions with the correct opperation performed on them,
 * if the subExression contains a variable it will return a concatination of the subexpressions instead. 
 */
public class ArithmeticExpression{
	private String expression;  // Holds the original expression
	private String core;
	private boolean multipartExpression;
	private String leftSide;
	private String opperator;
	private String rightSide;
	private ArrayList<Integer> depthLvlArray;
	private float value;
	private String svalue;
	private boolean hasVariables;
// Constructers:
	public ArithmeticExpression(){ this("");  /* Calls the constructor that takes a string parameter */ }
	public ArithmeticExpression(ArithmeticExpression e){  this(e.expression); /* Calls the constructor that takes a string parameter */ }
	/** Constructor that accepts a string */ 
	public ArithmeticExpression(String e){
		try{
			expression= e.replaceAll("\\s+",""); 	// Remove all white space from string 
			setDepthLvlArray();  					// Determine which charachters are nested in parenthesis and what level of nesting
			multipartExpression = false;			// set default value
			leftSide= "";							// set default value
			opperator = "";							// set default value
			rightSide = "";							// set default value
			setIfMultipart();						// Check if the expression can be broken down into 2 seperate expressions and reset values accordingly
			setCoreValue();							// set the core value to an opperation or an int or a variable
			setValuesAndIfContainsVariables();		// set the computed float and string value the expression, and if the expression contains a variable
		}
		catch(Exception m){
			System.out.println("Error in create ArithmeticExpression: " + m);
			System.out.println("Replacing InValidExpression with 'IVE' " ); // This way the program can still run.
			expression= "IVE";						// The rest of the functions will treat the expression as a nonMultipartExpression that contains a VARIABLE
			setDepthLvlArray();  					// Determine which charachters are nested in parenthesis and what level of nesting
			multipartExpression = false;			// set default value
			leftSide= "";							// set default value
			opperator = "";							// set default value
			rightSide = "";							// set default value
			setIfMultipart();						// Check if the expression can be broken down into 2 seperate expressions and reset values accordingly
			setCoreValue();							// set the core value to an opperation or an int or a variable
			setValuesAndIfContainsVariables();		// set the computed float and string value the expression, and if the expression contains a variable
		
		}
	}

// Accessor functions :
// Get functions:
	public String getCoreData(){ return core; }
	public String getLeftSide(){ return leftSide; }
	public String getOpperator(){ return opperator; }
	public String getRightSide(){ return rightSide; }
	public String getLeftSideOfE(){ return leftSide; }
	public String getOpperatorOfE(){ return opperator; }
	public String getRightSideOfE(){ return rightSide; }
	public String getExpression(){ return expression; }
	public ArithmeticExpression getLeftExpression(){  return new ArithmeticExpression( getLeftSide()  ); }
	public ArithmeticExpression getRightExpression(){ return new ArithmeticExpression( getRightSide() ); } 
	public String getValue(){  if(hasVariables() ){ return svalue + " Expression contains variables and cannot be fully computed "; } return svalue; }
	public boolean isMultipart(){ return multipartExpression; }
	public boolean hasVariables(){ return hasVariables; }
	
// Real Set Functions:    // aka they take arguments
	public void	 setExpression(String newE){
		expression = newE.replaceAll("\\s+","");
		setDepthLvlArray();
		setIfMultipart();
		setCoreValue(); 
		setValuesAndIfContainsVariables();
	}

// Helper Set Functions:  // aka they don't take arguments, but set some values based on other values inside the class
	
	/** Function to set depthLvlArray */
	private ArrayList<Integer> setDepthLvlArray(){
		String e = expression;
		depthLvlArray = new ArrayList(e.length()); 
		int currentDlvl= 0;
		if (e.length() > 0){
			for(int i=0; i < e.length(); i++){ // go through each charachter
				if(e.charAt(i) == '('){  // if the charachter is '(' add one to the depth
					currentDlvl ++;
				}
				else if(e.charAt(i) == ')'){  // if the charachter is ')' subtract one from the depth
					currentDlvl --; 
				}
				depthLvlArray.add(currentDlvl);
			}
		}
		return depthLvlArray;
	}
	//  Set if a node in a binary tree should show this expression as a value or an opperator
	public void setCoreValue(){
		if (isMultipart() ){ core = opperator; }
		else{ core = expression; }
	}

	// Determine if the expression has multiple parts
	public boolean setIfMultipart(){
		//System.out.println("Setting multipart for:  " + expression);
		boolean localIfMulti = false; 
		String e= expression;
		for(int i=1; i < expression.length(); i++){
				if(e.charAt(i)=='+' || e.charAt(i)=='/' ||  e.charAt(i)== '*' ){
					localIfMulti = true;
					i= e.length(); 
				}
				else if(e.charAt(i)=='-' && e.charAt(i-1)!='-' && e.charAt(i-1)!='(' && e.charAt(i-1)!='/' && e.charAt(i-1)!='+' && e.charAt(i-1)!='*'){
					localIfMulti = true;
					i= e.length(); 
				}
			}
		multipartExpression=  localIfMulti;
		int opperationPoint = findOpIndex();
		if(localIfMulti == true && opperationPoint != -1){
			int starter = 0;
			int ender = 0;
			leftSide = expression.substring(starter,opperationPoint-ender);
			opperator = "" + expression.charAt(opperationPoint);
			rightSide = expression.substring(opperationPoint+1);
		}
		else if(opperationPoint == -1 && localIfMulti == true){
			System.out.println("Invalid Expression: "+ expression);
			leftSide = "";
			opperator += "IVE";
			rightSide += "";
		}
		else{
			leftSide = "";
			opperator += "";
			rightSide += "";
		}
		return localIfMulti;
	}
	// Sets svalue and value and checks if the expression contains variables
	public boolean setValuesAndIfContainsVariables(){
		if(isMultipart()){
			ArithmeticExpression ls= getLeftExpression();
			ArithmeticExpression rs= getRightExpression();
			if(ls.hasVariables() || rs.hasVariables()){  // if subexpressions have variables just concatinate the expressions and give svalue
				hasVariables =true;
				value = 0.0f;
				svalue = ls.svalue + opperator + rs.svalue;
			}
			else{
				hasVariables = false;
				value = computeValue(ls.value, opperator,rs.value);	// If subExpressions don't contain variables figure out the value of the total expression
				svalue = Float.toString(value);
			}

		}
		else {
			Float f = new Float("0.0f");
			try{
				float retval = f.parseFloat(core);
				value = retval;
				svalue = Float.toString(retval);
				hasVariables = false;
			}
			catch(NumberFormatException e){
				value = 0.0f;
				svalue = core;
				hasVariables =true;
			}
		}
		return hasVariables;
	}

// Helper functions :
	public int findOpIndex(){
		return findOpIndexHelper(expression);
	}
	// Finds the index of an opperator or returns -1 
	public int findOpIndexHelper(String e){
		int positionOfFirstOpperatorAtLvlZero = -1; 
		boolean hasOp = false; 
		for(int i=0; i < e.length(); i++){	// checks if the expression has any opperator 
			if(isOpperatorAt(e,i) ){
				hasOp= true;
				if(depthLvlArray.get(i) == 0){
					positionOfFirstOpperatorAtLvlZero = i;  // finds the opperator that should occur first, no surrounded by '( )'
				}
			}
		}
		if(hasOp){															// There was at least one opperator in the expression
			if (positionOfFirstOpperatorAtLvlZero == -1){ 					// There was no opperators at lvl 0
				if(e.charAt(0) == '(' && e.charAt( e.length()-1 ) == ')'  ) // The expression starts with '(' and ends with ')' -> assume they are extra 
				{
					setExpression(e.substring(1,e.length()-1 )); 			// reset expression that to include the extra '( )'
					positionOfFirstOpperatorAtLvlZero = findOpIndex(); 							// Try to find the opIndex of that. 
				}
				else{
					System.out.println("Invalid Expression:  Requires opperation on level Zero " + expression);
				}
			}
		}
		else{ // there are no opperators AT ALL in this expression 
			return -1;
		}
		return positionOfFirstOpperatorAtLvlZero;
	}
	// Checks if a position in a string is an opperator, requires the entire string to check if a - sign is used as an opperator
	public boolean isOpperatorAt(String e, int i){
		boolean isOp = false; 
		if(e.charAt(i)=='+' || e.charAt(i)=='/' ||  e.charAt(i)== '*' ){
			isOp = true;
		}
		else if(i>=1){ // Check if a there is a negative sign used as an opperator
			if(e.charAt(i)=='-' && e.charAt(i-1)!='-' && e.charAt(i-1)!='(' && e.charAt(i-1)!='/' && e.charAt(i-1)!='+' && e.charAt(i-1)!='*'){
				isOp = true;
			}
		}
		return isOp;
	}
	// performs math on two floats by translating a string opperator
	public float computeValue(float ls, String op, float rs){
		float v = 0.0f;
		if(op.equals("+"))		{ v = ls + rs; 	}
		else if(op.equals("-"))	{ v=ls-rs;		}
		else if(op.equals("/"))	{ v=ls/rs;		}
		else if(op.equals("*"))	{ v=ls*rs;		}
		else{	throw new IllegalArgumentException("Opperator cannot be " + op);    }
		return v;
	}
}







/*	//  Function that became obsolete
	public String brokenUpAExpression(String ex){
		if(isMultipart()){
			String aEx = "";
			int opperationPoint = findOpIndex();
			if (opperationPoint == -1){
				System.out.println("Error every multipart expression should have an opperation");
			}
			int starter = 0;
			int ender = 0;
			if(ex.charAt(0)=='(' && ex.charAt(opperationPoint-1) == ')'){
				starter =1;
			}
			if(ex.charAt(opperationPoint-1)==')'){
				ender = +1;
			}
			aEx += ex.substring(starter,opperationPoint-ender);
			aEx += "\n ";
			aEx += ex.charAt(opperationPoint);
			aEx += "\n ";
			aEx += ex.substring(opperationPoint+1);
			return aEx;
		}
		else{
			return expression;
		}
	}
	//
	public String printDivdedExpression(){
		return brokenUpAExpression(expression);
	}
*/

			










