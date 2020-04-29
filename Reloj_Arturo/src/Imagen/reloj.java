
package Imagen;
import java.util.*;
import java.awt.*;
import javax.swing.ImageIcon;
import javax.swing.JPanel;

/**
 *
 * @author Arturo Zamudio
 * 
 */

public class reloj extends javax.swing.JFrame implements Runnable{
String hora, minutos,segundos, ampm;
Calendar calendario;
Thread h1;

    public reloj() {
        imagen_fondo relojImagen = new imagen_fondo();
         this.setContentPane(relojImagen);
        initComponents();
        h1 = new Thread(this);
        h1.start();
        setLocationRelativeTo(null);
        setTitle("Reloj");
        setVisible(true);
        
    }

    
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        lbReloj = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setBackground(new java.awt.Color(153, 255, 0));
        setForeground(java.awt.Color.black);

        lbReloj.setFont(new java.awt.Font("Tempus Sans ITC", 1, 24)); // NOI18N
        lbReloj.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        lbReloj.setText("jLabel1");
        lbReloj.setName("bReloj"); // NOI18N

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(lbReloj, javax.swing.GroupLayout.PREFERRED_SIZE, 692, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(152, 152, 152))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(lbReloj, javax.swing.GroupLayout.PREFERRED_SIZE, 368, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        lbReloj.getAccessibleContext().setAccessibleName("lbReloj");

        pack();
    }// </editor-fold>//GEN-END:initComponents

  
   

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel lbReloj;
    // End of variables declaration//GEN-END:variables

    @Override
    public void run() {
        Thread ct = Thread.currentThread();
        while(ct == h1){
            calcula();
            lbReloj.setText(hora+":"+minutos+":"+segundos+":"+ampm);
            try{
                Thread.sleep(1000);
            }catch(InterruptedException e){}
            
            
        }
    }

    private void calcula() {
       Calendar calendario = new GregorianCalendar();
       Date fechaHoraActual = new Date();
       calendario.setTime(fechaHoraActual);
       ampm = calendario.get(Calendar.AM_PM) == Calendar.AM?"AM":"PM";
       
       if(ampm.equals("PM")){
           int h= calendario.get(Calendar.HOUR_OF_DAY)-12;
           hora = h>9? ""+h:"0"+h;
       }else{
           hora = calendario.get(Calendar.HOUR_OF_DAY)>9?""+calendario.get(Calendar.HOUR_OF_DAY):"0"+calendario.get(Calendar.HOUR_OF_DAY);
       }
        minutos = calendario.get(Calendar.MINUTE)>9?""+calendario.get(Calendar.MINUTE):"0"+calendario.get(Calendar.MINUTE);
         segundos = calendario.get(Calendar.SECOND)>9?""+calendario.get(Calendar.SECOND):"0"+calendario.get(Calendar.SECOND);
       
    }
    class imagen_fondo extends JPanel {

        private Image imagen;

        public void paint(Graphics g) {
            imagen = new ImageIcon(getClass().getResource("/Imagen/astronauta.jpg")).getImage();
            g.drawImage(imagen, 0, 0, getWidth(), getHeight(), this);
            setOpaque(false);
            super.paint(g);
        }
    }
    
}
