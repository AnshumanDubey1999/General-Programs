import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class TimeBoostGUI {

    private JFrame inputFrame = new JFrame();
    private JFrame outputFrame = new JFrame();
    private JButton resetButton = new JButton("Reset");
    private JButton editButton = new JButton("Edit");
    private JButton enterButton = new JButton("Enter");
    private JPanel inputPanel = new JPanel();
    private JPanel outputPanel = new JPanel();
    private JLabel titleLabel = new JLabel("<html><h3 style=\"text-align:center;font-size:24px;font-family:Impact, Charcoal, sans-serif\"><font color=white>Enter the speedups you have :</font></h3></html>");
    private JLabel displayLabel = new JLabel();
    private JLabel endLabel = new JLabel("<html><br></html>");
    private JLabel timeLabel[] = new JLabel[10];
    private long time[] = new long[10];
    private int value[] = {3, 5, 10, 15, 30, 60, 180, 480, 900, 1440};
    private double timeSec = 0.0, timeMin = 0.0, timeHr = 0.0, timeDay = 0.0, timeMon = 0.0;
    private JTextField textField[] = new JTextField[10];

    public static void main(String[] args) {
        TimeBoostGUI timeBoostGUI = new TimeBoostGUI();
        timeBoostGUI.createEnvironment();
    }

    void createEnvironment(){
        JPanel tablePanel = new JPanel();
        JPanel titlePanel = new JPanel();
        for (int i = 0; i < 10; i++) {
            timeLabel[i] = new JLabel("<html><font color=white>"+(value[i]>30? (value[i]/60) + "hrs :" : value[i] + "mins : ") + "</font></html>");
        }                   //Adding labels
        inputFrame.setContentPane(inputPanel);
        for (int i = 0; i < 10; i++) {
            textField[i] = new JTextField(10);
            textField[i].setText("");
        }                   //Adding textFields
        textField[0].requestFocus();
        resetButton.addActionListener(new ResetButtonActionListener());
        enterButton.addActionListener(new KeyActionListener());
        editButton.addActionListener(new EditButtonActionListener());

        inputFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        inputFrame.setSize(850,400);                                 //SIZE
        inputFrame.setVisible(true);

        inputPanel.setAlignmentX(JPanel.CENTER_ALIGNMENT);
        inputPanel.setAlignmentY(JPanel.CENTER_ALIGNMENT);
        inputPanel.setSize(800,400);
        inputPanel.setBackground(Color.BLACK);
        inputPanel.setLayout(new BoxLayout(inputPanel,BoxLayout.Y_AXIS));

        titlePanel.setBackground(Color.BLACK);
        titlePanel.add(titleLabel);
        inputPanel.add(titlePanel);

        tablePanel.setLayout(new GridLayout(6,7, 25, 25));
        tablePanel.setBackground(Color.BLACK);
        for (int i = 0; i < 10; i++) {
            if(i%2==0)
                tablePanel.add(Box.createRigidArea(new Dimension(0,0)));
            tablePanel.add(timeLabel[i]);
            tablePanel.add(textField[i]);
            tablePanel.add(Box.createRigidArea(new Dimension(0,0)));
        }
        tablePanel.add(Box.createRigidArea(new Dimension(0,0)));
        tablePanel.add(Box.createRigidArea(new Dimension(0,0)));
        tablePanel.add(Box.createRigidArea(new Dimension(0,0)));
        tablePanel.add(Box.createRigidArea(new Dimension(0,0)));
        tablePanel.add(enterButton);
        tablePanel.add(resetButton);
        inputPanel.add(tablePanel);
        inputPanel.add(endLabel);
    }

    void reset(){
        for (int i = 0; i < 10; i++) {
            textField[i].setText("");
        }
        timeSec = 0.0;
        timeMin = 0.0;
        timeHr = 0.0;
        timeDay = 0.0;
        timeMon = 0.0;
        textField[0].requestFocus();
        outputFrame.setVisible(false);
    }

    void calculate(){
        for (int i = 0; i < 10; i++) {
            timeMin += time[i]*value[i];
        }
        timeSec = timeMin*60;
        timeHr = timeMin/60.0;
        timeDay = timeHr/24.0;
        timeMon = timeDay/30.0;
        display();
    }

    void display(){
        JPanel buttonPanel = new JPanel();
        JPanel printPanel = new JPanel();
        outputFrame.setContentPane(outputPanel);
        displayLabel.setText("<HTML> " +
                        "<B><h1 style=\"text-align:center;font-size:16px;font-family:Impact, Charcoal, sans-serif\"><font color=white>Total amount of time boosts<br> you have is :</font></h1></B> " +
                        "<p style=\"text-align:center;font-size:12px;font-family:Georgia, serif\"><font color=white>In seconds : "+ timeSec  +"<br> " +
                        "In Minutes : "+ timeMin  +"<br> " +
                        "In Hours   : "+ timeHr  +"<br> " +
                        "In Days    : "+ timeDay  +"<br> " +
                        "In Months  : "+ timeMon  +"<br><p> " +
                        "</font></HTML>");
        outputPanel.setLayout(new BoxLayout(outputPanel,BoxLayout.Y_AXIS));
        outputFrame.setSize(500,300);
        outputFrame.setVisible(true);
        outputPanel.setBackground(Color.BLACK);
        printPanel.setBackground(Color.BLACK);
        printPanel.add(displayLabel);
        outputPanel.add(printPanel);

        buttonPanel.setBackground(Color.BLACK);
        buttonPanel.add(editButton);
        buttonPanel.add(resetButton);
        outputPanel.add(buttonPanel);
        outputPanel.add(endLabel);
    }

    class KeyActionListener implements ActionListener{

        @Override
        public void actionPerformed(ActionEvent e) {
            String input;
            for (int i = 0; i < 10; i++) {
                input = textField[i].getText();
                if(input.equals(""))
                    time[i] = 0;
                else
                    time[i] = Long.parseLong(input);
            }
            calculate();
        }
    }

    class ResetButtonActionListener implements ActionListener{

        @Override
        public void actionPerformed(ActionEvent e) {
            reset();
        }
    }

    class EditButtonActionListener implements ActionListener{

        @Override
        public void actionPerformed(ActionEvent e) {
            outputFrame.setVisible(false);
        }
    }
}
