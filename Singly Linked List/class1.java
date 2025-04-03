class Node {
    int data;
    Node next;

    Node(int data1, Node next1) {
        this.data = data1;
        this.next = next1;
    }

    Node(int data1) {
        this.data = data1;
        this.next = null;
    }
}

public class class1 {

    private static Node convertArr2LL(int[] arr) {
        Node head = new Node(arr[0]);
        Node mover = head;

        for (int i = 1; i < arr.length; i++) {
            Node temp = new Node(arr[i]);
            mover.next = temp;
            mover = temp;
        }

        return head;
    }

    private static void traverseLL(Node head){
        Node temp = head;

        while(temp != null){
            System.out.print(temp.data + " ");
            temp = temp.next;
        }

        System.out.println();
    }

    private static int lengthOfLL(Node head){
        Node temp = head;

        int count = 0;

        while(temp != null){
            temp = temp.next;
            count++;
        }

        return count;
    }


    private static int checkIfPresent(Node head, int value){
        Node temp = head;
        while(temp != null){
            if(temp.data == value){
                return 1;
            }
            temp = temp.next;
        }
        
        return -1;
    }

    public static void main(String[] args) {
        int[] arr = { 12, 13, 14, 15, 16 };
        Node y = new Node(arr[0]);

        // System.out.println(y.data);

        Node head = convertArr2LL(arr);
        // System.out.println(head.data);


        // Traversing
        traverseLL(head);

        // Getting the length of the Linked List
        int lengthLL = lengthOfLL(head);
        System.out.println("Size of the linked list: " + lengthLL);

        // Searching element
        int searchedElement = checkIfPresent(head, 14);
        

        if(searchedElement == 1){
            System.out.println("Found");
        }
        else{
            System.out.println("Not Found");
        }
    }
}