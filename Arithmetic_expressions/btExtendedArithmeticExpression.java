public class BTExtendedArithmeticExpression extends ArithmeticExpression{
// an extended version of an Arithmetic Expression meant to be held in a binary tree and therefore equiped with a x position, y position, and a value which is updated from the tree
	private int xPos; 
	private int yPos;

	public BTExtendedArithmeticExpression(){xPos = 0; yPos = 0;}
	public BTExtendedArithmeticExpression(String x){ super(x); xPos = 0; yPos = 0;}
	public BTExtendedArithmeticExpression(ArithmeticExpression x){ super(x); xPos = 0; yPos = 0;}

	// Access methods: 
	public int getX(){ return xPos; }
	public int getY(){ return yPos; }
	public void setX(int nx){ xPos = nx; }
	public void setY(int ny){ yPos = ny; }
	// Function to enable recursive breakdown of expression while mantaing class BTExtendedArithmeticExpression as opposed to reverting back to a basic ArithmeticExpression class 
	public BTExtendedArithmeticExpression getLeftExpression(){
		BTExtendedArithmeticExpression le= new BTExtendedArithmeticExpression(getLeftSide() );
		return le;
	}
	// Function to enable recursive breakdown of expression while mantaing class BTExtendedArithmeticExpression as opposed to reverting back to a basic ArithmeticExpression class 
	public BTExtendedArithmeticExpression getRightExpression(){
		BTExtendedArithmeticExpression re= new BTExtendedArithmeticExpression(getRightSide() );
		return re;
	}
}














