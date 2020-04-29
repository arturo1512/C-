/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package reloj;

import java.util.*;

/**
 *
 * @author Arturo Zamudio
 */
public class reloj extends javax.swing.JFrame implements Runnable{
String hora, minutos,segundos, ampm;
Calendar calendario;
Thread h1;

    public reloj() {
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

        lbReloj.setFont(new java.awt.Font("Tempus Sans ITC", 1, 18)); // NOI18N
        lbReloj.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        lbReloj.setText("jLabel1");
        lbReloj.setName("bReloj"); // NOI18N

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(lbReloj, javax.swing.GroupLayout.DEFAULT_SIZE, 511, Short.MAX_VALUE)
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(lbReloj, javax.swing.GroupLayout.DEFAULT_SIZE, 179, Short.MAX_VALUE)
                .addContainerGap())
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
}
