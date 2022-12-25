import java.util.*;
public class Assignment2 {
    public int[][] makegraph(int v)
    {
        Scanner sc = new Scanner(System.in);
        int[][] m_graph = new int[v][v];
        for(int i =0;i<v;i++)
        {
            for(int j = i;j<v;j++)
            {
                System.out.print("\nIs the any edge from "+(i+1) + " to "+ (j+1) + "?\nIf Yes press 1 other wise press 2: ");
                int choice = sc.nextInt();
                if(choice==1)
                {
                    System.out.print("\nEnter The Weight of the Edge: ");
                    int w = sc.nextInt();
                    m_graph[i][j]=w;
                    m_graph[j][i]=w;
                }
                else
                {
                    m_graph[i][j]=0;
                    m_graph[j][i]=0;
    
                }
            }
        }
        sc.close();
        return m_graph;

    }
    public int Primsmst(int graph[][] , int v)
    {
        int res =0;
        int key[] = new int[v];
        Arrays.fill((key), Integer.MAX_VALUE);
        key[0]=0;
        boolean MST[] = new boolean[v];
        for(int count =0;count<v;count++)                                              // outer loop to traverse all vertices
        {
            int u =-1;
            for(int i = 0;i<v;i++)                                                      //this loop selects a vertex not yet included
            {                                                                           //and having minimum weight
                if(!MST[i]&&((u==-1) || key[i]<key[u]))
                {
                    u=i;
                }
            }
            MST[u] = true;
            res+=key[u];
            for(int j =0;j<v;j++)                                                       //this loop updates the weights of adjacent
            {                                                                           //vertices for the chosen value of "u"
                if(!MST[j] && graph[u][j]!=0 && graph[u][j]<key[j] )
                {
                    key[j]=graph[u][j];
                }
            }
        }
        return res;
    }
    public static void main(String[] args) {
        Assignment2 obj = new Assignment2();
        Scanner sc = new Scanner(System.in);
        System.out.println("Lets Create A graph first!! ");
        System.out.println("Enter The Number Of Vertices: ");
        int num= sc.nextInt();
        int[][] graph = new int[num][num];
        graph = obj.makegraph(num);
        int result = obj.Primsmst(graph, num);
        System.out.println("The Cost of MST of the above graph is:- "+ result);    
        sc.close();   
    }

}
