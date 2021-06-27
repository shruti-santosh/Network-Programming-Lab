import java.net.*;
import java.io.*;
import java.util.Scanner;
public class tcpclient
{
public static void main(String args[]) throws Exception
{
Socket s = new Socket("localhost",42069);
DataInputStream din = new
DataInputStream(s.getInputStream());
DataOutputStream dout = new
DataOutputStream(s.getOutputStream());

float num1,num2,result;
int flag;
char operator;
String msg;
Scanner sc = new Scanner(System.in);
System.out.print("Enter first number:");
num1 = sc.nextFloat();
dout.writeFloat(num1);
System.out.print("\nEnter second number:");
num2=sc.nextFloat();
dout.writeFloat(num2);
System.out.print("\nEnter operator(+,-,*,/,%):");
operator=sc.next().charAt(0);
dout.writeChar(operator);
dout.flush();
flag = din.readInt();
if(flag == 0)
{

result = din.readFloat();
System.out.print("\nResult: "+result+"\n");
}
else
System.out.print("Wrong Operator!\n");
dout.close();
s.close();
}
}
