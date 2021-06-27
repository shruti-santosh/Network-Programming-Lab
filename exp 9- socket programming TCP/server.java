import java.net.*;
import java.io.*;
public class tcpserver
{
public static void main(String args[]) throws Exception
{
ServerSocket ss = new ServerSocket(42069);
Socket s = ss.accept();
DataInputStream din = new
DataInputStream(s.getInputStream());
DataOutputStream dout = new
DataOutputStream(s.getOutputStream());
float num1,num2,result=0;
int flag = 0;
char operator;
num1 = din.readFloat();
System.out.print("First number: "+num1);
num2 = din.readFloat();
System.out.print("\nSecond number: "+num2);
operator = din.readChar();
System.out.print("\nOperator: "+operator+"\n");

switch (operator)
{
case '+':
result = num1 + num2;
break;
case '-':
result = num1 - num2;
break;
case '*':
result = num1* num2;
break;
case '/':
result = num1 / num2;
break;
case '%':
result = num1 % num2;
break;
default:
System.out.print("\nERROR!! Wrong
Operator\n");

flag = 1;
break;

}
dout.writeInt(flag);
dout.writeFloat(result);
dout.flush();
din.close();
s.close();
ss.close();
}
}
