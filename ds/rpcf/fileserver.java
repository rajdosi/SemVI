import java.rmi.*;
import java.rmi.server.*;
import java.rmi.registry.*;
import java.util.Date;
import java.io.*;

public class fileserver extends UnicastRemoteObject implements fileserverinterface{
public String data,buf;
	public String readit(int off,int numbytes )
	{
		try{
		byte[] b=new byte[numbytes];
		File file = new File("text");
		FileInputStream f1 = new FileInputStream(file);
		f1.skip(off);
		f1.read(b,0,numbytes);
		buf= new String(b);
		return buf;
 		}
		catch(Exception e)
		{System.out.println(e.toString());}
		
		return buf;
	}

	public fileserver() throws RemoteException 
	{super();
	data= "check";}
	public static void main(String a[])
	{
		try{
			fileserver obj = new fileserver();
			Registry r1=LocateRegistry.createRegistry(8100);
		r1.rebind("fileserver",obj);
		}catch(Exception e)
		{System.out.println(e.toString());}
	}
}
