public class DataPosition<E>{//extends Position<E>

	private E element;

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