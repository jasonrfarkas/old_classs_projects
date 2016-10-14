public class Tree<E> implements TreeInterface<E> {

	private TreePosition<E> startingTreePosition;
	private int treeSize;
	//unfinished

public TreePosition<E> root(){
	return startingTreePosition;
}

TreePosition<E> parent(TreePosition<E> p) throws IllegalArgumentException; 

Iterable<TreePosition<E>> children(TreePosition<E> p) throws IllegalArgumentException; 

int numChildren(TreePosition<E> p) throws IllegalArgumentException;

public boolean isInternal(TreePosition<E> p) throws IllegalArgumentException{
	return numChildren(p) > 0;
}

public boolean isExternal(TreePosition<E> p) throws IllegalArgumentException{
	return numChildren(p) == 0;
}

public boolean isRoot(TreePosition<E> p) throws IllegalArgumentException{
	return p == root();
} 

public int size(){
	return treeSize;
}

public boolean isEmpty(){
	return size() == 0;
}

Iterator<E> iterator(); 

Iterable<TreePosition<E>> Treepositions();
	
}




/* 

public abstract class AbstractTree<E> implements Tree<E> {

public boolean isInternal(TreePosition<E> p) { 
return numChildren(p) > 0; 
}

 public boolean isExternal(TreePosition<E> p) { 
 return numChildren(p) == 0; 
} 

public boolean isRoot(TreePosition<E> p) { 
return p == root(); 
}

public boolean isEmpty() { 
return size() == 0; 
}

}

*/