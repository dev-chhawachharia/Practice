import java.util.*;
class Main{
    static  int size =0 ;
    int hash(int key,int cap)
    {
        return key%cap;
    }
    boolean Search(int key , int cap , int[] arr)
    {
        int h = hash(key,cap);
        int i =h;
        while(arr[i]!=-1)
        {
            if(arr[i]==key)
                return true;
            i = (i+1)%cap;
            if(i==h)
                return false;
        }
        return false;
    }
    boolean Insert(int key,int cap, int[] arr)
    {
        if(size==cap)
            return false;
        int i = hash(key,cap);
        while(arr[i]!=-1 && arr[i]!=-2 && arr[i]!=key)
        {
            i=(i+1)%cap;
        }
        if(arr[i]==key)
            return false;
        else{
            arr[i]=key;
            size++;
            return true;
        }
    }
    boolean Erase(int key,int cap,int[] arr)
    {
        int h = hash(key,cap);
        int i =h;
        while(arr[i]!=-1)
        {
            if(arr[i]==key)
            {
                arr[i]=-2;
                return true;
            }
            i = (i+1)%cap;
            if(i==h)
                return false;
        }
        return false;
    }
    void printHash(int[] arr)
    {
        System.out.println("\n\n\n");
        for(int i = 0;i<arr.length;i++)
        {
            if(arr[i]==-1 || arr[i]==-2)
                System.out.println();
            else
                System.out.println(arr[i]);
        }
        System.out.println("\n\n\n");
    }
    public static void main (String[] args) {
        Scanner SC = new Scanner(System.in);
        System.out.print("Number of Elements: ");
        int n = SC.nextInt();
        int[] arr = new int[n];
        for(int i =0;i<n;i++)
        {
            arr[i]=-1;
        }
        SC.nextLine();
        Main obj = new Main();
        int choice ;
        do{
            System.out.println("Choose:\n1.Insert\n2.Search\n3.Delete\n4.Display Hash Table\n5.Exit");
            choice = SC.nextInt();
            switch(choice)
            {
                case 1:
                {
                    System.out.println("Enter Key to put into hash table: ");
                    int value_to_insert = SC.nextInt();
                    boolean check_insert = obj.Insert(value_to_insert ,n,arr);
                    if(check_insert){
                        System.out.println("Value Entered Succesfully");
                        // System.out.println(size);
                    }
                    else if(!check_insert)
                    {
                        System.out.println("Error in Inserting");
                    }
                    else {
                    	System.out.println();
                    }
                    break;
                }
                case 2:
                {
                    System.out.println("Enter Key to search in hash table: ");
                    int value_to_search = SC.nextInt();
                    boolean check_search = obj.Search(value_to_search,n,arr);
                    if(check_search)
                        System.out.println("Value Present");
                    else
                    {
                        System.out.println("Value Absent");
                    }
                    break;
                }
                case 3:
                {
                    System.out.println("Enter Key to put into hash table: ");
                    int value_to_delete = SC.nextInt();
                    boolean check_delete = obj.Erase(value_to_delete,n,arr);
                    if(check_delete)
                        System.out.println("Value Deleted Succesfully");
                    else
                    {
                        System.out.println("Error in Deleting");
                    }
                    break;
                }
                case 4:
                {
                    obj.printHash(arr);
                    break;
                }
                case 5:
                {
                    break;
                }
                default:
                    System.out.println("Try Again");
            }
        }while(choice != 5);
        SC.close();
    }
}