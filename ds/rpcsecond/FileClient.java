import java.awt.*;
import java.awt.event.*;
import java.applet.Applet;
import java.rmi.*;
import java.rmi.registry.*;

public class FileClient extends Applet implements ActionListener {
	public Button btn;
	public TextField txtDisp;

	public void init() {
		setLayout(new FlowLayout());
		setBackground(Color.lightGray);
		add(new Label("String : "));
		btn = new Button("Get String");
		add(btn);
		btn.addActionListener(this);
		txtDisp = new TextField(30);
		txtDisp.setEditable(false);
		add(txtDisp);
	}

	public void actionPerformed(ActionEvent ae) {
		FileServerInterface tobj;
		try {
			Registry r1 = LocateRegistry.getRegistry("localhost", 49111);
			tobj = (FileServerInterface)r1.lookup("FileServer");
			String str = tobj.getString();
			txtDisp.setText(str);
			repaint();
		} catch (Exception e) {
			System.out.println(e.toString());
		}
	}
}
