public class List340{
	//protected List340 info;
	//protected ListNode next;
	private int xLoc;
	private int yLoc;

	//default constructor
	public List340(){
		xLoc = 0;
		yLoc = 0;
		//info = null;
	}//end no argument constructor 

	public List340(int x, int y){
		xLoc = x;
		yLoc = y;
		//info = null;
	}//end no argument constructor 

	public void setXLoc(int toSetx){
		xLoc = toSetx;
	}

	public void setYLoc(int toSety){
		yLoc =toSety;
	}

	public int getXLoc(){
		return xLoc;
	}

	public int getYLoc(){
		return yLoc;
	}

}//end ListNode