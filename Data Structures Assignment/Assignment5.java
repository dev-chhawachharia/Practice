import java.util.*;

public class Assignment5 {
    int marks;
    int roll;
    String name;
    Assignment5(int m ,int r , String n){
        marks = m;
        name = n ;
        roll = r;
    }
    
    static int left(int i){
        return 2*i+1;
    }
    static int right(int i){
        return 2*i+2;
    }    
    static void min_build_heap(int arr[],int size ,int capacity)
    {
        for(int i = (size-2)/2;i>=0;i--)
            min_heapify(arr, size, capacity, i);
    }
    static void min_heapify(int arr[],int size ,int capacity,int i)
    {
        int lt = left(i);
        int rt = right(i);
        int smallest = i; 
        if(lt<size && arr[lt]<arr[i])
            smallest = lt;
        if(rt<size && arr[rt]<arr[smallest])
            smallest = rt;
        if(smallest!=i)
        {
            int temp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = temp;
            min_heapify(arr, size, capacity, smallest);
        }        
    }
    static int extract_min(int arr[],int size,int capacity )
    {
        if(size==0)
            return Integer.MAX_VALUE;
        if(size==1)
        {
            size--;
            return arr[0];
        }
        int temp = arr[0];
        arr[0] = arr[size-1];
        arr[size-1] = temp;
        size--;
        min_heapify(arr, size, capacity,0);
        return arr[size];
    }

    static void max_build_heap(int arr[],int size ,int capacity)
    {
        for(int i = (size-2)/2;i>=0;i--)
            max_heapify(arr, size, capacity, i);
    }
    static void max_heapify(int arr[],int size ,int capacity,int i)
    {
        int lt = left(i);
        int rt = right(i);
        int greatest = i; 
        if(lt<size && arr[lt]>arr[i])
            greatest = lt;
        if(rt<size && arr[rt]>arr[greatest])
            greatest = rt;
        if(greatest!=i)
        {
            int temp = arr[i];
            arr[i] = arr[greatest];
            arr[greatest] = temp;
            max_heapify(arr, size, capacity, greatest);
        }        
    }
    static int extract_max(int arr[],int size,int capacity )
    {
        if(size==0)
            return Integer.MAX_VALUE;
        if(size==1)
        {
            size--;
            return arr[0];
        }
        int temp = arr[0];
        arr[0] = arr[size-1];
        arr[size-1] = temp;
        size--;
        max_heapify(arr, size, capacity,0);
        return arr[size];
    }

 public static void main(String[] args) {
     Scanner sc = new Scanner(System.in);
     System.out.print("Enter Number Of Students: ");   
     int cap = sc.nextInt();
     System.out.println("");
     Assignment5[] s = new Assignment5[cap];
     int[] arr= new int[cap];
     for(int i = 0;i<cap;i++)
     {        
        System.out.print("\n\nEnter Student's Name: ");
        String t_name = sc.next(); 
        System.out.print("\nEnter Student's Roll Number: ");
        int t_roll = sc.nextInt();
        System.out.print("\nEnter Student's Marks: ");
        int t_marks = sc.nextInt();
        s[i] = new Assignment5(t_marks, t_roll,t_name);  
        arr[i] = s[i].marks; 
     }
     min_build_heap(arr, cap,cap);
     int min = extract_min(arr, cap,cap);
     for(int i = 0;i<cap;i++)
     {
         if(s[i].marks == min)
         {
             System.out.print("\n\nMinimum Marks In the Subject is obtained by: ");
             System.out.print("\nName: "+ s[i].name);
             System.out.print("\nRoll Number: "+s[i].roll);
             System.err.print("\nMarks: " + s[i].marks);
         }
     }
     max_build_heap(arr, cap,cap);
     int max = extract_max(arr, cap,cap);
     for(int i = 0;i<cap;i++)
     {
         if(s[i].marks == max)
         {
             System.out.print("\n\nMaximum Marks In the Subject is obtained by: ");
             System.out.print("\nName: "+ s[i].name);
             System.out.print("\nRoll Number: "+s[i].roll);
             System.err.print("\nMarks: " + s[i].marks);
         }
     }
    sc.close();   
 }   
}
