public class BTreePosition<E> extends Position<E>{

	private E element;
	private TreePosition<E> parent;
	private TreePosition<E> childOne;
	private TreePosition<E> childTwo;
	//Unfinished

	public BTreePosition(){
		element = Null;
		parent = Null;
		childOne=Null;
		childTwo = Null;
	}

	public BTreePosition(E toStore){
		element = toStore;
		parent = Null;
		childOne=Null;
		childTwo = Null;
	}

	public BTreePosition(E toStore, TreePosition<E> p){
		element = toStore;
		parent = p;
		childOne = Null;
		childTwo = Null
	}

	public BTreePosition(E toStore, TreePosition<E> p, TreePosition<E> cOne){
		element = toStore;
		parent = p;
		childOne =cOne;
		childTwo = Null
	}

	public BTreePosition(E toStore, TreePosition<E> p, TreePosition<E> cOne, TreePosition<E> cTwo){
		element = toStore;
		parent = p;
		childOne =cOne;
		childTwo = cTwo;
	}



	public TreePosition<E> getParent(){
		return parent;
	}
	public void setParent(TreePosition<E> p){
		parent = p;
	}

	public TreePosition<E> getChildOne(){
		return childOne;
	}
	public void setChildOne(TreePosition<E> p){
		childOne = p;
	}


	public TreePosition<E> getChildTwo(){
		return childTwo
	}
	public void setChildTwo(TreePosition<E> p){
		childTwo = p;
	}

	public E getElement(){
		return element;
	}

	public void setElement(E newElement){
		element = newElement;
	}
}