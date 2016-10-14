import java.util. *;
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
		}
		return h;
	}
	///∗∗ Returns the height of the subtree rooted at Position p. ∗/
	public int height(Position<E> p) { 
		int h = 0;
		for (Position<E> c : children(p)){
			h = Math.max(h, 1 + height(c));
		}
		return h;
	}
	///∗∗ Returns an iterable collection of positions of the tree in breadth-first order. ∗/
	public Iterable<Position<E>> breadthfirst() {
		List<Position<E>> snapshot = new ArrayList<>();
		if (!isEmpty() ) {
			Queue<Position<E>> fringe = new ArrayQueue<>();
			fringe.enqueue(root() ); // start with the root
			while (!fringe.isEmpty() ) {
				Position<E> p = fringe.dequeue(); // remove from front of the queue 
				snapshot.add(p); // report this position
				for (Position<E> c : children(p)){
					fringe.enqueue(c); // add children to back of queue 
				}
			}
		}
		return snapshot; 
	}
}












