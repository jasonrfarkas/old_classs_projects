public class TreePosition<E> extends Position<E>{//extends Position<E>

	private E element;
	private TreePosition<E> parent;
	private TreePosition<E>[] children;
	//Unfinished

	public DataPosition(){
		element = Null;
	}

	public DataPosition(E toStore){
		element = toStore;
	}

	public E getElement(){
		return element;
	}

	public void setElement(E newElement){
		element = newElement;
	}
}