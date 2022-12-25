import java.util.*;
public class BST_Traversals {
    class Node{
        int data;
        Node left,right;
        Node(int x)
        {
            data=x;
            left=right=null;
        }
    }
    Node root;
    BST_Traversals()
    {
        root = null;
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
    void level_wise_print(Node root)
    {
        Queue<Node> q = new LinkedList<Node>();
        q.add(root);
        while(!q.isEmpty())
        {            
            int count = q.size();
            for(int i =0;i<count;i++){
                Node curr = q.poll();
                System.out.print(curr.data+" ");
                if(curr.left!=null)
                q.add(curr.left);
                if(curr.right!=null)
                q.add(curr.right);
            }
            System.out.println();
        }
    }
    class Pair
    {
        Node node;
        int hd;
        Pair(Node n , int h)
        {
            node = n;
            hd = h;
        }
    }
     void vertical_print()
    {
        Queue<Pair> q = new LinkedList<Pair>();
        Map<Integer , ArrayList<Integer>> mp = new TreeMap<>();
        q.add(new Pair(root,0));
        while(!q.isEmpty())
        {
            Pair p = q.poll();
            Node curr = p.node;
            int hd = p.hd;
            if(mp.containsKey(hd))
                mp.get(hd).add(curr.data);
            else
            {
                ArrayList<Integer> al = new ArrayList<Integer>();
                al.add(curr.data);
                mp.put(hd, al);
            }
            if(curr.left!=null)
                q.add(new Pair(curr.left , hd-1));
            if(curr.right!=null)
                q.add(new Pair(curr.right , hd+1));
        }
        for(Map.Entry<Integer , ArrayList<Integer>> p: mp.entrySet())
        {
            ArrayList<Integer> al = p.getValue();
            for(int x : al)
                System.out.print(x+" ");
            System.out.println();
        }

    }   
    void spiral_print(Node root)
    {
        Stack<Node> s1 = new Stack<>();
        Stack<Node> s2 = new Stack<>();
        s1.push(root);
        while(!s1.isEmpty() || !s2.isEmpty())
        {
            while(!s1.isEmpty())
            {
                Node curr = s1.pop();
                System.err.print(curr.data + " ");
                if(curr.left!=null)
                s2.push(curr.left);
                if(curr.right!=null)
                s2.push(curr.right);
            }
            while(!s2.isEmpty())
            {
                Node curr = s2.pop();
                System.err.print(curr.data + " ");
                if(curr.right!=null)
                s1.push(curr.right);
                if(curr.left!=null)
                s1.push(curr.left);
            }
        }
    }
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        BST_Traversals bst = new BST_Traversals();
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
        System.out.println("\nInorder Traversal: ");
        bst.Inorder(bst.root);
        System.out.println("\nPreorder Traversal: ");
        bst.Preorder(bst.root);
        System.out.println("\nPostorder Traversal: ");
        bst.Postorder(bst.root);
        System.out.println("\nLevel Wise Print: ");
        bst.level_wise_print(bst.root);
        System.out.println("\nSpiral Print: ");
        bst.spiral_print(bst.root);
        System.out.println("\nVertical Level Print: ");
        bst.vertical_print();
        sc.close();
    }    
}
