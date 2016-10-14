
/**
 * Holds the loction of the next node and a Coordinates
 * @author JasonFarkas
 *
 */

public class ListNode{
	public Coordinates info;
	public ListNode next;

	//default constructor
	public ListNode(){
		info = null;
		next = null;
	}//end no argument constructor 
	/**
	 * 
	 * @param d , a Coordinates object
	 */
	//constructor that takes 
	public ListNode( Coordinates  d){
		info = d;
		next = null;
	}//end one-argument constructor 

}//end ListNode







