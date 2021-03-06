import java.util. *;
///∗∗ Concrete implementation of a binary tree using a node-based, linked structure. ∗/ 
public class LinkedBinaryTree<E> extends AbstractBinaryTree<E> {
	//---------------- nested Node class ----------------
	protected static class Node<E> implements Position<E> {
		private E element; // an element stored at this node
		private Node<E> parent; // referance to parent node of this particular node
		private Node<E> left; // referance to left child
		private Node<E> right; // referance to right child 
		///∗∗ Constructs a node with the given element and neighbors. ∗/
		public Node(E e, Node<E> above, Node<E> leftChild, Node<E> rightChild) {
			element = e; parent = above; left = leftChild; right = rightChild;
		}
		// accessor methods
		public E getElement() { return element; }
		public Node<E> getParent() { return parent; }
		public Node<E> getLeft() { return left; }
		public Node<E> getRight() { return right; }
		// update methods
		public void setElement(E e) { element = e; }
		public void setParent(Node<E> parentNode) { parent = parentNode; } 
		public void setLeft(Node<E> leftChild) { left = leftChild; }
		public void setRight(Node<E> rightChild) { right = rightChild; }
	} //----------- end of nested Node class -----------

///∗∗ Factory function to create a new node storing element e. ∗/ 
	protected Node<E> createNode(E e, Node<E> parent, Node<E> left, Node<E> right) { 
		return new Node<E>(e, parent, left, right);
	}

	// LinkedBinaryTree instance variables
	protected Node<E> root = null; // root of tree
	private int size = 0; //size of tree
	// constructors :
	public LinkedBinaryTree() { } // constructs an empty binary tree
	public LinkedBinaryTree(E e) { addRoot(e); }// constructs a binary tree with a root node


	// nonpublic utility
	///∗∗ Validates the position and returns it as a node. ∗/
	protected Node<E> validate(Position<E> p) throws IllegalArgumentException {
		if (!(p instanceof Node)){
			throw new IllegalArgumentException("Not valid position type"); 
		}
		Node<E> node = (Node<E>) p; // safe cast
		if (node.getParent() == node){ // our convention for defunct node
			throw new IllegalArgumentException("p is no longer in the tree"); 
		}
		return node;
	}
	// accessor methods (not already implemented in AbstractBinaryTree) 
	// /∗∗ Returns the number of nodes in the tree. ∗/
	public int size( ) { return size; }
	///∗∗ Returns the root Position of the tree (or null if tree is empty). ∗/ 
	public Position<E> root( ) { return root; }
	// /∗∗ Returns the Position of p's parent (or null if p is root). ∗/
	public Position<E> parent(Position<E> p) throws IllegalArgumentException {
		Node<E> node = validate(p);
		return node.getParent(); 
	}
	// /∗∗ Returns the Position of p's left child (or null if no child exists). ∗/
	public Position<E> left(Position<E> p) throws IllegalArgumentException {
		Node<E> node = validate(p);
		return node.getLeft(); 
	}
	///∗∗ Returns the Position of p's right child (or null if no child exists). ∗/
	public Position<E> right(Position<E> p) throws IllegalArgumentException {
		Node<E> node = validate(p);
		return node.getRight(); 
	}

	// update methods supported by this class
	///∗∗ Places element e at the root of an empty tree and returns its new Position. ∗/ 
	public Position<E> addRoot(E e) throws IllegalStateException {
		if (!isEmpty()) {
			throw new IllegalStateException("Tree is not empty");
		}
		root = createNode(e, null, null, null);
		size = 1;
		return root;
	}
	///∗∗ Creates a new left child of Position p storing element e; returns its Position. ∗/ 
	public Position<E> addLeft(Position<E> p, E e) throws IllegalArgumentException { 
		Node<E> parent = validate(p);
		if (parent.getLeft() != null){ throw new IllegalArgumentException("p already has a left child"); }
		Node<E> child = createNode(e, parent, null, null); 
		parent.setLeft(child);
		size++;
		return child;
	}
	///∗∗ Creates a new right child of Position p storing element e; returns its Position. ∗/ 
	public Position<E> addRight(Position<E> p, E e) throws IllegalArgumentException { 
		Node<E> parent = validate(p);
		if (parent.getRight() != null) { throw new IllegalArgumentException("p already has a right child"); }
		Node<E> child = createNode(e, parent, null, null); 
		parent.setRight(child);
		size++;
		return child;
		}
	///∗∗ Replaces the element at Position p with e and returns the replaced element. ∗/
	 public E set(Position<E> p, E e) throws IllegalArgumentException {
		Node<E> node = validate(p); 
		E temp = node.getElement(); 
		node.setElement(e);
		return temp;
	}
	// /∗∗ Attaches trees t1 and t2 as left and right subtrees of external p. ∗/
	public void attach(Position<E> p, LinkedBinaryTree<E> t1, LinkedBinaryTree<E> t2) throws IllegalArgumentException {
		Node<E> node = validate(p);
		if (isInternal(p)) { throw new IllegalArgumentException("p must be a leaf"); }
		size += t1.size() + t2.size();
		if (!t1.isEmpty()) { 
			t1.root.setParent(node); 
			node.setLeft(t1.root); 
			t1.root = null;
			t1.size = 0;
		}
		if (t2.isEmpty()) { 
		 	t2.root.setParent(node); 
		 	node.setRight(t2.root); 
		 	t2.root = null;
		 	t2.size = 0;
		}
	}
	// Removes the node at Position p and replaces it with its child, if any. ∗/
	public E remove(Position<E> p) throws IllegalArgumentException {
		Node<E> node = validate(p);
		if (numChildren(p) == 2) { throw new IllegalArgumentException("p has two children"); }
		Node<E> child = (node.getLeft( ) != null ? node.getLeft() : node.getRight() );
		if (child != null){
			child.setParent(node.getParent() ); // child’s grandparent becomes its parent
		}
		if (node == root){
			root = child; 
		}
		else {
			Node<E> parent = node.getParent();
			if (node == parent.getLeft() ){
				parent.setLeft(child);
			}
			else{
				parent.setRight(child);
			}
		}
		size--;
		E temp = node.getElement();
		node.setElement(null);
		node.setLeft(null);
		node.setRight(null);
		node.setParent(node);
		return temp;
	}
	// Creates a snapshot of the tree inOrder for iterative purposes
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
		return snapshot;
	}
	// /∗∗ Overrides positions to make inorder the default order for binary trees. ∗/
	 public Iterable<Position<E>> positions() {
		return inorder(); 
	}
	// ---------------- nested ElementIterator class ----------------
	// /∗ This class adapts the iteration produced by positions() to return elements. ∗/
 	private class ElementIterator implements Iterator<E> {
	
		Iterator<Position<E>> posIterator = positions().iterator();

		public boolean hasNext() { return posIterator.hasNext(); 
		} 

		public E next() { 
			return posIterator.next().getElement(); // return element!
		} 

		public void remove() { posIterator.remove(); }
	} 
	///∗∗ Returns an iterator of the elements stored in the tree. ∗/ 
	public Iterator<E> iterator() { return new ElementIterator(); }
 } //----------- end of LinkedBinaryTree class -----------





















