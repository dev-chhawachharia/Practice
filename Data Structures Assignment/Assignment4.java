import java.util.*;
public class Assignment4 {
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
    int[] dijkstraAlgorithm(int[][] graph, int source) {
        int vertices = graph.length;
        int[] dist = new int[vertices];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[source] = 0;
        boolean[] fin = new boolean[vertices];
        for (int count = 0; count <= vertices - 1; count++) {
            int u = -1;
            for (int i = 0; i < vertices; i++) {
                if (!fin[i] && (u == -1 || dist[i] < dist[u])) {
                    u = i;
                }
            }
                fin[u] = true;
                for (int currentVertex = 0; currentVertex < vertices; currentVertex++) {
                    if (!fin[currentVertex] && graph[u][currentVertex] != 0) {
                        dist[currentVertex] = Math.min(dist[currentVertex], dist[u] + graph[u][currentVertex]);
                    }
                }
            }
        return dist;
    }
    void print_solutuon(int dist[],int v)
    {   
        System.out.println("Vertex \t\t Distance From Source: ");
        for(int i =0;i<v;i++)
        {
            System.out.println(i + "\t\t" + dist[i]);
        }
    }
    

public static void main(String[] args) {
    Assignment4 obj = new Assignment4();
    Scanner sc = new Scanner(System.in);
    System.out.println("Lets Create A graph first!! ");
    System.out.println("Enter The Number Of Vertices: ");
    int num= sc.nextInt();
    System.out.println("Enter the Vertex of Source: ");
    int src = sc.nextInt();
    int[][] graph = new int[num][num];
    graph = obj.makegraph(num);
    sc.nextLine();
    int[] result = obj.dijkstraAlgorithm(graph,src);
    obj.print_solutuon(result,num);
       
    sc.close();   
 }
}
