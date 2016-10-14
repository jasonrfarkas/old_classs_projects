import java.util. *;
/**
 * @author Jason Farkas
 * This class extends a binary tree and specifies the type of data to be accepted to be BTExtended Arithmetic expresions
 * It adds compatability for BTExtended Arithmetic expresions for the following functions: addRoot, AddLeft, AddRight, Set
 * It also adds 2 brand new functions: Layout, and getValue
 *
 */

public class ArithmeticLinkedBinaryTree extends LinkedBinaryTree<BTExtendedArithmeticExpression>{
	public ArithmeticLinkedBinaryTree() {}
	public ArithmeticLinkedBinaryTree(BTExtendedArithmeticExpression e) { addRoot(e); }
	public ArithmeticLinkedBinaryTree(String e) {
		BTExtendedArithmeticExpression ae = new BTExtendedArithmeticExpression(e);
		addRoot(ae);
	}
	///∗∗ Places element e at the root of an empty tree and returns its new Position. ∗/ 
	public Position<BTExtendedArithmeticExpression> addRoot(BTExtendedArithmeticExpression e) throws IllegalStateException {
		Node<BTExtendedArithmeticExpression> root = validate(super.addRoot(e));
		if(e.isMultipart() ){ 
			addLeft(root, e.getLeftExpression() );
			addRight(root, e.getRightExpression() );
		}
		return root;
	}
	///∗∗ Creates a new left child of Position p storing element e; returns its Position. ∗/ 
	public Position<BTExtendedArithmeticExpression> addLeft(Position<BTExtendedArithmeticExpression> p, BTExtendedArithmeticExpression e) throws IllegalArgumentException { 
		Node<BTExtendedArithmeticExpression> child = validate(super.addLeft(p, e));
		if(e.isMultipart() ){
			addLeft(child, e.getLeftExpression() );
			addRight(child, e.getRightExpression() );
		}
		return child;
	}
	///∗∗ Creates a new right child of Position p storing element e; returns its Position. ∗/ 
	public Position<BTExtendedArithmeticExpression> addRight(Position<BTExtendedArithmeticExpression> p, BTExtendedArithmeticExpression e) throws IllegalArgumentException { 
		Node<BTExtendedArithmeticExpression> child = validate(super.addRight(p, e));
		if(e.isMultipart() ){
			addLeft(child, e.getLeftExpression() );
			addRight(child, e.getRightExpression() );
		}
		return child;
		}
	/** version of the above that accepts a simple arithmetic expression as a parameter */ 
	public Position<BTExtendedArithmeticExpression> addLeft(Position<BTExtendedArithmeticExpression> p, ArithmeticExpression ae) throws IllegalArgumentException { 
		BTExtendedArithmeticExpression e = new BTExtendedArithmeticExpression(ae);
		Node<BTExtendedArithmeticExpression> child = validate(super.addLeft(p, e));
		if(e.isMultipart() ){
			addLeft(child, e.getLeftExpression() );
			addRight(child, e.getRightExpression() );
		}
		return child;
	}
	/** version of the above that accepts a simple arithmetic expression as a parameter */ 
	public Position<BTExtendedArithmeticExpression> addRight(Position<BTExtendedArithmeticExpression> p, ArithmeticExpression ae) throws IllegalArgumentException { 
		BTExtendedArithmeticExpression e = new BTExtendedArithmeticExpression(ae);
		Node<BTExtendedArithmeticExpression> child = validate(super.addRight(p, e));
		if(e.isMultipart() ){
			addLeft(child, e.getLeftExpression() );
			addRight(child, e.getRightExpression() );
		}
		return child;
	}
	///∗∗ Replaces the element at Position p with e and returns the replaced element. ∗/
	 public BTExtendedArithmeticExpression set(Position<BTExtendedArithmeticExpression> p, BTExtendedArithmeticExpression e) throws IllegalArgumentException {
		Node<BTExtendedArithmeticExpression> node = validate(p); 
		BTExtendedArithmeticExpression temp = node.getElement(); 
		node.setElement(e);
		return temp;
	}
	/** This method recursively sets the X and Y values of each BTExtendedArithmeticExpression in the tree so that they can later be printed*/
	public static int layout(ArithmeticLinkedBinaryTree T, Position<BTExtendedArithmeticExpression>  p, int d, int x) { 
		if (T.left(p) != null){
			x = layout(T, T.left(p), d+1, x); 	// resulting x will be increased
		}
		p.getElement().setX(x++); 				// post-increment x
		p.getElement().setY(d);	
		if (T.right(p) != null){
			x = layout(T, T.right(p), d+1, x);	 // resulting x will be increased
		}
		return x;
	}// The initial call should be layout(T, T.root(), 0, 0).
	/** This methods returns the value of the tree's root arithmetic expression */
	public String getValue(){
		return root.getElement().getValue();
	}
}










