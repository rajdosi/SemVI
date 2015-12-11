import java.awt.*;
import java.awt.event.*;
import java.applet.Applet;
import java.rmi.*;
import java.rmi.registry.*;

public class TimeClient extends Applet implements ActionListener {
	public Button btn;
	public TextField txtDisp;

	public void init() {
		setLayout(new FlowLayout());
		setBackground(Color.lightGray);
		add(new Label("Time : "));
		btn = new Button("Get Time : ");
		add(btn);
		btn.addActionListener(this);
		txtDisp = new TextField(30);
		txtDisp.setEditable(false);
		add(txtDisp);
	}

	public void actionPerformed(ActionEvent ae) {
		TimeServerInterface tobj;
		try {
			Registry r1 = LocateRegistry.getRegistry("localhost", 49111);
			tobj = (TimeServerInterface)r1.lookup("TimeService");
			String str = tobj.getTime();
			txtDisp.setText(str);
			repaint();
		} catch (Exception e) {
			System.out.println(e.toString());
		}
	}
}
