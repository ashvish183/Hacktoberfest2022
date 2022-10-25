public class LinkedListApp {

    /
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
      LinkList x = new LinkList();
      x.insertFirst(5);
      x.insertFirst(9);
      x.insertFirst(3);
      x.insertFirst(7);
      x.insertFirst(1);
      x.displayList();
      
       
       

    
    }
    
}
class Node {
    int data;
    Node next;
    
    Node(int item) {
        this.data = item;
        this.next = null;
        }
    
    void displayNode() {
        System.out.print(this.data + " ");
    }
}
    
    class LinkList {
    private Node head;
    
    public LinkList() {
    head = null;
    }
    
    public boolean isEmpty() {
        /*if(this.head==null){
        return true;
        }else{
        return false;
        }*/
        
        return (this.head==null);
    }
    
    public void insertFirst(int i) {
        Node newNode = new Node(i);
        newNode.next = this.head;
        head = newNode;
    }
    
    public Node deleteFirst() {
        Node temp = this.head;
        this.head=this.head.next;
        temp.next = null;
        return null;
    }
    
    public void displayList() {
        Node curr = this.head;
        while(curr != null){
            System.out.print(curr.data + " ");
            curr = curr.next;
        }
        System.out.println(" ");
    }
    
    public Node find(int key) {
        Node curr = this.head;
        int count = 1;
        while(curr != null){
            if(count == key){
            return curr;
            }
            
        curr = curr.next;
        count++;
        }
        System.out.println("index out of bound");
        return  null;
    }
    
    public void delete(int key) {
        if(isEmpty()){
            System.out.println("list is empty. nothing to delete");
            return;
        }
        
        Node curr = this.head;
        Node prev = this.head;
        int count=1;
        
        while(curr!=null){
            if(count == key){
            if(count==1){//is dlt 1st
            this.deleteFirst();
            }  else{
            prev.next=curr.next;
           // curr.next=null;
            } 
                System.out.println("Item delete");
                return;
            }
        prev=curr;
        curr=curr.next;
        count++;
        }
        System.out.println("index out of bound");
       
    }
    
    
}
