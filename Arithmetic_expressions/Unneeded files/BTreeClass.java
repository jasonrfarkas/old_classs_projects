public class BTree<E> implements TreeInterface<E> {

	private BTreePosition<E> startingBTreePosition;
	private int treeSize;
	//unfinished

	public BTree(){
		startingBTreePosition = new BTreePosition();
		treeSize = 1;
	}

	public BTree(BTreePosition seed){
		startingBTreePosition = seed;
		treeSize = figureOutSize();
	}

	private int figureOutSize(){
		int tempSize= 1;
		if(startingBTreePosition.getChildOne() != null){
			tempSize += startingBTreePosition.getChildOne().figureOutSize();
		} 
		if(startingBTreePosition.getChildTwo() != null){
			tempSize += startingBTreePosition.getChildTwo().figureOutSize();
		}
		return tempSize;
	}


	public BTreePosition<E> root(){
		return startingBTreePosition;
	}

	BTreePosition<E> parent(BTreePosition<E> p) throws IllegalArgumentException; 

	Iterable<BTreePosition<E>> children(BTreePosition<E> p) throws IllegalArgumentException; 

	int numChildren(BTreePosition<E> p) throws IllegalArgumentException{
		
	}

	public boolean isInternal(BTreePosition<E> p) throws IllegalArgumentException{
		return numChildren(p) > 0;
	}

	public boolean isExternal(BTreePosition<E> p) throws IllegalArgumentException{
		return numChildren(p) == 0;
	}

	public boolean isRoot(BTreePosition<E> p) throws IllegalArgumentException{
		return p == root();
	} 

	public int size(){
		return treeSize;
	}

	public boolean isEmpty(){
		return size() == 0;
	}

	public Iterable<Position<E>> preorder() {
		List<Position<E>> snapshot = new ArrayList<>(); 

		if (!isEmpty() )
			preorderSubtree(root(), snapshot); // fill the snapshot recursively return snapshot;
		}
	}


	Iterator<E> iterator(); /* This class adapts the iteration produced by positions() to return elements. ∗/ private class ElementIterator implements Iterator<E> {
Iterator<Position<E>> posIterator = new PositionIterator( );
public boolean hasNext( ) { return posIterator.hasNext( ); }
public E next( ) { return posIterator.next( ).getElement( ); } // return element! public void remove( ) { posIterator.remove( ); }
}
/∗∗ Returns an iterator of the elements stored in the list. ∗/ public Iterator<E> iterator( ) { return new ElementIterator( );
*/



	Iterable<BTreePosition<E>> BTreepositions();
	/*//---------------- nested PositionIterable class ----------------
private class PositionIterable implements Iterable<Position<E>> {
public Iterator<Position<E>> iterator() { return new PositionIterator(); }
} //------------ end of nested PositionIterable class ------------


/∗∗ Returns an iterable representation of the list's positions. ∗/ public Iterable<Position<E>> positions( ) {
return new PositionIterable(); // create a new instance of the inner class }
*/
	

	private void inorderSubtree(Position<E> p, List<Position<E>> snapshot) {

		if (left(p) != null){
			inorderSubtree(left(p), snapshot);
		}
		snapshot.add(p);

		if (right(p) != null){
			inorderSubtree(right(p), snapshot);
		}
	}

/*Returns an iterable collection of positions of the tree, reported in inorder. */

	public Iterable<Position<E>> inorder() {

		List<Position<E>> snapshot = new ArrayList<>(); 
		if (!isEmpty()){
			inorderSubtree(root(), snapshot); // fill the snapshot recursively return snapshot;
		}
	}
	// /∗∗ Overrides positions to make inorder the default order for binary trees. ∗/

	 public Iterable<Position<E>> positions() {
		return inorder(); 
	}

}




























/* 

public abstract class AbstractTree<E> implements Tree<E> {

public boolean isInternal(BTreePosition<E> p) { 
return numChildren(p) > 0; 
}

 public boolean isExternal(BTreePosition<E> p) { 
 return numChildren(p) == 0; 
} 

public boolean isRoot(BTreePosition<E> p) { 
return p == root(); 
}

public boolean isEmpty() { 
return size() == 0; 
}

}

*/