import  java.util.*;
public class Assignment1 {
    class Node{
        int data;
        Node left,right;
        Node(int x)
        {
            data = x;
            left=right=null;
        }
    }
    Node root;
    Assignment1()
    {
        root=null;
    }
     Node Insert(Node root, int x)
    {
        if(root==null)
        {
            root = new Node(x);
            return root;
        }
        if(x<=root.data)
            root.left=Insert(root.left,x);
        else
            root.right = Insert(root.right,x);
        return root;
    }
    Node delete(Node root, int element)
    {
        if(root==null){
        return null;}
        if(root.data>element)
        root.left = delete(root.left, element);
        else if(root.data<element)
        root.right = delete(root.right, element);
        else
        {
            if(root.left==null) 
            return root.right;
            else if(root.right==null) 
            return root.left;
            else 
            {
                Node succ = minvalue(root);
                root.data = succ.data;
                root.right = delete(root.right, succ.data);
            }
        }
            return root;    
    }
    Node minvalue(Node root)
    {
        Node curr = root.right;
        while(curr!=null && curr.left!=null)
        curr=curr.left;
        return curr;  
    }
    boolean search(Node root,int  element)
    {
        while(root!=null)
        {
            if(root.data==element)
                return true;
            else if(element<root.data)
                root=root.left;
            else
                root = root.right;            
        }
        return false;
    }
      void Inorder(Node root)
    {
        if(root!=null)
        {
            Inorder(root.left);
            System.out.print(root.data+" ");
            Inorder(root.right);
        }
    }
     void Preorder(Node root)
    {
        if(root!=null)
        {
            System.out.print(root.data+" ");
            Preorder(root.left);
            Preorder(root.right);
        }
    }
    void Postorder(Node root)
    {
        if(root!=null) {
            Postorder(root.left);
            Postorder(root.right);
            System.out.print(root.data + " ");
        }
    }
    public static void main(String []args)
    {
        Scanner sc = new Scanner(System.in);
        Assignment1 bst = new Assignment1();
        System.out.print("Enter Number of Nodes while creation: ");
        int number_of_nodes = sc.nextInt();
        for(int i = 0;i<number_of_nodes;i++)
        {
            System.out.print("\nEnter Value of Node: ");
            int data = sc.nextInt();
            bst.root = bst.Insert(bst.root,data);
        }
        System.out.println("\nDisplaying Created Tree:- ");
        bst.Inorder(bst.root);
        int ch1;
        do {
            System.out.print("\n\nEnter 1 to Insert A Node.\nEnter 2 to Search an Element. \nEnter 3 to delete a node. \nEnter 4 to Display the tree. \nEnter 5 to exit: ");
            ch1 = sc.nextInt();
            switch (ch1)
            {
                case 1:
                {
                    System.out.print("\nEnter Value of Node: ");
                    int data1 = sc.nextInt();
                    bst.root = bst.Insert(bst.root,data1);
                    System.out.println("\nDisplaying Tree after Insertion:- ");
                    bst.Inorder(bst.root);
                    break;
                }
                case 2:
                {
                    System.out.print("\nEnter Data value to Search: ");
                    int data2 = sc.nextInt();
                    boolean answer = bst.search(bst.root,data2 );
                    if(answer)
                    {
                        System.out.print("\nElement present. Search Successful");
                    }
                    else
                        System.out.println("\nElement Not found");
                    break;
                }
                case 3:
                {
                    System.out.print("\nEnter Data value to Search: ");
                    int data3 = sc.nextInt();
                    boolean answer = bst.search(bst.root,data3);
                    if(answer)
                    {
                        bst.root = bst.delete(bst.root, data3);
                        System.out.println("\nElement Deleted Succesfully. Displaying after Deletion: ");
                        bst.Inorder(bst.root);
                    }
                    else
                        System.out.println("\nElement Not found and cannot be deleted.");                    
                    break;
                }
                case 4:
                {
                    System.out.println("\nInorder Traversal: ");
                    bst.Inorder(bst.root);
                    System.out.println("\nPreorder Traversal: ");
                    bst.Preorder(bst.root);
                    System.out.println("\nPostorder Traversal: ");
                    bst.Postorder(bst.root);
                    break;
                }
                case 5:
                {
                    System.exit(0);
                }
                default:
                    System.out.print("Invalid Input. Try Again: ");
                    break;
            }
        }while(ch1!=5);
        sc.close();     
    }

}
