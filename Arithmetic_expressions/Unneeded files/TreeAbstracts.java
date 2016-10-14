// /∗∗ An interface for a tree where nodes can have an arbitrary number of children. ∗/

public interface Tree<E> extends Iterable<E> {
 
Position<E> root();
Position<E> parent(Position<E> p) throws IllegalArgumentException;

Iterable<Position<E>> children(Position<E> p)throws IllegalArgumentException; 
int numChildren(Position<E> p) throws IllegalArgumentException;

boolean isInternal(Position<E> p) throws IllegalArgumentException; 
boolean isExternal(Position<E> p) throws IllegalArgumentException; 
boolean isRoot(Position<E> p) throws IllegalArgumentException; int size();
boolean isEmpty();

Iterator<E> iterator(); 
Iterable<Position<E>> positions();

}

///∗∗ An abstract base class providing some functionality of the Tree interface. ∗/ 
public abstract class AbstractTree<E> implements Tree<E> {
	public boolean isInternal(Position<E> p) { return numChildren(p) > 0; } 
	public boolean isExternal(Position<E> p) { return numChildren(p) == 0; } 
	public boolean isRoot(Position<E> p) { return p == root(); }
	public boolean isEmpty() { return size() == 0; }


///∗∗ Returns the number of levels separating Position p from the root. ∗/ 
	public int depth(Position<E> p) {
		if (isRoot(p)){ return 0; }
		else { return 1 + depth(parent(p)); } 
	}

	// /∗∗ Returns the height of the tree. ∗/ 
	private int heightBad() {
		int h = 0;
		for (Position<E> p : positions()){
			if (isExternal(p)){
				h = Math.max(h, depth(p));
			}
		return h;
		}
	}


///∗∗ Returns the height of the subtree rooted at Position p. ∗/
	public int height(Position<E> p) { 
		int h = 0;
		for (Position<E> c : children(p)){
			h = Math.max(h, 1 + height(c));
			return h;
		}
	}

}


///∗∗ An interface for a binary tree, in which each node has at most two children. ∗/
public interface BinaryTree<E> extends Tree<E> {
 ///∗∗ Returns the Position of p's left child (or null if no child exists). ∗/
 Position<E> left(Position<E> p) throws IllegalArgumentException;
 ///∗∗ Returns the Position of p's right child (or null if no child exists). ∗/
 Position<E> right(Position<E> p) throws IllegalArgumentException;
 ///∗∗ Returns the Position of p's sibling (or null if no sibling exists). ∗/
 Position<E> sibling(Position<E> p) throws IllegalArgumentException;
 }


/* /∗∗ An abstract base class providing some functionality of the BinaryTree interface.∗/  */
public abstract class AbstractBinaryTree<E> extends AbstractTree<E> implements BinaryTree<E> { 
	/* /∗∗ Returns the Position of p's sibling (or null if no sibling exists). ∗/ */
	public Position<E> sibling(Position<E> p) { 
		Position<E> parent = parent(p); 
		if (parent == null) { 
			return null; // p must be the root 
		}
		if (p == left(parent)){
			return right(parent);  //p is a leftchild  // (right child might be null)
		} 
		else{
			return left(parent); // p is a right child  // (left child might be null)
		}	
	}
	
	
	// /∗∗ Returns the number of children of Position p. ∗/ 
	public int numChildren(Position<E> p) {
		int count=0;
		if (left(p) != null){
			count++;
		}
		if (right(p) != null){
			count++; 
		}
		return count;
	}
	// /∗∗ Returns an iterable collection of the Positions representing p's children. ∗/
	public Iterable<Position<E>> children(Position<E> p) { 
		List<Position<E>> snapshot = new ArrayList<>(2); // max capacity of 2
		if (left(p) != null){
			snapshot.add(left(p));
		}
		if (right(p) != null){
			snapshot.add(right(p)); 
		}
		return snapshot;
	}
	
}








