import java.awt.FlowLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JFrame;
import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.JOptionPane;




public class ModernClock extends JFrame implements ActionListener {

	
private	JTextField textfield;
private JButton set;
private JButton clear;
private JButton display;
static String time;
ModernClock(){
	super("Displaying time and date");
	setLayout(new FlowLayout());
textfield=new JTextField(20);
add(textfield);
set=new JButton("Set");
add(set);
clear=new JButton("Clear");
add(clear);
display=new JButton("Display");
add(display);
set.addActionListener(this);
clear.addActionListener(this);
display.addActionListener(this);
}
public void actionPerformed(ActionEvent event) {
	
	if(event.getSource()==set)
{		time=JOptionPane.showInputDialog("enter the time and date in the following format hh:mm:ss AM or PM dd/MM/yyyy ");

 }
	

if(event.getSource()==clear)
{textfield.setText("");
}
if(event.getSource()==display)
	
	textfield.setText(time);
}}










	
	

	
	






