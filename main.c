import java.io.*;
import java.util.*;
class Node {
 int number;
 String data;
 Node yesLink, noLink;
 public Node(int number, String data) {
 this.number = number;
 this.data = data;
 this.yesLink = null;
 this.noLink = null;
 }
}
public class AIGameBinaryTree {
 private Node root;
 private final Scanner scanner = new Scanner(System.in);
 public static void main(String[] args) {
 AIGameBinaryTree game = new AIGameBinaryTree();
 game.loadDefaultData("C:\\Users\\ANUSHKA PANDEY\\Java\\MYProj\\src\\game1.txt");
// Load default data
 game.run();
 }
 private void loadDefaultData(String fileName) {
 try {
 File file = new File(fileName);
 Scanner fileScanner = new Scanner(file);
 fileScanner.nextLine(); // Skipping the first line (game title)
 while (fileScanner.hasNextLine()) {
 int number = fileScanner.nextInt();
 String data = fileScanner.nextLine().trim();
 Node newNode = new Node(number, data);
 insertNode(newNode);
 }
 fileScanner.close();
 } catch (FileNotFoundException e) {
 e.printStackTrace();
 }
 }
 private void insertNode(Node newNode) {
 if (root == null) {
 root = newNode;
 } else {
 Node current = root;
 while (true) {
 System.out.print("Is it a " + current.data + "? (Y/N): ");
 String response = scanner.nextLine().trim().toLowerCase();
 if (response.equals("y") || response.equals("yes")) {
 if (current.yesLink == null) {
 current.yesLink = newNode;
 break;
 } else {
current = current.yesLink;
 }
 } else if (response.equals("n") || response.equals("no")) {
 if (current.noLink == null) {
 current.noLink = newNode;
 break;
 } else {
 current = current.noLink;
 }
 } else {
 System.out.println("Please answer with Y/Yes or N/No.");
 }
 }
 }
 }
 private void displayTreeInOrder(Node node) {
 if (node != null) {
 displayTreeInOrder(node.yesLink);
 System.out.print(node.data + " ");
 displayTreeInOrder(node.noLink);
 }
 }
 private void run() {
 while (true) {
 System.out.println("\nMovie Guessing Game\nP Play the game\nL Load another game file\nD
Display the binary tree\nH Help information\nX Exit the program");
 System.out.print("...your choice: ");
 String choice = scanner.nextLine().trim().toLowerCase();
switch (choice) {
 case "p":
 playGame(root);
 break;
 case "l":
 System.out.print("Enter the file name: ");
 String fileName = scanner.nextLine().trim();
 loadDefaultData(fileName);
 break;
 case "d":
 displayBinaryTree();
 break;
 case "h":
 System.out.println("Help information: <Your help information here>");
 break;
 case "x":
 System.out.println("Exiting the program. Goodbye!");
 System.exit(0);
 break;
 default:
 System.out.println("Invalid choice. Please choose again.");
 }
 }
 }
 private void displayBinaryTree() {
 if (root == null) {
 System.out.println("Binary tree is empty.");
 } else {
 System.out.println("What order do you want to display?");
 System.out.println("1. Inorder\n2. Preorder\n3. Postorder\n4. Return to main menu")
System.out.print("... your choice: ");
 int displayChoice = scanner.nextInt();
 scanner.nextLine(); // Consume the newline character
 switch (displayChoice) {
 case 1:
 displayTreeInOrder(root);
 System.out.println();
 break;
 // Handle other display options (preorder, postorder)
 case 4:
 break;
 default:
 System.out.println("Invalid choice.");
 }
 }
 }
 private void playGame(Node current) {
 while (current != null) {
 System.out.println(current.data);
 if (current.yesLink == null && current.noLink == null)
 break;
 String answer;
 do {
 System.out.print("Your answer (Y/N): ");
 answer = scanner.next().trim().toLowerCase();
 scanner.nextLine(); // Consume the newline character
 } while (!(answer.equals("y") || answer.equals("yes") || answer.equals("n") ||
answer.equals("no")));
if (answer.equals("y") || answer.equals("yes"))
 current = current.yesLink;
 else
 current = current.noLink;
 }
 }
}
