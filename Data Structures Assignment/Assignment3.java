// Implement student database using files in JAVA and perform following operations: a. Insert, b. Delete, c. Display, d. Search

import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;
// Import the IOException Class to HANDLE ERRORS
import java.io.IOException;
import java.io.FileNotFoundException;


public class Assignment3 {
    void createFile() {
        try {
            File myObj = new File("Student.txt");
            if (myObj.createNewFile()) {
                System.out.println("File Created Successfully : " + myObj.getName());
            } 
            else {
                System.out.println("File Exists !!");
            }
        } catch (IOException e) {
            System.out.println("Error Occurred !!");
            e.printStackTrace();
        }
    }

    void insertRecord() throws IOException {
        FileWriter Writer = new FileWriter("Student.txt", true);
        Scanner SC = new Scanner(System.in);

        try {
            String name;
            int prNumber;
            double cgpa;

            System.out.print("\nEnter Student PR-Number : ");
            prNumber = SC.nextInt();
            SC.nextLine();
            Writer.write("PR Number : " + prNumber + "\n");

            System.out.print("Enter Student Name : ");
            name = SC.nextLine();
            Writer.write("Name : " + name + "\n");

            System.out.print("Enter Student CGPA : ");
            cgpa = SC.nextDouble();
            Writer.write("CGPA : " + cgpa + "\n");

            System.out.print("\nRecords Added Successfully !!!\n");        
            Writer.close();
        }

        catch (Exception e) {
            e.getStackTrace();
        }
        SC.close();
    }

    void readRecords() throws IOException {
        File myFile = new File("Student.txt");
        try {
            Scanner Reader = new Scanner(myFile);
            while(Reader.hasNextLine()) {
                String line = Reader.nextLine();
                System.out.println(line);
            }
            Reader.close();
        } 
        
        catch (FileNotFoundException e) {
            e.printStackTrace();
        }      
    }

    void deleteRecords() throws IOException {
        File myFile = new File("Student.txt");
        if(myFile.delete()) {
            System.out.println(myFile.getName() + " File Deleted");
        }
        else {
            System.out.println("File does not exist");
        }
    }

    boolean searchRecord(int prNumber) throws IOException {
        File myFile = new File("Student.txt");
        Scanner Reader = new Scanner(myFile);
     
        try {
            String line;
            int flag = 0;

            while(Reader.hasNextLine()) {
                line = Reader.nextLine();
                if (line.equals("PR Number : " + prNumber)){
                    System.out.println(line);
                    System.out.println(Reader.nextLine());
                    System.out.println(Reader.nextLine());

                    flag = 1;
                    return true;
                }
            }

            if(flag == 0){
                System.out.println("Record Not Found !!!");
            }
        } 
        finally {
            Reader.close();
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner SC = new Scanner(System.in);
        Assignment3 mainObject = new Assignment3();

        try {
            mainObject.createFile();
        } catch (Exception e) {
            e.printStackTrace();
        }

        try {
            while(true) {
                System.out.println("\n\n1. Insert New Student Record");
                System.out.println("2. Display All Student Records");
                System.out.println("3. Search for a Specific Student Record");
                System.out.println("4. Delete All Records");
                System.out.println("5. Exit");

                System.out.print("\nUser Choice : ");
                int userChoice = SC.nextInt();
                SC.nextLine();

                switch(userChoice){
                    case 1: {
                        mainObject.insertRecord();
                        break;
                    }

                    case 2: {
                        mainObject.readRecords();
                        System.out.println("\nEnd of File !!!");
                        break; 
                    }

                    case 3: {
                        System.out.print("Enter PR Number of Student to be Searched for : ");
                        int userSearchInput = SC.nextInt();
                        SC.nextLine();

                        mainObject.searchRecord(userSearchInput);
                        break;
                    }

                    case 4: {
                        mainObject.deleteRecords();
                        System.out.println("All Student Records Deleted Successfully !");
                        break;
                    }

                    case 5: {
                        System.exit(0);
                    }
                }
            }
        }

        catch(IOException e){
            e.printStackTrace();
        }
        SC.close();
    }
}