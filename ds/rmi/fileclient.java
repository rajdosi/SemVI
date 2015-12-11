import java.awt.*;
import java.awt.event.*;
import java.applet.Applet;
import java.rmi.*;
import java.rmi.registry.*;

public class fileclient extends Frame implements ActionListener
{
	Button b1;
	TextField seek,updated_off,text,num;
	Label lbl1,lbl2,lbl3,lbl4;
	
	fileserverinterface f1;
	
	fileclient()
	{
	setSize(400,400);	
	setLayout(new FlowLayout());

	lbl1=new Label("Offset");
	lbl2=new Label("Server offset");
	lbl3=new Label("String");
	lbl4=new Label("bytes");
	b1=new Button("Get");
	seek=new TextField(50);
	updated_off=new TextField(50);
	text=new TextField(50);
	num=new TextField(50);

	add(lbl1);
	add(seek);
	add(lbl2);
	add(updated_off);
	add(lbl3);
	add(text);
	add(lbl4);
	add(num);

	add(b1);
	b1.addActionListener(this);
	seek.setEditable(true);
	updated_off.setEditable(false);
	text.setEditable(false);
	num.setEditable(true);

	//TextField txtDisp=new TextField(30);



	}
public static void main(String args[])
	{

	fileclient t=new fileclient();
	t.setVisible(true);	
        }
	public void actionPerformed(ActionEvent ae)
	{
	try{

	Registry r=LocateRegistry.getRegistry("localhost",8100);
	f1=(fileserverinterface)r.lookup("fileserver");
	int s=Integer.parseInt(seek.getText());
	int n=Integer.parseInt(num.getText());
	String str=f1.readit(s,n);
	updated_off.setText("..."+str.length());
	text.setText("..."+str);
	//System.out.println(str);
	}
	catch(Exception e){System.out.println(e.toString());}
	}	
}
