package shapedetection.gui;

import shapedetection.model.Model;
import com.github.sarxos.webcam.Webcam;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class MainFrame extends javax.swing.JFrame {

    /**
     * Creates new form MainFrame
     */
    public MainFrame() {
        initComponents();
        startButton.setSelected(true);
        startButton.setEnabled(false);

        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                if (campanel != null) {
                    campanel.dispose();
                }
                System.exit(0);
            }
        });
    }

    public void init() {

        ProcessPanel procPanel = new ProcessPanel("Подготовка к работе...");
        actionPanel.add(procPanel);
        repaint();
        
        Webcam webcam = Webcam.getDefault();
        actionPanel.remove(procPanel);

        initCam(webcam);
    }

    public void initCam(Webcam webcam) {
        if (campanel != null) {
            campanel.dispose();
        }

        campanel = new WebcamDetectingPanel();
        WebcamPanelListener listener = new WebcamPanelListener(startButton, actionPanel);
        campanel.AttachListener(listener);

        setWorkingConfigs();

        campanel.Init(webcam);
    }

    public void setWorkingConfigs() {
        Model.setConfigs();
        campanel.setConfigs();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        startButton = new javax.swing.JToggleButton();
        actionPanel = new javax.swing.JPanel();
        menu = new javax.swing.JMenuBar();
        optionsItem = new javax.swing.JMenu();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Детектор образов");
        setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        setResizable(false);

        startButton.setText("Стоп");
        startButton.setEnabled(false);
        startButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                startButtonActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout actionPanelLayout = new javax.swing.GroupLayout(actionPanel);
        actionPanel.setLayout(actionPanelLayout);
        actionPanelLayout.setHorizontalGroup(
            actionPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 320, Short.MAX_VALUE)
        );
        actionPanelLayout.setVerticalGroup(
            actionPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 240, Short.MAX_VALUE)
        );

        optionsItem.setText("Настройки");
        optionsItem.addMenuListener(new javax.swing.event.MenuListener() {
            public void menuCanceled(javax.swing.event.MenuEvent evt) {
            }
            public void menuSelected(javax.swing.event.MenuEvent evt) {
                optionsItemMenuSelected(evt);
            }
            public void menuDeselected(javax.swing.event.MenuEvent evt) {
            }
        });
        menu.add(optionsItem);

        setJMenuBar(menu);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(actionPanel, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(120, 120, 120)
                        .addComponent(startButton, javax.swing.GroupLayout.PREFERRED_SIZE, 100, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(actionPanel, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(startButton, javax.swing.GroupLayout.PREFERRED_SIZE, 33, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        startButton.getAccessibleContext().setAccessibleName("");

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void startButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_startButtonActionPerformed
        if (startButton.isSelected()) {
            campanel.resume();
        } else {
            campanel.pause();
        }
    }//GEN-LAST:event_startButtonActionPerformed

    private void optionsItemMenuSelected(javax.swing.event.MenuEvent evt) {//GEN-FIRST:event_optionsItemMenuSelected
        if (optionsFrame == null) {
            optionsFrame = new OptionsFrame(this);
        }
        optionsFrame.getOptions();

        optionsFrame.setLocationRelativeTo(this);
        optionsFrame.setVisible(true);
    }//GEN-LAST:event_optionsItemMenuSelected
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JPanel actionPanel;
    private javax.swing.JMenuBar menu;
    private javax.swing.JMenu optionsItem;
    private javax.swing.JToggleButton startButton;
    // End of variables declaration//GEN-END:variables
    private WebcamDetectingPanel campanel;
    private OptionsFrame optionsFrame;
}